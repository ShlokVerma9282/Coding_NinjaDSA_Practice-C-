#include <iostream>
using namespace std;

int help(int *input, int i, int j,int** output)
{
    if (i == j)
    {
        return 0;
    }
    int mini = INT16_MAX;
    if (output[i][j]!=-1)
    {
        return output[i][j];
    }
    
    for (int k = i; k < j; k++)
    {
        int count = help(input, i, k,output) + help(input, k + 1, j,output) + input[i - 1] * input[k] * input[j];

        mini = min(count, mini);

        output[i][j] = mini; 
    }
    return mini;
}
int mult(int *input, int i, int j){
    int **output = new int *[j+1];
    for (int x = i-1; x < j+1 ; x++)
    {
        output[x]=new int [j+1];
        for (int y = 0; y < j+1; y++)
        {
            output[x][y]=-1;
        }
    }
    return help(input,i,j,output);
}
int main()
{
    int arr[4] = {10, 15, 20, 25};
    cout << mult(arr, 1, 3);
}
