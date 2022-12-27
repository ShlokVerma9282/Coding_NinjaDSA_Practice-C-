#include <iostream>
using namespace std;
#include <stack>
void transfer_rev(stack<int>&fir,stack<int>&sec){
    if (fir.empty()!=1)
    {
        int l=fir.top();
        sec.push(l);
        fir.pop();
        transfer_rev(fir,sec);
    }
}
void transfer(stack<int>&fir,stack<int>&sec){
    if (fir.empty()!=1)
    {
        int l=fir.top();
        fir.pop();
        transfer(fir,sec);
        sec.push(l);
    }
    
}

void reverse(stack<int>&fir){
  stack<int> sec;
  transfer_rev(fir,sec);
  transfer(sec,fir);
}
int main(){
    stack<int> fir;
    fir.push(4);
    fir.push(3);
    fir.push(2);
    fir.push(1);
    cout<<fir.top()<<endl;
    reverse(fir);
    cout<<fir.top()<<endl;
}
