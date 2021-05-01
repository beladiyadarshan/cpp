#include <bits/stdc++.h> 
#define int long long
using namespace std; 
#define MAX 200005
#define MOD 1000000007
std::vector<int> tree[MAX];
int childs[MAX];
std::vector<int> contr;
int n;
void dfs(int u,int par = -1)
{
    if(tree[u].size() == 1 && u != 1)
    {
        childs[u]=1;
        return;
    }
    for(auto ch : tree[u])
    {
        if(ch!=par)
        {
            dfs(ch,u);
            childs[u]+=childs[ch];
            contr.push_back(childs[ch]*(n-childs[ch]));
        }
    }
    childs[u]++;
}
void solve()
{
    contr.clear();
    cin>>n;
    for (int i = 0; i <= n; ++i)
    {
        childs[i]=0;
        tree[i].clear();
    }
    for (int i = 0; i < n-1; ++i)
    {
        int x,y;
        cin>>x>>y;
        tree[x].push_back(y);
        tree[y].push_back(x);
        
    }
    int m;
    cin>>m;
    int p[m];
    for (int i = 0; i < m; ++i)
        cin>>p[i];
    
    sort(p,p+m);
    dfs(1);
    int ans = 0;
    sort(contr.begin(), contr.end());
    if(m <= n-1)
    {
        for (int i = 0; i < n-1-m; ++i)
        {
            ans = (ans + contr[i])%MOD;
        }
        for (int i = n-1-m; i < n-1; ++i)
        {
            ans = (ans + (contr[i]*p[i-(n-1-m)])%MOD)%MOD;
        }
    }
    else
    {
        for (int i = 0; i < n-2; ++i)
        {
            ans = (ans + (contr[i]*p[i])%MOD)%MOD;
        }
        int x = 1;
        int i = n-2;
        while(i < m)
        {
            x = (x*p[i])%MOD;
            i++;
        }
        ans = (ans + (contr[n-2]*x)%MOD)%MOD;
    }
    cout<<ans<<endl;
}
    
int32_t main() 
{ 
    #ifndef ONLINE_JUDGE
     freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);
    #endif
   
    int t;
    cin>>t;

    while(t--)
    {
        solve();
    }
}
