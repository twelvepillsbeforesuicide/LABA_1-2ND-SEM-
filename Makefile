all: app

app: main.o vkcommunity.o database.o
	g++ main.o vkcommunity.o database.o -o app

main.o: main.cpp
	g++ -c main.cpp

vkcommunity.o: vkcommunity.cpp
	g++ -c vkcommunity.cpp

database.o: database.cpp
	g++ -c database.cpp

clean:
	rm -f *.o app
