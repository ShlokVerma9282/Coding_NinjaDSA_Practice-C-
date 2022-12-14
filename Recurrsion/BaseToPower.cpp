#include <iostream>
using namespace std;
int FindPower(int base, int power) {
   if (power == 0)
   return 1;
   else
   return (base * FindPower(base, power-1));
}
int main() {
   int base = 3, power = 5;
   cout<<base<<" raised to the power "<<power<<" is "<<FindPower(base, power);
   return 0;
}