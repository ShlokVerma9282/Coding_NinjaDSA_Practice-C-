#include <iostream>
using namespace std;

int help(string s, string t, int **output)
{
    if (s.size()==0||t.size()==0)
    {
       return  max(s.size(),t.size());
    }
    if (output[s.size()][t.size()]!=-1)
    {
        return output[s.size()][t.size()];
    }
    int ans;
    if (s[0]==t[0])
    {
        ans = help(s.substr(1),t.substr(1),output);
    }
    else{
        int a =help(s.substr(1),t.substr(1),output)+1;
        int b =help(s.substr(1),t,output)+1;
        int c =help(s,t.substr(1),output)+1;
        ans= min(a,min(b,c));
    }
    output[s.size()][t.size()] = ans;
    return ans;

}

int edit(string s, string t)
{
    int m = s.size();
    int n = t.size();
    int **output = new int *[m + 1];
    for (int i = 0; i <= m; i++)
    {
        output[i] = new int [n + 1];
        for (int j = 0; j <= n; j++)
        {
            output[i][j] = -1;
        }
    }
    return help(s, t, output);
}
int main()
{
    string s ="abc";
    string t= "dc";
    cout<<edit(s,t);
}
