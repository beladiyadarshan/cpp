#include<bits/stdc++.h>
using namespace std;

int main() {

     #ifndef ONLINE_JUDGE
     freopen("input.c","r",stdin);
     freopen("output.c","w",stdout);
    #endif
     int t;
     cin>>t;

     while(t--)
     {
        int n,k;
        cin>>n>>k;
        int ans=0;

        if(n<k)
            ans=k-n;
        if(n>k)
        {
            if(n&1)
            {
                if(k&1==0)
                    ans=1;
            }
            else
            {
                if(k&1)ans=1;
            }

        }


        cout<<ans<<endl;
     }


   
}


   