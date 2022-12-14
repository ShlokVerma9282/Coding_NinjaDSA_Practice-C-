#include <iostream>
using namespace std;

int help(int n, int *input, int cd, int **output)
{
    if (n <= 0 || cd < 0)
    {
        return 0;
    }
    if (cd == 0)
    {
        return 1;
    }
    if (output[n - 1][cd - 1] != -1)
    {
        return output[n - 1][cd - 1];
    }

    int a = help(n, input, cd - input[n - 1], output);
    int b = help(n - 1, input, cd, output);
    if (input[n - 1] <= cd)
    {
        int ans = a + b;
        output[n - 1][cd - 1] = ans;
        return ans;
    }
    else
    {
        output[n - 1][cd - 1] = b;
        return b;
    }
}
int coin(int n, int *input, int cd)
{
    int **output = new int *[n];
    for (int i = 0; i < n; i++)
    {
        output[i] = new int[cd];
        for (int j = 0; j < cd; j++)
        {
            output[i][j] = -1;
        }
    }
    return help(n, input, cd, output);
}

int main()
{
    int input[3] = {1, 2, 3};
    cout << coin(3, input, 4);
}
