#include<bits/stdc++.h>
using namespace std;
#define pb push_back
vector<int> g[100001];
vector<int> rev[100001];
int vis[100001];
vector<int> order,reverse_order;
void dfs1(int u)
{
    vis[u]=1;
    for(auto i:g[u])
        if(!vis[i])
            dfs1(i);
    order.pb(u);
}

void dfs2(int u)
{
    vis[u]=1;
    reverse_order.pb(u);
    for(auto i:rev[u])
        if(!vis[i])
            dfs2(i);
}
//your main function
vector<int> pw(int n,int m,vector<vector<int>> graph)
{
  order.clear();
  reverse_order.clear();
  memset(vis,0,sizeof vis);
  for(int i=0;i<=100000;i++)
  {
    g[i].clear();
    rev[i].clear();
  }
  for(auto i:graph)
  {
    g[i[0]].pb(i[1]);
    rev[i[1]].pb(i[0]);
  }
  for(int i=1;i<=n;i++)
        if(!vis[i])
            dfs1(i);
  memset(vis,0,sizeof vis);
  vector<int> ans(n,0);
  for(int i=order.size()-1;i>=0;i--)
  {
    cout<<order[i];
        int v = order[i];
        if(!vis[v])
        {
            dfs2(v);
            for(auto ii:reverse_order)
              cout<<ii;
            if(reverse_order.size()>1)
                for(auto &it:reverse_order)
                    ans[it-1]=1;
            reverse_order.clear();
        }
  }

  return ans;
}

int main()
{
  #ifndef ONLINE_JUDGE
     freopen("input.c","r",stdin);
     freopen("output.txt","w",stdout);
    #endif
  vector<int> ans=pw(2,1,{{1,2}});

  for(auto i:ans)
    cout<<i<<" ";

+