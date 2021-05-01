/*
	Given an unordered list of flights taken by someone, each represented as (origin, destination) pairs, and a starting airport, compute the person's itinerary. If no such itinerary exists, return null. If there are multiple possible itineraries, return the lexicographically smallest one. All flights must be used in the itinerary.
For example, given the list of flights [('SFO', 'HKO'), ('YYZ', 'SFO'), ('YUL', 'YYZ'), ('HKO', 'ORD')] and starting airport 'YUL', you should return the list ['YUL', 'YYZ', 'SFO', 'HKO', 'ORD'].
Given the list of flights [('SFO', 'COM'), ('COM', 'YYZ')] and starting airport 'COM', you should return null.
Given the list of flights [('A', 'B'), ('A', 'C'), ('B', 'C'), ('C', 'A')] and starting airport 'A', you should return the list ['A', 'B', 'C', 'A', 'C'] even though ['A', 'C', 'A', 'B', 'C'] is also a valid itinerary. However, the first one is lexicographically smaller.
*/
#include<bits/stdc++.h>
using namespace std;
#define PI pair<int,int> 
#define pb push_back
#define int long long
map<string,multiset<string>> ticket;

vector<string> jawab;

 void dfs(string source)
 {
 	auto &cur=ticket[source];
   
 	while(!ticket[source].empty())
 	{
 	    
 		string temp=*ticket[source].begin();
 		ticket[source].erase(ticket[source].begin());
 		dfs(temp);
 	}
    
 	jawab.pb(source);
 }
int32_t main()
{


     jawab.clear();
     ticket.clear();
     int n;
     cin>>n;
    
	for(int i=0;i<n;i++)
	{
		string s1,s2;
		cin>>s1>>s2;

		ticket[s1].insert(s2);



	}
	dfs("a");
	

	if(jawab.size()!=n+1)
	{
		cout<<0<<endl;
	}   
    else
    {
	for(int i=jawab.size()-1;i>=0;i--)cout<<jawab[i]<<" ";
	}	
    


		

}