#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  int tc;
  cin >> tc;
  while(tc--) {
  	int n;
  	cin >> n;

  	int a[n + 1];
  	vector<int> ve[2];

  	for(int i = 1; i <= n; i++) {
  		cin >> a[i];
  	}
  	for(int i = 1; i <= n; i++) {
  		int b;
  		cin >> b;
  		ve[b].push_back(a[i]);
  	}

  	vector<int> vc;
  	bool ok[2];
  	ok[0] = ok[1] = true;
  	int sz0 = (int)ve[0].size(), sz1 = (int)ve[1].size();

  	for(int i = 0; i < 2; i++) {
  		int sz = (int) ve[i].size();
  		if(sz == 0)
  			continue;
  		vc.clear();
  		for(int j = 0; j < sz; j++)
  			vc.push_back(ve[i][j]);
  		sort(vc.begin(), vc.end());
  		for(int j = 0; j < sz; j++){
  			ok[i] &= (vc[j] == ve[i][j]);
  		}
  	} 

  	if(sz0 > 0 && sz1 > 0)
		cout << "Yes";
  	else if(sz0 == 0)
  		if(ok[1])
  			cout << "Yes";
  		else
  			cout << "No";
  	else 
  		if(ok[0])
  			cout << "Yes";
  		else
  			cout << "No";
  	cout << '\n';
  }
  return 0;
}
