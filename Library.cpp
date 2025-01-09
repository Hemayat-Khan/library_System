#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// Structure to store book details
struct Book {
    int bookID;
    string title;
    string author;
    int quantity;
};
arif 
arif
// Function prototypes
void loadBooks(vector<Book>& books);
void saveBooks(const vector<Book>& books);
void addBook(vector<Book>& books);
void searchBook(const vector<Book>& books);
void displayBooks(const vector<Book>& books);

int main() {
    vector<Book> books;

    // Load books from file
    loadBooks(books);

    int choice;
    do {
        cout << "\nLibrary Management System\n";
        cout << "1. Add a new book\n";
        cout << "2. Search for a book\n";
        cout << "3. Display all books\n";
        cout << "4. Save and Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addBook(books);
                break;
            case 2:
                searchBook(books);
                break;
            case 3:
                displayBooks(books);
                break;
            case 4:
                saveBooks(books);
                cout << "Data saved successfully. Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}

// Function to load books from file
void loadBooks(vector<Book>& books) {
    ifstream file("library_data.txt");
    if (file.is_open()) {
        Book book;
        while (file >> book.bookID) {
            file.ignore(); // Ignore newline
            getline(file, book.title);
            getline(file, book.author);
            file >> book.quantity;
            books.push_back(book);
        }
        file.close(
            arifullah
            asim
    } else {
        cout << "No previous data found. Starting fresh...\n";
    }
}

// Function to save books to file
void saveBooks(const vector<Book>& books) {
    ofstream file("library_data.txt");
    for (const auto& book : books) {
        file << book.bookID << "\n";
        file << book.title << "\n";
        file << book.author << "\n";
        file << book.quantity << "\n";
    }
    file.close();
}

// Function to add a new book
void addBook(vector<Book>& books) {
    Book book;
    cout << "Enter Book ID: ";
    cin >> book.bookID;
    cin.ignore(); // Ignore leftover newline
    cout << "Enter Title: ";
    getline(cin, book.title);
    cout << "Enter Author: ";
    getline(cin, book.author);
    cout << "Enter Quantity: ";
    cin >> book.quantity;
    books.push_back(book);
    cout << "Book added successfully.\n";
}

// Function to search for a book//kone ghat harame ye//
//defyttfuuuvvuuuvuvu
///vjhvhbbjjhbkbkkbbkkz
void searchBook(const vector<Book>& books) {
    int searchID;
    string searchTitle;
    cout << "Search by:\n1. Book ID\n2. Title\nEnter your choice: ";
    int choice;
    cin >> choice;
    cin.ignore(); // Ignore leftover newline
    bool found = false;

    if (choice == 1) {
        cout << "Enter Book ID: ";
        cin >> searchID;
        for (const auto& book : books) {
            if (book.bookID == searchID) {
                cout << "Book Found:\n";
                cout << "ID: " << book.bookID << "\nTitle: " << book.title << "\nAuthor: " << book.author << "\nQuantity: " << book.quantity << "\n";
                found = true;
                break;
            }
        }
    } else if (choice == 2) {
        cout << "Enter Title: ";
        getline(cin, searchTitle);
        for (const auto& book : books) {
            if (book.title == searchTitle) {
                cout << "Book Found:\n";
                cout << "ID: " << book.bookID << "\nTitle: " << book.title << "\nAuthor: " << book.author << "\nQuantity: " << book.quantity << "\n";
                found = true;
                break;
            }
        }
    } else {
        cout << "Invalid choice.\n";
    }

    if (!found) {
        cout << "Book not found.\n";
    }
}

// Function to display all books
///Chup haramy 
//hhbjhbjhvjhvjh
void displayBooks(const vector<Book>& books) {
    if (books.empty()) {
        cout << "No books available.\n";
    } else {
        cout << "Available Books:\n";
        for (const auto& book : books) {
            cout << "ID: " << book.bookID << "\nTitle: " << book.title << "\nAuthor: " << book.author << "\nQuantity: " << book.quantity << "\n";
            cout << "--------------------\n";
        }
    }
}
