/******************************************************************************
** Program: pokemon.cpp
** Author: Muhammad Faks
** Description: This implementation file contains all function definitions
** Input: dex number, name, or type within the pokedex. Prompt to display pokedex informaiton to the terminal or to a file, name of new file, information to add new pokemon
** Ouput: Error messages if user input does not match pokedex data, error message if the file is not open, 
******************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include "pokemon.h"

using namespace std; 

/****************************************************************************
**Function: bool is_int ()
**Description: Checks if a string input is an integer
**Parameters: string input
**Pre-Conditions: Input is a string
**Post-Conditions: Returns true if the string input is an integer and if false if otherwise 
****************************************************************************/
bool is_int(string input) {

	for (int n = 0; n < input.length(); n++) {

		if (input[0] == '-' && input.length() > 1)
			continue;

		else if (!(input[n] >= '0' && input[n] <= '9'))  //checks the characters are not from 0 to 9
			return false;
	}
	return true;
}

/****************************************************************************
**Function: void string_to_int ()
**Description: converts a string input into an integer value
**Parameters: string input, int& value
**Pre-Conditions: Input is a defined string, integer variable has been itialized 
**Post-Conditions: Stores the integer value of the string in the new int value 
****************************************************************************/
void string_to_int(string input, int& value) {

	value = 0; //assings an "empty" value of zero 

	for (int i = 0; i < input.length(); i++) {

		if (input[i] == '-') 
			i++;

		int val = (int)(input[i] - '0');
		value = value * 10 + val; //math to store the value if a positive string into value 
	}

	if (input[0] == '-') {
		value = value * -1; //storing the negative integer in value if a "-" is detected
	}
}

/****************************************************************************
**Function: welcome_trainer
**Description: This function prompts the user to enter their name and store it in the Pokedex struct
**Parameters: Pokedex px
**Pre-Conditions: Pokedex struct has been declared, trainer has inputted their name  
**Post-Conditions: Trainer name is stored in the Pokedex and welcome message is prompted
****************************************************************************/
void welcome_trainer(Pokedex px) {

	cout << "\nHello trainer, what is your name? ";
	getline(cin, px.trainer); //stores trainer name in pokedex struct from header file
	cout << "Welcome to the National Pokedex, " << px.trainer << "!" << endl;

}

/****************************************************************************
**Function: void manage_dex ()
**Description: This function takes the user input from main and send the user to their desired option
**Parameters: string dexname, string choice, int choicevalue, Pokedex &px, ofstream &fout
**Pre-Conditions: User selected a valid manage dex option, structs have been declared, file opened successfully
**Post-Conditions: Traines is sent to manage their dex based on their input 
****************************************************************************/
void manage_dex(string dexname, string choice, int choicevalue, Pokedex &px, ofstream &fout) {

		if (is_int(choice) == false || choicevalue > 5 || choicevalue < 1) //error handling for invalid inputs 
			cout << "\nInvalid Input! Remember to enter the corresponding number in brackets to select how you will manage your dex today!" << endl; 

		string_to_int(choice, choicevalue); //converts the choice into an integer
		search_by_dex(px, choice, choicevalue, fout); //function if user wishes to search the dex by dex#
		search_by_name(px, choice, choicevalue, fout); //fucntion if the user wishes to search the dex by name
		search_by_type(px, choice, choicevalue, fout); //funciton if the user wishes to search the dex by type 
		add_pokemon(dexname, px, choice, choicevalue); //function if the user wishes to add a pokemon to their existing dex 

}

