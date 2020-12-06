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
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;


/**
* Will write random
*    push int
*    pop
*
*/

/*void PopulateFile(string filename,int items){
    //ofstream fout(filename,ofstream::out);

    ofstream fout;

    fout.open("input");

    for(int i=0;i<items;i++){

        if(random() % 2 == 0){
            fout<<"push "<<random() % 100;
        }else{
            fout<<"pop";
        }
        fout<<endl;

    }

    fout.close();

}
*/



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

    int FinalSize;

    int Largest;

    int StartSize;


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
        FinalSize = 0;          //sets final size to 0
        Largest = 0;            //sets largest size to 0
        StartSize = 10;         //Sets start size to default vaule

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
        FinalSize = 0;          //sets final size to 0
        Largest = 0;            //sets largest size to 0
        StartSize = cap;        //sets start size to initial vaule

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

        if (top == (capacity - 1))                       //Cheks if array is at cap
            //size >= capacity
        {

            int* S2 = new int[2 * capacity];        //creates new array



            for (int i = 0; i >= capacity; i++)     //Copys vaules from old array to new one

            {

                S2[i] = S[i];



            }

            int* S3 = S;        //S3 points to old array  

            S = S2;             //Sets S to new adj array

            delete S3;          //Deletes old array



            S2 = NULL;          //sets S2 pointer to Null

            S3 = NULL;          //sets S3 pointer to Null



            capacity_change++;          //Confirms that the capacity has changed for the check
            capacity = capacity * 2;    // changes capacity
            FinalSize = capacity;       //Sends a record of the final size

            BiggestSize(capacity);

            cout << "+ : " << setw(4)<< (capacity / 2) << "  -> " << setw(4) << capacity << "    \n";


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



            int* S2 = new int[capacity / 2];      //creates new smaller array



            for (int i = 0; i > size; i++)      //Copies old array to new

            {

                S2[i] = S[i];



            }

            int* S3 = S;        //Sets S3 to old array
             
            S = S2;             //Sets S to new array

            //delete S3;          //Deletes old array

            S2 = NULL;          //Sets S2 pointer to Null
            S3 = NULL;          //Sets S3 pointer to Null

            capacity_change--;
            capacity = (capacity / 2);
            FinalSize = capacity;

            cout << "- : " << setw(4) << (capacity * 2) << "  -> " << setw(4) << capacity << "    \n";
        }

        else
        {
            top--;              // shrink the stack
            size--;             // update our size

            return data;        // send item back
        }
    }

   

    /**

     * BiggestSize:

     *    To keep track what was the largest ary size.

     * Params:

     *    void

     *

     * Returns:

     *     void

     */
    void BiggestSize(int CurCap)
    {
      

        if (CurCap > Largest)
        {
            Largest = CurCap;
        }
        return;
    }

    /**

     * BiggestSize:

     *    To fetch the largest array size

     * Params:

     *    void

     *

     * Returns:

     *     int : the largest array size

     */
    int GetBiggest()
    {
        return Largest;
    }

    /**

     * GetFinal:

     *    To fetch the largest array size

     * Params:

     *    void

     *

     * Returns:

     *     int : the final array size

     */
    int GetFinal()
    {
        return FinalSize;
    }

    /**

     * GetStart:

     *    To fetch the Starting array size

     * Params:

     *    void

     *

     * Returns:

     *     int : the Starting array size

     */
    int GetStart()
    {
        return StartSize;
    }


};






int main() {

   // ifstream infile;

    ifstream fin;
    ofstream fout;

    string command;
    

    int value;
   // int* S = new int[SIZE];
    Stack S1;
    int tmp;                      //To temporaryly hold the vaule


    //prints header to screen output
    cout << "Name: Daniel Portillo\nProgram: P01\nDate: Sep 16 2020\n\n";

    fin.open("input.txt");        //opens input file
    while (!fin.eof())            //While loop reads from file until
    {                             //nothing is left.

        fin >> command;           // read push or pop  

        

        if (command == "push")  // if command is a push we need
        { 

            fin >> value;         // to read a value in as well
            tmp = value;
            S1.Push (tmp);        //pushes vule to stack class

        }
        else
        {
            S1.Pop();             //pops vaule off of stack class
        }


    }

    fout.open("output.txt");      // Opens output file

    
    //Prints header, Start size, largest size, and final size
    // of the arrayto output file.
    fout << "Name: Daniel Portillo\nProgram: P01\nDate: Sep 16 2020\n\n";   
    fout << "Start Size:  " << S1.GetStart() << "\nMax Size:  " << S1.GetBiggest(); 
    fout  << "\nEnding Size:  " << S1.GetFinal();


}
