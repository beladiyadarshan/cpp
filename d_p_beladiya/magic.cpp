 
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
      #define PI pair<long long ,long long > 
      #define ff first 
      #define MAXN   200002
      #define int long long
      #define ss second
      #define aint(v) v.begin(),v.end() 
    



      int32_t main()
      {

            ios_base::sync_with_stdio(false);
            cin.tie(0);
            #ifndef ONLINE_JUDGE
             freopen("input.c","r",stdin);
             freopen("output.txt","w",stdout);
            #endif
                 


          
          
         int t;
         cin>>t;

         while(t--)
         {
            
           string s,p;
           cin>>s>>p;

           map<char,int> m,ori;
           for(int i=0;i<p.size();i++)
           {
            m[p[i]]=1;
            ori[p[i]]--;
           }
            
           int f=0;
            for(int i=0;i<s.size();i++)ori[s[i]]++;


                for(auto i:ori)
                {
                    if(i.ff>=p[0] && f==0)
                        f=1;
                   for(int j=0;j<i.second;j++)
                    cout<<i.ff;

                    if(f==1)
                        {cout<<p;f=2;}

                }

                cout<<endl;

        }
            
    }
        



       