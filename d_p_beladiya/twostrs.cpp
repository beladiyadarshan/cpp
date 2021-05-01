//#pragma GCC optimize "trapv"
#include <bits/stdc++.h>
#define int int64_t
#define SZ 200005
#define pb push_back
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

//https://www.geeksforgeeks.org/frequency-substring-string/


void computeLPSArray(string pat, int M, int lps[]) 
{ 
	int len = 0; 
	int i = 1; 
	lps[0] = 0;
	while (i < M) { 
		if (pat[i] == pat[len]) { 
			len++; 
			lps[i] = len; 
			i++; 
		}
		else{ 
			if (len != 0) { 
				len = lps[len-1];
			} 
			else{ 
				lps[i] = len; 
				i++; 
			} 
		} 
	}
}

int KMPSearch(string &pat, string &txt) 
{ 
	int M = pat.length(); 
	int N = txt.length(); 
	int lps[M];
	int j = 0;
	computeLPSArray(pat,M,lps); 
	int i = 0;
	int res = 0;  
	int next_i = 0;   
	while (i < N) { 
		if (pat[j] == txt[i]){ 
			j++; 
			i++; 
		} 
		if (j == M){
			j = lps[j-1]; 
			res++;
			/*
			if (lps[j]!=0) 
				i = ++next_i; 
			j = 0; 
			*/
		} 
		else if (i < N && pat[j] != txt[i]) 
		{ 
			if (j != 0) 
				j = lps[j-1]; 
			else
				i = i+1; 
		} 
	} 
	return res; 
} 

/*
int countFreq(string &pat, string &txt) 
{ 
	int M = pat.length(); 
	int N = txt.length(); 
	int res = 0; 
	for (int i = 0; i <= N - M; i++) 
	{ 
		int j; 
		for (j = 0; j < M; j++) 
			if (txt[i+j] != pat[j]) 
				break; 
		if (j == M) 
		{ 
		res++; 
		j = 0; 
		} 
	} 
	return res; 
} 

int KMPSearch(string &pat, string &txt) 
{
	return countFreq(pat,txt);
}*/

int32_t main()
{
	/*
	string pat,txt;
	txt="techechef";
	pat="eche";
	int ans;
	ans=KMPSearch(pat,txt);
	cout<<ans<<"\n";
	*/
	
	fastio;
	int t=1,n,i,j,p;
	cin>>t;
	while (t--)
	{
		string in1,in2,conc;
		cin>>in1>>in2>>n;
		string favstr[n];
		int beauty[n];

		for(i=0;i<n;i++)
		{
			cin>>favstr[i]>>beauty[i];
		}
		int ans=0,tempans;//have to maximize it
		
		//special case 1: conc is only in1
		tempans=0;
		conc=in1;
		for(i=0;i<n;i++)
		{
			int cnt=KMPSearch(favstr[i],conc);
			tempans+=cnt*beauty[i];
		}
		ans=max(ans,tempans);


		//special case 2: conc is only in2
		tempans=0;
		conc=in2;
		for(i=0;i<n;i++)
		{
			int cnt=KMPSearch(favstr[i],conc);
			tempans+=cnt*beauty[i];
		}
		ans=max(ans,tempans);


		//remaining cases

		i=0;//in1 end   index
		j=0;//in2 start index

		for(i=0;i<in1.size();i++)
		{
			for(j=0;j<in2.size();j++)
			{
				conc=in1.substr(0,i+1)+in2.substr(in2.size()-1-j,j+1);
				tempans=0;
				for(p=0;p<n;p++)
				{
					int cnt=KMPSearch(favstr[p],conc);
					tempans+=cnt*beauty[p];
				}
				ans=max(ans,tempans);
			}
		}

		cout<<ans<<"\n";
	}
	
	return 0;
}

/*
	cin>>n;
	int a[n];
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}

	string s;
	cin>>s;

	ifstream cin("input.txt");
	ofstream cout("output.txt");
*/