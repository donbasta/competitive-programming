#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const ll INF = 1e18;

string greedy(int k) {
  if(k <= 8)
    return string(1, (char)(k + '0'));
  string ret = "8";
  k -= 8;
  while(k > 9) {
    ret = '9' + ret; 
    k -= 9;
  }
  ret = ((char) (k + '0')) + ret;
  return ret;
}

string greedy1(int k) {
  if(k == 0) {
    return "0";
  }
  string ret = "";
  while(k > 9) {
    ret = '9' + ret; 
    k -= 9;
  }
  ret = ((char) (k + '0')) + ret;
  return ret;
}

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
    ll ans = INF;
    int n, k;
    cin >> n >> k;
    if(k == 0) {
      cout << stoll(greedy1(n)) << '\n';
      continue;
    }
    for(int i = 0; i + k <= 9; i++) {
      int temp = n;
      int last = (k + 1) * (2 * i + k) / 2;
      if(temp < last)
        continue;
      temp -= last;
      if(temp % (k + 1) != 0)
        continue;
      temp /= (k + 1);
      ll cur = stoll(greedy1(temp));
      ans = min(cur * 10LL + i, ans);
    }
    for(int i = 1; i <= k; i++) {
      int lul = n;
      int last = i * (i - 1) / 2 +  (k + 1 - i) * (18 + i - k) / 2;
      lul -= last;
      if(lul < 0)
        continue;
      int dig = 0;
      while(true) {
        int temp = lul;
        int pad = 9 * dig * (k + 1 - i);
        if(temp < pad)
          break;
        temp -= pad;
        temp -= i;
        if(temp < 0 || (temp % (k + 1) != 0)) {
          dig++;
          continue;
        }
        temp /= (k + 1);
        ll cur = stoll(greedy(temp));
        for(int i = 0; i < dig; i++) {
          cur = cur * 10LL + 9;
        }
        cur = cur * 10LL + (9 + i - k);
        ans = min(ans, cur);
        dig++;
      }
    }
    if(ans == (ll)1e18)
      cout << -1 << '\n';
    else
      cout << ans << '\n';
  }
  return 0;
}
