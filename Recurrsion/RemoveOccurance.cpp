#include <iostream>
using namespace std;
void replace(char str[] ){
    if (str[0]=='\0') {
        return;
    }
    if (str[0] == str[1]){
        int i = 0;
        while (str[i] != '\0') {
            str[i] = str[i + 1];
            i++;
        }
        replace(str);  
 
    }
    replace(str+1);
}
int main(){
    char m []="xxxpxxxxxxixxxx";
    int size = sizeof(m)/sizeof(m[0]);
    replace(m);
    cout<<m;
    
}