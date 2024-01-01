/*
       Name: James Ignacio
      Class: Data Structures
 */


#include <iostream>
#include "BookList.h"
#include <string>
using namespace std;

int main()
{
    BookList booklist;
    int choice = 0;

    string title, author;
    int isbn;
    
    while (choice != 5)
    {
        cout << "Choose a command (by number):" << endl;
        cout << "1. Display" << endl;
        cout << "2. Add" << endl;
        cout << "3. Search" << endl;
        cout << "4. Delete" << endl;
        cout << "5. Quit" << endl;
        
        cin >> choice;
        
        cout << endl << endl;
        
        if (choice == 1)
        {
            cout << "Displaying all books:" << endl;
            booklist.PrintList();
            cout << endl;
        }
        else if (choice == 2)
        {
            cout << "Adding a new book:" << endl;
            
            cout << "Enter book title: ";
            cin.ignore();
            getline(cin, title);
            
            cout << "Enter author's name: ";
            getline(cin, author);
            
            cout << "Enter unique ISBN: ";
            cin >> isbn;
            
            
            if (booklist.SearchBook(isbn))
            {
                cout << "Error: Book with the same ISBN already exists.\n" << endl;
            }
            else
            {
                booklist.PutItem(title, author, isbn);
                cout << "Book added successfully.\n" << endl;
            }
        }
        else if (choice == 3)
        {
            cout << "Searching for a book by ISBN:" << endl;
            cout << "Enter ISBN to search: ";
            cin >> isbn;
            if (booklist.SearchBook(isbn))
            {
                cout << "Book with ISBN " << isbn << " is in the list.\n" << endl;
            }
            else
            {
                cout << "Book with ISBN " << isbn << " is not in the list.\n" << endl;
            }
        }
        else if(choice == 4)
        {
            cout << "Deleting a book by ISBN:" << endl;
            cout << "Enter ISBN to delete: ";
            cin >> isbn;
            if (booklist.SearchBook(isbn))
            {
                booklist.DeleteItem(isbn);
                cout << "Book with ISBN " << isbn << " deleted successfully.\n" << endl;
            }
            else
            {
                cout << "Book with ISBN " << isbn << " not found in the list.\n" << endl;
            }
        }
        else if (choice == 5)
        {
            cout << "Quitting the program.\n" << endl;
            return 0;
        }
        else
        {
            cout << "Invalid choice. Please choose a valid command.\n" << endl;
        }
    }
    return 0;
}
