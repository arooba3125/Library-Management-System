#include <iostream> // Include the iostream library for input/output operations
#include "Books.h" // Include the header file for the Books class

using namespace std; // Use the std namespace

int main() { // Main function definition

    // Declare variables to store user input
    string name;
    int id;
    float oldprice, newprice;

    Books book; // Create a Books object

    // Prompt user to enter details for a book
    cout << "Enter details for a book :" << endl;

    // Input title of the book
    cout << "Enter title of the book: ";
    cin >> name;

    // Input author of the book
    cout << "Enter author of the book: ";
    string author;
    cin >> author;

    // Input ISBN of the book
    cout << "Enter ISBN of the book: ";
    cin >> id;

    // Input genre of the book
    cout << "Enter genre of the book: ";
    string genre;
    cin >> genre;

    // Input publication year of the book
    cout << "Enter publication year of the book: ";
    int publicationYear;
    cin >> publicationYear;

    // Input number of pages in the book
    cout << "Enter number of pages in the book: ";
    int pages;
    cin >> pages;

    // Input old price of the book
    cout << "Enter old price of the book: ";
    cin >> oldprice;

    // Input new price of the book
    cout << "Enter new price of the book: ";
    cin >> newprice;

    // Set book details using setter functions
    book.settitle(name);
    book.setauthor(author);
    book.setisbn(id);
    book.setgenre(genre);
    book.setpubyear(publicationYear);
    book.setpages(pages);
    book.setPrices(oldprice, newprice);
    book.writetofile(); // Write book details to file

    // Display the list of books
    cout << "Book 1 data :\n" << book.tostring() << endl;
    cout << endl;
    cout << "Checking copy constructor working " << endl;
    // Apply the concept of a copy constructor
    Books book1("Example Book", "Example Author", 1234567890, "Example Genre", 2020, 300, 20.99, 25.99);
    Books book2 = book1;  
    cout << "Value before changing:\n";
    cout << book1.tostring() << endl;
    cout << endl;
    cout << book2.tostring() << endl;
    cout << endl;

    book1.setPrices(30.99, 35.99);

    // Display the values after changing
    cout << "Value after changing:\n";
    cout << book1.tostring() << endl;
    cout << endl;
    cout << book2.tostring() << endl;
    cout << endl;

    // Count the number of records in the file
    int recordCount = book.countBooks();
    cout << "Number of records in the file: " << recordCount << endl;
    cout << endl;

    // View all records in the file
    cout << " ********************************* " << endl;
    cout << "VIEWING ALL RECORDS" << endl;
        string allRecords = book.viewallrecords();
        cout << "All Records:\n" << allRecords << endl;
   
    return 0; // Return 0 to indicate successful completion of the program
}
