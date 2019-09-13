}
long long inv(long long x) { return qpow(x, MOD - 2); }

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	const int mod = 1e9+7;
	while(cin >> n) {
		vector<int> a(n);
		for (int i=0; i<n; i++){
			cin >> a[i];
		}

		int sum = 0;
		for (int i=0; i<n; i++){
			int now = a[i];