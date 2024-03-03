#include "Books.h" // Including the header file for the Books class
#include <stdexcept> // Include <stdexcept> for runtime_error
#include <iostream> // Include <iostream> for cout
#include <fstream> // Include <fstream> for file operations
#include <iomanip> // Include <iomanip> for setw
#include <string> // Include <string> for string manipulation
using namespace std; // Using the standard namespace

// Constructor
Books::Books() { // Definition of the default constructor for the Books class
    // Initialize your members here
    Btitile = " "; // Initializing Btitile member variable with an empty string
    Bauthor = " "; // Initializing Bauthor member variable with an empty string
    ISBN = 0; // Initializing ISBN member variable with 0
    genre = " "; // Initializing genre member variable with an empty string
    publication_year = 0; // Initializing publication_year member variable with 0
    no_of_pages = 0; // Initializing no_of_pages member variable with 0
    price = new float[2]; // Allocate memory for the price array dynamically
    price[0] = 0; // Set old price to the provided value
    price[1] = 0; // Set new price to the provided value
}

// Parameterized Constructor
Books::Books(string title, string author, long int isbn, string book_genre, int pub_year, int pages, float oldprice, float newprice) {
    // Initialize your members with the provided parameters
    Btitile = title; // Assigning title parameter to Btitile member variable
    Bauthor = author; // Assigning author parameter to Bauthor member variable
    ISBN = isbn; // Assigning isbn parameter to ISBN member variable
    genre = book_genre; // Assigning book_genre parameter to genre member variable
    publication_year = pub_year; // Assigning pub_year parameter to publication_year member variable
    no_of_pages = pages; // Assigning pages parameter to no_of_pages member variable
    price = new float[2]; // Allocate memory for the price array dynamically
    price[0] = oldprice; // Set old price to the provided value
    price[1] = newprice; // Set new price to the provided value
}

// Destructor
Books::~Books() { // Definition of the destructor for the Books class
    // Deallocate memory for the price array
    delete[] price; // Deallocate the dynamically allocated memory for the price array
}

// Copy Constructor
Books::Books(const Books& obj) { // Definition of the copy constructor for the Books class
    // Copying values from the provided object to the current object
    this->Btitile = obj.Btitile; // Copying Btitile member variable
    this->Bauthor = obj.Bauthor; // Copying Bauthor member variable
    this->ISBN = obj.ISBN; // Copying ISBN member variable
    this->genre = obj.genre; // Copying genre member variable
    this->publication_year = obj.publication_year; // Copying publication_year member variable
    this->no_of_pages = obj.no_of_pages; // Copying no_of_pages member variable
    price = new float[2]; // Allocate memory for the price array dynamically
    this->price[0] = obj.price[0]; // Copying old price
    this->price[1] = obj.price[1]; // Copying new price
}

// Setter functions
void Books::settitle(string title) { // Definition of the setter function for title
    Btitile = title; // Setting the value of Btitile member variable
}

void Books::setauthor(string author) { // Definition of the setter function for author
    Bauthor = author; // Setting the value of Bauthor member variable
}

void Books::setisbn(long int isbn) { // Definition of the setter function for isbn
    ISBN = isbn; // Setting the value of ISBN member variable
}

void Books::setgenre(string book_genre) { // Definition of the setter function for genre
    genre = book_genre; // Setting the value of genre member variable
}

void Books::setpubyear(int year) { // Definition of the setter function for publication year
    publication_year = year; // Setting the value of publication_year member variable
}

void Books::setpages(int pages) { // Definition of the setter function for number of pages
    no_of_pages = pages; // Setting the value of no_of_pages member variable
}

void Books::setPrices(float oldprice, float newprice) { // Definition of the setter function for prices
    price[0] = oldprice; // Setting the value of old price
    price[1] = newprice; // Setting the value of new price
}

