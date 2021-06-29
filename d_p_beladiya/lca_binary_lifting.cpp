 #include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

#define ll long long int
#define endl "\n"
#define F first
#define S second
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define debug(a) cout << #a << " = " << a << " ";

typedef tree < int ,null_type ,less<int>,  rb_tree_tag ,  tree_order_statistics_node_update > ordered_set;
template<typename T> istream &operator>>(istream &is, vector<T> &vec) { for (auto &v : vec) is >> v; return is; }
template<typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

const int  MOD=1000000007;
const int N=100005;
const int INF = 1e9;

ll n,val[N],dp[N],x[N],y[N],depth[N],parent[N],k,a;
vector< ll > g[N];

void dfs(ll nd,ll pt,ll dep) {
    parent[nd] = pt;
 
    depth[nd] = dep;
    for(ll it:g[nd]) {
        if(it==pt)
            continue;
        dfs(it,nd,dep+1);
       
    }
}

int find_lca(int u,int v)
{
    if (u == v)  return u;
    if (depth[u] > depth[v])
        swap(u, v);
    v = parent[v];
    return find_lca(u,v);
}

int dist(int u,int v)
{
  return depth[u]+depth[v]-2*depth[find_lca(u,v)];
}
void solve() {
    cin>>n>>k>>a;

    for(ll i=1;i<=k;i++)
        cin>>val[i];

    for(int i=0;i<n-1;i++) {
        cin>>x[i]>>y[i];
        g[x[i]].pb(y[i]);
        g[y[i]].pb(x[i]);
    }
    
    dfs(1,-1,0);
    
    for(int i=1;i<=5;i++)
      cout<<depth[i]<<" ";
    cout<<endl;

    cout<<dist(4,3);

    
    for(int i=0;i<N;i++)
        g[i].clear();
}

int main() {

   #ifndef ONLINE_JUDGE
     freopen("input.c","r",stdin);
     freopen("output.c","w",stdout);
    #endif


    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long int t = 1;
    cin >> t;
    for (long int tt = 1; tt <= t; tt++) {
        solve();
    }
    return 0;
}