Lab6: main.o
	g++ -g -std=c++11 -Wall -o Lab6 main.o

main.o: main.cpp Sorts.h Sorts.hpp
	g++ -g -std=c++11 -Wall -c main.cpp

clean:
	rm *o Lab6
	echo clean done
