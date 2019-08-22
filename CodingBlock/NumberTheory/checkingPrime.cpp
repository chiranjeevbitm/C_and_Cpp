#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool isPrime(int n)
{
  if(n==1)
  return false;

  for(int i=2;i*i<n;i++)
  {
    if(n*i==0)
    return false;
  }
  return true;
}

void SievePrime(int n)
{


    bool prime[n+1];
    memset(prime, true, sizeof(prime));

    for (int p=2; p*p<=n; p++)
    {
        if (prime[p] == true)
        {

            for (int i=p*p; i<=n; i += p)
                prime[i] = false;
        }
    }

    for (int p=2; p<=n; p++)
       if (prime[p])
          cout<<p <<"   ";
}
//
// vector<int> seivePrime(int *p,int n)
// {
//   p[0]=p[1]=0;
//   p[2]=1;
//   for(int i=3;i<=n;i+=2) p[i]=1;
//   for(int i=3;i<=n;i+=2)
//   {
//       if(p[i])
//       {
//         for(int j=2*i;j<=n;j+=2*i)
//         p[j]=0;
//       }
//   }
//   vector<int> primes;
//   primes.push_back(2);
//   for(int i=3;i<=n;i+=2)
//   {
//     if(p[i]==1)
//       primes.push_back(i);
//   }
//   return primes;
// }
//
// int segmented_seive(long long a,long long b)
// {
//   seivePrime();
//   bool pp[b-a+1];
//   memset(pp,1,sizeof(pp));
//   for(long long i=2;i*i<=b;i++)
//   {
//     for(long long j=a;j<=b;j++)
//     if(p[i])
//     {
//       if(j==i)
//       continue;
//       if(j%i==0)
//       pp[j-a]=0;
//     }
//   }
//   int res =1;
//   for(long long i=a;i<b;i++)
//   res+=pp[i-a];
//   return res;
// }
//
// vector<int> factorize(int m,vector<int> &primes)
// {
//   vector<int> factors;
//   factors.clear();
//   while(p*p<n)
//   {
//     if(m%p==0)
//     {
//       factors.push_back(p);
//       while(m%p==0)
//       {
//         m=m/p;
//       }
//     }
//     i++;
//     p=primes[i];
//   }
//   if(m!=1)
//   {
//     factors.push_back(m);
//   }
//   return factors;
// }
int main()
{
  int n;
  cin>>n;

  SievePrime(n);

  // int N = 100000;
  // int p[N];
  // memset( p, 0, sizeof(p));
  // int n;
  // cin>>n;
  // if(isPrime(n))
  // cout<<n<< " is a prime no"<<'\n';
  // else
  // cout<<n<< " is not a prime no"<<'\n';

  // SeivePrime(p,100);
  //   for(int i=0;i<100;i++)
  //   if(p[i])
  //   {
  //     cout<<i<<" ";
  //   }
 // vector<int> primes = seivePrime(p,100);
 // int no;
 // cin>>no;
 // vector<int> factors = factorize(no,primes);
 // for(auto f:factors)
 //  cout<<f<<" ";
  return 0;

}
