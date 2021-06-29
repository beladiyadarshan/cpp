#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define int long long

bool cmp(pair<int,pair<int,int>> a,pair<int,pair<int,int>> b)
{
   if(a.first>b.first)
   return true;
   return false;
}
int find(vector<vector<int>> &A)
{
   vector<pair<int,pair<int,int>>> v;

   for(int i=0;i<A.size();i++)
      for(int j=0;j<A[i].size();j++)
         v.push_back({A[i][j],{i,j}});

   sort(v.begin(),v.end(),cmp);
   
   int ans=INT_MIN;
   for(int i=0;i<v.size()-1;i++)
   {
      
      int j=i+1;
      while(j<v.size())
      {
         if(v[i].second.first!=v[j].second.first && v[i].second.second!=v[j].second.second)
         {
            // cout<<v[i].first<<" "<<v[j].first<<endl;
            ans=max(ans,v[i].first+v[j].first);
            break;
         }
         j++;
      }
   }


   return ans;
}
int32_t main() {

   #ifndef ONLINE_JUDGE
     freopen("input.c","r",stdin);
     freopen("output.txt","w",stdout);
    #endif
  
   vector<vector<int>> A={
      {15,1,5},{16,3,8},{2,6,4}
   };

   cout<<find(A); 
  return 0;
}