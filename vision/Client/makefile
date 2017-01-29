all:
	cd fork && make
	cd thread && make
	cd overlapped && make
	g++ Client.cpp -o client
	# -lnsl -lsocket
clean:
	cd fork && make clean
	cd thread && make clean
	cd overlapped && make clean
	rm client

