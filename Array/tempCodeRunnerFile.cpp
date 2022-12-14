#include <iostream>
using namespace std;
void pair_sum(int arr[], int i, int j, int target, int count, int k)
{
    if (k != size)
    {
        if (i > j)
        {
            k++;
            pair_sum(arr, 0, j, target, count, k) return;
        }
        if (i == k)
        {
            i++;
        }
        if (j == k)
        {
            j--;
        }

        if (arr[k] + arr[i] + arr[j] == target)
        {
            cout << i << " " << j << endl;
            count++;
            if (arr[i] == arr[i + 1])
            {
                if (i == k)
                {
                    i++;
                }
                pair_sum(arr, i + 1, j, target, count, k);
            }
            if (arr[j] == arr[j - 1])
            {
                if (j == k)
                {
                    j--;
                }
                pair_sum(arr, i, j - 1, target, count, k);
            }
            else
            {
                pair_sum(arr, i, j - 1, target, count, k);
            }
        }
        if (arr[i] + arr[j] < target)
        {
            pair_sum(arr, i + 1, j, target, count, k);
        }
        if (arr[i] + arr[j] > target)
        {
            pair_sum(arr, i, j - 1, target, count, k);
        }
    }
}
int main()
{
    int i[9] = {2, -5, 8, -6, 0, 5, 10, 11, -3};
    int size = sizeof(i) / sizeof(i[0]);
    sort(i, i + size);
    pair_sum(i, 0, size - 1, 10, 0, 0);
}