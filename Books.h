#pragma once // Preprocessor directive to ensure that the header file is included only once during compilation

#ifndef BOOKS_H // Preprocessor directive to check if BOOKS_H macro is not defined
#define BOOKS_H // Define BOOKS_H macro to prevent multiple inclusion of the header file

#include<iostream> // Include the iostream library for input/output operations
using namespace std; // Use the std namespace

class Books { // Declaration of the Books class
	string Btitile;         // Title of the book
	string Bauthor;         // Author of the book
	long int ISBN;          // ISBN of the book
	string genre;           // Genre of the book
	int publication_year;   // Publication year of the book
	int no_of_pages;        // Number of pages in the book
	float* price;           // Pointer to store old and new prices

public:
	// Default constructor
	Books(); // Declaration of the default constructor

	// Parameterized constructor
	Books(string, string, long int, string, int, int, float, float); // Declaration of the parameterized constructor

	// Destructor
	~Books(); // Declaration of the destructor

	// Copy constructor
	Books(const Books& obj); // Declaration of the copy constructor

	// Setter functions
	void settitle(string);       // Set title of the book
	void setauthor(string);      // Set author of the book
	void setisbn(long int);      // Set ISBN of the book
	void setgenre(string);       // Set genre of the book
	void setpubyear(int);        // Set publication year of the book
	void setpages(int);          // Set number of pages in the book
	void setPrices(float, float);// Set prices of the book

	// Getter functions
	string gettitle();           // Get title of the book
	string getauthor();          // Get author of the book
	long int getisbn();          // Get ISBN of the book
	string getgenre();           // Get genre of the book
	int getpubyear();            // Get publication year of the book
	int getpages();              // Get number of pages in the book
	float getOldPrice();         // Get old price of the book
	float getNewPrice();         // Get new price of the book

	// Convert object state to string
	string tostring(); // Declaration of the tostring function

	// Write book details to file
	void writetofile(); // Declaration of the writetofile function

	// View all records
	string viewallrecords(); // Declaration of the viewallrecords function

	// Counting the number of books
	int countBooks(); // Declaration of the countBooks function
};

#endif // End of the preprocessor directive for BOOKS_H
