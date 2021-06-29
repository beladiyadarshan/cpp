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
 
