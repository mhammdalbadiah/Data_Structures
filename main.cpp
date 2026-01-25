#include <iostream>
using namespace std ;




// ========== DATA STRUCTURES =========
//
// Primitive Data Types:
// int , bool , float , char
//
// Non-Primitive Data Structures:
// Array, Linked List, Stack, Queue, Tree, Graph
//
// ===================================
//
//            LINKED LIST
//
// A Linked List is a collection of nodes.
// Each node contains:
// 1) Data
// 2) A pointer to the next node
//
// Ex :
//
// [10] -> [20] -> [30] -> NULL
//
// ===================================
//
// We use "struct" when the data structure
// needs to store more than one value
// or when elements are connected together.
//
// ===================================
//
// Definition of a Node:
//
struct Node {
    int data;      // data stores the value
    Node* next;    // next points to the next node
};




int main(){
    
    
    // First Node :
    Node* head = new Node();
    head -> data = 100;
    head -> next = NULL;
    
    //  [100] -> NULL
    
    // ========================
    
    
    
    
    
    // Second Node :
    Node* Second = new Node();
    Second -> data = 200 ;
    Second -> next = NULL;
    
    //  [200] -> NULL
    // How to conecte Them ? Like :
    // [100] -> [200] -> NULL
    
    head ->next = Second;
   
    // ==========================
    
    // Third Node :
    Node * Third = new Node();
    Third -> data = 300 ;
    Third -> next = NULL ;
    
    // Now its like  [300] -> NULL
    // How to make it like this
    // [100] -> [200] -> [300] -> NULL
    
    Second->next = Third;
    
    
    
    // ===============================================
    
    
    
    
    
    // ======= PRINT THE LINKED LIST ========
    
    Node * temp = head ;    // Start From the Beg
    while (temp != NULL) {
        
        cout << temp->data << " " ;
        temp = temp->next;
    }
    
    
    
    
    
    cout << endl;
    
    
    return 0;
}