/****************************************************************************
**Function: void search_by_dex ()
**Description: Searches the dex based off user input
**Parameters: Pokedex px, string choice, int choicevalue, ofstream &fout
**Pre-Conditions: User selects to search by dex 
**Post-Conditions: Prints dex to file or terminal, outputs error message if dex number does not exist
****************************************************************************/
void search_by_dex(Pokedex px, string choice, int choicevalue, ofstream &fout) {

	string_to_int(choice, choicevalue);	
	if (choicevalue == 1) { //runs if user wishes to search by dex

		int search = 0, print = 0, count = 0;
		cout << "\nWhat is the dex number of the pokemon you wish to search for?: ";
		cin >> search;

		for (int i = 0; i < px.num_pokemon; i++) { //checks if the user inputted a dex number within the pokedex array 
			if (px.dex[i].dex_num == search)
				count++;
		}
		
		if (count > 0) { //if there is a matching dex number to the other input
			cout << "\nWould you like your information to printed in the terminal or a .txt file? Enter '0' for terminal or '1' for .txt file: ";
			cin >> print;
			print_dex(print, search, px, fout); //calls print_dex function
		}

		else
			cout << "\nThe dex number you entered DOES NOT EXIST! Gotta catch em all! " << endl; //output error if dex# does not exist
	}
}

/****************************************************************************
**Function: void print_dex ()
**Description: This function prints the dex information to the terminal or file
**Parameters: int print, int search, Pokedex px, ofstream &f
**Pre-Conditions: Dex number exists in the .txt file
**Post-Conditions: Prints information to terminal or file
****************************************************************************/
void print_dex(int print, int search, Pokedex px, ofstream &f) {

	if (print == 0) { //print to terminal 
		for (int i = 0; i < px.num_pokemon; i++) {
			if (px.dex[i].dex_num == search) { //checks for a matching dex number in the dex
				cout << "\nDex Number: " << px.dex[i].dex_num << endl << "Pokemon: " << px.dex[i].name << endl << "Type: " << px.dex[i].type << endl << "Moves: ";
				for (int j = 0; j < px.dex[i].num_moves; j++) { //outputs moves 
					cout << px.dex[i].moves[j] << " ";
				}
				cout << endl; 
			}
		}
	}
	
	else if (print == 1) { //print to file
		search_by_dex_to_file(px, f, search); 
	}
}

/****************************************************************************
**Function: void search_by_dex_to_file ()
**Description: Prints dex information to an empty file 
**Parameters: Pokedex &px, ofstream &f, int search
**Pre-Conditions: User wishes to write their output to a blank file
**Post-Conditions: Desired dex information is outputted to the file
****************************************************************************/
void search_by_dex_to_file(Pokedex px, ofstream &f, int search) {

	open_new_file(f); //opens a new and empty file
	for (int i = 0; i < px.num_pokemon; i++) {
		if (px.dex[i].dex_num == search) { //outputs matching informaiton to the file 
			f << "\nDex Number: " << px.dex[i].dex_num << endl << "Pokemon: " << px.dex[i].name << endl << "Type: " << px.dex[i].type << endl << "Moves: ";
			for (int j = 0; j < px.dex[i].num_moves; j++) {
				f << px.dex[i].moves[j] << " ";
			}
			f << endl;
		}
	}
	f.close();
}


/****************************************************************************
**Function: void search_by_name ()
**Description: Searches the dex for a matching name input
**Parameters: Pokedex px, string choice, int choicevalue, ofstream &fout
**Pre-Conditions: User enters input to search their dex by the name of the pokemon
**Post-Conditions: Prints matching name input to terminal or file or outputs an error message if there are no mathces
****************************************************************************/
void search_by_name(Pokedex px, string choice, int choicevalue, ofstream &fout) {

	string_to_int(choice, choicevalue);
	if (choicevalue == 2) { //if the user's choice was the search by dex
		int print = 0, count = 0;
		string search; 

		cout << "\nWhat is the name of the pokemon you wish to search for?: ";
		getline(cin, search);

		for (int i = 0; i < px.num_pokemon; i++) {
			if (px.dex[i].name == search) //checks if there is a matching string input in the dex
				count++;
		}

		if (count > 0) { //prompts to print to file or terminal if there is a match
			cout << "\nWould you like your information to printed in the terminal or a .txt file? Enter '0' for terminal or '1' for .txt file: ";
			cin >> print;
			print_name(print, search, px, fout);
		}

		else //error message if there is not match
			cout << "\nThe name you entered DOES NOT EXIST in your pokedex! Gotta catch em all!" << endl; 
	}
}

