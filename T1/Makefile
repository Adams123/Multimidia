all: bwt.o main.o rl.o compile
all2: clean bwt.o main.o rl.o compile
bwt.o:
	@g++ -std=c++11 -c bwt.cpp -o bwt.o -g

rl.o:
	@g++ -std=c++11 -c rl.cpp -o rl.o -g

main.o:
	@g++ -std=c++11 -c main.cpp -o main.o -g

compile:
	@g++ -std=c++11 bwt.o rl.o main.o -o t1 -g
zip:
	zip -r t1 *.cpp *.h Makefile
clean:
	@rm -f *.o
