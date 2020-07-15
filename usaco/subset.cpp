/*
ID: faddila1
TASK: subset
LANG: C++14                 
*/

#include <bits/stdc++.h>
using namespace std;

int n;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	ofstream fout ("subset.out");
	ifstream fin ("subset.in");

	fin >> n;
	if(n % 4 == 1 || n % 4 == 2) {
		fout << 0 << "\n";
	} else {
		long long ans = 0;
		int mid = n / 2;
		int target = n * (n + 1) / 4;
		map<int, int> mp1, mp2;
 
		for(int i = 0; i < (1 << mid); i++) {
			int temp = 0;
			for(int j = 0; j < mid; j++) {
				if((i >> j) & 1)
					temp += (j + 1);
			}
			mp1[temp]++;
		}

		mid = n - mid;
		for(int i = 0; i < (1 << mid); i++) {
			int temp = 0;
			for(int j = 0; j < mid; j++) {
				if((i >> j) & 1)
					temp += (n - j);
			}
			mp2[temp]++;
		}

		for(auto i : mp1) {
			if(mp2.find(target - i.first) == mp2.end())
				continue;
			ans += 1LL * i.second * mp2[target - i.first];
		}

		fout << ans / 2 << "\n";
	}

}
