#include <iostream>
using namespace std;
void reverseArray1(vector<int> &arr)
{
    int n = arr.size();
    int i = 0, e = n - 1;
    while (i < e)
    {
        int temp = arr[e];
        arr[e] = arr[i];
        arr[i] = temp;
        i++;
        e--;
    }
}
void helperfunction(vector<int> &arr, int start, int end)
{
    if (start > end)
        return;
    int temp = arr[end];
    arr[end] = arr[start];
    arr[start] = temp;
    helperfunction(arr, start + 1, end - 1);
}
void reverseArray2(vector<int> &arr)
{
    int n = arr.size();
    helperfunction(arr, 0, n - 1);
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};

    reverseArray1(arr);
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    vector<int> arr2 = {1, 2, 3, 4, 5};
    reverseArray2(arr2);
    for (int num : arr2)
    {
        cout << num << " ";
    }

    return 0;
}