#include <bits/stdc++.h>
using namespace std;

int n;
int ar[2];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for(int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		ar[x & 1]++;
	}

	int ans = min(ar[0], ar[1]);
	if(ar[1] > ar[0]) {
		ans += (ar[1] - ar[0]) / 2;
	}
	cout << ans << "\n";
	return 0;
}