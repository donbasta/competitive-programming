#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tc;
  cin >> tc;
  while(tc--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> cnt(26, 0);
    for(int i = 0; i < n; i++) {
      cnt[s[i] - 'a']++;
    }
    int mx = -1;
    for(int i = 0; i < 26; i++) {
      mx = max(mx, cnt[i]);
    }
    int ans = n - mx;
    cout << ans << '\n';
  }
  
  return 0;
}