#include <iostream>
using namespace std;

void merge(int arr[],int const start,int const mid,int const end){
    auto const subone = mid - start +1;
    auto const subtwo = end - mid;

    auto *leftarray = new int[subone];
    auto *rightarray = new int[subtwo];

    for (auto i = 0; i < subone; i++)
        leftarray[i] = arr[start + i];
    for (auto j = 0; j < subtwo; j++)
        rightarray[j] = arr[mid + 1 + j];

    auto indexofsubone = 0;
    auto indexofsubtwo = 0;
    int indexofmixedarray = start;

    while (indexofsubone<subone && indexofsubtwo<subtwo)
    {
        if (leftarray[indexofsubone]<rightarray[indexofsubtwo])
        {
            arr[indexofmixedarray] = leftarray[indexofsubone];
            indexofsubone++;
            indexofmixedarray++;
        }
        else{
            arr[indexofmixedarray] = rightarray[indexofsubtwo];
            indexofsubtwo++;
            indexofmixedarray++;
        }
    }
    
    while (indexofsubone<subone)
    {
        arr[indexofmixedarray] = leftarray[indexofsubone];
        indexofsubone++;
        indexofmixedarray++;

    }
    while (indexofsubtwo<subtwo)
    {
        arr[indexofmixedarray] = rightarray[indexofsubtwo];
        indexofsubtwo++;
        indexofmixedarray++;
    }
    delete[]leftarray;
    delete[]rightarray;
}

void mergesort(int arr[],int const start,int const end){
    if (start>=end)
    {
        return;
    }
    
    auto   mid = start +(end-start)/2;
    mergesort(arr,start,mid);
    mergesort(arr,mid+1,end);
    merge(arr,start,mid,end);

}
void printArray(int A[], int size)
{
    for (auto i = 0; i < size; i++)
        cout << A[i] << " ";
}
int main(){
        int arr[] = { 12, 11, 13, 5, 6, 7 };
    auto arr_size = sizeof(arr) / sizeof(arr[0]);
 
 
    mergesort(arr, 0, arr_size - 1);
 
    cout << "\nSorted array is \n";
    printArray(arr, arr_size);
    return 0;
}