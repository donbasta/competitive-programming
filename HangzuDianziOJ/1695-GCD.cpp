#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int N = 1e5;

int mob[N + 69];

void sieveMobius() {
  vector<int> pr;
  vector<bool> composite(N + 1);
  mob[1] = 1;
  for(int i = 2; i <= N; i++) {
    if(!composite[i]) {
      mob[i] = -1;
      pr.push_back(i);
    }
    for(int j = 0; j < (int)pr.size(); j++) {
      if(i * pr[j] > N)
        break;
      composite[i * pr[j]] = true;
      if(i % pr[j] != 0) {
        mob[i * pr[j]] = mob[i] * (-1);
      } else {
        mob[i * pr[j]] = 0;
        break;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  sieveMobius();

  int tc;
  cin >> tc;
  for(int q = 1; q <= tc; q++) {
    int a, b, c, d, k;
    cin >> a >> b >> c >> d >> k;
    assert(a == 1 && c == 1);
    if(k == 0) {
      cout << "Case " << q << ": ";
      cout << 0 << '\n';
      continue;
    }

    if(b > d) swap(b, d);
  	ll ans1 = 0, ans2 = 0;
    for(int i = 1; i * k <= b; i++) {
      ll temp = 1LL * k * i;
      ans1 += 1LL * mob[i] * (b / temp) * (d / temp);
      ans2 += 1LL * mob[i] * (b / temp) * (b / temp);
    }
    cout << "Case " << q << ": ";
    cout << ans1 - (ans2 / 2) << '\n';
  }
  return 0;
}
