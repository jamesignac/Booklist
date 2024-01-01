//
//  BookList.hpp
//  Lab2Problem2.cpp
//
//  Created by James Ignacio on 10/2/23.
//

#ifndef BookList_h
#define BookList_h

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

class BookList
{
public:
    
    BookList();
    ~BookList();
    void PutItem(const string &title, const string &author, int isbn);
    void DeleteItem(int isbn);
    bool IsFull();
    bool IsEmpty();
    bool SearchBook(int isbn);
    void EmptyList();
    void PrintList();
    
    
private:
    struct BookNode 
    {
        string title;
        string author;
        int isbn;
        BookNode* next;
        BookNode(const string& t, const string& a, int i)
        : title(t), author(a), isbn(i), next(nullptr) {}
    };

    BookNode* head;
};

#endif /* BookList_h */
