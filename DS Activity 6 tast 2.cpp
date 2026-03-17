#include <iostream>
using namespace std;

class Inventory {
public:
    int serialNum;
    int manufactYear;
    int lotNum;
};

class Node {
public:
    Inventory part;
    Node* next;
};

class Stack {
    Node* top;

public:
    Stack() {
        top = NULL;
    }

    void push(Inventory p) {
        Node* temp = new Node();
        temp->part = p;
        temp->next = top;
        top = temp;
    }

    void pop() {

        if (top == NULL) {
            cout << "Inventory Empty\n";
            return;
        }

        Node* temp = top;

        cout << "\nRemoved Part:\n";
        cout << "Serial: " << temp->part.serialNum << endl;
        cout << "Year: " << temp->part.manufactYear << endl;
        cout << "Lot: " << temp->part.lotNum << endl;

        top = top->next;
        delete temp;
    }

    void display() {

        Node* temp = top;

        cout << "\nRemaining Parts:\n";

        while (temp != NULL) {

            cout << "Serial: " << temp->part.serialNum << endl;
            cout << "Year: " << temp->part.manufactYear << endl;
            cout << "Lot: " << temp->part.lotNum << endl;
            cout << "-----------------\n";

            temp = temp->next;
        }
    }
};

int main() {

    Stack s;
    int choice;

    do {
        cout << "\n1 Add Part\n";
        cout << "2 Remove Part\n";
        cout << "3 Exit\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) {

            Inventory p;

            cout << "Enter Serial Number: ";
            cin >> p.serialNum;

            cout << "Enter Manufacture Year: ";
            cin >> p.manufactYear;

            cout << "Enter Lot Number: ";
            cin >> p.lotNum;

            s.push(p);
        }

        else if (choice == 2) {
            s.pop();
        }

    } while (choice != 3);

    s.display();
}