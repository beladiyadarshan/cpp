//
   
  //  #can_change_the_world_with_the_help_of_0_1
  //                                  -darshan786
   
  //
 
 
 
#include<bits/stdc++.h>
using namespace std;
#define int
#define pb push_back
#define mod 1000000007
#define boost ios_base::sync_with_stdio(false);cin.tie(0); 
#define PI pair<int ,int > 
#define ff first 
#define ss second    
#define N 200002
#define MAXN   200002 
int  mod_pow(int  a,int  b,int  M = mod)
{
    int  ans = 1;
    
    while(b)
    {
        if(b&1) ans=(ans*a)%M;
        a=(a*a)%M;
        b>>=1;
    }
    
    return ans;
}
 
 
 
 
 
int  power(int  x, unsigned int  y, int  p)  
  {  
      int  ans = 1;    
    
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
 
  int  modInverse(int  a, int  m) 
  { 
      int  m0 = m; 
      int  y = 0, x = 1; 
    
      if (m == 1) 
        return 0; 
    
      while (a > 1) 
      { 
          
          int  q = a / m; 
          int  t = m; 
    
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

bool solve(long int num){
    vector<long int> copy(2000);

    for(long int i = 0; i < n; i++){
        copy[(v[i] ^ num)]++;
    }

    if(copy == freq)
        return true;
    return false;
}

 
int32_t main (){
       #ifndef ONLINE_JUDGE
   freopen("input.c","r",stdin);
   freopen("output.c","w",stdout);
  #endif
    
int t;
cin>>t;
while(t--)
{

int n;
        cin>>n;
        int p = n/4;
        int sum = p*7;
        int add=0;
        if(n%4==1) add = 1;
        else if(n%4 ==2) add = 3;
        else if(n%4 ==3) add = 4;
        else add = 0;
        cout<<sum+add<<endl;
    }
   return 0;
}
}