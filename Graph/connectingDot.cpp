#include <iostream>
using namespace std;
bool initialize(bool **visited)
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 11; j++)
            visited[i][j] = false;
    }
}
bool dfs(char Graph[3][4], int count, int k, char c, int i, int j, int N, int M, bool **visited)
{
    if (count == k)
        return true;

    visited[i][j] = true;
    bool ans = false;
    if (i - 1 >= 0 && j - 1 >= 0 && Graph[i - 1][j - 1] == c && !visited[i - 1][j - 1])
    {
        count++;
        ans = ans || dfs(Graph, count, k, c, i - 1, j - 1, N, M, visited);
    }
    if (i - 1 >= 0 && Graph[i - 1][j] == c && !visited[i - 1][j])
    {
        count++;
        ans = ans || dfs(Graph, count, k, c, i - 1, j, N, M, visited);
    }
    if (i - 1 >= 0 && j + 1 < M && Graph[i - 1][j + 1] == c && !visited[i - 1][j + 1])
    {
        count++;
        ans = ans || dfs(Graph, count, k, c, i - 1, j + 1, N, M, visited);
    }
    if (j + 1 < M && Graph[i][j + 1] == c && !visited[i][j + 1])
    {
        count++;
        ans = ans || dfs(Graph, count, k, c, i, j + 1, N, M, visited);
    }
    if (i + 1 < N && j + 1 < M && Graph[i + 1][j + 1] == c && !visited[i + 1][j + 1])
    {
        count++;
        ans = ans || dfs(Graph, count, k, c, i + 1, j + 1, N, M, visited);
    }
    if (i + 1 < N && Graph[i + 1][j] == c && !visited[i + 1][j])
    {
        count++;
        ans = ans || dfs(Graph, count, k, c, i + 1, j, N, M, visited);
    }
    if (i + 1 < N && j - 1 >= 0 && Graph[i + 1][j - 1] == c && !visited[i + 1][j - 1])
    {
        count++;
        ans = ans || dfs(Graph, count, k, c, i + 1, j - 1, N, M, visited);
    }
    if (j - 1 >= 0 && Graph[i][j - 1] == c && !visited[i][j - 1])
    {
        count++;
        ans = ans || dfs(Graph, count, k, c, i, j - 1, N, M, visited);
    }
    return ans;
}
int solve(char input[3][4], bool **visited, int k)
{

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            bool ans = false;
            char temp = input[i][j];
            ans = dfs(input, 1, 4, temp, i, j, 3, 4, visited);
            if (ans)
            {
                return 1;
            }
            initialize(visited);
        }
    }
    return 0;
}
int main()
{
    char input[3][4] = {{'A', 'A', 'A', 'A'}, {'D', 'W', 'C', 'Q'}, {'T', 'Y', 'U', 'I'}};
    cout << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {

            cout << input[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    bool **visited = new bool *[3];
    for (int i = 0; i < 3; i++)
    {
        visited[i] = new bool[4];
    }
    initialize(visited);
    cout << solve(input, visited, 4);
}