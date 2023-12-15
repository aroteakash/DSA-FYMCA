//08. Circular Queue


#include <iostream>
using namespace std;
class Circular_Queue
{
    public :
    int cqueue[10];
    int front = -1, rear = -1, n = 10, val;

    void insertCQ()
    {
        if ((front == 0 && rear == n - 1) || (front == rear + 1))
        {
            cout << "Queue Overflow \n";
            return;
        }
        if (front == -1)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            if (rear == n - 1)
            {
                rear = 0;
            }
            else
            {
                rear++;
            }
        }
        cout <<"Insert the Element : " << endl;
        cin >> val;
        cqueue[rear] = val;
    }

    void deleteCQ()
    {
        if (front == -1)
        {
            cout << "Queue Underflow\n";
            return;
        }
        cout << "Element deleted from queue is : " << cqueue[front] << endl;

        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            if (front == n - 1)
            {
                front = 0;
            }
            else
            {
                front++;
            }
        }
    }
    void displayCQ()
    {
        int f = front, r = rear;
        if (front == -1)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue elements are :\n";
        if (f <= r)
        {
            while (f <= r)
            {
                cout << cqueue[f] << " ";
                f++;
            }
        }
        else
        {
            while (f <= n - 1)
            {
                cout << cqueue[f] << " ";
                f++;
            }
            f = 0;
            while (f <= r)
            {
                cout << cqueue[f] << " ";
                f++;
            }
        }
        cout << endl;
    }
};
int main()
{
    Circular_Queue obj;
    int ch;
    while(1)
    {
        cout<<"|1.Enqueue(Insert) |2.Dequeue(Delete) |3.Exit..|\n";
        cout << "Enter choice : " << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            obj.insertCQ();
            obj.displayCQ();
            break;

        case 2:
            obj.deleteCQ();
             obj.displayCQ();
            break;

        case 3:
            cout << "Exit\n";
            return 0;
            break;
 
        default:
            cout << "Incorrect!\n";
        }
    }
    return 0;
}


