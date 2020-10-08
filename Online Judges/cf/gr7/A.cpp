#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int n;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  cin >> n;
  for(int i = 1; i <= n; i++) {
    string s;
    bool ok = false, yes = false;
    cin >> s;
    int temp = 0;
    for(auto i : s) {
      int c = i - '0';
      temp += c;
      if(c == 0 && !yes)
        yes = true;
      else if(c % 2 == 0)
        ok = true;
    }
    if(temp % 3 == 0 && ok && yes) {
      cout << "red";
    } else {
      cout << "cyan";
    }
    cout << '\n';
  }
  return 0;
}
