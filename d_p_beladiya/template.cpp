#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define PI pair<string,string>
#define ff first
#define ss second
int mods(int a, int m=mod)
{
    return (a%m + m) % m;
}
int add(int x, int y){ 
  x += y; 
  if(x >= mod) 
    x -= mod; 
  return x;
}
int sub(int x, int y){
 x -= y; 
 if(x < 0) 
  x += mod; 
return x;
}
int mul(int x, int y){ 
  return (x * 1ll * y) % mod;
}

int  mod_pow(int  a,int  b,int  M = mod)
{
    int  jawab = 1;
    
    while(b)
    {
        if(b&1) jawab=(jawab*a)%M;
        a=(a*a)%M;
        b>>=1;
    }
    
    return jawab;
}

int mod_inv(int a){
 return mod_pow(a, mod - 2);
}

int get(int x, int b) {

  int start = (1 << b);

  if (start > x) return 0;

  int d = x - start + 1;

  int temp = start * (d / (2 * start)) ;
  temp+= min(start, (d % (2 * start)));

  return temp;
}
vector <vector <pair <int,int> > > adjlst, mst;

int32_t main() {

   #ifndef ONLINE_JUDGE
     freopen("input.c","r",stdin);
     freopen("output.txt","w",stdout);
    #endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
 
mst.assign(4, vector <pair <int,int> > (0));
for(int i=0;i<4;i++)cout<<mst[i]<<endl;
}
 