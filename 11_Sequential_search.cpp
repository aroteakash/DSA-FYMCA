#include <iostream>
using namespace std;
int sequentialSearch(int arr[], int n, int x)
{
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == x)
            return i;
    }
    return -1;
}
int main()
{
    int x;
    int arr[] = {3, 7, 1, 9, 4, 6, 8, 2, 5};
    int n = sizeof(arr)/sizeof(arr[0]);   
    cout<<"Enter the Number of elements:";
    cin >> x;
    int index = sequentialSearch(arr, n, x);
    if(index == -1)
        cout << "Element not found." << endl;
    else
        cout << "Element found at index " << index << endl;
    return 0;
}