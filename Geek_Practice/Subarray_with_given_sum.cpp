#include<iostream>
#include<map>
using namespace std;
void subarrysum(int arr[],int n,int sum)
{
// n size of array
  summap<int, int> map;
  int curr_sum =0;

  if (curr_sum==sum  || summap.find(curr_sum-sum) != summap.end())
			{
       if(curr_sum!=sum)
			 for(int j=summap[curr_sum-sum]+1;j<=i;j++)
			 cout<<arr[j]<<" ";
			 else
			 for(int k=0;k<=i;k++)
			 cout<<arr[k]<<" ";
			 cout<<endl;

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
