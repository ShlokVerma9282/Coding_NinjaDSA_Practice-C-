#include <iostream>
using namespace std;
void swap(int &x,int&y){
    int temp;
    temp =x;
    x=y;
    y=temp;

}
int *AllIndex(int *arr,int *rer,int count,int num,int size ){
    static int i = 1;
    static int j = 0;
    if (count == 0 && j !=0 )
    {
        swap(size,j);
        return rer;
    }
    if (count == 0 && j ==0){
        rer[j] == -1;
        return rer;
    }

    if(arr[0] == num){
        cout<<i<<" ";
        j++;
    }
    i++;
    return AllIndex(arr+1,rer,count-1,num,size);
    
}
int main(){
    
    int arr[6] = {1,2,4,4,5,6};
    int rer[6];
    int size = 0;
    int *p = AllIndex(arr,rer,6,4,size);
    if (p[0] == -1){
        cout<<"No";
    }
    else{
        for (int i = 0;i < size;i++)
        cout << " " << p[i];
    }
    
}