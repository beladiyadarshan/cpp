// phi(p^x)=p^x-p^(x-1)

void phi_1_to_n(int n) {
    vector<int> phi(n + 1);
    phi[0] = 0;
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
        phi[i] = i;

    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
}

////////

Biggest Prime Divisor Sieve O(n log log n)

int big[n + 1] = {1, 1};

for (int i = 1; i <= n; ++i)
 if (big[i] == 1)
  for (int j = i; j <= n; j += i)
   big[j] = i;