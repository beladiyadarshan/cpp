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
#define F first 
#define MAXN   1010
#define int long long
#define S second
#define all(v) v.begin(),v.end() 
#define PI pair<int,int>
#define PIS pair<int,inpring>





int values[41];
   
void value()
{
   values[0]=1;
    for(int i=1;i<=40;i++)
    {
        values[i]=2*values[i-1];
    }
}

void print()
{
  vector<int> v;
  for(int i=0;i<1000;i++)
    v.pb(i);


  reverse(all(v));sort(all(v));
}
int32_t main() {

    boost
     #ifndef ONLINE_JUDGE
     freopen("input.c","r",stdin);
     freopen("outpu.txt","w",stdout);
    #endif

    

    // print();
    // value();

    int t;
    cin >> t;

    while(t--) {

    int n;
    cin>>n;
    string s;
    cin>>s;
   
    cpout<<s<<endl;
 

      

    }
}
 