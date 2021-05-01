  //
   
  //  #can_change_the_world_with_the_help_of_0_1
  //                                  -darshan786
   
  //



#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mod 1000000007
#define boost ios_base::sync_with_stdio(false);cin.tie(0); 
#define PI pair<long long ,long long > 
#define ff first 
#define ss second    
#define N 200002
#define MAXN   200002 
long long  mod_pow(long long  a,long long  b,long long  M = mod)
{
    long long  res = 1;
    
    while(b)
    {
        if(b&1) res=(res*a)%M;
        a=(a*a)%M;
        b>>=1;
    }
    
    return res;
}





long long  power(long long  x, unsigned long long  y, long long  p)  
  {  
      long long  res = 1;    
    
      x = x % p; 
     
      if (x == 0) return 0; 
      while (y > 0)  
      {  
          if (y & 1)  
              res = (res*x) % p;  
    
         
          y = y>>1; 
          x = (x*x) % p;  
      }  
      return res;  
  }  

  long long  modInverse(long long  a, long long  m) 
  { 
      long long  m0 = m; 
      long long  y = 0, x = 1; 
    
      if (m == 1) 
        return 0; 
    
      while (a > 1) 
      { 
          
          long long  q = a / m; 
          long long  t = m; 
    
          m = a % m, a = t; 
          t = y; 
    
          y = x - q * y; 
          x = t; 
      } 
    
      if (x < 0) 
         x += m0; 
    
      return x; 
  } 


string decToBinary(long long  n) 
{ 
    string s="";
    for (long long  i = 40; i >= 0; i--) { 
        long long  k = n >> i; 
        if (k & 1)
           s=s+'1';
        else
           s=s+'0'; 
    }
    return s;
} 




long long  gcd(long long  a, long long  b) {
	if (b == 0) return a;
	return gcd(b, a%b);
} 

pair<int, int> getDig(long long a) {
	int mn = 9, mx = 0;
	while(a > 0) {
		int cur = a % 10;
		mn = min(mn, cur);
		mx = max(mx, cur);
		a = a / 10;	
	}
	return {mn, mx};
}

bool isPerfectSquare(int  x) 
{   
  int sr = sqrt(x); 
 
  if(sr*sr==x)
  	return true;
  return false;
} 
int32_t main()
{
boost;
 #ifndef ONLINE_JUDGE
   freopen("input.c","r",stdin);
   freopen("output.c","w",stdout);
  #endif

   
    int t=0,x=1;
    cin>>t;
    

    string ss="#can_change_the_world_with_the_help_of_0_1darshan786";

for(int i=0;i<ss.size();i++)
{
  ss+='a';
}
   while(t--)
    {
      int n,r;
    cin>>n>>r;
    if(r>=n)
    {
      int ans=(n*(n-1)/2);
      cout<<ans+1<<endl;
    }
    else//true
    {
      cout<<(r*(r+1)/2)<<endl;
    }
 
      
 
    }
    return 0;
}