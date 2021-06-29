#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long


int32_t main() {

   #ifndef ONLINE_JUDGE
     freopen("input.c","r",stdin);
     freopen("output.txt","w",stdout);
    #endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int test;
  cin >> test;

  while (test--) {
    int n;
    cin>>n;
   vector<int> a(n),d(n),pre(n);

   for(auto &i:a){cin>>i;}

    for(int i=0;i<n;i++)pre[i]=a[i];
    for(auto &i:d)cin>>i;


    int ans=INT_MIN;

    for(int i=0;i<n;i++)
    {
      
      if((i+d[i])<n)
      {
        
      
      pre[i+d[i]]-=a[i];
    }
    }  

    for(int i=0;i<n;i++)
    {
      if(i>0)
        pre[i]+=pre[i-1];
     
      ans=max(ans,pre[i]);
    }

    cout<<ans<<endl;

  }  

  return 0;
  
 
}
 