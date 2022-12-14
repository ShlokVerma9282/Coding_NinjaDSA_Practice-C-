#include <iostream>
using namespace std;

int help(string s, string t,int **output){
    int m=s.size()-1;
    int n=t.size()-1;
    if (s.size()==0||t.size()==0)
    {
        return 0;
    }
    if (output[m][n]!=-1)
    {
        return output[m][n];
    }
    
    int ans;
    
    if (s[0]==t[0])
    {
        ans= 1+help(s.substr(1),t.substr(1),output);
    }
    else{
        int a = help(s.substr(1),t,output);
        int b = help(s,t.substr(1),output);
        int c = help(s.substr(1),t.substr(1),output);
        ans =  max(a,max(b,c));
    }
    output[m][n] = ans;
    return ans;
}
int LCS(string s, string t){
    int **output = new int *[s.size()];
    for (int i = 0; i < s.size(); i++)
    {
        output[i] = new int[t.size()];
        for (int j = 0; j < t.size(); j++)
        {
            output[i][j]=-1;
        }
    }
    return help(s,t,output);

}

int main(){
    string s = "abcwddbabcdefgd";
    string t = "abcd";
    cout<<LCS(s,t);
}