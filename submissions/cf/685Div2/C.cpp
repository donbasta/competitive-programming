#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n, k;
  cin >> n >> k;
  string s1, s2;
  cin >> s1 >> s2;

  vector<int> cnt1(26), cnt2(26);
  for (int i = 0; i < n; i++) {
    cnt1[s1[i] - 'a']++;
    cnt2[s2[i] - 'a']++;
  }

  int acc = 0;
  bool ok = 1;
  for (int i = 0; i < 26; i++) {
    if (abs(cnt1[i] - cnt2[i]) % k != 0) {
      ok = 0;
      break;
    }
    if (cnt1[i] - cnt2[i] + acc < 0) {
      ok = 0;
      break;
    }
    acc = (cnt1[i] - cnt2[i] + acc);
  }

  if (!ok) {
    cout << "No";
  } else {
    cout << "Yes";
  }
  cout << '\n';

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