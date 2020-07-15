#include <bits/stdc++.h>
using namespace std;

const int N = 150;

int n, ans;
int a[N], b[N];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++) {
		cin >> b[i];
	}
	for(int i = 1; i <= n; i++) {
		if(a[i] > b[i]) {
			ans += 3;
		} else if(a[i] == b[i]) {
			ans += 1;
		}
	}
	cout << ans << "\n";
	return 0;

}
