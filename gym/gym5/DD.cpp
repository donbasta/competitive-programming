#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const ll MAX = 1e18;
ll pw2[100], pw3[100];

int v3(ll n) {
  int ret = 0;
  while(n % 3 == 0) {
    ret++;
    n /= 3LL;
  }
  return ret;
}

void solve(ll n) {
  vector<ll> res;
  ll temp = n;
  int last = 60;
  while(temp > 0) {
    ll p3 = v3(temp);
    ll lol = pw3[p3];
    ll rem = temp / lol;
    // cerr << p3 << ' ' << lol << ' ' << rem << ":D" << '\n';
    // cari 2 ^ r terbesar yang kurang dari r sebelumnya
    // lebih gede dari v2(n) (kalau sama harus sama dengan n)
    // 2 ^ r * 3 ^ pw3 < n (kalau sama, r nya boleh sama dengan n)
    while((pw2[last] >= (2 * MAX / lol)) || (pw2[last] * lol > temp))
      last--;
    while(((rem - pw2[last]) % 3) != 0)
      last--;
    cerr << last << " :(\n";
    res.push_back(pw2[last] * pw3[p3]);
    temp -= pw2[last] * pw3[p3];
    last--;
  } 
  cout << (int)res.size() << '\n';
  for(auto i : res) {
    cout << i << ' ';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  freopen("distribution.in", "r", stdin);
  freopen("distribution.out", "w", stdout);

  pw2[0] = pw3[0] = 1;
  for(int i = 1; i <= 60; i++) {
    pw2[i] = pw2[i - 1] * 2LL;
  }
  for(int i = 1; i <= 38; i++) {
    pw3[i] = pw3[i - 1] * 3LL;
  }

  int tc;
  cin >> tc;
  while(tc--) {
    ll n;
    cin >> n;
    solve(n);
    cout << '\n';
  }

  return 0;
}
