void pre()
{
    fact[0]=1;
    for(int i=1;i<MAXN;i++)
        fact[i]=(fact[i-1]*i)%(mod);


    naturals[0] = naturals[1] = 1; 
    for (int i = 2; i <= MAXN; i++) 
        naturals[i] = naturals[mod % i] * (mod - mod / i) % mod; 

    facinverse[0] = facinverse[1] = 1; 

    // precompute inverse of natural numbers 
    for (int i = 2; i < MAXN; i++) 
        facinverse[i] = (naturals[i] * facinverse[i - 1]) % mod; 
}

int ncr(int N, int R) 
{ 
    int jawab = ((fact[N] * facinverse[R]) % mod * facinverse[N - R]) % mod; 
    return jawab; 
}


