#include <iostream>
using namespace std;
bool check(char s[]){
    if(s[0] == '\0'){
        return true;
    }

    if((s[0] =='a'&&s[1]=='\0')||(s[0]=='a'&&s[1]=='a')||(s[0]=='a'&&s[1]=='b'&&s[2]=='b')){
        return check(s+1);
    }
    if((s[0]=='b'&&s[1]=='b'&&s[2]=='a')||(s[0]=='b'&&s[1]=='b'&&s[2]=='\0')){
        return check(s+2);
    }
    return false;

}
int main(){
    char s[8]= "abbaabb";
    if (check(s))
    {
        cout<<"yes";
    }
    else{
        cout<<"no";
    }
    
    
}