#include <iostream>
using namespace std;

int mult(int *input, int i, int j)
{
    if (i == j)
    {
        return 0;
    }
    int mini = INT16_MAX;
    for (int k = i; k < j; k++)
    {
        int count = mult(input, i, k) + mult(input, k + 1, j) + input[i - 1] * input[k] * input[j];

        mini = min(count, mini);
    }
    return mini;
}
int main()
{
    int arr[4] = {10, 15, 20, 25};
    cout << mult(arr, 1, 3);
}
