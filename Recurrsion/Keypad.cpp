#include <iostream>
using namespace std;
string num_yo_key(int i){
    string input;
     switch(i){
            case 2: input = "abc";
                break;
            case 3: input = "def";
                break;
            case 4: input = "ghi";
                break;
            case 5: input = "jkl";
                break;
            case 6: input = "mno";
                break;
            case 7: input = "pqrs";
                break;
            case 8: input = "tuv";
                break;
            case 9: input = "wxyz";
                break;
               
    }
    return input;

} 
void keypad(int i){

    string a = num_yo_key(i/10);
    int sizea = a.length();
    string b = num_yo_key(i%10);
    int sizeb = b.length();

    for (int x = 0; x <sizea ; x++)
    {
        char first_l = a[x];
        for (int y = 0; y <sizeb; y++)
        {
            char second_l = b[y];
            cout<< first_l<<second_l<<endl;
        }
        
    }
    


}
int main(){
    int i=23;
    keypad(i);
}
