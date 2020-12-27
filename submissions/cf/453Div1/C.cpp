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

  int h;
  cin >> h;
  vector<int> dep(h + 1);
  bool ok = true;
  int pos = -1, sum = 1;
  cin >> dep[0];
  for(int i = 1; i <= h; i++) {
  	cin >> dep[i];
  	sum += dep[i];
  	if(dep[i] > 1 && dep[i - 1] > 1){
  		ok = false;
  		pos = i;
  	}
  }
  // assert(dep[0] == 1);
  if(!ok) {
  	cout << "ambiguous" << '\n';
  	vector<int> a(sum + 1), b(sum + 1);
  	int cur = 1;
  	a[1] = b[1] = 0;
  	for(int i = 1; i <= h; i++) {
  		for(int j = 1; j <= dep[i]; j++) {
  			a[cur + j] = b[cur + j] = cur;
  		}
  		if(i == pos) {
  			b[cur + 1] = cur - 1;
  		}
  		cur += dep[i];
  	}
  	for(int i = 1; i <= sum; i++) {
  		cout << a[i] << ' ';
  	}
  	cout << '\n';
  	for(int i = 1; i <= sum; i++) {
  		cout << b[i] << ' ';
  	}
  } else {
  	cout << "perfect" << '\n';
  }
  return 0;
}
