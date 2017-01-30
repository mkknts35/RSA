
CFLAGS=-std=c++11 -O3
encode: main.cpp rsa.o
	echo "#define ENCRYPT 1" > pp.h
	g++ $(CFLAGS) -o encode main.cpp rsa.o
decode: main.cpp rsa.o
	echo "#define ENCRYPT 0" > pp.h
	g++ $(CFLAGS) -o decode main.cpp rsa.o
rsa.o: rsa.h rsa.cpp
	g++ $(CFLAGS) -c rsa.cpp -o rsa.o
clean:
	rm -f encode decode rsa.o
