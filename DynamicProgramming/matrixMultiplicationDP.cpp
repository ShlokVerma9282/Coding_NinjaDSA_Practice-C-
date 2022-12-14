#include <iostream>
using namespace std;

int mult(int *input, int n)
{
    int **output = new int*[n];
    for (int i = 0; i < n; i++)
    {
        output[i] = new int[n];
    }

    for (int i = 0; i < n; i++)
    {
        output[n][n] = 0;
    }

    for (int l = 0; l < n; l++)
    {
        for (int i = 1; i < n - l + 1; i++)
        {
            int j = i + l - 1;
            output[i][j] = INT16_MAX;
            for (int k = i; k < j - 1; k++)
            {
                int q = output[i][k] + output[k + 1][j] + input[i - 1] * input[k] * input[j];
                if (q < output[i][j])
                {
                    output[i][j] = q;
                }
            }
        }
    }

    return output[1][n - 1];
}
int main()
{
    int arr[4] = {10, 15, 20, 25};
    cout << mult(arr, 3);
}
