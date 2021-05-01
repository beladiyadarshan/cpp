

    
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
#define mod 1000000007
#define boost ios_base::sync_with_stdio(false);cin.tie(0); 
#define ff first 
#define MAXN   1010
#define int long long
#define ss second
#define aint (v) v.begin(),v.end() 
#define PI pair<int,int>
#define f(i,a,n) for(int i=a ; i<n ; i++)
#define rf(i,n,a) for(int i=n ; i>=a ; i--)

vector<int> v[100001];



set<int>  bfs(int emp)
{
  set<int> st;
      queue<int> q;
      
        int iemp = emp;
        q.push(iemp);
        st.insert(iemp);
        
        while(!q.empty())
        {
            int emp1 = q.front();
          

            q.pop();
            for(auto i=v[emp1].begin();i!=v[emp1].end();i++)
            {
                if(st.find(*i)==st.end())
                {
                    q.push(*i);
                    st.insert(*i);
                }
            }
        }
        return st;
}

 

const int N = 1e5 + 5;
int n, a, b, da, db, depth[N];
vector<int> adj[N];
int diam = 0;
 
int dfs(int x, int p) {
    int len = 0;
    for(int y : adj[x]) {
        if(y != p) {
            depth[y] = depth[x] + 1;
            int cur = 1 + dfs(y, x);
            diam = max(diam, cur + len);
            len = max(len, cur);
        }
    }
    return len;
}
 

int32_t main() {

  boost

   
    #ifndef ONLINE_JUDGE
     freopen("input.c","r",stdin);
     freopen("output.c","w",stdout);
    #endif
 
 
    
    
   int t;
    cin >> t;
    while(t--) {
       
    }

  
}