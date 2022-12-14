#include <iostream>
using namespace std;

int findMin(int *distance, bool *visited, int n)
{

    int minVertex = -1;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && (minVertex == -1 || distance[i] < distance[minVertex]))
        {
            minVertex = i;
        }
    }
    return minVertex;
}

dijktra(int **edges, int n)
{
    int *distance = new int[n];
    bool *visited = new bool[n];

    for (int i = 0; i < n; i++)
    {
        distance[i] = INT16_MAX;
        visited[i] = false;
    }
    distance[0] = 0;

    for (int i = 0; i < n - 1; i++)
    {
        int minVertex = findMin(distance, visited, n);
        visited[minVertex] = true;
        for (int j = 0; j < n; j++)
        {
            if (edges[minVertex][j] != 0 && !visited[j])
            {
                int dist = distance[minVertex] + edges[minVertex][j];
                if (dist < distance[j])
                {
                    distance[j] = dist;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << i << " " << distance[i] << endl;
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
    dijktra(input, n);
}