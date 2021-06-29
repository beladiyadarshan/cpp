 /*
Given an array of strictly the characters 'R', 'G', and 'B', segregate the values of the array so that all the Rs come first, the Gs come second, and the Bs come last. You can only swap elements of the array.
Do this in linear time and in-place.
For example, given the array ['G', 'B', 'R', 'R', 'B', 'R', 'G'], it should become ['R', 'R', 'R', 'G', 'G', 'B', 'B'].

*/
#include<bits/stdc++.h>
using namespace std;
#define PI pair<int,int> 
#define pb push_back
#define int long long

int32_t main()
{


    
   
    
	char a[]={'G', 'B', 'R', 'R', 'B', 'R', 'G'};
	
	int n=sizeof(a)/sizeof(a[0]);
	   
	
    int l=0;
    int h=n-1;
    int mid=0;
    
    while(mid<=h)
    {
        if(a[mid]=='R')
        {
            swap(a[l++],a[mid++]);
        }
        else if(a[mid]=='G')
        {
            mid++;
            continue;
        }
        else if(a[mid]=='B')
        {
            swap(a[mid],a[h--]);
        }
    }
    
    for(int i=0;i<n;i++)cout<<a[i]<<" ";


		

}