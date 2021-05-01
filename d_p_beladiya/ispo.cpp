long long c[20][20];
long long fact[20];
int n;
cin>>N;
	fact[0] = 1;
	for (int n = 1; n < 20; n++) {
		fact[n] = fact[n - 1] * n;
	}
	for (int n = 0; n < 20; n++) {
		c[n][0] = 1;
		c[0][n] = 1;
	}
	for (int i = 1; i < 20; i++) {
