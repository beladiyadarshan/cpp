#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mod 1000000007
#define boost ios_base::sync_with_stdio(false);cin.tie(0); 
#define ff first 
#define MAXN   1010
#define int long long
#define ss second
#define aint(v) v.begin(),v.end() 
#define PI pair<int,int>
#define all(v) v.begin(),v.end()


class trie{
   public:
    trie* left;
     trie* right;
    
};

void insert(int n,trie*head)
{
    trie* cur=head;
    for(int i=31;i>=0;i--)
    {
        int b=(n>>i)&1;
        if(b==0)
        {
            if(cur->left == NULL)cur->left=new trie();
            cur=cur->left;
        }
        else
        {
            if(cur->right == NULL)cur->right=new trie();
            cur=cur->right;
        }
        
    }
}

int findmax(trie* head,vector<int> &arr)
{
   int maxx=INT_MIN;

    for(auto i:arr)
    {
        trie* cur=head;
        int xoo=0;
        for(int j=31;j>=0;j--)
        {
            int b=(i>>j)&1;
            
            if(b==0)
            {
                
                if(cur->right)
                {
                    xoo+=pow(2,j);
                    cur=cur->right;
                }
                else
                    cur=cur->left;
            }
            else
            {
                if(cur->left)
                {
                    xoo+=pow(2,j);
                    cur=cur->left;
                }
                else
                    cur=cur->right;
            }
        }
        
        maxx=max(maxx,xoo);
    }
    
    return maxx;
    
}
   

int32_t main() {




    #ifndef ONLINE_JUDGE
     freopen("input.c","r",stdin);
     freopen("output.c","w",stdout);
    #endif



     vector<int> nums={3,10,5,25,2,8};

      trie* head=new trie();
        for(auto i:nums)
        {
            insert(i,head);
        }
        
        
        cout<< findmax(head,nums);


 
    




  
    }
 