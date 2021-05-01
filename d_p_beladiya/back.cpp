
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
#define all(v) v.begin(),v.end() 
#define PI pair<int,int>
#define PIS pair<int,string>





int values[41];
   
void value()
{
   values[0]=1;
    for(int i=1;i<=40;i++)
    {
        values[i]=2*values[i-1];
    }
}
void print(int x)
{
  cout<<"Case #"<<x<<": ";
}

int32_t main() {
	// your code goes here
	int x;
     cin>>x;

     for(int i=1;i<=x;i++)
     {
     	value();
      print(i);
            
    
     
     int w,n;
     cin>>w>>n;
     int a[w];
     for(int i=0;i<w;i++)cin>>a[i];

     	sort(a,a+n);
     int mid=w/2;
     int c=0;
     for(int i=0;i<w;i++)
     {
     	if(mid!=i)
     		c+=abs(a[i]-a[mid]);
     }

     cout<<c<<endl;

	}
	return 0;
}