#include <iostream>
using namespace std;

int minPath(int **arr, int i, int j, int x, int y)
{
    if (i == x && j == y)
    {
        return arr[i][j];
    }
    if (i > x || j > y)
    {
        return INT16_MAX;
    }
    int a = minPath(arr, i + 1, j, x, y);
    int b = minPath(arr, i, j + 1, x, y);
    int c = minPath(arr, i + 1, j + 1, x, y);

    int ans = min(a,min(b,c))+arr[i][j];

    return ans;
}

int main()
{
    int **arr = new int *[3];
    for (int i = 0; i < 3; i++)
    {
        arr[i] = new int[4];
        for (int j = 0; j < 4; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << minPath(arr, 0, 0, 2, 3);
}
