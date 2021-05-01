

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
#define mod 1000000007
#define boost ios_base::sync_with_stdio(false);cin.tie(0); 
#define ff first 
#define MAXN   1010
#define int long long
#define ss second
#define all(v) v.begin(),v.end() 
#define PI pair<int,int>
#define PIS pair<int,string>
#define pb push_back




int values[41];
   
void value()
{
   values[0]=1;
    for(int i=1;i<=40;i++)
    {
        values[i]=2*values[i-1];
    }
}

void fake()
{
  vector<int> v;
  for(int i=0;i<1000;i++)v.pb(1000-i);

    sort(all(v));
}

void print(int x)
{
  cout<<"Case #"<<x<<": ";
}
int32_t main() {
	  
   #ifndef ONLINE_JUDGE
     freopen("input.c","r",stdin);
     freopen("outpu.txt","w",stdout);
    #endif
     int x;
     cin>>x;

     for(int kk=1;kk<=x;kk++)
     {
      print(kk);
        
        int s,xa,ya,xb,yb,c,x,y;
		cin>>s>>xa>>ya>>xb>>yb>>c;

		int i,j;

		map<PI,vector<PI>>g;
		map<PI,int> under;
		for(int y=0;y<c;y++)
		{
			cin>>x>>y;
			under[{x-1,y-1}]=1;
		}
		for(i=1;i<=s;i++){
			int nodes=2*i-1;
			for(j=0;j<nodes;j++){
				if(under[{i-1,j}]==1)
					continue;

				//up
				if(j%2 && j>0 && under[{i-2,j-1}]==0)
					g[{i-1,j}].pb({i-2,j-1});
				
				//down
				if(j%2==0 && j<s && under[{i,j+1}]==0)
					g[{i-1,j}].pb({i,j+1});
				
				//left
				if(j>0 && under[{i-1,j-1}]==0)
					g[{i-1,j}].pb({i-1,j-1});
				//right
				if(j<nodes-1 && under[{i-1,j+1}]==0)
					g[{i-1,j}].pb({i-1,j+1});
				
				
			}
		}
		for(auto it : g){
			cout<<it.first.first<<" "<<it.first.second<<"  -   ";
			for(auto i:it.second){
				cout<<i.first<<","<<i.second<<" ";
			}
			cout<<endl;
		}
     }
   
     


      
  }


