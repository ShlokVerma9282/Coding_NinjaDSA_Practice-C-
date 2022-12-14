#include <iostream>
using namespace std;
int Print_num(int a,int num){
    cout<< a;
    if (a == num){
        return 0;
    }
    return a +Print_num(a+1,num);

}
int main(){

    Print_num(1,6);
    
}