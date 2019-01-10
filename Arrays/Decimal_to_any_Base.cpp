#include<iostream>
using namespace std;

int main(){
  int num ,base;
  int power  = 1;
  int ans =0;

  cin >> num;
  cin >> base;
  while(num!=0){
    int rem = num % base;
    ans = ans + (rem*power);
    power = power * 10;
    num = num / base;
  }
  std::cout << ans << '\n';

}
