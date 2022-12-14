#include <iostream>
using namespace std;

int LCS(string s, string t)
{
    int m = s.size();
    int n = t.size();
    int **output = new int *[m+1];
    for (int i = 0; i <= m; i++)
    {
        output[i] = new int[n+1];
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
            {
                output[i][j] = 0;
            }
        }
    }
    
    for (int i = 1; i <= m; i++)
    { 
        for (int j = 1; j <= n; j++)
        {
            if (s[s.size()-i] == t[t.size()-j])
            {
                output[i][j]= 1 + output[i-1][j-1];
            }
            else
            {
                int a = output[i-1][j];
                int b = output[i][j-1];
                int c = output[i-1][j-1];
                int ans = min(a, min(b, c));
                output[i][j] = ans;
            }
        }
    }

    return output[m][n];
}

int main()
{
    string s = "babab";
    string t = "babba";
    cout << LCS(s, t);
}
