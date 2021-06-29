
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
#define mod 1000000007
#define boost ios_base::sync_with_stdio(false);cin.tie(0); 
#define pb push_back
#define ff first
#define ss second
#define MAX_SIZE 2000001
#define PI pair<int,int>

vector<int> isprime(MAX_SIZE , true);
vector<int>prime;
vector<int> SPF(MAX_SIZE);
vector<int> divs;
vector<PI> arr;
void manipulated_seive(int N)
{
    isprime[0] = isprime[1] = false ;
  
    for (int i=2; i<N ; i++)
    {
       
        if (isprime[i])
        {
            prime.push_back(i);
            SPF[i] = i;
        }
  

        for (int j=0;j < (int)prime.size() &&i*prime[j] < N && prime[j] <= SPF[i];j++)
        {
            isprime[i*prime[j]]=false;
            SPF[i*prime[j]] = prime[j] ;
        }
    }
}


void find_div(int ind, int divi)
{
	cout<<ind<<" "<<divi<<endl;
    if (ind == arr.size()) {
    	cout<<endl;
        divs.push_back(divi);
        return;
    }

    for (int i = 0; i <=arr[ind].ff; ++i) {
        find_div(ind + 1, divi);
        divi =divi* arr[ind].ss;
    }
}

void findDivisors(int n)
{
    int i=0;
    int temp=prime[i];
    for (; temp*temp <= n; temp=prime[++i]) {
        if (n % temp == 0) {
            int count = 0;
            while (n % temp == 0) {
                n = n/temp;
                count++;
            }
            arr.pb( {count, temp} );
        }
    }


    if (n > 1) {
        arr.pb( {1, n });
    }

    for(auto i:arr)
    	cout<<i.ff<<" "<<i.ss<<endl;

    find_div(0, 1);
}



int32_t main()
{
    boost

    manipulated_seive(MAX_SIZE);	
    vector<int> output;

    arr.clear();
    divs.clear();
   	findDivisors(20);

   	for(auto i:divs)cout<<i<<" ";


}