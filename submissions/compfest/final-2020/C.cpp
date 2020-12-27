#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int x, y, n, m;

vector<int> get_mod3(int x) {
  int temp = x / 3 + 1;
  if(x % 3 == 0) return { temp, temp - 1, temp - 1 };
  if(x % 3 == 1) return { temp, temp, temp - 1 };
  if(x % 3 == 2) return { temp, temp, temp };
  return vector<int>();
}

ll calc(int a, int b) {
  if(a == 0 || b == 0) return 0;
  vector<int> a3 = get_mod3(a);
  vector<int> b3 = get_mod3(b);
  vector<int> sumpair(3);

  cerr << a << ' ' << b << '\n';
  cerr << a3[0] << ' ' << a3[1] << ' ' << a3[2] << '\n';
  cerr << b3[0] << ' ' << b3[1] << ' ' << b3[2] << '\n';

  sumpair[0] = a3[0] * b3[0] + a3[1] * b3[2] + a3[2] * b3[1];
  sumpair[1] = a3[0] * b3[1] + a3[1] * b3[0] + a3[2] * b3[2];
  sumpair[2] = a3[0] * b3[2] + a3[1] * b3[1] + a3[2] * b3[0];

  ll sum = (a + 1) * (b + 1) * (a + b) / 2;
  ll kur = 0;
  for(int i = 0; i < 3; i++) {
    kur += i * sumpair[i];
  }
  cerr << sum << ' ' << kur << ":D \n";
  sum -= kur;
  
  assert(sum % 3 == 0);
  cerr << sum / 3 << ":(\n";
  return sum / 3;
}

ll calc_suf(int a, int b) {
  ll ret = calc(n, m) - calc(a - 1, m) - calc(n, b - 1) + calc(a - 1, b - 1);
  if(a == 3 && b == 3) ret += 2;
  return ret;
}

void solve() {
  cin >> x >> y >> n >> m;
  cout << calc_suf(x, y) << '\n';
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