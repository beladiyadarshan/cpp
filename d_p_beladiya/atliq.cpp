/*

Given the mapping a = 1, b = 2, ... z = 26, and an encoded message, count the number of ways it can be decoded.
For example, the message '111' would give 3, since it could be decoded as 'aaa', 'ka', and 'ak'.
*/

#include<bits/stdc++.h>
using namespace std;


int main()
{

	#ifndef ONLINE_JUDGE
     freopen("input.c","r",stdin);
     freopen("output.txt","w",stdout);
    #endif


	

	string s;
	cin>>s;

	int dp[s.size()+1];
	memset(dp,0,sizeof 0);

	dp[0]=1;
	dp[1]=(s[0]=='0')?0:1;

	for(int i=2;i<=s.size();i++)
	{
		int temp=s[i-1]-'0';
		if(temp>=1  && temp<=9)
			dp[i]=dp[i-1];

		string temp1=s.substr(i-2,2);

		int val=(temp1[0]-'0')*10+(temp1[1]-'0');

		if(val<=26 && val>=10 )
			dp[i]+=dp[i-2];
	}

	cout<<dp[s.size()]<<endl;





}