// Getter functions
string Books::gettitle() { // Definition of the getter function for title
    return Btitile; // Returning the value of Btitile member variable
}

string Books::getauthor() { // Definition of the getter function for author
    return Bauthor; // Returning the value of Bauthor member variable
}

long int Books::getisbn() { // Definition of the getter function for isbn
    return ISBN; // Returning the value of ISBN member variable
}

string Books::getgenre() { // Definition of the getter function for genre
    return genre; // Returning the value of genre member variable
}

int Books::getpubyear() { // Definition of the getter function for publication year
    return publication_year; // Returning the value of publication_year member variable
}

int Books::getpages() { // Definition of the getter function for number of pages
    return no_of_pages; // Returning the value of no_of_pages member variable
}

float Books::getOldPrice() { // Definition of the getter function for old price
    return price[0]; // Returning the value of old price
}

float Books::getNewPrice() { // Definition of the getter function for new price
    return price[1]; // Returning the value of new price
}

// Function to convert object to string
string Books::tostring() { // Definition of the function to convert object to string and checking state of the object
    return "Title: " + Btitile + "\nAuthor: " + Bauthor + "\nISBN: " + to_string(ISBN) + "\nGenre: " + genre + "\nPublication Year: " + to_string(publication_year) + "\nNo. of Pages: " + to_string(no_of_pages) + "\nOld Price: $" + to_string(price[0]) + "\nNew Price: $" + to_string(price[1]); // Returning the string representation of the object
}

// Function to write object details to a file
void Books::writetofile() { // Definition of the function to write object details to a file
    ofstream fout; // Declare an ofstream object
    fout.open("BOOKS_LIST.txt", ios::app); // Open the file for writing in append mode
    fout << Btitile << setw(12) << Bauthor << setw(12) << ISBN << setw(12) << genre << setw(12) << publication_year << setw(12) << no_of_pages << setw(12) << price[0] << setw(12) << price[1] << endl; // Write product details to the file
    fout.close(); // Close the file
}

// Function to view all records
string Books::viewallrecords() { // Definition of the function to view all records
    ifstream fin("BOOKS_LIST.txt"); // Declare an ifstream object and open the file for reading
    try {
        if (!fin.is_open()) { // Check if the file is open
            throw runtime_error("Error: Unable to open the file for reading.");// Throw an exception if unable to open the file
            return;
        }
    }
    catch (const runtime_error& e) { // Catch runtime errors
        cout << "Error: " << e.what() << endl; // Display error message
    }

    string result; // Declare a string variable to store the result

    while (fin >> Btitile >> Bauthor >> ISBN >> genre >> publication_year >> no_of_pages >> price[0] >> price[1]) { // Read records from the file
        result += "Title: " + Btitile + ", Author: " + Bauthor + ", ISBN: " + to_string(ISBN) + ", Genre: " + genre + ", Publication Year: " + to_string(publication_year) + ", Pages: " + to_string(no_of_pages) + ", Old Price: " + to_string(price[0]) + ", New Price: " + to_string(price[1]) + "\n"; // Append record details to the result string
    }

    fin.close(); // Close the file
    return result; // Return the result string
}

// Function to count the number of books in the file
int Books::countBooks() { // Definition of the function to count the number of books in the file
    ifstream fin("BOOKS_LIST.txt"); // Declare an ifstream object and open the file for reading
    try {
        if (!fin.is_open()) { // Check if the file is open
            throw runtime_error("Error: Unable to open the file for reading.");// Throw an exception if unable to open the file
            return;
        }
    }
    catch (const runtime_error& e) { // Catch runtime errors
        cout << "Error: " << e.what() << endl; // Display error message
    }
    int count = 0; // Initialize count to 0

    string line; // Declare a string variable to store each line of the file
    while (getline(fin, line)) { // Read each line from the file
        count++; // Increment count for each line (each book)
    }

    fin.close(); // Close the file
    return count; // Return the total count of books
}
