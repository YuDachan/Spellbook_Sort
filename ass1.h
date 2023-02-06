/********************************************************************* 
** Program Filename: Assignment 1
** Author: Dachan Yu
** Date: 4/9/2021
** Description: sorts a spellbook catalogue by page #/avg spell success rate/ spell type
** Input: spellbook catalogue and various user decisions
** Output: displays sorted catalogue and prints displayed catalogue if needed
*********************************************************************/

#ifndef ASS1
#define ASS1
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

struct spellbook {
	string title;
	string author;
	int num_pages;
	int edition;
	int num_spells;
	float avg_success_rate;
	struct spell* s;
};

struct spell {
	string name;
	float success_rate;
	string effect;
};

/*********************************************************************
** Function: create_spellbooks
** Description: creates the struct for the spellbook
** Parameters: integer num
** Pre-Conditions: a struct must be assigned
** Post-Conditions: creates a struct array 
*********************************************************************/
spellbook* create_spellbooks(int num);

/********************************************************************* 
** Function: creates_spell
** Description: creates a struct array within a struct array
** Parameters: integer num
** Pre-Conditions: spellbooks array must be initialized, number of spells
*  per book must be obtained from txt
** Post-Conditions: a second struct array is created within the spellbooks array
*********************************************************************/
spell* create_spell(int num);

/*********************************************************************
** Function: book info
** Description: obtains book information from .txt file
** Parameters: spellbook array, istream file, number of books, lines to skip
** Pre-Conditions: spellbook array must be created with the neccessary amount of memory
*  and the text file must follow a format
** Post-Conditions: all information from text file is inputed into the program
*********************************************************************/
void bookinfo(spellbook*& catalogue, ifstream& cat, int num, int skip);

/*********************************************************************
** Function: get_spell_book_data
** Description: follows order of necessary steps to obtain txt data
** Parameters: spellbook array must be initialized, num of books, text file
** Pre-Conditions: spellbook must initialized, text file must be opened
** Post-Conditions: all information from text file in inputed into program
*********************************************************************/
void get_spellbook_data(spellbook*& catalogue, int num, ifstream& cat);

/*********************************************************************
** Function: spellinfo
** Description: obtains spell information from text file
** Parameters: spellbook array, number of books, text file
** Pre-Conditions: array must be initialized, text file must be open
** Post-Conditions: all spell information is inputed into program
*********************************************************************/
void spellinfo(spellbook*& catalogue, ifstream& cat, int num);

/*********************************************************************
** Function: avg
** Description: calculates average spell success rate per book
** Parameters: spellbook array, number of books
** Pre-Conditions: array must have all necessary information
** Post-Conditions: an average success rate of all books is established
*********************************************************************/
void avg(spellbook*& catalogue, int num);

/*********************************************************************
** Function: get_spell_data
** Description: reads spell info in txt and inputs it into the program
** Parameters: spellbook array, num of books, text file
** Pre-Conditions: spellbook array must be established, text file is opened
** Post-Conditions: spellbook array has all spell info
*********************************************************************/
void get_spell_data(spellbook*& catalogue, int num, ifstream& cat);

/*********************************************************************
** Function: write
** Description: writes sorted items into output file
** Parameters: spellbook array with all necessary data, number of books
** Pre-Conditions: spellbook array must have all information
** Post-Conditions: a text file will have the sorted out info
*********************************************************************/
void write(spellbook* catalogue, int num);

/*********************************************************************
** Function: is_digit
** Description: check if inputs are digits
** Parameters: string
** Pre-Conditions: none
** Post-Conditions: ouputs true or false if string has a digit or not
*********************************************************************/
bool is_digit(string str);

/*********************************************************************
** Function: ask
** Description: ask user if they want to print into text file
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: output text file is written
*********************************************************************/
int ask();

/*********************************************************************
** Function: print
** Description: print sorted data on terminal
** Parameters: spellbook array, number of books
** Pre-Conditions: spellbook must have all necessary info
** Post-Conditions: prints information on terminal
*********************************************************************/
void print(spellbook*& catalogue, int num);

/*********************************************************************
** Function: swap
** Description: switches information within the struct array
** Parameters: spellbook array, number of books
** Pre-Conditions: none
** Post-Conditions: information in the array is swapped
*********************************************************************/
void swap(spellbook*& catalogue, int num);

/*********************************************************************
** Function: pgsort
** Description: sorts books by page number
** Parameters: spellbook array, number of pages
** Pre-Conditions: spellbook must have all information
** Post-Conditions: information is sorted by page number
*********************************************************************/
void pgsort(spellbook*& catalogue, int num);

/*********************************************************************
** Function: avgsort
** Description: sorts books by average success rate
** Parameters: spellbook array, number of books
** Pre-Conditions: average success rate of spellbooks are established
** Post-Conditions: lists in order of spellbook's average success rate
*********************************************************************/
void avgsort(spellbook*& catalogue, int num);

/*********************************************************************
** Function: print2
** Description: displays spells by spell effect
** Parameters: spellbook array, book number, spell number
** Pre-Conditions: spellbook array must have necessary information
** Post-Conditions: spells are displayed on terminal
*********************************************************************/
void print2(spellbook* catalogue, int i, int j);

/*********************************************************************
** Function: write2
** Description: writes spells by spell effect in text file
** Parameters: spellbook array, book number, spell number
** Pre-Conditions: spellbook array has all information
** Post-Conditions: data is written in output file
*********************************************************************/
void write2(spellbook* catalogue, int i, int j);

/*********************************************************************
** Function: spellsort
** Description: sorts spells by effect to display on terminal
** Parameters: spellbook array, number of books
** Pre-Conditions: spellbook array must have all information
** Post-Conditions: sorts the spells by their spell effect
*********************************************************************/
void spellsort(spellbook* catalogue, int num);

/*********************************************************************
** Function: spellsort2
** Description: sorts spells by effect to write into text file
** Parameters: spelbbok array, number of books
** Pre-Conditions: spellbook array must be complete
** Post-Conditions: spells are sorted to print
*********************************************************************/
void spellsort2(spellbook* catalogue, int num);

/*********************************************************************
** Function: inputs
** Description: asks user how they would like the books to be sorted
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: outputs a number 
*********************************************************************/
int inputs();

/*********************************************************************
** Function: clear
** Description: deletes dynamic arrays
** Parameters: spellbook array, command line arguments, number of books
** Pre-Conditions: none
** Post-Conditions: deletes all memory used
*********************************************************************/
void clear(spellbook*& catalogue, char**& argv, int num);

/*********************************************************************
** Function: sort
** Description: reads users commands and begins the algorithm to sort
** Parameters: spellbook array, number of books, user input number
** Pre-Conditions: valid user input is established, array is completed
** Post-Conditions: does what the user asks 
*********************************************************************/
void sort(spellbook*& catalogue, int num, int in);

/*********************************************************************
** Function: arg
** Description: reads command line argument to see if it's valid or not
** Parameters: command line argument vector, # of command line arguments
*  spellbook array
** Pre-Conditions: none
** Post-Conditions: takes necessary steps to address poor inputs
*********************************************************************/
void arg(spellbook*& catalogue, char**& argv, int argc, int num);

#endif