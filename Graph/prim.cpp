#include <iostream>
#include <algorithm>
using namespace std;

int findMin(int *weight, bool *visited, int n)
{

    int minVertex = -1;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && (minVertex == -1 || weight[i] < weight[minVertex]))
        {
            minVertex = i;
        }
    }
    return minVertex;
}

void prim(int **edges, int n)
{

    int *parent = new int[n];
    int *weight = new int[n];
    bool *visited = new bool[n];

    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
        weight[i] = INT16_MAX;
    }
    parent[0] = -1;
    weight[0] = 0;

    for (int i = 0; i < n; i++)
    {
        int minVertex = findMin(weight, visited, n);
        visited[minVertex] = true;

        for (int j = 0; j < n; j++)
        {
            if (edges[minVertex][j] != 0 && !visited[j])
            {
                if (edges[minVertex][j] < weight[j])
                {
                    weight[j] = edges[minVertex][j];
                    parent[j] = minVertex;
                }
            }
        }
    }
    for (int i = 1; i < n; i++)
    {
        if (parent[i] < i)
        {
            cout << parent[i] << " " << i << " " << weight[i] << endl;
        }
        else
        {
            cout << i << " " << parent[i] << " " << weight[i] << endl;
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    int **input = new int *[n];
    for (int i = 0; i < n; i++)
    {
        input[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            input[i][j] = 0;
        }
    }
    for (int i = 0; i < e; i++)
    {
        int s, d, w;
        cin >> s >> d >> w;
        input[s][d] = w;
        input[d][s] = w;
    }
    cout << endl;
    prim(input, n);
}