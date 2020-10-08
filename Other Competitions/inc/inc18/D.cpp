#include <bits/stdc++.h>
using namespace std;

string s, t;
int ss[26], tt[26];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> s >> t;
	for(auto i : s) {
		ss[i - 'a']++;
	}
	for(auto i : t) {
		tt[i - 'a']++;
	}
	bool ok = true;
	for(int i = 0; i < 26; i++) {
		ok &= (tt[i] <= ss[i]);
	}
	cout << (ok ? "YES" : "NO");
	cout << "\n";
	return 0;
}
