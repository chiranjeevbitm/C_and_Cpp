#include<iostream>
using namespace std;
void reverse(string& str){
  int n = str.length();
  for(int i=0;i<n/2;i++){

    swap(str[i],str[n-i-1]);
  }
}

int main() {
  string str ="abcd";
  reverse(str);
  cout << str<< '\n';
  // Reverse str[beign..end]
    reverse(str.begin(), str.end());
    cout << "using inbuilt function Reverse str[beign..end] \n"<<str<<"\n";
  return 0;
}
