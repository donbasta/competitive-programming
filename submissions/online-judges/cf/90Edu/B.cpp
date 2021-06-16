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
    string s;
    cin >> s;
    int sz = (int)s.length();
    string copy = s;
    sort(copy.begin(), copy.end());
    if(copy[0] == copy[sz - 1]) {
      cout << "NET";
    } else {
      vector<int> cnt(2, 0);
      for(int i = 0; i < sz; i++) {
        cnt[s[i] - '0']++;
      }
      int lol = min(cnt[0], cnt[1]);
      if(lol % 2 == 1) {
        cout << "DA";
      } else {
        cout << "NET";
      }
    }
    cout << '\n';
  }
  return 0;
}
