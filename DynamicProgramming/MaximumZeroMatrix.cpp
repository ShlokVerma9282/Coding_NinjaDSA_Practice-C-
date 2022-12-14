#include <iostream>
using namespace std;

int Zero(int **input, int n)
{
    int **dp = new int*[n];
    for (int i = 0; i < n; i++)
    {
        dp[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            if (i == 0 || j == 0)
            {
                if (input[i][j] == 0)
                {
                    dp[i][j] = 1;
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }
    }
    int max = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (input[i][j] == 0)
            {
                if (dp[i - 1][j - 1] >=1&&dp[i - 1][j] >=1&& dp[i][j - 1]>=1)
                {
                    int k = min(dp[i - 1][j - 1],min(dp[i - 1][j],dp[i][j - 1]));
                    dp[i][j] = k + 1;
                    if (dp[i][j] > max)
                    {
                        max = dp[i][j];
                    }
                }
                else
                {
                    dp[i][j] = 1 ;
                    if (dp[i][j] > max)
                    {
                        max = dp[i][j];
                    }
                }
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    return max;
}
int main()
{
    int **arr = new int *[3];
    for (int i = 0; i < 3; i++)
    {
        arr[i] = new int[3];
        for (int j = 0; j < 3; j++)
        {
            arr[i][j]=0;
        }
    }
    cout << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout<<endl;
    cout<<Zero(arr,3);
}
