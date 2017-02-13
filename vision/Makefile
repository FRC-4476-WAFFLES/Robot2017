# Use the libraries in libarm for pi, libx86_64 for desktop linux
LIBS=-lntcore `pkg-config --libs opencv` -lpthread
G++_FLAGS=-O2

all: build_dir main build/vision.o build/run_result.o

build_dir:
	@mkdir -p build

main: main.cpp build/vision.o build/run_result.o
	g++ ${G++_FLAGS} -std=c++1z -Wall build/vision.o build/run_result.o main.cpp ${LIBS} -o main

build/vision.o: vision.cpp vision.hpp run_result.hpp
	g++ ${G++_FLAGS} -std=c++1z -c vision.cpp -o build/vision.o

build/run_result.o: run_result.cpp run_result.hpp
	g++ ${G++_FLAGS} -std=c++1z -c run_result.cpp -o build/run_result.o

clean:
	rm -r build

install:
	install -m 755 main /usr/local/bin/waffles_vision
	install -m waffles_vision.service
