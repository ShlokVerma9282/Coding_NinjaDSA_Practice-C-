#include <iostream>
using namespace std;

int helper(int n, int *ans)
{
    if (n <= 1)
    {
        return 0;
    }

    if (ans[n] != -1)
    {
        return ans[n];
    }

    int x = helper(n - 1, ans);

    int y = INT16_MAX;
    int z = INT16_MAX;

    if (n % 2 == 0)
    {
        y = helper(n / 2, ans);
    }
    if (n % 3 == 0)
    {
        z = helper(n / 3, ans);
    }

    ans[n] = min(x, min(y, z))+1;

    return ans[n];
}

int min_Step(int n)
{
    int *ans = new int[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        ans[i] = -1;
    }

    return helper(n, ans);
}
int main()
{

    cout << min_Step(4);
}
