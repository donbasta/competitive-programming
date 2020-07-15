#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int tc;
	cin >> tc;
	while(tc--) {

		int n;
		cin >> n;
		bool ok = true;
		int ar[n + 1];
		map<int, int> mp;

		for(int i = 1; i <= n; i++) {
			cin >> ar[i];
		}
		int cur = ar[1], len = 1;
		for(int i = 2; i <= n; i++) {
			if(ar[i] == cur){
				len++;
			} else {
				ok &= (mp.find(cur) == mp.end());
				mp[cur] = len;
				len = 1;
				cur = ar[i];
			}
		}
		ok &= (mp.find(cur) == mp.end());
		mp[cur] = len;
		set<int> se; 
		for(auto i : mp) {
			// cerr << i.first << " " << i.second << " --\n";
			se.insert(i.second);
		}
		if((int)se.size() < (int)mp.size()) {
			ok = false;
		}
		if(ok) {
			cout << "YES";
		} else {
			cout << "NO";
		}	
		cout << "\n";
	}
	return 0;
}