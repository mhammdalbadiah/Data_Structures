#include <iostream>
#include <string>
using namespace std;


// ##############################
// #          NODE              #
// ##############################

struct Node {

    Node * next;
    double data;

    Node(double val) : next(nullptr), data(val) {}
};


// ##############################
// #       LINKED LIST          #
// ##############################

class List {

    Node * head;
    int counter;

    public:

    List() : head(nullptr), counter(0) {}

    ~List() {

        while (head != nullptr) {
            Node * temp = head;
            head = head -> next;
            delete temp;
        }
    }


    void Insert(int idx, double val) {

        // if index is out of range , exit immediately
        if (idx > counter || idx < 0) return;

        // create a new node with the given value
        Node * newNode = new Node(val);

        if (idx == 0) {

            // new node points to the old first node
            // [NEW] -> [A] -> [B] -> [C] -> nullptr
            newNode -> next = head;

            // head now points to the new node
            // head -> [NEW] -> [A] -> [B] -> [C] -> nullptr
            head = newNode;

        } else {

            // start from the beginning of the list
            Node * curr = head;

            // walk until we stop just before the target index
            for (int i = 1; i < idx; i++)
                curr = curr -> next;

            // new node points to the node after curr
            newNode -> next = curr -> next;

            // curr now points to the new node
            curr -> next = newNode;
        }

        // increment the counter
        counter++;
    }


    void DeleteNode(double val) {

        // if list is empty , exit immediately
        if (head == nullptr) return;

        // curr walks the list , prev stays one step behind
        Node * curr = head;
        Node * prev = nullptr;

        // walk until we find the node with the target value
        while (curr && curr -> data != val) {
            prev = curr;
            curr = curr -> next;
        }

        // value not found , exit
        if (curr == nullptr) return;

        if (prev == nullptr)
            // target is the first node , move head forward
            head = curr -> next;
        else
            // bypass the target node
            prev -> next = curr -> next;

        // free the memory
        delete curr;

        // decrement the counter
        counter--;
    }


    void Display() {

        // if list is empty , exit immediately
        if (head == nullptr) return;

        // start from the first node
        Node * curr = head;

        // walk and print each node until the end
        while (curr != nullptr) {
            cout << curr -> data << endl;
            curr = curr -> next;
        }
    }
};


// ##############################
// #       STACK ( ARRAY )      #
// ##############################

class Stack_Arr {

    int top, maxsize, counter;
    double * values;

    public:

    Stack_Arr(int size = 10) : maxsize(size), top(-1), counter(0) {
        values = new double[size];
    }

    ~Stack_Arr() { delete[] values; }


    bool isEmpty() { return counter == 0; }
    bool isFull()  { return counter == maxsize; }


    void Push(double val) {

        // if stack is full , exit immediately
        if (isFull()) return;

        // increment top and insert value
        // - values[0] = first push
        // - values[1] = second push
        // - values[top] = latest push
        values[++top] = val;

        // increment the counter
        counter++;
    }


    void Pop(double & val) {

        // if stack is empty , exit immediately
        if (isEmpty()) return;

        // save the top value and move top down
        // - val = values[top]
        // - top goes from [top] to [top-1]
        val = values[top--];

        // decrement the counter
        counter--;
    }


    void Peek() {

        // if stack is empty , exit immediately
        if (isEmpty()) return;

        // print the top value without removing it
        cout << values[top] << endl;
    }


    void Display() {

        // if stack is empty , exit immediately
        if (isEmpty()) return;

        // print from top to bottom
        for (int i = top; i >= 0; i--)
            cout << i + 1 << " : " << values[i] << endl;
    }
};


// ##############################
// #     STACK ( LINKEDLIST )   #
// ##############################

class Stack_List {

    Node * head;
    int counter;

    public:

    Stack_List() : head(nullptr), counter(0) {}

    ~Stack_List() {

        while (head != nullptr) {
            Node * temp = head;
            head = head -> next;
            delete temp;
        }
    }


    void Push(double val) {

        // create a new node with the given value
        Node * newNode = new Node(val);

        // new node points to the current top
        newNode -> next = head;
        // - [NEW] -> [A]
        // - [A]   -> [B]
        // - [B]   -> [C]
        // - [C]   -> nullptr

        // head now points to the new node ( new top )
        head = newNode;
        // - head -> [NEW]
        // - [NEW] -> [A]
        // - [A]   -> [B]
        // - [B]   -> [C]
        // - [C]   -> nullptr

        // increment the counter
        counter++;
    }


