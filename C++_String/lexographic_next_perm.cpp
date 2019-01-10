#include<iostream>
#include<algorithm>
using namespace std;
void nth_permute(string str,long int n){
  sort(str.begin(),str.end());
  long int i =1;
  do{
    if(i==n)
    break;
    i++;
  }while(next_permutation(str.begin(),str.end()));
  std::cout << str << '\n';
}


int main(){
  std::string str = "chiranjeev";
  long int n =100;
  nth_permute(str,n);

  // bool val = next_permutation(str.begin(),str.end());
  // if(val==false){
  //    std::cout << "no word possible" << '\n';
  // }else{
  //  std::cout << str << '\n';
  //
  // }
  return 0;
}
