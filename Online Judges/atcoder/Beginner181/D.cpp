#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int cnt[10];
int par[2];

bool cek() {
  for (int i = 8; i < 200; i++) {
    string tes = to_string(i);
    // if ((int)tes.length < 3) continue;
    vector<int> temp(10);
    for (auto c : tes) {
      temp[c]++;
    }
    bool ok = 1;
    for (int i = 0; i < 10; i++) {
      ok &= temp[i] <= cnt[i];
    }
    if (ok) return 1;
  }
  return 0;
}

void solve() {
  string s;
  cin >> s;
  int n = (int)s.length();
  if (n == 1) {
    if (s == "8") cout << "Yes\n";
    else cout << "No\n";
    return;
  }
  if (n == 2) {
    for (int i = 16; i < 100; i += 8) {
      if (i == 40 || i == 80) continue;
      string tes = to_string(i);
      if (s == tes) { cout << "Yes\n"; return; }
      reverse(tes.begin(), tes.end());
      if (s == tes) { cout << "Yes\n"; return; }
    }
    cout << "No\n";
    return;
  }
  for (int i = 0; i < n; i++) {
    int dig = (s[i] - '0');
    cnt[dig]++;
    par[dig % 2]++;
  }
  if (cek()) {
    cout << "Yes";
  } else {
    cout << "No";
  }
  cout << '\n';
  return;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int TC = 1;
  cin >> TC;
  for(int i = 1; i <= TC; i++) {
    solve();
  }
  
  return 0;
}