    void Pop(double & val) {

        // if stack is empty , exit immediately
        if (head == nullptr) return;

        // save the top value to return it
        val = head -> data;
        // - val = [A] data

        // save the top node before moving head
        Node * temp = head;
        // - temp -> [A] -> [B] -> [C] -> nullptr
        // - head -> [A] -> [B] -> [C] -> nullptr

        // move head forward to the next node ( new top )
        head = head -> next;
        // - temp -> [A] -> [B] -> [C] -> nullptr
        // - head -> [B] -> [C] -> nullptr

        // free the old top node
        delete temp;
        // - head -> [B] -> [C] -> nullptr

        // decrement the counter
        counter--;
    }


    void Display() {

        // if stack is empty , exit immediately
        if (head == nullptr) return;

        // start from the top
        Node * curr = head;

        // walk and print each node until the end
        while (curr != nullptr) {
            cout << curr -> data << endl;
            curr = curr -> next;
        }
    }
};


// ##############################
// #       QUEUE ( ARRAY )      #
// ##############################

class Queue {

    int front, rear, maxsize, counter;
    double * values;

    public:

    Queue(int size = 10) : maxsize(size), front(0), rear(-1), counter(0) {
        values = new double[size];
    }

    ~Queue() { delete[] values; }


    bool isEmpty() { return counter == 0; }
    bool isFull()  { return counter == maxsize; }


    void Enqueue(double val) {

        // if queue is full , exit immediately
        if (isFull()) return;

        // move rear forward ( circular )
        rear = (rear + 1) % maxsize;

        // insert value at rear
        // - values[rear] = val
        values[rear] = val;

        // increment the counter
        counter++;
    }


    void Dequeue(double & val) {

        // if queue is empty , exit immediately
        if (isEmpty()) return;

        // save the front value to return it
        // - val = values[front]
        val = values[front];

        // move front forward ( circular )
        front = (front + 1) % maxsize;

        // decrement the counter
        counter--;
    }


    void Display() {

        // if queue is empty , exit immediately
        if (isEmpty()) return;

        // print from front to rear
        for (int i = 0; i < counter; i++)
            cout << values[(front + i) % maxsize] << endl;
    }
};


// ##############################
// #     QUEUE ( LINKEDLIST )   #
// ##############################

class Queue_List {

    Node * front;
    Node * rear;
    int counter;

    public:

    Queue_List() : front(nullptr), rear(nullptr), counter(0) {}

    ~Queue_List() {

        while (front != nullptr) {
            Node * temp = front;
            front = front -> next;
            delete temp;
        }
    }


    void Enqueue(double val) {

        // create a new node with the given value
        Node * newNode = new Node(val);

        if (front == nullptr) {

            // queue is empty , new node is both front and rear
            front = newNode;
            rear  = newNode;
            // - front -> [NEW] <- rear

        } else {

            // attach new node to the end of the queue
            rear -> next = newNode;
            // - front -> [A] -> [B] -> [C] -> [NEW]
            // - rear still on [C]

            // move rear to the new last node
            rear = newNode;
            // - front -> [A] -> [B] -> [C] -> [NEW] <- rear
        }

        // increment the counter
        counter++;
    }


    void Dequeue(double & val) {

        // if queue is empty , exit immediately
        if (front == nullptr) return;

        // save the front node before moving
        Node * temp = front;
        // - temp  -> [A] -> [B] -> [C] -> nullptr
        // - front -> [A] -> [B] -> [C] -> nullptr

        // save the front value to return it
        val = front -> data;
        // - val = [A] data

        // move front forward to the next node
        front = front -> next;
        // - temp  -> [A] -> [B] -> [C] -> nullptr
        // - front -> [B] -> [C] -> nullptr

        // free the old front node
        delete temp;
        // - front -> [B] -> [C] -> nullptr

        // decrement the counter
        counter--;
    }


    void Display() {

        // if queue is empty , exit immediately
        if (front == nullptr) return;

        // start from the front
        Node * curr = front;

        // walk and print each node until the end
        while (curr != nullptr) {
            cout << curr -> data << endl;
            curr = curr -> next;
        }
    }
};
