#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class Queue {
    Node *front, *rear;

public:
    Queue() {
        front = rear = NULL;
    }

    void enqueue(int val) {
        Node* newNode = new Node(val);

        if (rear == NULL) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    int count() {
        int c = 0;
        Node* temp = front;

        while (temp != NULL) {
            c++;
            temp = temp->next;
        }

        return c;
    }
};

int main() {
    Queue q;

    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(15);

    cout << "Number of elements in queue: " << q.count();

    return 0;
}