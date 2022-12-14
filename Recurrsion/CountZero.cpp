#include <iostream>
using namespace std;
int count(int num){
    if(num == 0){
        return 0;
    }
    if (num%10==0)
    {
        return 1+count(num/10);
    }
    return 0 +count(num/10);

}
int main(){
    cout<<count(100100);
}