 //
   
  //  #can_change_the_world_with_the_help_of_0_1
  //                                  -darshan786
   
  //
 
 
 
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mod 1000000007
#define boost ios_base::sync_with_stdio(false);cin.tie(0); 
#define PI pair<long long ,long long > 
#define ff first 
#define ss second    
#define N 200002
#define MAXN   200002 
#define int long long
#define all(v) v.begin(),v.end()

bool sortbysec(const pair<int,int> &a, 
              const pair<int,int> &b) 
{ 
  if(a.first==b.first)
    return a.second <= b.second;
    return (a.first < b.first); 
} 
  



 
int getMid(int s, int e) 
{ 
  return s + (e - s) / 2; 
} 


int MaxUtil(int* st, int ss, int se, int l, 
      int r, int node) 
{ 
  
  if (l <= ss && r >= se) 
    return st[node]; 

 
  if (se < l || ss > r) 
    return -1; 

 
  int mid = getMid(ss, se); 
  
  return max(MaxUtil(st, ss, mid, l, r, 
          2 * node + 1), 
      MaxUtil(st, mid + 1, se, l, 
          r, 2 * node + 2)); 
} 



int getMax(int* st, int n, int l, int r) 
{ 
  if (l < 0 || r > n - 1 || l > r) 
  { 
   // printf("Invalid Input"); 
    return -1; 
  } 

  return MaxUtil(st, 0, n - 1, l, r, 0); 
} 


int constructSTUtil(int arr[], int ss, int se, int* st, int si) 
{ 
 
  if (ss == se) 
  { 
    st[si] = arr[ss]; 
    return arr[ss]; 
  } 

 
  int mid = getMid(ss, se); 
  
  st[si] = max(constructSTUtil(arr, ss, mid, st, si * 2 + 1), constructSTUtil(arr, mid + 1, se, st, si * 2 + 2)); 
  
  return st[si]; 
} 


int* constructST(int arr[], int n) 
{ 
  int x = (int)(ceil(log2(n))); 

  int max_size = 2 * (int)pow(2, x) - 1; 

  int* st = new int[max_size]; 

  constructSTUtil(arr, 0, n - 1, st, 0); 

  return st; 
} 



 vector<vector<int>> v,v1,v3;
int32_t main()
{
  boost;
  #ifndef ONLINE_JUDGE
   freopen("input.c","r",stdin);
   freopen("output.c","w",stdout);
  #endif
  

   int n,x;
   cin>>n>>x;
   //cout<<n;
   int a[n];
   int parent[n],parent1[n],parent3[n];
   memset(parent,-1,sizeof parent);
   memset(parent1,-1,sizeof parent1);
   for(int i=0;i<n;i++)
   {
    cin>>a[i];
   }

   int b[n];
   for(int i=0;i<n;i++)cin>>b[i];

    int* st = constructST(a, n); 


    stack<int> sc,sc1;

  
   v.resize(n);v1.resize(n);v3.resize(n);
   int val[n],val1[n],val3[n];
   for(int i=0;i<n;i++)val[i]=b[i],val1[i]=b[i];















  for(int i=0;i<n;i++)
  {
      


    if(sc.empty())
    {
      sc.push(i);

    }
    
    else
    {
      while(!sc.empty() && a[i]>=a[sc.top()])sc.pop();
      if(!sc.empty())
      {
        parent[i]=sc.top();
        v[sc.top()].pb(i);
        val[i]=val[i]+val[sc.top()];
      }
      sc.push(i);
    }
  


  }


   for(int i=n-1;i>=0;i--)
  {
      


    if(sc.empty())
    {
      sc.push(i);

    }
    
    else
    {
      while(!sc.empty() && a[i]>=a[sc.top()])sc.pop();
      if(!sc.empty())
      {
        parent1[i]=sc.top();
        val1[i]=val1[i]+val1[sc.top()];

        v1[sc.top()].pb(i);
      }
      sc.push(i);
    }
  


  }
  

  
   stack<int>   tttttt;


   for(int i=n-1;i>=0;i--)
  {
      


    if(tttttt.empty())
    {
      tttttt.push(i);

    }
    
    else
    {
      while(!tttttt.empty() && a[i]>=a[tttttt.top()])tttttt.pop();
      if(!tttttt.empty())
      {
        parent3[i]=tttttt.top();
        val3[i]=val3[i]+val3[tttttt.top()];

        v3[tttttt.top()].pb(i);
      }
      tttttt.push(i);
    }
  


  }

  while(!tttttt.empty())
    tttttt.pop();
   for(int i=n-1;i>=0;i--)
  {
      


    if(tttttt.empty())
    {
      tttttt.push(i);

    }
    
    else
    {
      while(!tttttt.empty() && a[i]>=a[tttttt.top()])tttttt.pop();
      if(!tttttt.empty())
      {
        parent3[i]=tttttt.top();
        val3[i]=val3[i]+val3[tttttt.top()];

        v3[tttttt.top()].pb(i);
      }
      tttttt.push(i);
    }
  


  }

  while(!tttttt.empty())
    tttttt.pop();




    int aa,bb,cc;

    while(x--)
    {
      cin>>aa>>bb>>cc;
      int zz;
      if(bb<cc)
       { 

          zz=getMax(st, n, bb, cc-2);
         // cout<<zz<<endl;
          if(zz>=a[bb-1] )
          {
            cout<<-1<<endl;
          }
          else
          {
            if(parent[bb-1]==-1)
            cout<<val[cc-1]<<endl;
            else
              cout<<val[cc-1]-val[parent[bb-1]]<<endl;
          }


       }
      else
      {
        zz=getMax(st, n, cc, bb-2);
       // cout<<zz<<endl;
        if(zz>=a[bb-1])
        {
          cout<<-1<<endl;
        }
        else
        {
         // cout<<parent1[bb-1]<<endl;

          if(parent1[bb-1]==-1)
            cout<<val1[cc-1]<<endl;
          else
            cout<<val1[cc-1]-val1[parent1[bb-1]]<<endl;
        }
      }
      
     



    }
 

}
        
      
    




//