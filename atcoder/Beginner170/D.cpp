#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int N = 2e5 + 69;

int n;
int ar[N];
map<int, int> mp;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> ar[i];
    mp[ar[i]]++;
  }

  if(mp.find(1) != mp.end()) {
    if(mp[1] == 1)
      cout << 1 << '\n';
    else if(mp[1] > 1)
      cout << 0 << '\n';
    return 0;
  }

  int cnt = 0;
  for(int i = 1; i <= n; i++) {
    if(mp[ar[i]] > 1)
      continue;
    bool ok = true;
    for(int j = 2; j * j <= ar[i]; j++) {
      if(ar[i] % j == 0) {
        if(mp.find(j) != mp.end()) {
          ok = false;
          break;
        }
        if(mp.find(ar[i] / j) != mp.end()) {
          ok = false;
          break;
        }
      }
    }
    if(ok)
      cnt++;
  }
  cout << cnt << '\n';
  return 0;
}

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  return 0;
}
