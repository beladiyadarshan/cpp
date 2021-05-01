#include<iostream> 
using namespace std; 
  
int maxsum(int a[], int size) 
{ 
    int ma = INT_MIN, cur = 0, 
       start =0, end = 0, s=0; 
  
    for (int i=0; i< size; i++ ) 
    { 
        cur += a[i]; 
  
        if (ma < cur) 
        { 
            ma = cur; 
            start = s; 
            end = i; 
        } 
  
        if (cur < 0) 
        { 
            cur = 0; 
            s = i + 1; 
        } 
    } 
    cout << "Maximum contiguous sum is "
        << ma << endl; 
    cout << "Starting index "<< start << endl << "Ending index "<< end << endl; 
} 
  
  
/* Driver program to test maxSubArraySum */
int main() 
{ 

   #ifndef ONLINE_JUDGE
     freopen("input.c","r",stdin);
     freopen("output.c","w",stdout);
    #endif

   int a[] =  {-2, -3, 4, -1, -2, 1, 5, -3}; 
   int n = sizeof(a)/sizeof(a[0]); 
   int max_sum = maxsum(a, n); 
   cout << "Maximum contiguous sum is " << max_sum; 
   return 0; 
} 