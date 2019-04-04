/*
simple permutation -SimPer
permutation with repitation - PerNoDup
permutation lexicographic - PerLexico
simple fibonaci -SimFib
fibonaci with dp -FibDP
Conting lexicographic -CountLexico
Coin Toss finding sequence of outputs - CoinToss
Coin Toss No consequtive Heads - CTNoConcHead
Board Path
Maze Path
*/
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

void SimPer(string ques,string ans)
{
  // base
  if(ques.length()==0)
  {
    cout<< ans << "\n";
    return;
  }
  //call
  for(int i=0;i<ques.length();i++)
  {
    char ch = ques[i];
    string ros = ques.substr(0,i)+ques.substr(i+1);
    SimPer(ros,ans+ch);
  }
}
void SimPerInteger(int que,string ans)
{
  string ques = std::to_string(que);
  // base
  if(ques.length()==0)
  {
    cout<< std::stoi(ans) << "\n";
    return;
  }
  //call
  for(int i=0;i<ques.length();i++)
  {
    char ch = ques[i];
    string ros = ques.substr(0,i)+ques.substr(i+1);
    SimPer(ros,ans+ch);
  }
}

void PerNoDup(string ques,string ans)
{
  bool visited[256]={false};
  // base
  if(ques.length()==0)
  {
    cout<< ans << "\n";
    return;
  }
  //call
  for(int i=0;i<ques.length();i++)
  {
    char ch = ques[i];
    if(visited[ch])
    {
      continue;
    }
    visited[ch] = true;
    string ros = ques.substr(0,i)+ques.substr(i+1);
    PerNoDup(ros,ans+ch);
  }
}
void PerLexico(string ques,string ans)
{
  sort(ques.begin(),ques.end());
  bool visited[256]={false};
  // base
  if(ques.length()==0)
  {
    cout<< ans << "\n";
    return;
  }
  //call
  for(int i=0;i<ques.length();i++)
  {
    char ch = ques[i];
    if(visited[ch])
    {
      continue;
    }
    visited[ch] = true;
    string ros = ques.substr(0,i)+ques.substr(i+1);
    PerLexico(ros,ans+ch);
  }
}

int SimFib(long n)
{
  if(n==0) return 0;
  if(n==1) return 1;

  long r1 = SimFib(n-1);
  long r2 = SimFib(n-2);
  return r1+r2;

}
int FibDP(int n,long arr[])
{

  if(n==0) return 0;
  if(n==1) return 1;
//  int arr[n] = {0};
  if(arr[n]!=0) return arr[n];


  long r1 = FibDP(n-1,arr);
  long r2 = FibDP(n-2,arr);
  arr[n] = r1+r2;
  return r1+r2;

}
// void RecMul(int one[][],int two[][],int r1,int c1,int r2,int c2,int sum)
// {
//   if(one.size()==r1)
//   return sum;
//   if(two.size()==r2)
//   RecMul(one,two,r1,0,0,c2+1,sum);
//
//   if(c2==two.size())
//   RecMul(one,two,r1+1,0,0,0,sum);
//
//
//   RecMul(one,two,r1,c1+1,r2+1,c2,sum+one[r1][c1]*two[r2][c2]);
// }

void CountLexico(int cur,int end)
{
  if(cur==0)  return;
  if(cur>end) return;

  std::cout << cur << '\n';
  for(int i=0;i<=9;i++)
  CountLexico(cur*10+i,end);

  if(cur<9)
  CountLexico(cur+1,end);
}
void CoinToss(int idx,int total,string ans)
{
  if(idx==total)
  {
  std::cout <<ans << '\n';
  return;
}

  CoinToss(idx+1,total,ans+" H");
  CoinToss(idx+1,total,ans+" T");
}
void CTNoConcHead(int idx,int total,string ans,bool Isvisited)
{
  if(idx==total)
  {
  std::cout <<ans << '\n';
  return;
}
if(Isvisited)
CTNoConcHead(idx+1,total,ans+" T",false);
else
{
  CTNoConcHead(idx+1,total,ans+" T",false);
  CTNoConcHead(idx+1,total,ans+" H",true);
}
}
void BoardPath(int cur,int end,string asf)
{
  if(cur==end)
  {
    std::cout << asf<<'\n';
    return ;
  }
  if(cur>end)
  return;


  for(int dice=1;dice<=6;dice++)
  {
   BoardPath(cur+dice,end,asf+std::to_string(dice));

  }


}
int main()
{
  //SimPer("abc","");
  //SimPerInteger(123,"");
  //PerNoDup("aac","");
  //PerLexico("dcba","");
  //cout<<SimFib(40)<<"\n";
  /*long arr[41] = {0};
  cout<<FibDP(40,arr)<<"\n";
  */
  //CountLexico(1,1000);
  //CoinToss(0,4,"");
//  CTNoConcHead(0,4,"",false);
   BoardPath(0,3,"");
  return 0;
}
