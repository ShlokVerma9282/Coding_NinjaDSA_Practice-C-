#include <iostream>
#include <queue>
using namespace std;

bool check(int **edges, int n, int sv, int e, bool *visited)
{
    queue<int> pending;
    pending.push(sv);
    visited[sv] = true;
    while (!pending.empty())
    {
        int curr = pending.front();
        pending.pop();
        if (curr == e)
        {
            return true;
        }
        for (int i = 0; i < n; i++)
        {
            if (curr == i)
            {
                continue;
            }
            if (edges[curr][i] == 1 and !visited[i])
            {
                pending.push(i);
                visited[i] = true;
            }
        }
    }
    return false;
}

void print(int **edges, int n, int sv, bool *visited)
{
    queue<int> pending;
    pending.push(sv);
    visited[sv] = true;
    while (!pending.empty())
    {
        int curr = pending.front();
        pending.pop();
        cout << curr << endl;
        for (int i = 0; i < n; i++)
        {
            if (curr == i)
            {
                continue;
            }

            if (edges[curr][i] == 1 and !visited[i])
            {
                pending.push(i);
                visited[i] = true;
            }
        }
    }
}
void BFS(int **edges, int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            print(edges, n, i, visited);
        }
    }
}

int main()
{
    int n;
    int e;
    cin >> n >> e;
    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }

    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    bool a = check(edges, n, 1, 3, visited);
    if (a)
    {
        cout<<"True";
    }
    else
    {
        cout<<"False";
    }
    
}