/****************************************************************************
**Function: void print_name ()
**Description: Prints the dex information to the terminal or to a new file
**Parameters: int print, string search, Pokedex px, ofstream& f
**Pre-Conditions: Pokedex struct correctly stores dex information 
**Post-Conditions: Prints the information to the file or terminal  
****************************************************************************/
void print_name(int print, string search, Pokedex px, ofstream& f) {

	if (print == 0) { //print to terminal 
		for (int i = 0; i < px.num_pokemon; i++) {
			if (px.dex[i].name == search) { //prints the matching name info to the terminal
				cout << "\nDex Number: " << px.dex[i].dex_num << endl << "Pokemon: " << px.dex[i].name << endl << "Type: " << px.dex[i].type << endl << "Moves: ";
				for (int j = 0; j < px.dex[i].num_moves; j++) {
					cout << px.dex[i].moves[j] << " ";
				}
				cout << endl;
			}
		}
	}

	else if (print == 1) { //print to file
		
		open_new_file(f); //prompts user to open a new file
		for (int i = 0; i < px.num_pokemon; i++) {
			if (px.dex[i].name == search) { //prints the matching name info to the file
				f << "\nDex Number: " << px.dex[i].dex_num << endl << "Pokemon: " << px.dex[i].name << endl << "Type: " << px.dex[i].type << endl << "Moves: ";
				for (int j = 0; j < px.dex[i].num_moves; j++) {
					f << px.dex[i].moves[j] << " ";
				}
			}
		}
		f.close(); 
	}
}


/****************************************************************************
**Function: void search_by_type () 
**Description: This function searches the dex for a matching type
**Parameters: Pokedex px, string choice, int choicevalue, ofstream& fout
**Pre-Conditions: User wishes to search their dex by pokemon type 
**Post-Conditions: Information for all pokemon of same type are printed to the terminal or a file or an error message is printed if there are no matches
****************************************************************************/
void search_by_type(Pokedex px, string choice, int choicevalue, ofstream& fout) {

	string_to_int(choice, choicevalue);
	int print = 0, count = 0;
	string searcht;

	if (choicevalue == 3) { //if the user wishes to search by type
		cout << "\nWhat type is your pokemon? Be sure to capitalize the first letter of the desired type: ";
		getline(cin, searcht);

		for (int i = 0; i < px.num_pokemon; i++) { //adds to the count if a matching type string is found
			if (px.dex[i].type == searcht) 
				count++;
		}

		if (count > 0) { //prompts to output to the file or terminal if a match is found
			cout << "\nWould you like your information to printed in the terminal or a .txt file? Enter '0' for terminal or '1' for .txt file: ";
			cin >> print;
			print_search_by_type(print, searcht, px, fout);
		}

		else //error message if there is no match found
			cout << "\nThe type you entered DOES NOT EXIST in your pokedex! Gotta catch em all!" << endl;
	}
}

/****************************************************************************
**Function: void print_search_by_type ()
**Description: Function prints matching type input to the terminal or to a file
**Parameters: int print, string searcht, Pokedex px, ofstream &f 
**Pre-Conditions: .txt file information successfully stored in Pokedex struct 
**Post-Conditions: Prints matching type information to file or terminal
****************************************************************************/
void print_search_by_type(int print, string searcht, Pokedex px, ofstream &f) {
	
	if (print == 0) { //print to terminal 
		for (int i = 0; i < px.num_pokemon; i++) {
			if (px.dex[i].type == searcht) { //outputs matching string type informatio to the terminal
				cout << "\nDex Number: " << px.dex[i].dex_num << endl << "Pokemon: " << px.dex[i].name << endl << "Type: " << px.dex[i].type << endl << "Moves: ";
				for (int j = 0; j < px.dex[i].num_moves; j++) {
					cout << px.dex[i].moves[j] << " ";
				}
				cout << endl;
			}
		}
	}

	else if (print == 1) { //print to file
	
		open_new_file(f); //opens a new file based on user input
		for (int i = 0; i < px.num_pokemon; i++) { //outputs matching string type information to file
			if (px.dex[i].type == searcht) {
				f << "\nDex Number: " << px.dex[i].dex_num << endl << "Pokemon: " << px.dex[i].name << endl << "Type: " << px.dex[i].type << endl << "Moves: ";
				for (int j = 0; j < px.dex[i].num_moves; j++) {
					f << px.dex[i].moves[j] << " ";
				}
				f << endl;
			}
		}
		f.close();
	}
}

