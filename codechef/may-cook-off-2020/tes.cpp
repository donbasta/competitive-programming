#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	map<int, int> mp;
	for(int i = 1; i <= 10; i++) {
		for(int j = 1; j <= i / 2; j++) {
			mp[i]++;
		}
	}
	for(auto i : mp) {
		mp[i.first]--;
	}
	for(auto i : mp) {
		cout << i.second << " " << i.first << "\n";
	}

}
