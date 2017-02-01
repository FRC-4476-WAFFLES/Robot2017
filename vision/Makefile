build/main: build main.cpp build/vision.o build/run_result.o
	g++ -ggdb -std=c++1z -Wall build/vision.o build/run_result.o main.cpp `pkg-config --libs opencv` -lpthread -o main

build/vision.o: vision.cpp vision.hpp run_result.hpp
	g++ -std=c++1z -c vision.cpp -o build/vision.o

build/run_result.o: run_result.cpp run_result.hpp
	g++ -std=c++1z -c run_result.cpp -o build/run_result.o

build:
	mkdir -p build

clean:
	rm -r build
