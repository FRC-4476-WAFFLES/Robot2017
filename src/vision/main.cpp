#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <netinet/in.h>
#include <resolv.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <thread>
#include "vision.hpp"
#include "run_result.hpp"

constexpr int ONE = 1;
constexpr int HOST_PORT = 8080;

void SocketHandler(int csock, Vision* vision) {
  while(true) {
    // Request the next frame
    RunResult result = vision->get_blocking();
    printf("%f\n", result.angle);
    char* bytes_to_send = to_bytes(&result);

    // Send the frame
    if(send(csock, bytes_to_send, sizeof(RunResult), MSG_NOSIGNAL) == -1) {
      fprintf(stderr, "Disconnect: %d\n", errno);
      return;
    }
  }
}

int main(int argv, char** argc) {
  // Ignore SIGPIPE on connection die
  signal(SIGPIPE, SIG_IGN);

  // Setup camera and check that it worked
  Vision vision(1);
  vision.main_loop();

  // Open the socket
  struct sockaddr_in my_addr = {};
  my_addr.sin_family = AF_INET;
  my_addr.sin_port = htons(HOST_PORT);
  my_addr.sin_addr.s_addr = INADDR_ANY;

  int hsock = socket(AF_INET, SOCK_STREAM, 0);

  if(hsock == -1)
    return 2;
  if((setsockopt(hsock, SOL_SOCKET, SO_REUSEADDR, &ONE, sizeof(int)) == -1)||
     (setsockopt(hsock, SOL_SOCKET, SO_KEEPALIVE, &ONE, sizeof(int)) == -1))
    return 3;
  if(bind(hsock, (sockaddr*)&my_addr, sizeof(my_addr)) == -1)
    return 4;
  if(listen(hsock, 10) == -1)
    return 5;

  while(true) {
    int csock = accept(hsock, nullptr, nullptr);
    if(csock != -1) {
      fprintf(stderr, "Connection!\n");
      std::thread(SocketHandler, csock, &vision).detach();
    } else {
      fprintf(stderr, "Error accepting %d\n", errno);
    }
  }
}
