#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 1e5;
int a[N + 5], ans[N + 5];

void solve() {
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);

  int up = n;
  int last;
  for(int i = 1; i <= n; i += 2) {
    ans[i] = a[up--];
    last = i;
  }
  multiset<int> se;
  for(int i = 1; i <= up; i++) {
    se.insert(a[i]);
  }
  for(int i = last; i >= 3; i -= 2) {
    int mn = min(ans[i], ans[i - 2]);
    auto pos = se.find(mn);
    if(pos == se.begin()) continue;
    else {
      auto prv = --pos;
      ans[i - 1] = *prv;
      se.erase(prv);
    }
  }
  for(int i = 1; i <= n; i++) {
    if(ans[i] == 0) {
      ans[i] = *se.begin();
      se.erase(se.begin());
    }
  }
  int jwb = 0;
  for(int i = 2; i < n; i++) {
    if(ans[i] < ans[i - 1] && ans[i] < ans[i + 1]) {
      jwb++;
    }
  }

  cout << jwb << '\n';
  for(int i = 1; i <= n; i++) {
    cout << ans[i] << ' ';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int TC = 1;
  for(int i = 1; i <= TC; i++) {
    solve();
  }
  
  return 0;
}