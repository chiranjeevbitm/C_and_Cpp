#include<iostream>
using namespace std;



void Calculate_nCr(int n ,int r){
  int y = n-r;
  int n_fact=1;
  int r_fact=1;
  int n_r_fact=1;
  // Calculate n!
  while(n>0){
    n_fact = n_fact*n;
    n--;
  }
   cout << n_fact << '\n';
  //Calculate r!
  while(r>0){
    r_fact = r_fact*r;
    r--;
  }
   cout << r_fact << '\n';
  //Calculate (n-r)!
  while(y>0){
    n_r_fact = n_r_fact*y;
    y--;
  }
  std::cout << n_r_fact << '\n';
  int x =  n_r_fact*r_fact;
  float result = n_fact/x;
  cout << result << '\n';
}

int main(){
  int n,r;
  cin >> n;
  cin >> r;
  Calculate_nCr(n,r);


}
