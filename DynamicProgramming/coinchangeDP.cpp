#include <iostream>
using namespace std;

int coin(int n, int *input, int cd)
{
    if (n <= 0 || cd < 0)
    {
        return 0;
    }
    if (cd == 0)
    {
        return 1;
    }
    int **output = new int *[n+1];
    for (int i = 0; i <=n; i++)
    {
        output[i] = new int[cd + 1];
        for (int j = 0; j <= cd; j++)
        {
            if (i == 0)
            {
                output[i][j] = 0;
            }
            else if (j == 0)
            {
                output[i][j] = 1;
            }
        }
    }
    for (int i = 1; i <=n; i++)
    {
        for (int j = 1; j <= cd; j++)
        {

            if (input[i - 1] <= j)
            {
                int a = output[i ][j - input[i - 1]];
                int b = output[i - 1][j];
                output[i][j] = a + b;
            }
            else
            {
                int b = output[i - 1][j];
                output[i][j] = b;
            }
        }
    }
    return output[n][cd];
}

int main()
{
    int input[3] = {1, 2, 3};
    cout << coin(3, input, 5);
}