/****************************************************************************
**Function: void add_pokemon ()
**Description: Prompts and stores information of a new pokemon to the pokedex
**Parameters: string dexname, Pokedex &px, string choice, int choicevalue,
**Pre-Conditions: User wishes to add a pokemon to their dex 
**Post-Conditions: Outputs origional and added dex information to the file
****************************************************************************/
void add_pokemon (string dexname, Pokedex &px, string choice, int choicevalue) {
	
	string_to_int(choice, choicevalue);
	if (choicevalue == 4) { //if the user wishes to add a pokemon... 
		
		Pokemon add = { //initializes a pokemon struct used to store the new dex info
			1, //dex num
			"name", //name
			"type", //type
			2, //num moves
			NULL, //moves
		};

		ofstream fout;  
		fout.open(dexname.c_str(), ios::trunc); //truncate the existing .txt file
		
		fout << px.num_pokemon + 1 << endl; //adds one to the num of pokemon in the current file
		for (int i = 0; i < px.num_pokemon; i++) { //outputs the origional dex information to the current file
			fout << px.dex[i].dex_num << " " << px.dex[i].name << " " << px.dex[i].type << " " << px.dex[i].num_moves << endl;
			for (int j = 0; j < px.dex[i].num_moves; j++) { 
				fout << px.dex[i].moves[j] << " ";
			}
			fout << endl;
		}
		add_new_part2(add, fout); //function is called where user is prompted for additional pokemon information
		fout.close(); 
		delete_added_moves(add.moves); //frees memory allocated to new moves
		delete_info(px);

		ifstream fin; 
		fin.open(dexname.c_str(), ios::in); 
		populate_pokedex_data(px, fin); //populates current .txt with new pokemon
		fin.close();  //closes input stream to new file 
	}
}

/****************************************************************************
**Function: void add_new_part2 ()
**Description: User inputs the information of the pokemon they wish to add
**Parameters: Pokemon &add, ofstream &fout
**Pre-Conditions: Current .txt file in use is successfully truncated 
**Post-Conditions: Information is outputted to a user specified file
****************************************************************************/
void add_new_part2(Pokemon &add, ofstream &fout) {

	cout << "\nWhat dex number do you want to assign to your new pokemon?: ";
	cin >> add.dex_num; 
	cout << "\nWhat the name of your new pokemon?: ";
	cin >> add.name;
	cout << "\nWhat type is your new pokemon?: ";
	cin >> add.type;
	cout << "\nHow many moves does your new pokemon have?: ";
	cin >> add.num_moves;
	
	add.moves = create_moves(add.num_moves); //creates a 1-D array to store moves based on how many the user wishes to input

	for (int i = 0; i < add.num_moves; i++) { //prompts for moves
		cout << "\nEnter the name of move " << i + 1 << " using '_' as spaces for moves with more than one word: ";
		cin >> add.moves[i]; 
	}

	fout << add.dex_num << " " << add.name << " " << add.type << " " << add.num_moves << endl;
	for (int i = 0; i < add.num_moves; i++)
		fout << add.moves[i] << " "; //adds moves to the output file

	fout << endl;
	fout.close();
}

