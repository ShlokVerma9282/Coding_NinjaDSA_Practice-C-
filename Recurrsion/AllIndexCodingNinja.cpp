#include <iostream>
using namespace std;
int allIndexes(int input[], int size, int x, int output[]) {

    if (size == 0) { 
        return 0; 
    } 
  
    // Getting the recursive answer 
    int smallAns = allIndexes(input + 1, 
                                    size - 1, x, output); 
  
   
    if (input[0] == x) { 
        for (int i = smallAns - 1; i >= 0; i--) { 
            output[i + 1] = output[i] + 1; 
        } 

        output[0] = 0; 
        smallAns++; 
    } 
    else { 

        for (int i = smallAns - 1; i >= 0; i--) { 
            output[i] = output[i] + 1; 
        } 
    } 
    return smallAns; 

}
int main(){
    int input[6] = {1,2,4,4,5,6};
    int output[6];
    int x = 4;
    int n = 6;
    int size = allIndexes(input,n,x,output);
    for(int i =0;i<size;i++){
        cout<< output[i]<<" ";
    }
    }