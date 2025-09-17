#include <iostream>
using namespace std;
/*
optimal apporach : 
using recursion we can reduce the tc very well but the space somplexity increases
here we are using a helper function to send the array define its starting and ending 
and then until the start <= end pointer we swap the location value  if it surpases return 
the array reverses the whole array
*/
void helper(vector<int> &arr, int start, int end)
{
    if (start <= end)
    {
        swap(arr[start], arr[end]);
        start++, end--;
        helper(arr, start, end);
    }
    else
        return;
}
void reverseArray(vector<int> &arr)
{
    helper(arr, 0, arr.size() - 1);
}