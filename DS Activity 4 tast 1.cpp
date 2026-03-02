#include <iostream>
using namespace std;

struct Node {
    string brand;
    int stock;
    float price;
    Node* next;
};

Node* head = NULL;

// Add Mobile
void addMobile() {
    Node* newNode = new Node();

    cout << "Enter Brand Name: ";
    cin >> newNode->brand;

    cout << "Enter Units in Stock: ";
    cin >> newNode->stock;

    cout << "Enter Price: ";
    cin >> newNode->price;

    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    cout << "Mobile Added Successfully!\n";
}

// Display Mobiles
void displayMobiles() {
    if (head == NULL) {
        cout << "No mobiles in inventory.\n";
        return;
    }

    Node* temp = head;
    while (temp != NULL) {
        cout << "\nBrand: " << temp->brand;
        cout << "\nStock: " << temp->stock;
        cout << "\nPrice: " << temp->price << endl;
        temp = temp->next;
    }
}

// Delete Mobile
void deleteMobile() {
    if (head == NULL) {
        cout << "Inventory is empty.\n";
        return;
    }

    string brand;
    cout << "Enter Brand Name to Delete: ";
    cin >> brand;

    if (head->brand == brand) {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Mobile Deleted Successfully!\n";
        return;
    }

    Node* current = head;
    Node* previous = NULL;

    while (current != NULL && current->brand != brand) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        cout << "Mobile not found.\n";
        return;
    }

    previous->next = current->next;
    delete current;

    cout << "Mobile Deleted Successfully!\n";
}

int main() {
    int choice;

    do {
        cout << "\n--- Mobile Inventory Menu ---\n";
        cout << "1. Add Mobile\n";
        cout << "2. Delete Mobile\n";
        cout << "3. Display Mobiles\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addMobile();
                break;
            case 2:
                deleteMobile();
                break;
            case 3:
                displayMobiles();
                break;
            case 4:
                cout << "Exiting Program...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}