#include<iostream>
#include<map>
using namespace std;
void subarrysum(int arr[],int n,int sum)
{
// n size of array
  summap<int, int> map;
  int curr_sum =0;

  for(int i=1;i<=n;i++)
  {
     curr_sum +=arr[i];
     if(curr_sum==sum)
     {
     std::cout << 1 <<" " << i << '\n';
     return;
    }
    //If curr_sum - sum already exists in map we have found a subarray with target sum
    if(map.find(curr_sum - sum)!=sum)
    {
      std::cout << map[curr_sum-sum]+1 << " "<< i << '\n';
      return;
    }
    map[curr_sum] = i;
  }
}

int main()
{
  int t,n,sum;
  //sum_map <int, int> map;

  std::cin >>t ;
  while(t--)
  {
  std::cin >> n;
  std::cin >> sum;
  int arr[n];
  for(int i=1;i<=n;i++)
  std::cin >> arr[i];

  subarrysum(arr,n,sum);
}
return 0;
}
