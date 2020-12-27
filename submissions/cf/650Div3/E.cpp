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
    int n, k, ans = 1;
    string s;
    cin >> n >> k >> s;
    vector<int> cnt(26);
    for(int i = 0; i < n; i++) {
      cnt[s[i] - 'a']++;
    }
    for(int i = n; i >= 1; i--) {
      int lol = i / __gcd(i, k), temp = 0;
      for(int j = 0; j < 26; j++) {
        temp += (cnt[j] / lol);
      }
      if(temp >= (i / lol)) {
        ans = i;
        break;
      }
    }
    cout << ans << '\n';
  }

  return 0;
}
