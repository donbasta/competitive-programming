#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int N = 1e5 + 69;

long long pre[N];
long long poww[N];

// vector<int> prefix_function(string s) {
//     int n = (int)s.length();
//     vector<int> pi(n);
//     for (int i = 1; i < n; i++) {
//         int j = pi[i-1];
//         while (j > 0 && s[i] != s[j])
//             j = pi[j-1];
//         if (s[i] == s[j])
//             j++;
//         pi[i] = j;
//     }
//     return pi;
// }

long long getHash(int a, int b) {
	long long res = pre[b] - pre[a - 1] * poww[b - a + 1];
	res %= MOD;
	if(res < 0)
		res += MOD;
	return res;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int tc;
	cin >> tc;

	poww[0] = 1;
	for(int i = 1; i <= 100000; i++) {
		poww[i] = poww[i - 1] * 31 % MOD;
	}

	while(tc--) {
		string tete;
		cin >> tete;
		int n = (int) tete.length();
		// vector<int> lol = prefix_function(tete);
		for(int i = 0; i < n; i++) {
			pre[i + 1] = pre[i] * 31 + 1LL * (tete[i] - 'a');
			pre[i + 1] %= MOD;
		}
		int ans = 0;
		for(int i = 0; i < n; i++) {
			if(2 * i + 4 > n)
				break;
			bool ok = true;
			ok &= (getHash(1, i + 1) == getHash(i + 2, 2 * i + 2));
			// cerr << getHash(1, i + 1) << " " << getHash(i+2, 2*i+2) << "dfsdf\n";
			int sisa = n - 2 * i - 2;
			ok &= getHash(2 * i + 3, (2 * i) + 2 + (sisa / 2)) == getHash((2 * i) + 3 + (sisa / 2), n);
			ans += ok;
			// if(ok) {
			// 	cerr << i << " -- ";
			// }
		}
		cout << ans << "\n";
	}

}