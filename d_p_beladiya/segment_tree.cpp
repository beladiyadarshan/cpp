
#include<bits/stdc++.h>
using namespace std;

int tree[411111];
void built(int x,int l,int r,vector<int> ve)
{
    if(l==r)
    {
        tree[x]=ve[l];
        return;
    }
    int m=(l+r)/2;
    built(2*x,l,m,ve);
    built(2*x+1,m+1,r,ve);
    tree[x]=(tree[2*x]+tree[2*x+1]);
}
void update(int x,int l,int r,int p,int v)
{
    if(l>p || r<p)
        return;
    if(l==r)
    {
        tree[x]=v;
        return;
    }
    int m=(l+r)/2;
    update(2*x,l,m,p,v);
    update(2*x+1,m+1,r,p,v);
    tree[x]=(tree[2*x]+tree[2*x+1]);
}
int query(int x,int s,int e,int l,int r)
{
    if(s>r || e<l || s>e)
        return 0;
    if(l<=s && r>=e)
        return tree[x];
    int m=(s+e)/2;
    int p=query(2*x,s,m,l,r);
    int q=query(2*x+1,m+1,e,l,r);
    return (p+q);
}


int main()
{


    #ifndef ONLINE_JUDGE
     freopen("input.c","r",stdin);
     freopen("output.c","w",stdout);
    #endif
    

    vector<int> ve={1,2,3,4,5,6,7,8,9};
    int n=ve.size();

    memset(tree,0,sizeof tree);
    built(1,0,n-1,ve);//array index from 0,n-1 and tree index from 1,2*n-1

    for(int i=1;i<18;i++)
    {
        cout<<tree[i]<<" ";
    }
    cout<<endl;
    update(1,0,n-1,0,10);//updte in tree ve[0] to 10

    for(int i=1;i<18;i++)
    {
        cout<<tree[i]<<" ";
    }
    cout<<endl;
    cout<<query(1,0,n-1,0,0);//sum of array ele. 0...0

    return 0;

}













