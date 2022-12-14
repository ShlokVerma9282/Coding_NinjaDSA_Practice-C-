#include <iostream>
using namespace std;


int help(int **arr, int i, int j, int x, int y,int **output)
{
    if (i == x && j == y)
    {
        return arr[i][j];
    }
    if (i > x || j > y)
    {
        return INT16_MAX;
    }
    if(output[i][j]!=-1){

        return output[i][j];
    }
    int a = help(arr, i + 1, j, x, y,output);
    int b = help(arr, i, j + 1, x, y,output);
    int c = help(arr, i + 1, j + 1, x, y,output);

    int ans = min(a,min(b,c))+arr[i][j];
    output[i][j]=ans;
    return output[i][j];
}

int minPath(int **arr, int i, int j, int x, int y){
    int **output = new int *[3];
    for (int i = 0; i < 3; i++)
    {
        output[i] = new int[4];
        for (int j = 0; j < 4; j++)
        {
            output[i][j]=-1;
        }
    }
    return help(arr,i,j,x,y,output);
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
    cout << minPath(arr, 0, 0, 2, 3);
}
