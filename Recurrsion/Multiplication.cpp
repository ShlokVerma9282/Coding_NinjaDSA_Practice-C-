#include <iostream>
using namespace std;
int mult(int a, int b){
    if(b == 0){
        return 1;
    }
    return a*mult(a,b-1);

}
int main(){

    cout<<mult(2,4);
}