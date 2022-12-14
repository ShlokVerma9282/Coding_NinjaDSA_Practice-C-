#include <iostream>
using namespace std;

int min_step(int n)
{
    int *ans = new int[n + 1];
    ans[0] = 0;
    ans[1] = 0;

    for (int i = 2; i < n + 1; i++)
    {
        int x = ans[i-1];

        int y= INT16_MAX, z = INT16_MAX;

        if (i % 2 == 0)
        {
            y = ans[i/2];
        }
        if (i % 3 == 0)
        {
            z = ans[i/3];
        }

        ans[i] = min(x, min(y, z)) + 1;
    }

    return ans[n];
}

int main()
{

    cout << min_step(10);
}
