#include <iostream>
using namespace std;
#include <stack>
bool balanced(string str){
    stack<int> s;
    for (int i = 0; i < str.length(); i++)
    {
        if (s.empty())
        {
            s.push(str[i]);
        }
        else if(s.top()=='('&&str[i]==')'||s.top()=='{'&&str[i]=='}'||s.top()=='['&&str[i]==']'){
            s.pop();
        }
        else{
            s.push(str[i]);
        }
    }
    if(s.empty()){
        return true;
    }
    return false;
}
int main(){
    string str="()[]}[]";
    cout<<balanced(str)<<endl;
}