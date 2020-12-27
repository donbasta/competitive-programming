#include <bits/stdc++.h>
using namespace std;

long long sumLSB(long long n) {
	long long cost = 0;
	long long poww = 1;
	long long cur = n;
	while(cur > 0) {
		cost += poww * (cur - cur / 2);
		poww *= 2;
		cur = cur / 2;
	}
	return cost;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int tc;
	cin >> tc;
	while(tc--) {
		long long n;
		cin >> n;
		if((n & (n - 1)) == 0) {
			cout << -1 << "\n";
		} else {
			cout << sumLSB(n) - 1 << "\n";
		}
	}
	return 0;

}
