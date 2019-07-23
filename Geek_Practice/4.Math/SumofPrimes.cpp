#include<iostream>
using namespace std;
bool isPrime(int n)
{
    if (n <= 1)
        return false;

    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;

    return true;
}
void SievePrime(int n)
{
  long long int sum =0 ;
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[if] will
    // finally be false if i is Not a prime, else true.
    bool prime[n+1];
    memset(prime, true, sizeof(prime));

    for (int p=2; p*p<=n; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples of p greater than or
            // equal to the square of it
            // numbers which are multiple of p and are
            // less than p^2 are already been marked.
            for (int i=p*p; i<=n; i += p)
                prime[i] = false;
        }
    }

    // Print all prime numbers
    for (int p=2; p<=n; p++)
       if (prime[p])
          sum+=p;

    cout<<sum<<'\n';
}
int psum(int n)
{
    long long sum =0;
    for(int i=2;i<=n;i++)
    if(isPrime(i))
    sum+=i;

    return sum;
}
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	int n;
	cin>>n;
	SievePrime(n);
	}
	return 0;
}
