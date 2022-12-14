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

bool dfs(char Graph[2][11], char *c, int i, int j, int N, int M, bool **visited)
{
    if (Graph[i][j] == 'A')
        return true;

    visited[i][j] = true;
    bool ans = false;

    if (i - 1 >= 0 && j - 1 >= 0 && Graph[i - 1][j - 1] == c[0] && !visited[i - 1][j - 1])
    {
        ans = ans || dfs(Graph, c + 1, i - 1, j - 1, N, M, visited);
    }

    if (i - 1 >= 0 && Graph[i - 1][j] == c[0] && !visited[i - 1][j])
    {
        ans = ans || dfs(Graph, c + 1, i - 1, j, N, M, visited);
    }

    if (i - 1 >= 0 && j + 1 < M && Graph[i - 1][j + 1] == c[0] && !visited[i - 1][j + 1])
    {
        ans = ans || dfs(Graph, c + 1, i - 1, j + 1, N, M, visited);
    }

    if (j + 1 < M && Graph[i][j + 1] == c[0] && !visited[i][j + 1])
    {
        ans = ans || dfs(Graph, c + 1, i, j + 1, N, M, visited);
    }

    if (i + 1 < N && j + 1 < M && Graph[i + 1][j + 1] == c[0] && !visited[i + 1][j + 1])
    {
        ans = ans || dfs(Graph, c + 1, i + 1, j + 1, N, M, visited);
    }

    if (i + 1 < N && Graph[i + 1][j] == c[0] && !visited[i + 1][j])
    {
        ans = ans || dfs(Graph, c + 1, i + 1, j, N, M, visited);
    }

    if (i + 1 < N && j - 1 >= 0 && Graph[i + 1][j - 1] == c[0] && !visited[i + 1][j - 1])
    {
        ans = ans || dfs(Graph, c + 1, i + 1, j - 1, N, M, visited);
    }

    if (j - 1 >= 0 && Graph[i][j - 1] == c[0] && !visited[i][j - 1])
    {
        ans = ans || dfs(Graph, c + 1, i, j - 1, N, M, visited);
    }

    return ans;
}
int solve(char input[2][11], bool **visited, char *c)
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            bool ans = false;
            if (input[i][j] == c[0])
            {
                ans = dfs(input,c+1,i,j,2,11,visited);
                if (ans)
                {
                    return 1;
                }
                initialize(visited);
            }
        }
    }
    return 0;
}
int main()
{
    char input[2][11] = {{'C', 'X', 'D', 'X', 'N', 'X', 'N', 'X', 'N', 'X', 'A'}, {'X', 'O', 'X', 'I', 'X', 'G', 'X', 'I', 'X', 'J', 'X'}};
    cout << endl;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 11; j++)
        {

            cout << input[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    char c[] = "CODINGNINJA";
    bool **visited = new bool *[2];
    for (int i = 0; i < 2; i++)
    {
        visited[i] = new bool[11];
    }
    initialize(visited);
    cout << solve(input, visited, c);
}