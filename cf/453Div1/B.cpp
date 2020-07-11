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

  int n;
  cin >> n;
  vector<int> a(n + 1), b(n);
  cout << n << '\n';
  for(int i = n; i >= 0; i--) {
  	int lol = (n - i) % 3;
  	if(lol == 0) 
  		a[i] = 1;
  	else if(lol == 1)
  		a[i] = 0;
  	else
  		a[i] = -1;
  }
  for(int i = 0; i <= n; i++) {
  	cout << a[i] << ' ';
  }
  cout << '\n';
  cout << n - 1 << '\n';
	for(int i = n - 1; i >= 0; i--) {
		int lol = (n - 1 - i) % 3;
		if(lol == 0)
			b[i] = 1;
		else
			b[i] = 0;
  }
  for(int i = 0; i <= n - 1; i++) {
  	cout << b[i] << ' ';
  }
  cout << '\n';
  return 0;
}