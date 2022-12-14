#include <iostream>
using namespace std;
void hanoi(int n, char from, char to, char aux){
    if (n==0){
        return;
    }
    hanoi(n-1,from,aux,to);
    cout<<n<<" moves from "<<from<<" to "<<to<<endl;
    hanoi(n-1,aux,to,from);

}
int main(){
    int N =4 ;
 
    hanoi(N, 'A', 'C', 'B');
    return 0;
    
}