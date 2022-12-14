#include <iostream>
#include <algorithm>
using namespace std;

class Edge
{
public:
    int src;
    int des;
    int wgh;
};
bool compare(Edge a, Edge b)
{
    return a.wgh < b.wgh;
}
int findParent(int v, int *parent)
{
    if (parent[v] == v)
    {
        return v;
    }
    return findParent(parent[v], parent);
}
krushal(Edge *input, int n, int e)
{

    sort(input, input + e, compare);

    Edge *output = new Edge[n - 1];

    int *parent = new int[n];

    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    int count = 0;
    int i = 0;

    while (count != n - 1)
    {
        Edge curr = input[i];

        int srcParent = findParent(curr.src, parent);
        int desParent = findParent(curr.des, parent);

        if (srcParent != desParent)
        {
            output[count] = curr;
            parent[srcParent] = parent[desParent];
            count++;
        }
        i++;
    }
    for (int i = 0; i < n - 1; i++)
    {
        cout << output[i].src << " " << output[i].des << " " << output[i].wgh << endl;
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    Edge *input = new Edge[e];
    for (int i = 0; i < e; i++)
    {
        int s, d, w;
        cin >> s >> d >> w;
        input[i].src = s;
        input[i].des = d;
        input[i].wgh = w;
    }
    cout<<endl;
    krushal(input, n, e);
}