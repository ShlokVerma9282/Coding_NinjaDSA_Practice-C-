#include <iostream>
#include<vector>
#include<cmath>
using namespace std;
void replace(char S[],int k,int &a){
    if(S[0]=='\0'){
        return;
    } 
    int i =int(S[0]-'0');
    a+=i*pow(10,(k-1));
    replace(S+1,k-1,a);
}
int main(){
    char S[5]="1234";
    int a =0;
    replace(S,4,a);
    cout<<a;
}
