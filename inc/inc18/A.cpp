#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int n;
int ar[N], pre[N], pre2[N];
int a, b;
string da, db;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> ar[i];
		pre[i] = pre[i - 1] + ar[i];
		pre2[i] = pre2[i - 1] + (ar[i] == 0);
	}
	cin >> a >> da;
	cin >> b >> db;
	int ans, ans2;
	if(da == "left") {
		ans = pre[a];
	} else if(da == "right") {
		ans = pre[n] - pre[a - 1];
	}
	if(db == "left") {
		ans2 = pre2[b];
	} else if(db == "right") {
		ans2 = pre2[n] - pre2[b - 1];
	}

	cout << ans << " " << ans2 << "\n";
	return 0;
}
