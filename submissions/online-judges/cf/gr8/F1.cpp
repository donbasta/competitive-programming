#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {

  // #ifndef ONLINE_JUDGE
  //   freopen("input.txt", "r", stdin);
  //   freopen("output.txt", "w", stdout);
  // #endif

  int n;
  cin >> n;
  if(n <= 3) {
  	//early retreat
  	cout << 0 << endl;
  	return 0;
  }

  int mx = -1, loc = 1;
  for(int i = 1; i <= n; i++) {
    int temp = i * (n / (i + 1)) + max(0, (n % (i + 1) - 1));
    if(temp <= i)
      continue;
    if(mx < temp - i) {
      mx = temp - i;
      loc = i;
    }
  }

  int on = 0;
  set<int> se;
  vector<bool> lol(n + 1);
  for(int i = 1; i < n; i += (loc + 1)) {
    for(int j = 0; j < loc; j++){
      if(i + j == n)
        break;
      lol[i + j] = true;
      se.insert(i + j);
    }
  } 
  while((int)se.size() > loc) {
  	int k = (int)se.size(), rep;
  	cout << k << ' ';
  	for(auto i : se) {
  		cout << i << ' ';
  	}
  	cout << endl;
  	se.clear();
  	cin >> rep;
  	if(rep == -1) {
  		return 0;
  	}
  	for(int i = 0; i < k; i++) {
  		int cur = (rep + i);
  		if(cur > n) {
  			cur = cur % n;
  		}
  		if(lol[cur]) {
  			se.insert(cur);
  		}
  	}
  }
  cout << 0 << endl;
  return 0;
}