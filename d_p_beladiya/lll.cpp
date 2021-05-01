

    
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


vector<int> v[100001];



set<int>  bfs(int emp)
{
  set<int> st;
      queue<int> q;
      
        int iemp = emp;
        q.push(iemp);
        st.insert(iemp);
        
        while(!q.empty())
        {
            int emp1 = q.front();
          

            q.pop();
            for(auto i=v[emp1].begin();i!=v[emp1].end();i++)
            {
                if(st.find(*i)==st.end())
                {
                    q.push(*i);
                    st.insert(*i);
                }
            }
        }
        return st;
}


int find(int n,int s)
{
  int x=n,ss=0;

  while(x>0)
  {
    ss+=(x%10);
    x/=10;
  }

    

  if(ss<=s)
  {
    return 0;
  }
 
  string temp=to_string(n);
  
  ss=0;
  for(int i=0;i<temp.size();i++)
  {
    ss+=(temp[i]-'0');
    if(ss>=s)
    {
      for(int j=i;j<temp.size();j++)
      {
        temp[j]='0';
      }
   
    
    
      if(i==0)
      {
        temp="1"+temp;
        break;
      }
      for(int j=i-1;j<=i-1;j--)
      {
        if(temp[j]=='9')
        {
            temp[j]='0';
          if(j==0)
            temp="1"+temp;
          continue;
        }
        temp[j]++;

        break;
      }
      break;
    }
  }


  int ans=stoll(temp)-n;

 
  return ans;
  
}

int32_t main() {

  boost
  
    #ifndef ONLINE_JUDGE
     freopen("input.c","r",stdin);
     freopen("output.c","w",stdout);
    #endif
    
   
    
    
   int t;cin>>t;

   while(t--)
   {
   
    int n,s;
    cin>>n>>s;

    int ans=find(n,s);

    cout<<ans<<endl;
   }

  
}