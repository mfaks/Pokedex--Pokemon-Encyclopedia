CC=g++
exe=prog

$(exe): pokemon.o run_pokemon.cpp
	$(CC) pokemon.o run_pokemon.cpp -o $(exe)

pokemon.o: pokemon.cpp pokemon.h
	$(CC) -c pokemon.cpp

clean: 
	rm -f *.o $(exe)
