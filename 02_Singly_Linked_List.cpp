// 02. Write a menu driven program to perform following operations on singly linked list: Create, Insert, Delete, and Display
#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
node *head = NULL;
class Sll
{
public:
    void insertbeg() // Insert at the Beginning
    {
        cout << "Enter the data :" << endl;
        node *nn = new node;
        if (head == NULL)
        {
            cin >> nn->data;
            nn->next = NULL;
            head = nn;
        }
        else
        {
            cin >> nn->data;
            nn->next = head;
            head = nn;
        }
    }
    void displaybeg() // display at beginning
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    void insertloc() // Insert at the Specific Location
    {
        int loc;
        node *nn = new node;
        nn->next = NULL;
        cout << "Enter the Location :" << endl;
        cin >> loc;
        cout << "Enter the data :" << endl;
        if (loc < 1)
        {
            cout << "Location should  greater than 1.\n";
        }
        else if (loc == 1)
        {
            cin >> nn->data;
            nn->next = head;
            head = nn;
        }
        else
        {
            node *temp = head;
            for (int i = 1; i < loc - 1; i++)
            {
                if (temp != NULL)
                {
                    temp = temp->next;
                }
            }
            if (temp != NULL)
            {
                cin >> nn->data;
                nn->next = temp->next;
                temp->next = nn;
            }
            else
            {
                cout << "previous node is null.\n";
            }
        }
    }
    void displayloc() // display at specific location
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    void insertend() // insert at end
    {
        cout << "Enter the data :" << endl;
        node *nn = new node;
        nn->next = NULL;
        if (head == NULL)
        {
            cin >> nn->data;
            head = nn;
        }
        else
        {
            cin >> nn->data;
            node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = nn;
        }
    }
    void displayend() // display at end
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    void deletebigin() // delete beginning
    {
        node *temp;
        if (head == NULL)
        {
            cout << "Underflow Plz First insert a node first\n"<< endl;
        }
        else
        {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
    void displaybigin() // display at beginning
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    void deleteend() // delete end
    {
        node *temp;
        node *current;
        if (head == NULL)
        {
            cout << "First insert a node first\n"<< endl;
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
            {
                current = temp;
                temp = temp->next;
            }
            current->next = NULL;
            delete temp;
        }
    }
    void deleteloc() 
    {
        if (head == NULL)
        {
            cout << "List is Empty please Insert a Node First\n"<< endl;
        }
        else
        {
            int pos, i = 1;
            node *temp, *nextnode;
            cout << "Plz enter Position : ";
            cin >> pos;
            temp = head;
            while (i < pos - 1)
            {
                temp = temp->next;
                i++;
            }
            nextnode = temp->next;
            temp->next = nextnode->next;
            delete nextnode;
        }
    }
    void displaylocation() // displat at specific location
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    Sll s;
    int ch;
    while (1)
    {
        cout << "1.Insert | 2. Delete | 3.Exit" << endl;
        cout << "Enter the choice : ";
        cin >> ch;
        switch (ch)
        {
        //case 1:
            int a;
            cout << "1.Insert at Beginning | 2.Insert at Specific Location | 3.Insert at End " << endl;
            cout << "Enter the choice : ";
            cin >> a;
            switch (a)
            {
            case 1:
                s.insertbeg();
                s.displaybeg();
                break;
            case 2:
                s.insertloc();
                s.displayloc();
                break;
            case 3:
                s.insertend();
                s.displayend();
                break;
            default:
                cout << "Invalid Choice :-(\n";
                break;
            }
            break;
        case 2:
            int b;
            cout << "1.Delete at Beginning | 2.Delete at Specific Location | 3.Delete at End " << endl;
            cout << "Enter the choice : ";
            cin >> b;
            switch (b)
            {
            case 1:
                s.deletebigin();
                s.displaybigin();
                break;
            case 2:
                s.deleteloc();
                s.displaylocation();
                break;
            case 3:
                s.deleteend();
                s.displayend();
                break;
            default:
                cout << "Invalid Choice:\n";
                break;
            }
            break;
        case 3:
            exit(0);
        default:
            cout << "Invalid Choice:\n";
            break;
        }
    }
    return 0;
}
