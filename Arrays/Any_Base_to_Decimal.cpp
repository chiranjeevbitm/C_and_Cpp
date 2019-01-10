#include<iostream>
using namespace std;

int main(){
  int num ,base;
  int power  = 1;
  int ans =0;

  cin >> num;
  cin >> base;
  while(num!=0){
    int rem = num %10;
    ans = ans + (rem*power);
    power = power * base;
    num = num /10;
  }
  std::cout << ans << '\n';

}
