#include <iostream>
using namespace std;

int minPath(int **arr, int x, int y)
{   
    int **output = new int *[3];
    for (int i = 0; i < 3; i++)
    {
        output[i] = new int[4];
        for (int j = 0; j < 4; j++)
        {
            output[i][j]=-1;
        }
    }
    
    output[x][y]=arr[x][y];

    for (int i = y-1; i >= 0; i--)
    {
        output[x][i]=output[x][i+1]+arr[x][i];
    }
    for (int i = x-1; i >= 0; i--)
    {
        output[i][y]=output[i+1][y]+arr[i][y];
    }
    for (int i = x-1; i >=0 ; i--)
    {
    for (int j = y-1; j >=0 ; j--)
     {
        output[i][j]=min(output[i+1][j+1],min(output[i+1][j],output[i][j+1]))+arr[i][j];
        
        }
    }
    return output[0][0];
}
int main(){
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
    cout << minPath(arr, 2, 3);
    
}
