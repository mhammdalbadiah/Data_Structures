

#include <iostream>
#include <string>
using namespace std ; 


// just Global VAR , To every FN use the same list 
int Counter = 0 ;
const int  size = 100 ;
string Emp_Name[size]; 



// To reset the FN
void Rest() {

    if ( Counter > 0 ){

    Counter = 0 ; 
    cout << "The list is empty Now !!! " << endl;

    }
    else {

    cout << "Sorry , The list is already Empty !" << endl;
    }

 }

void Print_List() {


    if (Counter == 0){ 
        cout << "The list is Already Empty !" << endl;
        return ; 
    }

    for (int i = 0 ; i < Counter ; i = i+1 ){

        cout << "====================================" << endl;
        cout << "Element Number : " << i+1 << endl;
        cout << "The name is : " << Emp_Name[i] << endl;
        cout << "====================================" << endl;

    }


}

// to find the INDEX
int FIND(string &x){

if (Counter == 0 ){
    cout << "The list is already empty ! " << endl;
    return -1 ;
}

for (int i=0 ; i < Counter ; i = i+1 )
    if ( Emp_Name[i] == x ) { return i+1 ; } 

     return -1;

}

// to insert the Emp Name into the list 
void Insert(string &x , int pos) {


    if (Counter == size) { cout << "The list is already FULL !" << endl; return ;}
    if (pos <= 0 ) {cout << "chose another postion please " << endl; return ;}
    if (pos > Counter + 1 ) { cout << "Invalid postion !" << endl; return ; }
       
    int idx = pos - 1 ; 


    for (int i = Counter ; i > idx ; --i )
        Emp_Name[i] = Emp_Name[i - 1];


    Emp_Name[idx] = x;
    Counter++;
}

// to remove element from the list 
void Remove(string &x){

    if (Counter == 0 ) { cout << "the list is already empty , you can't delete anything !" << endl; return ;}

    int pos = FIND(x) ;

    if ( pos == -1 ) {cout << "We Can't find the element ! " << endl; return ;}

    int idx = pos -1 ; 

    for (int i = idx ;  i <Counter -1 ; i = i+1 ) 
        Emp_Name[i] = Emp_Name[i + 1];

    Counter-- ; 
    cout << "Element Removed Successfully !! " << endl;

}


void Find_x (int x ) { 

    if (Counter == 0 ) {cout << "the list is empty already ! " << endl; return ;}
    if ( x < 1 or  x > Counter ) {cout << "Invalid postion ! " << endl; return ;}

    cout << Emp_Name[x-1] << endl;

}







int main () { 


    int choice ; 

    do { 


        cout << endl << "========= MENU =========" << endl;;
        cout << "1) Insert" << endl;
        cout << "2) Remove"<< endl;
        cout << "3) Find"<< endl;
        cout << "4) Find Kth"<< endl;;
        cout << "5) Print List"<< endl;
        cout << "6) Make Empty"<< endl;
        cout << "0) Exit"<< endl;
        cout << "Choose: ";
        cin >> choice;

    
        switch (choice) {

            case 1: {


                string name;
                int pos;

                cout << "Enter name: ";
                cin >> name;
                cout << "Enter position (1 to " << Counter + 1 << "): ";
                cin >> pos;

                Insert(name, pos);

                break;
            }

            case 2: {

                string name;

                cout << "Enter name to remove: ";
                cin >> name;
                Remove(name);

                break;
            }

            case 3: {

                string name;

                cout << "Enter name to find: ";
                cin >> name;

                int result = FIND(name);

                if (result == -1){ cout << "Not Found!" << endl; }
                else
                    cout << "Found at position: " << result << endl;

                break;

            }

            case 4: {

                int x;
                
                cout << "Enter position: ";
                cin >> x;
                Find_x(x);  

                break ; 
            }

            case 5: {

                Print_List();
                break;
            }
            case 6:{

                Rest();   
                break;
            }
            case 0: {

                cout << "Program Ended." << endl;

                break;
            }

            default:

                cout << "Invalid choice!" << endl;

        }






    }while (choice != 0 ) ;




    return 0 ;

}