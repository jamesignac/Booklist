//
//  BookList.cpp
//  Lab2Problem2.cpp
//
//  Created by James Ignacio on 10/2/23.
//

#include "BookList.h"

// Constructor
BookList::BookList() : head(nullptr) 
{
    
}

// Destructor
BookList::~BookList() 
{
    EmptyList();
}

// Function to check if the list is empty
bool BookList::IsEmpty()
{
    return head == nullptr;
}

// Function to add a new book to the list
void BookList::PutItem(const string& title, const string& author, int isbn)
{
    BookNode* newNode = new BookNode(title, author, isbn);
    if (IsEmpty()) 
    {
        head = newNode;
    } 
    else
    {
        BookNode* current = head;
        while (current->next != nullptr) 
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to delete a book by ISBN
void BookList::DeleteItem(int isbn) 
{
    if (IsEmpty()) {
        return; // List is empty, nothing to delete
    }

    if (head->isbn == isbn) {
        BookNode* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    BookNode* current = head;
    while (current->next != nullptr && current->next->isbn != isbn) {
        current = current->next;
    }

    if (current->next != nullptr) {
        BookNode* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }
}

// Function to check if the list is full (assuming no memory limits)
bool BookList::IsFull() 
{
    return false;
}

// Function to search for a book by ISBN
bool BookList::SearchBook(int isbn) 
{
    BookNode* current = head;
    while (current != nullptr) {
        if (current->isbn == isbn) {
            return true; // Book with the given ISBN found
        }
        current = current->next;
    }
    return false; // Book with the given ISBN not found
}

// Function to empty the list of books
void BookList::EmptyList() 
{
    while (!IsEmpty()) {
        DeleteItem(head->isbn);
    }
}

// Function to print the list of existing books
void BookList::PrintList() 
{
    if (!IsEmpty())
    {
        BookNode* current = head;
        while (current != nullptr) {
            cout << "Title: " << current->title << ", Author: " << current->author << ", ISBN: " << current->isbn << endl;
            current = current->next;
        }
    }
    else
    {
        cout << "List is empty!\n";
    }
}
