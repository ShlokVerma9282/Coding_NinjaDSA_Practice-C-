#include <iostream>
using namespace std;
void replace(char str[],int size ,int start){
    if (start+1>size) {
        return;
    }
    replace(str,size,start+1);
    if (str[start]=='p' && str[start+1]=='i'){
        for (int i = size; i >= start + 2; i--) {
            str[i + 2] = str[i];
        }
 
        str[start] = '3';
        str[start + 1] = '.';
        str[start + 2] = '1';
        str[start + 3] = '4';
    }
}
int main(){
    char m []="xpix";
    int size = sizeof(m)/sizeof(m[0]);
    replace(m,size-1,0);
    cout<<m;
    
}