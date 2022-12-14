#include <iostream>
using namespace std;
void HeapSort(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        int childIndex = i;
        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;
            if (arr[childIndex] < arr[parentIndex])
            {
                int temp = arr[childIndex];
                arr[childIndex] = arr[parentIndex];
                arr[parentIndex] = temp;
            }
            else
            {
                break;
            }
            childIndex = parentIndex;
        }
    }

    int n = size;

    while (n > 1)
    {
        int temp = arr[0];
        arr[0] = arr[n - 1];
        arr[n - 1] = temp;
        n--;

        int parentIndex = 0;
        int leftIndex = 2 * parentIndex + 1;
        int rightIndex = 2 * parentIndex + 2;

        while (leftIndex < n)
        {
            int minIndex = parentIndex;

            if (arr[minIndex] > arr[leftIndex])
            {
                minIndex = leftIndex;
            }
            if (rightIndex < n&& arr[rightIndex]<arr[minIndex] )
            {
                minIndex = rightIndex;
            }
            if (minIndex == parentIndex)
            {
                break;
            }
            int temp = arr[minIndex];
            arr[minIndex] = arr[parentIndex];
            arr[parentIndex] = temp;

            parentIndex = minIndex;
            leftIndex = 2 * parentIndex + 1;
            rightIndex = 2 * parentIndex + 2;
        }
    }
}
int main()
{
    int arr[6] = {2, 6, 8, 5, 4, 3};
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    HeapSort(arr, 6);
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
