/******************************************
** Program: pokemon.h 
** Author: Muhammad Faks
** Description: This header file contains all struct declarations and function prototypes
** Inputs: N/A
** Outputs: N/A
******************************************/

#ifndef POKEMON_H
#define POKEMON_H

#include <iostream> 
#include <string>
#include <fstream>

using namespace std; 

struct Pokemon { //used to read information from the dex.txt file and holds information about a pokemon
	int dex_num;
	string name;
	string type;
	int num_moves;
	string* moves;
};

struct Pokedex { //used to hold information from the dex.tct file and holds information about the pokedex
	string trainer;
	int num_pokemon;
	Pokemon* dex; //Declares a pokemeon object to store within the Pokedex struct
};

bool is_int(string);
void string_to_int(string, int&);
void welcome_trainer(Pokedex);
void manage_dex(string, int, ifstream&, Pokedex, Pokemon&, ofstream&);
void manage_dex_error(string, int); 
void search_by_dex(Pokedex, Pokemon&, ifstream&, string, int, ofstream&);
void print_dex(int, int, Pokedex, Pokemon, ofstream&);
void search_by_dex_to_file(Pokedex&, ofstream&, int);
void search_by_name(Pokedex, Pokemon&, ifstream&, string, int, ofstream&);
void print_name(int, string, Pokedex, Pokemon, ofstream&);
void search_by_type(Pokedex, Pokemon&, ifstream&, string, int, ofstream&);
void print_search_by_type(int, string, Pokedex, Pokemon&, ofstream&);
void add_pokemon(Pokedex&, ifstream&, string, int, ofstream&);
void add_new_part2(Pokemon&, ofstream&);
void open_new_file(ofstream&);
void trunc_file(ofstream&);
void delete_added_moves(string*); 
Pokemon* create_pokemons(int);
void populate_pokedex_data(Pokedex& , ifstream&);
string* create_moves(int);
void populate_pokemon(Pokemon&, ifstream&);
void delete_info(Pokedex&); 

#endif
