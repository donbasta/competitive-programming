#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> ord(n), w(n);
  vector<int> l(m), v(m);
  for(int i = 0; i < n; i++) {
    ord[i] = i;
  }
  for(int i = 0; i < n; i++) {
    cin >> w[i];
  }
  for(int i = 0; i < m; i++) {
    cin >> l[i] >> v[i];
  }
  int bat_berat = v[0], mx_len1 = l[0];
  for(int i = 1; i < m; i++) {
    cerr << i << ' ' << l[i] << ' ' << mx_len1 << '\n';
    if(mx_len1 == l[i]) {
      if(v[i] > bat_berat)
        bat_berat = v[i];
    } else if(mx_len1 < l[i]) {
      mx_len1 = l[i];
      bat_berat = v[i];
    }
  }
  int mx = *max_element(w.begin(), w.end());
  int mn = *min_element(v.begin(), v.end());
  // int mx_w = 
  int mx_len = *max_element(l.begin(), l.end());
  if(mx > mn) {
    cout << -1 << '\n';
    return;
  }
  sort(w.begin(), w.end());
  reverse(w.begin(), w.end());
  int cnt = 0;
  vector<bool> udah(n);
  vector<int> gab;
  for(int i = 0; i < n; i++) {
    if(udah[i]) continue;
    cnt++;
    int sum = w[i];
    udah[i] = 1;
    for(int j = i + 1; j < n; j++) {
      if(udah[j]) continue;
      if(sum + w[j] > mn) continue;
      sum += w[j];
      udah[j] = 1;
    }
    gab.push_back(sum);
  }
  cerr << bat_berat << '\n';
  cerr << (int)gab.size() << '\n';
  for(auto& e : gab) {
    cerr << e << ' ';
  }
  cerr << '\n';
  int ans = (cnt - 1) * (mx_len);
  cerr << cnt << ' ' << mx_len << '\n';
  cout << ans << '\n';
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