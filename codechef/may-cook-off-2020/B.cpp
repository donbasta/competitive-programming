#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int tc;
	cin >> tc;
	while(tc--) {
		int n, m;
		cin >> n >> m;
		int ar[n + 10][m + 10];
		map<int, int> mp;

		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				int x;
				cin >> x;
				mp[x]++;
			}
		}

		if(m == 1) {
			for(auto it : mp) {
				for(int i = 0; i < it.second; i++) {
					cout << it.first << "\n";
				}
			}
			continue;
		}

		int odd = 0;
		for(auto i : mp) {
			if(i.second & 1) {
				odd++;
			}
		}

		if(m & 1) {
			if(odd > n) {
				cout << -1 << "\n";
				continue;
			} else {
				vector<int> sisa;
				int i = 1, j = 1;
				for(auto it = mp.begin(); it != mp.end(); ++it) {
					auto k = *it;
					if(i > n) {
						for(int l = 1; l <= mp[k.first]; l++){
							sisa.push_back(k.first);
						}
						continue;
					}
					while(mp[k.first] > 1 && i <= n) {
						ar[i][j] = k.first;
						ar[i][m + 1 - j] = k.first;
						if(j < m / 2){
							j++;
						} else if(j == m / 2) {
							j = 1;
							i++;
						}
						mp[k.first] -= 2;
					}
					for(int l = 1; l <= mp[k.first]; l++){
						sisa.push_back(k.first);
					}
				}
				assert((int)sisa.size() == n);
				for(int ii = 1; ii <= n; ii++) {
					ar[ii][m / 2 + 1] = sisa[ii - 1];
				}
			}
		} else if (m % 2 == 0) {
			if(odd > 0) {
				cout << -1 << "\n";
				continue;
			} else{
				int i = 1, j = 1;
				for(auto it = mp.begin(); it != mp.end(); ++it) {
					auto k = *it;
					while(mp[k.first] > 0 && i <= n) {
						ar[i][j] = k.first;
						ar[i][m + 1 - j] = k.first;
						if(j < m / 2){
							j++;
						} else {
							j = 1;
							i++;
						}
						mp[k.first] -= 2;
					}
				}
			}
		}

		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				cout << ar[i][j] << " ";
			}
			cout << "\n";
		}

	}
	return 0;
}