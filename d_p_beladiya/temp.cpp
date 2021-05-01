#include<bits/stdc++.h>
using  namespace std;
#define PI pair<int,int>
#define ff first
#define ss second

bool comp(PI a,PI b)
{
	if(a.ff>b.ff)
		return true;
	return false;
}
int main()
{

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.c","w",stdout);
	#endif

	int t;
	cin>>t;

	while(t--)
	{
	
	int N, M; cin >> N >> M;
    map<int,int> cnt;
    for(int i=0;i<N;i++) {
        int X; cin >> X; cnt[X%M]++;
    }
    int ans = 0;
    if (cnt[0]) ans++;
    if (M%2==0 && cnt[M/2]) ans++;
    for(int i=1;i<(M+1)/2;i++){
        int X = min(cnt[i], cnt[M-i]), Y = max(cnt[i], cnt[M-i]);
        if (Y == 0) continue;
        ans += max(1, Y-X);
    }
    cout << ans << endl;
	}

	return 0;
}