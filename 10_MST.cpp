//MST using Prims Algorithm
//MST using Prim's Algorithm

#include <iostream>
using namespace std;
struct node
{
    int fr, to, cost;
} p[4];
int c = 0, temp1 = 0, temp = 0;
void prims(int *a, int b[][5], int i, int j)
{
    a[i] = 1;
    while (c < 4)
    {
        int min = 999;
        for (int i = 0; i < 5; i++)
        {
            if (a[i] == 1)
            {
                for (int j = 0; j < 5;)
                {
                    if (b[i][j] >= min || b[i][j] == 0)
                    {
                        j++;
                    }
                    else if (b[i][j] < min)
                    {
                        min = b[i][j];
                        temp = i;
                        temp1 = j;
                    }
                }
            }
        }
        a[temp1] = 1;
        p[c].fr = temp;
        p[c].to = temp1;
        p[c].cost = min;
        c++;
        b[temp][temp1] = b[temp1][temp] = 1000;
    }
    cout<<"----------------"<<endl;
    cout<<"Edge Weight"<<endl;
    for (int k = 0; k < 4; k++)
    {
        cout<<p[k].fr<<" - "<<p[k].to<<" "<<p[k].cost<<endl;
        // cout << "Source node : " << p[k].fr << endl;
        // cout << "Destination node : " << p[k].to << endl;
        // cout << "Weight of node : " << p[k].cost << endl;
    }
}
int main()
{
    int a[5];
    for (int i = 0; i < 5; i++)
    {
        a[i] = 0;
    }
    int b[5][5];
    for (int i = 0; i < 5; i++)
    {
        cout << "enter values for " << (i + 1) << " row" << endl;
        for (int j = 0; j < 5; j++)
        {
            cin >> b[i][j];
        }
    }
    prims(a, b, 0, 0);
}

