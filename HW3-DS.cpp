/* 


    HW 3 : 


    1)     Create class Student which contains:
            studentID is student’s identification.
            studentGPA is student’s GPA grade of 5.
            studentCourse is student’s course name and code (for example: CS231).

    2)     Create class StudentQueue in Queue based on Linked list which contains:
            isEmpty function to examine the Queue is empty or not.
            enqueueStud function to insert an object student to a Queue.
            dequeueStud function to remove an object student from a Queue.
            printStud function to print all data in the Queue.
 


*/ 


#include <iostream>
#include <string>
using namespace std ; 




class Student {

    public :

    int studentID ; 
    float studentGPA ; 
    string studentCourse ;   


    Student() {
        studentID = 0;
        studentGPA = 0.0;
        studentCourse = "";
    }

    Student(int id, float gpa, string course): studentID(id), studentGPA(gpa),studentCourse(course){}


    void display() {

            cout << "ID: " << studentID
             << " , GPA: " << studentGPA
             << " , Course: " << studentCourse << endl;
             
    }


}; 



struct node {


    Student data;
    node* next;


    node(Student s):data(s),next(NULL) {} 


};



class StudentQueue {


    node* front ;
    node* rear ;


    public :


    StudentQueue() { front = rear = NULL ;}


    bool isEmpty() {

        if(front == NULL) return true ;
        else return false ;

    }



    void enqueueStud(Student s) {


        node* newNode = new node(s) ;


        if(isEmpty()) { front = rear = newNode ;}
        else {

            rear->next = newNode ;
            rear = newNode ;

        }

    }



   Student dequeueStud() {


    if(isEmpty()) {

        cout << "Queue is empty !" << endl ;

        return Student() ;  

    }


    node* temp = front ;
    Student removed = temp->data ;

    front = front->next ;


    if(front == NULL) rear = NULL ;


    delete temp ;

    return removed ;

}



    void printStud() {


        if(isEmpty()) {


            cout << "Queue is empty !" << endl ;

            return ;

        }


        node* temp = front ;


        while(temp != NULL) {

            temp->data.display() ;
            temp = temp->next ;

        }

    }



};




int main() {




    StudentQueue x ;


    cout << endl << endl << endl;

    cout << "#######################################" << endl;

    cout << "Print empty queue" << endl ;
    x.printStud() ;

    cout << "#######################################" << endl;

    cout << endl << "Dequeue from empty queue" << endl ;
    x.dequeueStud() ;

    cout << "#######################################" << endl;

    cout << endl << "isEmpty before enqueue" << endl ;
    if(x.isEmpty()) cout << "Queue is Empty" << endl ;
    else cout << "Queue is not Empty" << endl ;

    cout << "#######################################" << endl;

    cout << endl << "Enqueue first student" << endl ;
    x.enqueueStud(Student(1 , 4.5 , "CS231")) ;
    x.printStud() ;

    cout << "#######################################" << endl;

    cout << endl << "isEmpty after first enqueue" << endl ;
    if(x.isEmpty()) cout << "Queue is Empty" << endl ;
    else cout << "Queue is not Empty" << endl ;

     cout << "#######################################" << endl;

    cout << endl << "Enqueue more students" << endl ;
    x.enqueueStud(Student(2 , 3.9 , "CS141")) ;
    x.enqueueStud(Student(3 , 4.8 , "CS330")) ;
    x.enqueueStud(Student(4 , 4.2 , "IT211")) ;
    x.printStud() ;

    cout << "#######################################" << endl;

    cout << endl << "Dequeue one student" << endl ;
    x.dequeueStud() ;
    x.printStud() ;

     cout << "#######################################" << endl;

    cout << endl << "Dequeue all students" << endl ;
    x.dequeueStud() ;
    x.dequeueStud() ;
    x.dequeueStud() ;
    x.printStud() ;

    cout << "#######################################" << endl;

    cout << endl << "isEmpty after removing all students" << endl ;
    if(x.isEmpty()) cout << "Queue is Empty" << endl ;
    else cout << "Queue is not Empty" << endl ;

    cout << "#######################################" << endl;

    cout << endl << "Dequeue again from empty queue" << endl ;
    x.dequeueStud() ;

    cout << "#######################################" << endl;

    return 0 ;

}