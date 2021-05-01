#include <cstdio>
#include<bits/stdc++.h>
using namespace std;
#ifdef _MSC_VER
#define GC getchar
#else
#define GC getchar_unlocked
#endif

int main()
{
	int N,i,j,k,d;
	int a[6];
	int m[32];
	int M[32];
	for (i=0; i<32; i++)
	{
		m[i]=1000000000;
		M[i]=-1000000000;
	}
	scanf("%d %d",&N,&d);
	for (i=0; i<N; i++)
	{
		for (j=0; j<d; j++)
			cin>>a[j];//,fix();
		for (j=0; j<1<<(d-1); j++)
		{
			int x=a[0];
			for (k=0; k<d-1; k++)
				if (j&(1<<k))
					x+=a[k+1];
				else
					x-=a[k+1];
			if (m[j]>x)
				m[j]=x;
			if (M[j]<x)
				M[j]=x;
		}
	}
	int ans=0;
	for (i=0; i<1<<(d-1); i++)
		if (ans<M[i]-m[i])
			ans=M[i]-m[i];
	printf("%d\n",ans);
	return 0;
}






-----------
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll w,h,n,m,maxi=INT_MIN,i,mx=0;
    cin>>w>>h>>n>>m;
    ll x[n+1],y[m+1];
    for(i=0;i<n;i++)
    cin>>x[i];
    for(i=0;i<m;i++)
    cin>>y[i];
    map<ll,ll>mp1,mp2;
    ll j,ans=0;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            ll diff=abs(x[i]-x[j]);
            mp1[diff]++;
        }
    }
    for(i=0;i<m;i++)
    {
        for(j=i+1;j<m;j++)
        {
            ll diff=abs(y[i]-y[j]);
            mp2[diff]++;
        }
    }
    for(auto it=mp1.begin();it!=mp1.end();it++)
    {
        if(mp2.find(it->first)!=mp2.end())
        ans++;
    }
    for(i=0;i<=h;i++)
    {
        mx=0;
        for(j=0;j<m;j++)
        {
            if(i!=y[j])
            {
                ll diff=abs(i-y[j]);
                if(mp2.find(diff)==mp2.end())
                {
                    if(mp1.find(diff)!=mp1.end())
                    mx++;
                    maxi=max(mx,maxi);
                }
            }
        }
    }
    ans+=maxi;
    cout<<ans<<endl;
}