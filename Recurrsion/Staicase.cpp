#include <iostream>
using namespace std;
int stair(int n){
    if (n==0)
    {
        return 0;
    }
    
    if(n>3){
        return 3 + stair(n-1) + stair(n-2)+stair(n-3);
    }
    if (n == 2)
    {
        return 1;
    }
    if(n == 1){
        return 0;
    }

}
int main(){
    int n = 10;
    cout<<stair(n);
}
