# Pokedex - Pokemon Encyclopedia

**PROBLEM STATEMENT:**

Professor Oak has been discovering more new Pokemon than he knows what to do with lately. Create a Pokemon catalog program that will make gathering new Pokemon data and
searching through it easier.

To simplify the task, the Professor has provided their current Pokemon information. These
come in the form of a text file that contains a list of the currently discovered Pokemon and their moves,
all of the information that the program will display.

**GOALS:**

• Practice good software engineering design principles:
    o Design the solution before writing the program
    o Develop test cases before writing the program

• Review pointers, arrays, and structs
• Use file I/O to read from and write to files
• Practice file separation and create Makefile
• Use functions to modularize code to increase readability and reduce repeated code

**REQUIREMENTS:**

1. Initial User Input

When starting the program, the user will be prompted for one input. The input will be the name of the file
that contains the information about Pokemon. If the user does not provide the name of an existing file,
the program should print out an error message and quit.

2. Searching and Printing:

Once the program begins, the user should be prompted with a list of different ways to display the
Pokedex information. After the user has chosen an option, they should be asked if they want the
information printed to the screen or written to a file. If they choose to write to a file, they should be
prompted for a file name. If the file name already exists, the information should be appended to the file.
If the file name does not exist, a file should be created and the information should be written to the file.

3. Available Options:

• Search by dex number:

    If the user picks this option, the program must search through the available Pokemon for one that
    matches a user entered number. Once found, it should print/write to file that Pokemon's data. If there
    is no matching Pokemon, the program must print an error message and give them all of the options
    again.

• Search by name:

    If the user picks this option, the program must search through the available Pokemon for one that
    matches a user entered name. Once found, it should print/write to file that Pokemon's data. If there is
    no matching Pokemon, the program must print an error message and give them all of the options
    again.

• Search by type:

    If the user picks this option, the program must search through the available Pokemon for ones that
    match a user entered type. Once found, it should print/write to file all of the Pokemon that have that
    type. If there is no Pokemon with the requested type, the program must print an error message and
    give them all of the options again.

• Add new Pokemon:

    If the user picks this option, the program must prompt the user to enter each of the fields for a new Pokemon. 
    The size of the Pokedex will need to dynamically increase to store the new data. 
    Assume the user will not add a repeated pokemon or dex number. 
    Assume there is no need to sort the .txt file to display the pokemon in ascending dex number order. 
    *Hint: Think of rewriting the whole file instead of appending the new Pokemon to the end.

• Quit: The program will exit.

4. The program should continue searching and printing/writing until the user chooses to quit.

**REQUIRED STRUCTS:**

The following structs are required in the program. They will help organize the information that will be
read in (or derived) from the files. Do not modify, add, or take away any part of the class.

1. The Pokedex struct will be used to hold information from the dex.txt file. This struct holds information about the Pokedex.  
 
   struct Pokedex {    
        string trainer;  
        int num_pokemon;  
        Pokemon* dex;  
    };

2. The Pokemon struct will also be used to read in information from the dex.txt file. This struct holds information about a Pokemon.
 
   struct Pokemon {  
         int dex_num;  
         string name;  
         string type;  
         int num_moves;  
         string* moves;  
    };

**REQUIRED FUNCTIONS:**

Implement the following functions in the program. Do not modify these required function declarations in any way. Note: it is acceptable to choose to add additional functions (but the program must still include the required functions).

1. This function will dynamically allocate an array of Pokemons (of the requested size):

&nbsp;&nbsp;&nbsp;&nbsp; Pokemon* create_pokemons(int);

2. This function will fill a Pokedex object with information that is read in from dex.txt. Hint: “ifstream &” is a reference to a filestream object. Create one and pass it into this function to read from the dex.txt file.

&nbsp;&nbsp;&nbsp;&nbsp; void populate_pokedex_data(Pokedex & , ifstream &);

3. This function will dynamically allocate an array of moves of a Pokemon (of the requested size):

&nbsp;&nbsp;&nbsp;&nbsp; string* create_moves(int);

4. This function will fill a single Pokemon object with information that is read in from dex.txt.

&nbsp;&nbsp;&nbsp;&nbsp; void populate_pokemon(Pokemon &, ifstream &);

5. Implement a function that will delete all the memory that was dynamically allocated.

&nbsp;&nbsp;&nbsp;&nbsp; void delete_info(Pokedex &);

**REQUIRED INPUT FILE FORMAT:**

The dex.txt file will have the following pattern:

{total number of Pokemon in file}  
{dex number of first Pokemon} {name} {type} {number of moves}  
{name of move 1} {name of move 2} {…}    
{dex number of second Pokemon}, {name}, {type}, {number of moves}  
{name of move 1} {name of move 2} {…}    
{dex number of third Pokemon} {name} {type} {number of moves}  
{name of move 1} {name of move 2} {…}    

**REQUIRED FILES:**

Modularize the code into a header file (.h), an implementation file (.cpp), and a
driver file (.cpp).
 
1. pokemon.h: This header file contains all struct declarations and function prototypes

2. pokemon.cpp: This implementation file contains all function definitions

3. run_pokemon.cpp: This driver file contains the main function

4. A Makefile is required
