# Pokedex - Pokemon Encyclopedia

**PROBLEM STATEMENT:**

Program a Pokdex that will help Pokemon trainers collect new Pokemon data and sort through it easier. This information is read from a text file containing currently discovered Pokemon, their moves, and their type.

**REQUIREMENTS:**

1. Initial User Input

When starting the program, the user will be prompted to enter the name of the file that contains the information about Pokemon. The program will output an error message and quit if the user enters an invalid file. 

2. Searching and Printing:

The user will then be prompted with a list of different ways to display 
Pokedex information. The user will then be asked if they want to print their information to the terminal or to a text file. 
If they choose to write to a text file, they should be prompted for a file name. 
If the file name exists, the information will be appended to the existing file.
If the file name does not exist, a new text file will be created with the new information.

3. Available Options:

• Search by dex number:

    Program searches through the available Pokemon for one that a specified number (via user input).
    If there is a matching Pokemon, all that Pokemon's data will be printed to the terminal or written to a text file. 
    If there is no matching Pokemon, an error message will be printed and the options will be displayed again.

• Search by name:

    Program searches through the available Pokemon for one that matches a user entered name. 
    If there is a matching Pokemon, all that Pokemon's data will be printed to the terminal or written to a text file. 
    If there is no matching Pokemon, an error message will be printed and the options will be displayed again.

• Search by type:

    Program searches for all avaible Pokemon that match a user entered type. 
    If there is a matching Pokemon, all of each applicable Pokemon's data will be printed to the terminal or written to a text file. 
    If there is no matching Pokemon, an error message will be printed and the options will be displayed again.

• Add new Pokemon:

    Program asks the user to enter a dex number, name, type, and move(s) for a new Pokemon. 
    To store the new data, the size of the Pokedex will need to dynamically increase. 
    Assume the user will not add a repeated pokemon or dex number. 
    Assume there is no need to sort the .txt file to display the pokemon in ascending dex number order. 

• Quit: The user exists the program.

4. The program should continue searching and printing/writing until the user chooses to quit.

**INPUT FILE FORMAT:**

The dex.txt file will have the following pattern:

{total number of Pokemon in file}  
{dex number of first Pokemon} {name} {type} {number of moves}  
{name of move 1} {name of move 2} {…}    
{dex number of second Pokemon}, {name}, {type}, {number of moves}  
{name of move 1} {name of move 2} {…}    
{dex number of third Pokemon} {name} {type} {number of moves}  
{name of move 1} {name of move 2} {…}    

**FILE SEPARATION:**

Modularize the code into a header file (.h), an implementation file (.cpp), and a
driver file (.cpp).
 
1. pokemon.h: This header file contains all struct declarations and function prototypes

2. pokemon.cpp: This implementation file contains all function definitions

3. run_pokemon.cpp: This driver file contains the main function

4. A Makefile is required
