#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp  make_pair
#define pb push_back
#define mod 1000000007
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

#ifndef ONLINE_JUDGE
   freopen("input.c","r",stdin);
   freopen("output.c","w",stdout);
  #endif
int T;
cin>>T;
while(T--){
int n;
cin>>n;
vector<int>a(n);
for(int i=0;i<n;i++)cin>>a[i];
set<int>all;
set<int>d;
map<int,int> m;
m[a[0]]++;
d.insert(a[0]);
int f=0;
for(int i=1;i<n;i++){
    set<int>d1;
    for(auto j:d){d1.insert(a[i]|j);all.insert(a[i]|j);}
    d=d1;
    d.insert(a[i]);
   	if(m[a[i]]!=0)
   	{
   		f=1;break;
   	}
   	m[a[i]]++;
}

if(f==0)
	cout<<"YES"<<endl;
else
	cout<<"NO"<<endl;

}

return 0;}

