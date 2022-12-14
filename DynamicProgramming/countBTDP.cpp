#include <iostream>
#include <math.h>
using namespace std;

int CountBT(int n)
{
    int *ans = new int[n + 1];
    ans[0] = 1;
    ans[1] = 1;
    for (int i = 2; i < n + 1; i++)
    {
        int mod = (int)(pow(10, 9)) + 7;
        int x = ans[i - 1];
        int y = ans[i - 2];

        int temp1 = (int)(((long)(x)*x) % mod);
        int temp2 = (int)(((long)(y)*x * 2) % mod);

        int final_ans = (temp1 + temp2) % mod;

        ans[i] = final_ans;
    }
    return ans[n];
}
int main()
{
    cout << CountBT(5);
}
