
/*
       ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄
      ▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░▌
      ▐░█▀▀▀▀▀▀▀▀▀ ▐░█▀▀▀▀▀▀▀█░▌▐░█▀▀▀▀▀▀▀█░▌
      ▐░▌          ▐░▌       ▐░▌▐░▌       ▐░▌
      ▐░▌ ▄▄▄▄▄▄▄▄ ▐░▌       ▐░▌▐░▌       ▐░▌
      ▐░▌▐░░░░░░░░▌▐░▌       ▐░▌▐░▌       ▐░▌
      ▐░▌ ▀▀▀▀▀▀█░▌▐░▌       ▐░▌▐░▌       ▐░▌
      ▐░▌       ▐░▌▐░▌       ▐░▌▐░▌       ▐░▌
      ▐░█▄▄▄▄▄▄▄█░▌▐░█▄▄▄▄▄▄▄█░▌▐░█▄▄▄▄▄▄▄█░▌
      ▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░▌
       ▀▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀▀  
 
 #can_change_the_world_with_the_help_of_0_1
                                    -darshan786    */
 
  
 
 
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define boost ios_base::sync_with_stdio(false);cin.tie(0); 
#define ff first 
#define MAX  300005
#define int long long
#define ss second
#define all(v) v.begin(),v.end() 
#define PI pair<int,int>
#define pb push_back
#define endl '\n'
#define MOD 1000000007
std::vector<int> tree[MAX];
int values[MAX],assign[MAX];
int n,x;

int mod(int a, int m=MOD)
{
    return (a%m + m) % m;
}

void dfs(int u,int &jawab,int par = 0)
{
    vector<int> temp;

    int ret=0,h=0;
    for(auto ch : tree[u])
    {
        if(ch!=par)
        {
            dfs(ch,jawab,u);
            
            temp.pb(values[ch]);
            // cout<<values[ch]<<" ";
            h=mod(h+values[ch]);
        }
    }
    // cout<<endl;
    //for(auto i:temp)cout<<i<<" ";cout<<endl;

    for(auto i:temp)
      {            
        int dif=h-i;
        int mul=mod(dif*i);
        ret=mod(ret+mul);
      }

    jawab=mod(jawab+mod(ret+h+1));
    values[u]=mod(h+h+1);
    for(int i=1;i<=4;i++)cout<<values[i]<<" ";cout<<endl;

    
    
}


void pre(){
    vector<int> phi(n + 1);
    phi[0] = 0;
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
        phi[i] = i;

    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }

}
void solve()
{

    cin>>n;
    
      


    

    
}

int32_t main()
{
  boost

  #ifndef ONLINE_JUDGE
     freopen("input.c","r",stdin);
     freopen("output.c","w",stdout);
    #endif

     int t;
     cin>>t;
     pre();
     while(t--)
      solve();
  
}