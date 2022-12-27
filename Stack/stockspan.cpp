#include <iostream>
#include <stack>
using namespace std;
void check(int ent[],int out[],int l){
    stack<int> s;
    s.push(0);
    for (int i = i; i < l; i++)
    {
    while (price[i]>price[s.top()])
    {
        s.pop();
        if (s.empty()==1)
        {
            break;
        }
        
    }
    if (s.empty()=1)
    {
        out[i]=i+1;
    } 
    else{
        out[i]=i-s.top();
    } 
    s.push(i)
    }
}
int main(){
    int price[] = { 60,70,80,100,90,75,80,120};
    int n = sizeof(price) / sizeof(price[0]);
    int out[9];
    out[0]=1;
 
    check(price,out, n);
    
}