#include <iostream>
using namespace std;
double gm(int n){
    if(n ==0){
        return 0;
    }
    return 1 + 0.5*gm(n-1);
}
int main(){
    cout<<gm(3);
}