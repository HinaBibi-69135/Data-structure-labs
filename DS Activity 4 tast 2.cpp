#include <iostream>
using namespace std;

struct Node {
    string name;
    int age;
    string city;
    Node* next;
};

Node* head = NULL;

// Create Profile
void createProfile() {
    Node* newNode = new Node();

    cout << "Enter Name: ";
    cin >> newNode->name;
    cout << "Enter Age: ";
    cin >> newNode->age;
    cout << "Enter City: ";
    cin >> newNode->city;

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

    cout << "Profile Created Successfully!\n";
}

// View All Profiles
void viewProfiles() {
    if (head == NULL) {
        cout << "No profiles available.\n";
        return;
    }

    Node* temp = head;
    while (temp != NULL) {
        cout << "\nName: " << temp->name;
        cout << "\nAge: " << temp->age;
        cout << "\nCity: " << temp->city << endl;
        temp = temp->next;
    }
}

// Search Profile
void searchProfile() {
    if (head == NULL) {
        cout << "No profiles available.\n";
        return;
    }

    string name;
    cout << "Enter Name to Search: ";
    cin >> name;

    Node* temp = head;
    while (temp != NULL) {
        if (temp->name == name) {
            cout << "\nProfile Found!";
            cout << "\nName: " << temp->name;
            cout << "\nAge: " << temp->age;
            cout << "\nCity: " << temp->city << endl;
            return;
        }
        temp = temp->next;
    }

    cout << "Profile not found.\n";
}

// Update Profile
void updateProfile() {
    if (head == NULL) {
        cout << "No profiles available.\n";
        return;
    }

    string name;
    cout << "Enter Name to Update: ";
    cin >> name;

    Node* temp = head;
    while (temp != NULL) {
        if (temp->name == name) {
            cout << "Enter New Age: ";
            cin >> temp->age;
            cout << "Enter New City: ";
            cin >> temp->city;
            cout << "Profile Updated Successfully!\n";
            return;
        }
        temp = temp->next;
    }

    cout << "Profile not found.\n";
}

// Delete Profile
void deleteProfile() {
    if (head == NULL) {
        cout << "No profiles available.\n";
        return;
    }

    string name;
    cout << "Enter Name to Delete: ";
    cin >> name;

    if (head->name == name) {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Profile Deleted Successfully!\n";
        return;
    }

    Node* current = head;
    Node* previous = NULL;

    while (current != NULL && current->name != name) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        cout << "Profile not found.\n";
        return;
    }

    previous->next = current->next;
    delete current;

    cout << "Profile Deleted Successfully!\n";
}

int main() {
    int choice;

    do {
        cout << "\n--- Social Media Portal ---\n";
        cout << "1. Create Profile\n";
        cout << "2. Update Profile\n";
        cout << "3. Delete Profile\n";
        cout << "4. Search Profile\n";
        cout << "5. View All Profiles\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                createProfile();
                break;
            case 2:
                updateProfile();
                break;
            case 3:
                deleteProfile();
                break;
            case 4:
                searchProfile();
                break;
            case 5:
                viewProfiles();
                break;
            case 6:
                cout << "Exiting Program...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 6);

    return 0;
}