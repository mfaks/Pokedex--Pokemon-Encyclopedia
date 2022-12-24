/************************************************
** Program: run_pokemon.cpp
** Author: Muhammad Faks
** Description: This driver file contains the main function that runs the program
** Inputs: trainer name, name of .txt they wish to open, choice to manage their dex
** Outputs: prompt for trainer name, error message if file is not open, lists options to manage dex 
************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include "pokemon.h"

using namespace std; 

int main() {

	ifstream file;  //read from the file
	ofstream fout; //output to the file 
	Pokedex px; //declare pokedex struct 
	Pokemon pk; //declare pokemon struct 
	string choice, dexname;
	int choicevalue = 0;

	welcome_trainer(px); 
	cout << "\nEnter the name of .txt the file containing information about the Pokemon in your Pokedex: "; 
	getline(cin, dexname); 
	
	file.open(dexname.c_str(), ios::in);
	
	if (!file.is_open()) {	//checks if the file is not successfully opened
		cout << "Error opening the file . . . " << endl;
		return 1;
	}
	
	populate_pokedex_data(px, file); //populates the dex based on the inputted .txt file

	do { //runs until the user wishes to quit
	
		cin.clear();
		cin.ignore(1000, '\n'); 
		cout << "\n********************************************************************************************************************************" << endl;
		cout << "Search By Dex Number [1]" << endl << "Search By Name [2]" << endl << "Search By Type [3]" << endl << "Add New Pokemon [4]" << endl << "Quit [5]" << endl;
		cout << "\nHow would you like to manage your Pokedex today? Enter the corresponding number from brackets above to select an option: ";
		getline(cin, choice);
		string_to_int(choice, choicevalue);
		manage_dex(dexname, choice, choicevalue, px, fout);
		
	} while (choicevalue != 5);

	delete_info(px); //frees the memory allocated to the dynamic arrays 

	return 0;
}