/****************************************************************************
**Function: void open_new_file ()
**Description: Opens an empty output file based on user input
**Parameters: ofstream &f
**Pre-Conditions: User wishes to open a file
**Post-Conditions: Opens output file based on the input name
****************************************************************************/
void open_new_file(ofstream &f) {
	string tempname;
	cout << "\nWhat is the name of the file you want to open?: ";
	cin >> tempname;
	f.open(tempname.c_str(), ios::out | ios::app); 
	if (!f.is_open()) {	//checks if the file is not successfully opened
		cout << "Error opening the file . . . " << endl;
	}

}

/****************************************************************************
**Function: void populate_pokedex_data ()
**Description: This function populates the pokedex using the arrays created to store the pokemon and their moves
**Parameters: Pokedex &px, ifstream &f
**Pre-Conditions: File opened and read from successfully
**Post-Conditions: Creates and populates information in the pokedex 
****************************************************************************/
void populate_pokedex_data(Pokedex &px, ifstream &f) {

	f >> px.num_pokemon; 
	px.dex = create_pokemons(px.num_pokemon);

	for (int i = 0; i < px.num_pokemon; i++) {
		populate_pokemon(px.dex[i], f);
	}
}

/****************************************************************************
**Function: Pokemon* create_pokemons
**Description: Creates an array of new pokemon based on the number of them in the file
**Parameters: int size
**Pre-Conditions: Number of pokemon is the dex is expressed an as integer 
**Post-Conditions: 1-D dynamic array is created to store the information of each pokemon
****************************************************************************/
Pokemon* create_pokemons(int size) { //array to create a new pokemon based on the px.num_pokemon that the user wished to int

	Pokemon* p_ptr = new Pokemon[size];
	return p_ptr;

}

/****************************************************************************
**Function: string* create_moves ()
**Description: Creates a dynamic array to store each pokemon's moves
**Parameters: int size
**Pre-Conditions: Number of moves is stored in an integer value
**Post-Conditions: 1-D dynamic array is created to store moves
****************************************************************************/
string* create_moves(int size) { //creating an array of moves for each pokemon
	
	string *s_ptr = new string[size];
	return s_ptr; 

}

/****************************************************************************
**Function: void populate_pokemon ()
**Description: Stores the information from the pokedex into an input fire
**Parameters: Pokemon &pm, ifstream &fin
**Pre-Conditions: .txt file opened successfully
**Post-Conditions: Stores the information into the Pokededx struct
****************************************************************************/
void populate_pokemon(Pokemon& pm, ifstream& fin) {

	fin >> pm.dex_num >> pm.name >> pm.type >> pm.num_moves; //stores the information from the.txt file
	pm.moves = create_moves(pm.num_moves); //creates moves based on the number of moves each pokemon has

	for (int j = 0; j < pm.num_moves; j++) { //stores moves 
		fin >> pm.moves[j];
	}
}

/****************************************************************************
**Function: void delete_added_moves ()
**Description: Frees the memory allocated to the new moves of the added pokemon
**Parameters: string* moves
**Pre-Conditions: Moves have been created for the added pokemon
**Post-Conditions: Frees the memory to prevent memory leaks
****************************************************************************/
void delete_added_moves(string* moves) {

		delete [] moves; //deletes the moves
		moves = NULL; //sets the moves equal to null 

}

/****************************************************************************
**Function: void delete_info ()
**Description: Frees the memory allocated to the pokedex array
**Parameters: Pokedex &px
**Pre-Conditions: Pokedex information is stored in a dynamic array
**Post-Conditions: Deletes the memory allocated to the array
****************************************************************************/
void delete_info (Pokedex& px) { //free memory allocated to the pokedex

	for (int i = 0; i < px.num_pokemon; i++) {
		delete[] px.dex[i].moves; //deletes contents in array
		px.dex[i].moves = NULL;  //sets contents to null
	}

	delete [] px.dex;
	px.dex = NULL; 

}
