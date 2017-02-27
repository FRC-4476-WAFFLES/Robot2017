# Use the libraries in libarm for pi, libx86_64 for desktop linux
LIBS=-Lntcore/native/ntcore/build/libs/ntcore/static/* -lntcore\
	-Lcscore/native/build/libs/cscore/static/ -lcscore\
	-Lntcore/native/wpiutil/build/libs/wpituil/static/* -lwpiutil\
	`pkg-config --libs opencv`\
	-lpthread
INCLUDES=-Intcore/include -Icscore/include
G++_FLAGS=-O2 ${INCLUDES}

all: build_dir main
	@ #empty

deps:
	git submodule update
	cd ntcore && ./gradlew build
	rm -r cscore/examples
	cd cscore && ./gradlew build

main: main.cpp build/vision.o build/run_result.o
	g++ ${G++_FLAGS} -std=c++1z -Wall build/vision.o build/run_result.o main.cpp ${LIBS} -o main

build/vision.o: vision.cpp vision.hpp run_result.hpp
	g++ ${G++_FLAGS} -std=c++1z -c vision.cpp -o build/vision.o

build/run_result.o:  run_result.cpp run_result.hpp
	g++ ${G++_FLAGS} -std=c++1z -c run_result.cpp -o build/run_result.o

build_dir:
	@mkdir -p build

clean:
	rm -r build
	rm main

install:
	install -m 755 main /usr/local/bin/waffles_vision
	install -m 644 waffles_vision.service /etc/systemd/system/waffles_vision.service
	systemctl daemon-reload
