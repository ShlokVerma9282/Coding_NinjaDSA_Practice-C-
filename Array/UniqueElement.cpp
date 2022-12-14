#include <iostream>
using namespace std;
int unique(int arr[], int size)
{

    int k=0;

    for (int i = 0; i < size; i++)
    {
        k = arr[i] ^ k;
    }
    return k;
}

int main()
{
    int i[5] = {1, 1, 3, 3, 4};
    int size = sizeof(i) / sizeof(i[0]);
    cout<<size<<endl;
    cout<<unique(i,size);
}
