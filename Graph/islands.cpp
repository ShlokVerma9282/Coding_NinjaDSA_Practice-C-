#include <iostream>
using namespace std;



void length(int **edges, int n, int sv,bool*visited){
    visited[sv]=true;
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
        length(edges,n,i,visited);
        }
        
    }
    

}

void DFS(int **edges,int n){
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i]=false;
    }
    int total =0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            total++;
            length(edges,n,i,visited);
        }
        
    }
    cout<<total;
    
}
int main(){
    int n;
    int e;
    cin>>n>>e;
    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j]=0;
        }
    }
    
    for (int i = 0; i < e; i++)
    {
        int f,s;
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }

    
    DFS(edges,n);
    
}
