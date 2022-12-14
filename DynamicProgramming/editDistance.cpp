#include <iostream>
using namespace std;

int edit(string s , string t){
    if (s.size()==0||t.size()==0)
    {
       return  max(s.size(),t.size());
    }
    if (s[0]==t[0])
    {
        return edit(s.substr(1),t.substr(1));
    }
    else{
        int a =edit(s.substr(1),t.substr(1))+1;
        int b =edit(s.substr(1),t)+1;
        int c =edit(s,t.substr(1))+1;
        return min(a,min(b,c));
    }
}
int main(){
    string s ="abc";
    string t= "dc";
    cout<<edit(s,t);
}
