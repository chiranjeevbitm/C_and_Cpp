#include<iostream>
using namespace std;

int main(){
  int n;
  cout << "Enter the number upto which you want to find fibonacci number"<<"\n";
  cin >> n;
  int a = 0;
  int b = 1;
  int count =0;
  while(count <= n){
    cout << a << '\n';
    int sum = a+b;
    a = b;
    b = sum;
    count++;
  }
}
