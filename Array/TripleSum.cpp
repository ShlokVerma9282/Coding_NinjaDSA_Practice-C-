#include <iostream>
#include <algorithm>
using namespace std;
int search(int arr[], int i, int j, int mid, int sum, int target, int count)
{
    if (mid > i && mid < j)
    {
        if (sum + arr[mid] == target)
        {
            count++;
            if((arr[mid] == arr[mid + 1])||(arr[mid] == arr[mid - 1])){
            while (arr[mid] == arr[mid + 1])
            {
                mid++;
            }
            while (arr[mid] == arr[mid - 1])
            {
                count++;
                mid--;
            }
            }
            return count;
        }
        if (sum + arr[mid] > target)
        {
            search(arr, i, j, mid - 1,sum, target, count);
        }
        if (sum + arr[mid] < target)
        {
            search(arr, i, j, mid + 1,sum, target, count);
        }
    }
    return count;
}
    void pair_trip(int arr[], int i, int j, int target, int count)
    {
        auto mid = i + (j - i) / 2;
        if (j-i<1)
        {
            cout << count << endl;
            return;
        }
        if (arr[i] + arr[j] < target)
        {
            count =search(arr, i , j,mid,arr[i]+arr[j], target, count);
            pair_trip(arr,i+1,j,target,count);
        }
        if (arr[i] + arr[j] > target)
        {
            count = search(arr, i,j,mid,arr[i]+arr[j], target, count);
            pair_trip(arr,i,j-1,target,count);
        }
    }

    int main()
    {
        int i[9] = {-6,-5,-3,0,2,5,8,10,11};
        int size = sizeof(i) / sizeof(i[0]);
        pair_trip(i,0,size-1,10,0);
    }