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
void pairSum(int*arr,int a){
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
    for (int i = 0; i < a; i++)
    {
        if (check.count(-arr[i]) > 0)
        {
            cout << arr[i] << " ";
            int temp = check[-arr[i]];
            int temp1 = check[-arr[i]];
            if (temp == 1)
            {
                check.erase(-arr[i]);
            }
            else if(temp>1)
            {
                int temp = check[-arr[i]];
                check[-arr[i]] = temp - 1;
            }
            if (temp1 == 1)
            {
                check.erase(arr[i]);
            }
            else if(temp1>1)
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
        int a[6] = {2,1,-2,-2,2,3};
        pairSum(a, 6);
    }
