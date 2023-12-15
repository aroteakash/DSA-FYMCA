// Queue as ADT

#include <bits/stdc++.h>
using namespace std;
class Queue
{
public:
    int q[100], front = -1, rear = -1, size = 100;
    int val;
    void enqueue()
    {
        if (rear == size - 1)
        {
            cout << "Queue Overflow\n";
        }
        else
        {
            if (front == -1)
            {
                front = 0;
            }
            cout << "Insert the Element :";
            cin >> val;
            rear++;
            q[rear] = val;
        }
    }

    void dequeue()
    {
        if (front == -1 || front > rear)
        {
            cout << "Queue Underflow\n";
            return;
        }
        else
        {
            cout << "Deleted ELement :" << q[front] << endl;
            front++;
        }
    }

    void display()
    {
        if (front == -1)
        {
            cout << "Queue is Empty\n";
        }
        else
        {
            cout << "Queue elements are :\n";
            cout << "|";
            for (int i = front; i <= rear; i++)
            {
                cout << q[i] << "|";
            }
            cout << endl
                 << "\n";
        }
    }
};

int main()
{
    Queue q1;
    int ch;
    while (1)
    {
        cout << "|1.Enqueue(Insert) |2.Dequeue(Delete) |3.Exit..|\n";
        cout << "Enter the Choice :\n";
        cin >> ch;
        switch (ch)
        {
        case 1:
            q1.enqueue();
            q1.display();
            break;
        case 2:
            q1.dequeue();
            q1.display();
            break;
        case 3:
            return 0;
            break;
        }
    }
    return 0;
}