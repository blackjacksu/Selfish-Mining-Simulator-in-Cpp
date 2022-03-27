

all: main.o miner.o chain.o 
	g++ -g3 -o Selfish_Mine_Simulate main.o miner.o chain.o

clean:
	rm -f *.o *.bin
	
main.o: main.cpp miner.o 
	g++ -c main.cpp

miner.o: miner.cpp miner.h
	g++ -c miner.cpp

chain.o: chain.cpp chain.h
	g++ -c chain.cpp


