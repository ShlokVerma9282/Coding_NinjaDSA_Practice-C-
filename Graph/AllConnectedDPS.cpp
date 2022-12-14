#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void check(int **edges, int n, int sv, int e, bool *visited, queue<int> q)
{
    q.push(sv);
    visited[sv] = true;
    for (int i = 0; i < n; i++)
    {
        if (i == sv)
        {
            continue;
        }
        if (edges[sv][i] == 1)
        {
            if (visited[i])
            {
                continue;
            }
            if (i == e)
            {
                cout << "True"<<endl;
                q.push(i);
                while (!q.empty())
                {
                    cout << q.front()<<" ";
                    q.pop();
                }
            }
            check(edges, n, i, e, visited,q);
        }
    }
}

void help(int **edges, int n, int sv, bool *visited,queue<int> &q)
{
    q.push(sv);
    visited[sv] = true;
    for (int i = 0; i < n; i++)
    {
        if (i == sv)
        {
            continue;
        }
        if (edges[sv][i] == 1)
        {
            if (visited[i])
            {
                continue;
            }
            help(edges, n, i, visited,q);
        }
    }
}

vector<queue<int>> DFS(int **edges, int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    queue<int> q;
    vector<queue<int>>vect;
    queue<int> t;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            help(edges, n, i, visited,q);
            t=q;
            vect.push_back(t);
            while (!q.empty())
            {
                q.pop();
            }
            
        }
    }
    return vect;
}
int main()
{/*
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
    */
   /*int n;
    int e;
    cin >> n >> e;*/
    int n =4;
    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }
    /*
    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }*/
    edges[0][1]=1;
    edges[1][0]=1;
    edges[3][2]=1;
    edges[2][3]=1;

    vector<queue<int>>q;
    q = DFS(edges, n);
    for (int i = 0; i < q.size(); i++)
    {
        while (!q[i].empty())
        {
            cout<<q[i].front()<<" ";
            q[i].pop();
        }
        cout<<endl;
    }
    
}
