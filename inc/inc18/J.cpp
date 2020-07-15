#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 69;

int n, m;
int ar[N];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> ar[i];
	}
	sort(ar + 1, ar + n + 1);

	long long mn = 0;
	for(int i = 1; i <= m; i++) {
		mn = mn + 1LL * ar[i];
	}

	int x = n / m, y = n % m;
	long long mx = 0;
	for(int i = 0; i < y; i++) {
		mx = mx + 1LL * ar[i * (x + 1) + 1];
	}
	for(int i = y; i < m; i++) {
		mx = mx + 1LL * ar[i * x + y + 1];
	}

	cout << mn << " " << mx << "\n";

}
