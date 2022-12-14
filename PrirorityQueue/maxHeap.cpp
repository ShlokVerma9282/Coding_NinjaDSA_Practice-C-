#include <iostream>
using namespace std;
bool maxHeap(int *arr, int size)
{
    bool ans = true;
    for (int i = 0; i < size - 1; i++)
    {
        int parentIndex = i;
        int left = 2 * i + 1;
        if (left < size)
        {
            int leftIndex = left;
            if (arr[parentIndex] < arr[leftIndex])
            {
                ans = false;
                return ans;
            }
        }
        int right = 2 * i + 2;
        if (right < size)
        {
            int rightIndex = right;
            if (arr[parentIndex] < arr[rightIndex])
            {
                ans = false;
                return ans;
            }
        }
    }
    return ans;
}
int main()
{
    int arr[8]={42,20,18,6,14,11,9,4};
    bool ans =maxHeap(arr,8);
    if (ans==true)
    {
        cout<<"true";
    }
    else{
        cout<<"false";
    }
    
}
