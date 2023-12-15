//01  Implement application of array in sparse matrix to perform simple and fast transpose.

#include <iostream>
using namespace std;
class Matrix
{
	int m1[10][10], i, j, rows, cols;
	int t = 0, trip[10][10];

public:
	void read()
	{
		cout << "Enter rows:";
		cin >> rows;
		cout << "Enter colums:";
		cin >> cols;
		cout << "Ente elements of matrix:" << endl;
		for (i = 0; i < rows; i++)
		{
			for (j = 0; j < cols; j++)
			{
				cin >> m1[i][j];
				if (m1[i][j])
				{
					t++;
					trip[t][0] = i + 1;
					trip[t][1] = j + 1;
					trip[t][2] = m1[i][j];
				}
			}
		}
		trip[0][0] = rows;
		trip[0][1] = cols;
		trip[0][2] = t;
	}
	void display()
	{
		cout << "Matrix A:" << endl;
		for (i = 0; i < rows; i++)
		{
			for (j = 0; j < cols; j++)
			{
				cout << m1[i][j] << " ";
			}
			cout << endl;
		}
	}
	void display1()
	{
		cout << "Triplet:" << endl;
		for (i = 0; i <= t; i++)
		{
			for (j = 0; j < 3; j++)
			{
				cout << trip[i][j] << " ";
			}
			cout << endl;
		}
	}
	void transpose()
	{
		int trans[10][5];
		trans[0][0] = trip[0][1];
		trans[0][1] = trip[0][0];
		trans[0][2] = trip[0][2];
		cout << "transpose is:" << endl;
		int q = 1;
		for (i = 0; i <= cols; i++)
		{
			for (int p = 1; p <= t; p++)
			{
				if (trip[p][1] == i)
				{
					trans[q][0] = trip[p][1];
					trans[q][1] = trip[p][0];
					trans[q][2] = trip[p][2];
					q++;
				}
			}
		}
		cout << "transpose" << endl;
		for (i = 0; i <= t; i++)
		{
			for (j = 0; j < 3; j++)
			{
				cout << trans[i][j] << " ";
			}
			cout << endl;
		}
	}
};

int main()
{
	Matrix m;
	m.read();
	m.display();
	m.display1();
	m.transpose();
	return 0;
}
