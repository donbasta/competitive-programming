#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int N = 569;

int n;
int a[N], b[N], ac[N], bc[N];

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
  	cin >> n;
    bool ok = true;
  	for(int i = 1; i <= n; i++) {
      cin >> a[i];
      ac[i] = a[i];
  	}
    for(int i = 1; i <= n; i++) {
      cin >> b[i];
      bc[i] = b[i];
    }
    if(n & 1) {
      ok &= (a[(1 + n) / 2] == b[(1 + n) / 2]);
    }
    sort(ac + 1, ac + n + 1);
    sort(bc + 1, bc + n + 1);
    for(int i = 1; i <= n; i++)
      ok &= (ac[i] == bc[i]);

    map<pair<int, int>, int> mpa, mpb;
    for(int i = 1; i <= (n / 2); i++) {
      int mx = max(a[i], a[n + 1 - i]);
      int mn = min(a[i], a[n + 1 - i]);
      mpa[make_pair(mx, mn)]++;
      mx = max(b[i], b[n + 1 - i]);
      mn = min(b[i], b[n + 1 - i]);
      mpb[make_pair(mx, mn)]++;
    }

    for(auto i : mpa) {
      ok &= (i.second == mpb[i.first]);
    }

    cout << (ok ? "Yes" : "No");
    cout << '\n';
  }

  return 0;
}
