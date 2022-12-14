#include <iostream>
using namespace std;
int FirstIndex(int *arr, int count, int num)
{
    if (count == 0)
    {
        return -1;
    }
    static int i = 1;
    if (arr[0] == num)
    {
        return i;
    }
    i++;
    return FirstIndex(arr + 1, count - 1, num);
}
int main()
{

    int arr[6] = {1, 2, 3, 4, 5, 6};
    cout << FirstIndex(arr, 6, 1);
}