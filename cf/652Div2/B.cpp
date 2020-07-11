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
    int n;
    string s;
    cin >> n >> s;
    string pref = "", suf = "";
    int l = n - 1, r = 0;
    for(int i = 0; i < n; i++) {
      if(s[i] != '0'){
        l = i - 1;
        break;
      }
      pref += s[i];
    }
    for(int i = n - 1; i >= 0; i--) {
      if(s[i] != '1'){
        r = i + 1;
        break;
      }
      suf += s[i];
    }
    // if(pref == s)
    //   l = n - 1;
    // if(suf == s)
    //   r = 0;
    if(r - l == 1) {
      cout << pref + suf;
    } else {
      cout << pref + "0" + suf;
    }
    cout << '\n';
  }
  return 0;
}
