#include <iostream>
using namespace std;

int lIS(int n, int *input)
{
    int *output = new int[n];
    output[0]=1;
    for (int i = 1; i < n; i++)
    {
        output[i] = 1;
        for (int j = i - 1; j >= 0; j--)
        {
            if (input[j] > input[i])
            {
                continue;
            }
            int possibleAns = output[j] + 1;
            if (possibleAns > output[i])
            {
                output[i] = possibleAns;
            }
        }
    }
    int best = 0;
    for (int i = 0; i < n; i++)
    {
        if (best < output[i])
        {
            best = output[i];
        }
    }
    delete[] output;
    return best;
}
int main()
{
    int arr[6] = {5, 4, 11, 1, 16, 8};
    cout << lIS(6, arr);
}
