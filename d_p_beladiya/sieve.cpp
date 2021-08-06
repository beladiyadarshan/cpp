  
// void SieveOfEratosthenes(int n)
// {

//     bool prime[n + 1];
//     memset(prime, true, sizeof(prime));
 
//     for (int p = 2; p * p <= n; p++)
//         if (prime[p] == true)
//             for (int i = p * p; i <= n; i += p)
//                 prime[i] = false;
        
    
 
//     for (int p = 2; p <= n; p++)
//         if (prime[p])
//             cout << p << " ";
// }

#include<bits/stdc++.h>
using namespace std;
const long long MAX_SIZE = 1000001;

vector<long long >isprime(MAX_SIZE , true);
vector<long long >prime;
vector<long long >SPF(MAX_SIZE);
  
void manipulated_seive(int N)
{
    isprime[0] = isprime[1] = false ;
  
    for (long long int i=2; i<N ; i++)
    {
       
        if (isprime[i])
        {
            prime.push_back(i);
            SPF[i] = i;
        }
  

        for (long long int j=0;j < (int)prime.size() &&i*prime[j] < N && prime[j] <= SPF[i];j++)
        {
            isprime[i*prime[j]]=false;
            SPF[i*prime[j]] = prime[j] ;
        }
    }
}

vector<int> getFactorization(int x)
{
    vector<int> ret;
    while (x != 1)
    {
        ret.push_back(SPF[x]);
        x = x / SPF[x];
    }
    return ret;
}
  
// driver  program to test above function
int main()
{
    int N = 13 ; // Must be less than MAX_SIZE
  
    manipulated_seive(N);
  
    // pint all prime number less then N
    for (int i=0; i<prime.size() && prime[i] <= N ; i++)
        cout << prime[i] << " ";
  
    return 0;
}


//////////

https://www.geeksforgeeks.org/segmented-sieve/

for lower memory consuming 

///////

int spf[MAXN];
 

// Time Complexity : O(nloglogn)
void sieve()
{
    spf[1] = 1;
    for (int i=2; i<MAXN; i++)
        spf[i] = i;
 

    for (int i=4; i<MAXN; i+=2)
        spf[i] = 2;
 
    for (int i=3; i*i<MAXN; i++)
    {
        if (spf[i] == i)
        {
            for (int j=i*i; j<MAXN; j+=i)
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}
 

vector<int> getFactorization(int x)
{
    vector<int> ret;
    while (x != 1)
    {
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
    return ret;
}
