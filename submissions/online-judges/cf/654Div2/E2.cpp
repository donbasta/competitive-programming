#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int N = 1e5 + 69;

int n, p;
int ar[N];
int lo[N], hi[N];
set<int> se;
vector<int> ve;

void upd(int a, int b) {
	// int hi = ((b + p - 1) / p) * p;
	for(auto i : se) {
		lo[i] = min(lo[i], a);
		hi[i] = max(hi[i], b);
		// int cur = hi + i;
		// while(cur >= a) {
		// 	if(cur > b) {
		// 		cur -= p;
		// 		continue;
		// 	}
		// 	if(cur < ar[n] - n + 1)
		// 		break;
		// 	ve.push_back(cur);
		// 	cur -= p;
		// }
	}
}

void fi(int x) {
	int l = max(lo[x], ar[n] - n + 1);
	int r = hi[x];
	int mx = ((r + p - 1) / p) * p;
	mx += x;
	while(mx >= l) {
		if(mx > r) {
			mx -= p;
			continue;
		}
		// if(mx < ar[n] - n + 1)
		// 	break;
		ve.push_back(mx);
		mx -= p;
	}
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  cin >> n >> p;
  for(int i = 1; i <= n; i++) {
  	cin >> ar[i];
  }
  sort(ar + 1, ar + 1 + n);
  ar[0] = 0;

  for(int i = 0; i < p; i++){
  	lo[i] = 1;
  	se.insert(i);
  	hi[i] = 0;
  }
  for(int i = n; i > p; i--) {
  	int cur = (((ar[i] - i) % p) + p) % p;
  	if(se.count(cur))
  		se.erase(cur);
  }
  // for(auto i : se) {
  // 	hi[]
  // }
  // for(int i = 0; i < p; i++) {
  // 	hi[i] =
  // }

  for(int i = p; i >= 1; i--) {
  	int lower = ar[i - 1] + 1;
  	int upper = ar[i];
  	int cur = (((ar[i] - i) % p) + p) % p;
  	if(se.count(cur)){
  		lo[cur] = upper + 1;
  		se.erase(cur);
  	}
  	if(i == p) {
  		for(auto i : se) {
  			hi[i] = upper;
  		}
  	}
  	if(lower > upper)
  		continue;
  	if(upper < ar[n] - n + 1)
  		break;
  	// upd(lower, upper);
  }
  for(int i = 0; i < p; i++) {
  	fi(i);
  }
  sort(ve.begin(), ve.end());
  cout << (int)ve.size() << '\n';
  for(auto i : ve) {
  	cout << i << ' ';
  }
  cout << '\n';
  return 0;
}
