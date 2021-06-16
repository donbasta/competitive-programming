#include <bits/stdc++.h>
using namespace std;

int n;
string s, t;
int cnt[26];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	cin >> s >> t;
	for(int i = 0; i < n; i++) {
		int a = t[i] - 'a';
		int b = s[i] - 'a';
		if(a == b) {
			cnt[a]++;
		} else {
			cnt[a]++;
			cnt[b]++;
		}
	}
	int mx = 0;
	for(int i = 0; i < 26; i++) {
		mx = max(mx, cnt[i]);
	}
	cout << mx << "\n";
	return 0;
}