#include <iostream>
using namespace std;
#include <stack>
bool balanced(string str){
    stack<char> s;
    for (int i = 0; i < str.length(); i++)
    {
        if (s.empty())
        {
            s.push(str[i]);
        }
        else if(s.top()=='('&&str[i]==')'){
            s.pop();
        }
        else if(str[i]=='('){
            s.push(str[i]);
        }
        else{
            s.push(str[i]);
            s.pop();
        }
    }
    if(s.empty()){
        return false;
    }
    return true;
}
int main(){
    string str="((a+b))+c";
    cout<<balanced(str)<<endl;
}