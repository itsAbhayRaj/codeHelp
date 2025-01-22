#include <iostream>
#include <vector>
using namespace std;
bool check(int *arr, int size)
{
    if (size == 0 || size==1)
        return 1;
    if (arr[size - 1] > arr[size - 2])
        return check(arr, size - 1);
    else
        return 0;
   
}
int main()
{
    int arr[] = {-9, 1, -7, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    string ans = check(arr, n) ? "Sorted" : "Not Sorted";
    cout << ans;
}