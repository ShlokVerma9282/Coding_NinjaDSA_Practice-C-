#include <iostream>
using namespace std;
bool palindrome(string s){
    int low = 0;
    int high = s.length()-1;
    while (low<high)
    {
        if (s[low] != s[high])
        {
            return false;
        }
        low++;
        high--;
        
    }
    return true;

}
int main(){
    string m ="geaeg";
    if (palindrome(m))
    {
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    
}