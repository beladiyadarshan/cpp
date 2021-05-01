Existence of path solutions-
#include<bits/stdc++.h>
using namespace std;
#define loi long long
#define ll long long
#define lod long double
#define doubel double
#define pb push_back
#define run ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define mod 1000000007
#define lim 5000000000000000000
#define in(ar, n) for(loi i = 0; i < n; i++) cin >> ar[i];
#define out(ar, n) for (loi i = 0; i < n; i++) cout << ar[i] << "\n";
#define rep(i, n) for(loi i = 0; i < n; i++)
#define rep1(i, n) for(loi i = 1; i <= n; i++)
#define rev(i, n) for(loi i = n - 1; ~i; i--)
#define rep3(i, l, r) for(loi i = l; i <= r; i++)
#define rev3(i, r, l) for(loi i = r; i >= l; i--)
#define rep4(i, r, l) for(loi i = r; i >= l; i--)
#define all(x) x.begin(), x.end ()
#define mkp make_pair
#define vii vector<loi>
#define mii map<loi, loi>
#define sii set<loi>
#define pii pair<loi, loi>
#define mxdepth 23 // FOR LCA til N = 1e6
#define mxn 2000001

ll root (ll Arr[ ] ,ll i)
{
    while(Arr[ i ] != i)
    {
        //Arr[ i ] = Arr[ Arr[ i ] ] ; 
i = Arr[ i ]; 
    }
return i;
}

  // to do union  initilize size[] by 1 
void weighted_union(ll Arr[ ],ll size[ ],ll A,ll B)
{
    ll root_A = root(Arr,A);
    ll root_B = root(Arr,B);
    if(size[root_A] < size[root_B ])
    {
Arr[ root_A ] = Arr[root_B];
size[root_B] += size[root_A];
}
    else
    {
Arr[ root_B ] = Arr[root_A];
size[root_A] += size[root_B];
}

}

bool cmp(pair < pii, pii > a, pair < pii, pii > b)
{
  if(a.second.first == b.second.first)
  {
    return (a.second.second == 1);
  }
  return (a.second.first < b.second.first);
}

int main()
{
  run;
  loi t;
  cin >> t;
  while(t--)
  {
    loi n, m, q;
    cin >> n >> m >> q;
    loi arr[n], sz[n];
    
    rep(i, n)
     arr[i] = i, sz[i] = 1;
    
    loi u, v, w;
  
    vector < pair < pii, pii > > events;

    rep(i, m)
    {
      cin >> u >> v >> w;
      u--, v--;
      pair < pii, pii > pp;
      pp = mkp(mkp(u, v), mkp(w, 1));
      events.pb(pp);
    }

    rep(i, q)
    {
      cin >> u >> v >> w;
      u--, v--;
      pair < pii, pii> pp;
      pp = mkp(mkp(u, v), mkp(w, i + 2));
      events.pb(pp);
    }
    
    sort(all(events), cmp);
    
    loi res[q];
    
    rep(i, events.size())
    {
      if(events[i].second.second == 1)
      {
         weighted_union(arr, sz, events[i].first.first, events[i].first.second);
      }

      else
      {
        if(root(arr, events[i].first.first) == root(arr, events[i].first.second))
        {
              res[events[i].second.second - 2] = 1;
        }

        else res[events[i].second.second - 2] = 0;
      }
      
    }
  
    out(res, q);
  }
  return 0;
}