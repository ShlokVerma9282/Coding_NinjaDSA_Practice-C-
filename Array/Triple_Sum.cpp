#include <iostream>
#include<algorithm>
using namespace std;
void pair_sum(int arr[], int i, int j, int target, int count, int k,int size)
{
    while (k != size-2)
    {
        if (i==j)
        {
            k++;
            pair_sum(arr, k+1, size-1, target, count, k,size);
            return;
        }
        else{
        while(arr[i] == arr[k])
        {
            i++;
        }
        while(arr[j] == arr[k])
        {
            j--;
        }
        if (arr[k] + arr[i] + arr[j] == target)
        {
            cout <<arr[k] << " "<< arr[i] << " " << arr[j] << endl;
            count++;
            i++;
        }
        else if (arr[k]+arr[i] + arr[j] < target)
        {
            i++;
        }
        else if (arr[k]+arr[i] + arr[j] > target)
        {
            j--;
        }
        }
    }
    if(k==size-1){
        cout<<count<<endl;
        return;
    }
}
int main()
{
    int i[9] = {-6,-5,-3,0,2,5,8,10,11};
    int size = sizeof(i) / sizeof(i[0]);
    pair_sum(i, 0, size - 1, 10, 0, 0,size);
}