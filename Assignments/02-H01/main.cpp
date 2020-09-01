///////////////////////////////////////////////////////////////////////////////
//                   
// Author:           Daniel Portillo
// Email:            morenoportillho@gmail.com
// Label:            02-H01
// Title:            Homework 1- Basic Project Organization
// Course:           CMPS 2143
// Semester:         Fall 2020
//
// Description:
//       describe program here thoroughly 
//
// Usage:
//       how to use the program if necessary
//
// Files:            
//      main.cpp   : driver program, definition, and implementation
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>

using namespace std;

int A[100];

struct Node
{
    int x;
    Node *next;
    Node()
    {
        x = -1;
        next = NULL;
    }
    Node(int n)
    {
        x = n;
        next = NULL;
    }
};

/**
 * List
 * 
 * Description:
 *      This class sets up a linked list and contains all the 
 *      methods necessary to create such a list using an array.
 * 
 * Public Methods:
 *                      List()
 *      Void            Push(int)
 *      Void            Insert(int)
 *      Void            PrintTail()
 *      String          Print()
 *      List            operator(const List)
 *      int             operator(int)
 *      friend          ostream(ostream, List)
 * Private Methods:
 *       
 *      Node            _Head
 *      Node            _Tail
 *      Int             _Size
 * 
 * Usage: 
 * 
 *      List L;
 *      L.Push(i);
 *      
 */
class List
{
  private:
    Node *Head;
    Node *Tail;
    int Size;

  public:
    
    /**
     * Public : List
     * 
     * Description:
     *      Default constructor for the class that
     *      sets Head and Tail to NULL
     * 
     * Params:
     *      none
     * 
     * Returns:
     *      none
     */
    List()
    {
        Head = Tail = NULL;
        Size = 0;
    }

    /**
     * Public : Push
     * 
     * Description:
     *      Adds a number to the linked list as a push
     *      to a stack.
     * 
     * Params:
     *     int      :   Vaue to add to linked list
     * 
     * Returns:
     *      Void    :    nothing
     */
    void Push(int val)
    {
        // allocate new memory and init node
        Node *Temp = new Node(val);

        if (!Head && !Tail)
        {
            Head = Tail = Temp;
        }
        else
        {
            Tail->next = Temp;
            Tail = Temp;
        }
        Size++;
    }

    /**
     * Public : Insert
     * 
     * Description:
     *      Adds a new vaule to where Head is and links tails
     *      back to head
     *
     * Params:
     *      int     :  the new vaule added
     * 
     * Returns:
     *      void    :
     */
    void Insert(int val)
    {
        // allocate new memory and init node
        Node *Temp = new Node(val);

        // figure out where it goes in the list

        Temp->next = Head;
        Head = Temp;
        if (!Tail)
        {
            Tail = Head;
        }
        Size++;
    }

    /**
     * Public : PrintTail
     * 
     * Description:
     *      Prints out the vaule of the tail pointer
     * 
     * Params:
     *      none
     * 
     * Returns:
     *      void        : none
     */
    void PrintTail()
    {
        cout << Tail->x << endl;
    }

    /**
     * Public : String
     * 
     * Description:
     *       Creates a string that is a formated version of
     *      the data in the linked list.
     * 
     * Params:
     *      none
     * 
     * Returns:
     *      string      :   The newly made Formated list
     */
    string Print()
    {
        Node *Temp = Head;
        string list;

        while (Temp != NULL)
        {
            list += to_string(Temp->x) + "->";
            Temp = Temp->next;
        }

        return list;
    }

    // not implemented 
    int Pop()
    {
        Size--;
        return 0; //
    }

    /**
     * Public : operator+
     * 
     * Description:
     *      saves current list while modifing a copy of it to format it.
     * 
     * Params:
     *      const List&     :   the list
     * 
     * Returns:
     *      List    : a new concatanted version of the lists
     */
    List operator+(const List &Rhs)
    {
        // Create a new list that will contain both when done
        List NewList;

        // Get a reference to beginning of local list
        Node *Temp = Head;

        // Loop through local list and Push values onto new list
        while (Temp != NULL)
        {
            NewList.Push(Temp->x);
            Temp = Temp->next;
        }

        // Get a reference to head of Rhs
        Temp = Rhs.Head;

        // Same as above, loop and push
        while (Temp != NULL)
        {
            NewList.Push(Temp->x);
            Temp = Temp->next;
        }

        // Return new concatenated version of lists
        return NewList;
    }

    
    // Implementation of [] operator.  This function returns an
    // int value as if the list were an array.
    int operator[](int index)
    {
        Node *Temp = Head;

        if (index >= Size)
        {
            cout << "Index out of bounds, exiting";
            exit(0);
        }
        else
        {

            for (int i = 0; i < index; i++)
            {
                Temp = Temp->next;
            }
            return Temp->x;
        }
    }

    /**
     * Public : ostream
     * 
     * Description:
     *      Prints out the linked list to the screen
     * 
     * Params:
     *      ostream     : the fromated list
     * 
     * Returns:
     *      none
     */
    friend ostream &operator<<(ostream &os, List L)
    {
        os << L.Print();
        return os;
    }
};

int main(int argc, char **argv)
{
    List L1;                        //Creates 2 lists
    List L2;

    for (int i = 0; i < 25; i++)    // begins to push vaules
    {                               // (25 of them) onto the list
        L1.Push(i);
    }

    for (int i = 50; i < 100; i++)  // Pushes vaules onto
    {                               // second list
        L2.Push(i);
    }

    //cout << L1 << endl;
    L1.PrintTail();                 // Prints both lists
    L2.PrintTail();

    List L3 = L1 + L2;              // Initializes 3rd list
    cout << L3 << endl;             // by adding the first two

    cout << L3[5] << endl;          //Prints out the number at
    return 0;                       //Index 5
}
