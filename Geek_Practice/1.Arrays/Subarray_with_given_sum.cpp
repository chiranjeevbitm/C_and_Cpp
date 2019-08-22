#include<iostream>
#include<map>
using namespace std;
// void subarrysum(int arr[],int n,int sum)
// {
// // n size of array
//   summap<int, int> map;
//   int curr_sum =0;
//
//   for(int i=1;i<=n;i++)
//   {
//      curr_sum +=arr[i];
//      if(curr_sum==sum)
//      {
//      std::cout << 1 <<" " << i << '\n';
//      return;
//     }
//     //If curr_sum - sum already exists in map we have found a subarray with target sum
//     if(map.find(curr_sum - sum)!=sum)
//     {
//       std::cout << map[curr_sum-sum]+1 << " "<< i << '\n';
//       return;
//    q}
//     map[curr_sum] = i;
//   }
// }
void SubArrSum(int a[],int n,int s)
{
  int sum,flag,start,end;
  sum=0;
  flag=0;
  start=0;
  end=0;
  while(end<n)
  {
    sum+=a[end];
    if(sum>s)
    {
      start++;
      end = start;
      sum=0;
    }
    else if(sum==s)
    {
      flag=1;
      break;
    }
    else
    end++;
  }
  if(flag==1)
    cout<<start+1<<" "<<end+1<<'\n';
	else
	  cout<<-1<<'\n';
}


int main()
{
  int t,n,sum;


  std::cin >>t ;
  while(t--)
  {
  std::cin >> n;
  std::cin >> sum;
  int arr[n];
  for(int i=0;i<n;i++)
  std::cin >> arr[i];

  SubArrSum(arr,n,sum);
}
return 0;
}
