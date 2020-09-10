///////////////////////////////////////////////////////////////////////////////
//                   
// Author:           Daniel Portillo
// Email:            morenoportillho@gmail.com
// Label:            p01
// Title:            Program 1- Stack upgrade
// Course:           2143
// Semester:         Fall 2020
//
// Description:
//       This assignment fixes the pop and push method to dynamically adjust
//       array based stack that holds integers that was on the leacture
//
// Usage:
//       Nothing special right now.
//
// Files:            
//       None
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
using namespace std;

/**
 * Stack
 *
 * Description:
 *      Integer array based stack implementation
 *
 * Public Methods:
 *      - Stack()
 *      - Stack(int)
 *      - void Push()
 *      - int Pop()
 *      - bool empty()
 *      - bool full()
 *      - void Print()
 *
 * Private Methods:
 *      - None
 *
 * Usage:
 *
 *  Stack S;
 *  S.Push(80);
 *  S.Push(90);
 *  S.Print();
 *  int x = S.Pop();
 *
 */
class Stack {
private:
    int* S;             //array pointer
    int capacity;       //max stack size
    int top;            //current top (index)
    int size;           //current num items
    int capacity_change;//check to see if the cap has already been modified
public:
    /**
     * Stack:
     *    Constructor.
     * Params:
     *    void
     *
     * Returns:
     *     Void
     */
    Stack() {
        capacity = 10;          // set array size
        S = new int[capacity];  // allocate new memory
        top = -1;               // initialize top of stack
        size = 0;               // set stack to empty
        capacity_change = 0;    // Set the array size manipulation check to 0
    }

    /**
     * Stack:
     *    Constructor.
     * Params:
     *    int : capacity
     *
     * Returns:
     *     Void
     */
    Stack(int cap) {
        capacity = cap;         // set array size      
        S = new int[capacity];  // allocate new memory
        top = -1;               // initialize top of stack
        size = 0;               // set stack to empty
        capacity_change = 0;    // Set the array size manipulation check to 0
    }




    /**
     * Push:
     *    Push item onto stack.
     * Params:
     *    int : data
     *
     * Returns:
     *     Void
     */
    void Push(int data) {
        if (size >= capacity)                       //Cheks if array is at cap
        {
            int *S2 = new int[2 * capacity];        //creates new array

            for (int i = 0; i >= capacity; i++)     //Copys vaules from old array to new one
            {
                S2[i] = S[i];
                
            }
            int* S3 = S;        //S3 points to old array
            S = S2;             //Sets S to new adj array
            delete S3;          //Deletes old array

            S2 = NULL;          //sets S2 pointer to Null
            S3 = NULL;          //sets S3 pointer to Null

            capacity_change ++; //Confirms that the capacity has changed 
            
        }
        top++;              // move top of stack up
        size++;             // increment size
        S[top] = data;      // add item to array
    }

    /**
     * Pop:
     *    remove item from stack.
     * Params:
     *    void
     *
     * Returns:
     *     int
     */
    int Pop() {
        int data = S[top];  // pull item from stack
        if (top <= 0)          // To check if the stack is empty
        {                      
            cout << "Error: Stack empty!\n";
            return -1;
        }
        else if (size <= (capacity / 2) && capacity_change >= 1) //checks if array is at
        {                                                        //half cap and larger than original

            int* S2 = new int[capacity/2];      //creates new smaller array
             
            for (int i = 0; i > size; i++)      //Copies old array to new
            {
                S2[i] = S[i];

            }
            int* S3 = S;        //Sets S3 to old array
            S = S2;             //Sets S to new array
            delete S3;          //Deletes old array
            

            S2 = NULL;          //Sets S2 pointer to Null
            S3 = NULL;          //Sets S3 pointer to Null

            capacity_change --;
        }
        else
        {
            top--;              // shrink the stack
            size--;             // update our size
            return data;        // send item back
        }
    }






    /**
     * Empty:
     *    is the stack empty?
     * Params:
     *    void
     *
     * Returns:
     *     bool : true == stack is empty
     */
    bool Empty() {
        //return size == 0;
        return top == -1;
    }

    /**
     * Full:
     *    is the stack full?
     * Params:
     *    void
     *
     * Returns:
     *     bool : true == stack is full
     */
    bool Full() {
        return top == capacity - 1;
    }

    /**
     * Print:
     *    Used so we can inspect our stack.
     * Params:
     *    void
     *
     * Returns:
     *     void
     */
    void Print() {
        for (int i = top; i >= 0; i--) {
            cout << S[i] << endl;
        }
    }

    /**
     * Overloaded ostream <<
     *    Lets us print a stack using cout
     * Params:
     *    ostream &os   : instance of ostream passed in by reference
     *    const Stack   : instance of stack passed in using const so
     *                    it cannot be changed
     *
     * Returns:
     *     ostream
     */
    friend ostream& operator<<(ostream& os, const Stack s) {
        os << "Overloaded!!" << endl;
        for (int i = s.top; i >= 0; i--) {
            os << s.S[i] << endl;
        }
        return os;
    }
};

/**
 * Person
 *
 * Description:
 *      Example struct that represents a person.
 *
 * Usage:
 *
 *  Person P1;
 *
 *  P1.fname = "firstName";
 *  P1.lname = "lastName";
 *  P1.age = 99
 *  cout<<P1<<endl;
 *
 *  Person P2("billy","bob",11);
 *  cout<<P2<<endl;
 */
struct Person {
    string fname;
    string lname;
    int age;

    Person();
    Person(string, string, int);

    friend ostream& operator<<(ostream& os, const Person p) {
        os << p.fname << "," << p.lname << " : " << p.age << endl;
        return os;
    }
};

/**
 * Constructor:
 *    Constructs the person structure
 * Params:
 *    void
 *
 * Returns:
 *     void
 */
Person::Person() {
    fname = "";
    lname = "";
    age = 0;
}

/**
 * Constructor:
 *    Constructs the person structure
 * Params:
 *    string    : first name
 *    string    : last name
 *    int       : persons age
 *
 * Returns:
 *     void
 */
Person::Person(string f, string l, int a) {
    fname = f;
    lname = l;
    age = a;
}

int main() {
    Stack S1;           // calls default constructor
    Stack S2(25);       // calls overloaded constructor

    S1.Push(7);
    S1.Push(4);
    S1.Push(8);
    S1.Push(2);
    S1.Print();

    cout << "Popped a: " << S1.Pop() << endl;
    cout << "Popped a: " << S1.Pop() << endl;

    S1.Push(9);

    //S1.Print();           // old way to print!
    cout << S1 << endl;     // cool way to print

    Person P1;              // calls default constructor (no params)

    P1.fname = "suzy";      // adds values to person P1
    P1.lname = "queue";
    P1.age = 14;

    cout << P1 << endl;     // calls overloaded ostream method

    Person P2("dudley", "doowright", 30);   // uses overloaded constructor

    cout << P2 << endl;     // calls overloaded ostream method
}
