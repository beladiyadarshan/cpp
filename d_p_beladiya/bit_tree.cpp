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
    long long  ans
     = 1;
    
    while(b)
    {
        if(b&1) ans=(ans*a)%M;
        a=(a*a)%M;
        b>>=1;
    }
    
    return ans;
}
 
 
 
 
 
long long  power(long long  x, unsigned long long  y, long long  p)  
  {  
      long long  ans = 1;    
    
      x = x % p; 
     
      if (x == 0) return 0; 
      while (y > 0)  
      {  
          if (y & 1)  
              ans = (ans*x) % p;  
    
         
          y = y>>1; 
          x = (x*x) % p;  
      }  
      return ans;  
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
int values[41];
     
  void value()
  {
     values[0]=1;
      for(int i=1;i<=40;i++)
      {
          values[i]=2*values[i-1];
      }
  }



int  solve(string s,int n)
{

    

        string back=s;
        string x,y,zz,w;


        int ans=0,i=1;
        
        while((2*i)<=n-2)
        {
            x=s.substr(0,i);
            y=s.substr(i,i);
            if(x==y)
            {
                int ppp=2*i;int qqq=(n-ppp)/2;
                zz=s.substr(ppp,qqq);
                w=s.substr(ppp+qqq,qqq);
                
                if(zz==w)ans++;
                
            }
            i++;
        }

        return ans;

} 



int  a[500005],pre[600005],pre2[600005];

int  sum(int  l, int  r) {

  int ttt1= r*(r+1)/2;

  int ttt2=l*(l+1)/2;

  return ttt1-ttt2;
}






int n, q;

class BIT{
private:
    int n;
    vector<int> bit;

public:
    void init(int _n){
        n = _n;
        bit.assign(n + 1, 0);
    }
    //x=index
    void update(int x, int val){
        for(; x <= n; x += x & (-x)) bit[x] += val;
    }

    int query(int x){
        int ret = 0;
        for(; x; x -= x & (-x)) ret += bit[x];
        return ret;

    }

    int query(int l, int r){
        if(l > r) return 0;
        return query(r) - query(l - 1);
    }
} ds;

void del(int kth){
  int l = 1, r = n, m;

  while(l <= r){
    m = (l + r) >> 1;

    if(ds.query(m) < kth) l = m + 1;
    else r = m - 1;
  }

  ds.update(l, -1);
}

int32_t main()
{

    #ifndef ONLINE_JUDGE
   freopen("input.c","r",stdin);
   freopen("output.txt","w",stdout);
  #endif


     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  cin >> n >> q;

  ds.init(n+1);

  for(int i = 1; i <= n; i++){
    int x; cin >> x;
    ds.update(i, x);
  }

 
  ds.update(3,4);

 cout<<ds.query(3);


  return 0;
}

   
