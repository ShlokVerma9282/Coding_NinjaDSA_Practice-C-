#include <iostream>
using namespace std;
void replace(char str[],int size ,int start){
    if (start+1>size) {
        return;
    }
    replace(str,size,start+1);
    if (str[start] == str[start+1]){
        for (int i = size; i >= start + 1; i--) {
            str[i + 1] = str[i];
        }
 
        str[start + 1] = '*';
    }
}
int main(){
    char m []="xpixx";
    int size = sizeof(m)/sizeof(m[0]);
    replace(m,size-1,0);
    cout<<m;
    
}