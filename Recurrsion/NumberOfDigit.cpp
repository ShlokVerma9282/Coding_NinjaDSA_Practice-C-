#include <iostream>
using namespace std;
int Count(int num){
    if (num == 0){
        return 0;
    }
    return 1 + Count(num/10);
}
int main(){
    cout<<Count(10000);
}