#include <iostream>
using namespace std;
void replace(char str[],int size ,int start){
    if (str[start]=='\0') {
        return;
    }
    replace(str,size,start+1);
    if (str[start] == 'x'){
        for (int i = start; i <=size; i++)
        {
            str[i]=str[i+1];
            if (str[i]=='\0')
            {
                break;
            }
        }
    }
}
int main(){
    char m []="xpixxpi";
    int size = sizeof(m)/sizeof(m[0]);
    replace(m,size-1,0);
    cout<<m;
    
}