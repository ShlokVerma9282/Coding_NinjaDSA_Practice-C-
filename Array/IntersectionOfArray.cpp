#include <iostream>
#include <algorithm>
using namespace std;
int intersection(int arr1[],int arr2[],int size1,int size2){
    int j = 0;
    int n = 0;
    for (int i = 0; i < size1; i++)
    {
        if (arr2[j]=='\0')
        {
            break;
        }
        if(arr1[i]>arr2[j]){
            j++;
        }
        if (arr1[i] == arr2[j])
        {
            arr2[n] = arr2[j];
            j++;
            n++;
        }
    }
    return n;

}
int main(){
    int i[5]={7,3,5,4,1};
    int sizei = sizeof(i)/sizeof(i[0]);
    int j[4]={7,1,2,6};
    int sizej = sizeof(j)/sizeof(j[0]);
    sort(i,i+sizei);
    sort(j,j+sizej);
    cout<<intersection(i,j,sizei,sizej);
}