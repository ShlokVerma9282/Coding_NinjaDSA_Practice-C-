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
void pairSumK(int*arr,int a,int k){
    int count = 0;
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
    if(k!=0){
        for (int i = 0; i < a; i++)
        {
            if (check.count(k-arr[i]) > 0)
            {
                int j = 0;
                while (j<check.count(k-arr[i]))
                {
                    count++;
                    j++;
                }
            }
            if (check.count(k+arr[i]) > 0)
            {
                int j = 0;
                while (j<check.count(k+arr[i]))
                {
                    count++;
                    j++;
                }
            }
            check.erase(arr[i]);
        }
    }
    else if (k==0)
    {
        for (int i = 0; i < a; i++)
        {
            if (check.count(arr[i])>0)
            {
                for (int j = 0; j < check[arr[j]]-1; j++)
                {
                    count++;
                }
                int temp = check[arr[i]];
                check[arr[i]]=temp-1; 
            }
            
        }
        
    }
    
    cout<<count;
}

    int main()
    {
        int a[4] = {4,4,4,4};
        pairSumK(a, 4,0);
    }
