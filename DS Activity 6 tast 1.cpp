#include <iostream>
using namespace std;

class Node
{
public:
    string title;
    float price;
    int edition;
    int pages;
    Node* next;
};

class Stack
{
    Node* top;

public:

    Stack()
    {
        top = NULL;
    }

    void push(string t, float p, int e, int pg)
    {
        Node* temp = new Node;

        temp->title = t;
        temp->price = p;
        temp->edition = e;
        temp->pages = pg;

        temp->next = top;
        top = temp;

        cout << "Book Pushed: " << t << endl;
    }

    void pop()
    {
        if(top == NULL)
        {
            cout << "Stack Underflow\n";
            return;
        }

        Node* temp = top;

        cout << "Book Removed: " << temp->title << endl;

        top = top->next;

        delete temp;
    }

    void peek()
    {
        if(top == NULL)
        {
            cout << "Stack Empty\n";
            return;
        }

        cout << "\nTop Book Details\n";
        cout << "Title: " << top->title << endl;
        cout << "Price: " << top->price << endl;
        cout << "Edition: " << top->edition << endl;
        cout << "Pages: " << top->pages << endl;
    }

    void display()
    {
        if(top == NULL)
        {
            cout << "Stack Empty\n";
            return;
        }

        Node* temp = top;

        cout << "\nRemaining Books in Stack:\n";

        while(temp != NULL)
        {
            cout << "Title: " << temp->title << endl;
            cout << "Price: " << temp->price << endl;
            cout << "Edition: " << temp->edition << endl;
            cout << "Pages: " << temp->pages << endl;
            cout << "---------------------\n";

            temp = temp->next;
        }
    }
};

int main()
{
    Stack s;

    // Push 5 books
    s.push("DSA",500,3,450);
    s.push("OOP",600,2,380);
    s.push("Database",550,4,420);
    s.push("AI",700,1,350);
    s.push("Networks",650,5,500);

    // Find top element
    s.peek();

    // Pop 2 books
    s.pop();
    s.pop();

    // Display remaining books
    s.display();

    return 0;
}