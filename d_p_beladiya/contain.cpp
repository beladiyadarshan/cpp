 //
   
  //  #can_change_the_world_with_the_help_of_0_1
  //                                  -darshan786
   
  //
 
 
 
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mod 1000000007
#define boost ios_base::sync_with_stdio(false);cin.tie(0); 
#define PI pair<long long ,long long > 
#define ff first 
#define ss second    
#define N 200002
#define MAXN   200002 
#define int long long

bool sortbysec(const pair<int,int> &a, 
              const pair<int,int> &b) 
{ 
  if(a.first==b.first)
    return a.second <= b.second;
    return (a.first < b.first); 
} 
  


int n,m,c=0;
vector<vector<int>> g;
map<int,int> mm;
vector<PI>  pp;
int a[197763];
 int x,y;
int32_t main()
{
  #ifndef ONLINE_JUDGE
   freopen("a3.in","r",stdin);
   freopen("output.txt","w",stdout);
  #endif
  
  int t;
  cin>>t;
  int mas=0;
  while(t--)
  {

    int bit[41];
    memset(bit,0,1);
    int n,k;
    cin>>n>>k;

    int a[n];
    int aa[40]={0};
    for(int i=0;i<n;i++){cin>>a[i];


        int zz=a[i];

        int maa=-1,cc=0;
        while(zz)
        {
            int tt=zz&1;
            if(tt==1)
            aa[cc]++;

            cc++;
            zz>>=1;
            
        }


        

    }

    vector<PI> pp;

    for(int i=0;i<41;i++)
    {
        if(a[i]!=0)
        {
            pp.pb(a[i],i);
        }
    }

    sort(pp.begin(),pp.end());




  }


}
        
      
    




