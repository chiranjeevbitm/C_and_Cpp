#include<iostream>
#include<vector>
using namespace std;
int main(){
  int t;
  cin >> t;
  char mat[55][55];
  for(int i =0;i<t;i++)
  {
    int M,N,K;
    cin >> M >> N >> K;
    vector<int> bulbList(M,0);
    for(int r =0;r<M;r++){
      for(int c=0;c<N;c++)
        {
          cin >> mat[r][c];
          if(mat[r][c]=='*') ++bulbList[r];
        }
      }
  }
}
