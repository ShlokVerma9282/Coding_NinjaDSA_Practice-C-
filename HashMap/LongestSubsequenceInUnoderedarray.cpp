#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
void Long(int *arr,int size){
    if (size==0)
    {
        return;
    }
    int head = 0;
    int max = 0;
    unordered_map<int,bool> check;
    for (int i = 0; i < size; i++)
    {
        check[arr[i]]=false;
    }
    for (int j = 0; j < size; j++)
    {
        if (check[arr[j]]==false)
        {
            int temp_head=arr[j];
            int count =0;
            int n =1;
            bool loop = true;
            check[arr[j]]=true;
            while (loop==true)
            {
                if (check.count(arr[j]+n)>0)
                {
                    int temp = arr[j]+n;
                    check[temp]=true;
                    count++;
                    n++;
                }
                else{
                    loop = false;
                }
            }
            loop=true;
            n=1;
            while (loop==true)
            {
                if (check.count(arr[j]-n)>0)
                {
                    int temp = arr[j]-n;
                    check[temp]=true;
                    count++;
                    n++;
                }
                else{
                    temp_head = (arr[j]-n)+1;
                    loop = false;
                }
            }
            if (count>max)
            {
                max=count;
                head=temp_head;
            }
        }
    }
    cout<< head<<"  "<<max+head<<endl;
     
}
int main(){
    int a[13]={2,12,9,16,10,5,3,20,25,11,1,8,6};
    Long(a,13);
}
