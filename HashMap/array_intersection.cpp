#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
void intersection(int *arr, int a, int *brr, int b)
{
    unordered_map<int, int> check;
    for (int i = 0; i < a; i++)
    {
        if (check.count(arr[i]) == 0)
        {
            check[arr[i]] = 1;
        }
        else
        {
            int temp = check[arr[i]];
            check[arr[i]] = temp + 1;
        }
    }
    for (int i = 0; i < b; i++)
    {
        if (check.count(brr[i]) > 0)
        {
            cout << brr[i] << " ";
            int temp = check[arr[i]];
            if (temp == 1)
            {
                check.erase(brr[i]);
            }
            else if(temp>1)
            {
                int temp = check[arr[i]];
                check[arr[i]] = temp - 1;
            }
            else
            {
                continue;
            }
        }
    }
}
    int main()
    {
        int a[10] = {1, 1, 1, 3, 2, 4, 2, 3, 2};
        int b[6] = {1, 1,1,1, 4, 3};
        intersection(a, 10, b, 6);
    }
