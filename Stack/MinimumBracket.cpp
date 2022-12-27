#include <iostream>
using namespace std;
#include <stack>
int balanced(string str){
    stack<char> s;
    int count=0;
    for (int i = 0; i < str.length(); i++)
    {
        if (s.empty())
        {
            s.push(str[i]);
            count++;
        }
        else if(s.top()=='('&&str[i]==')'){
            s.pop();
            count--;
        }
        else{
            s.push(str[i]);
            count++;
        }
    }
    if(s.empty()){
        return 0;
    }
    if (count%2==0)
    {
        return count/2;
    }
    return -1;
    
    
}
int main(){
    string str="(((((())";
    cout<<balanced(str)<<endl;
}