#include <iostream>
using namespace std;

void sub(int i[],int size,int j){
    
    if(j==size){
        cout<<"[]"<<endl;
        return;
    }
    sub(i,size,j+1);
    cout<<i[j]<<endl;
    if(j<size-1){
        for (int k = j+1; k <size; k++)
        {
         while (k>j)
        {
             cout<<i[j]<<" ";
             j++;
        }
        cout<<endl;
        }
    
    }


}
int main(){
    int i[3]={15,20,12};
    int size = sizeof(i)/sizeof(i[0]);
    sub(i,size,0);
    
}
