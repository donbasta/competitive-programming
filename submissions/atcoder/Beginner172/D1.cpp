#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int N = 1e7 + 10;

long long di[N];
ll n, ans;

void sieve() {
  vector<ll> pr, cnt(N + 1), pcnt(N + 1);
  vector<bool> comp(N + 1);
  di[1] = 1;
  for(int i = 2; i <= N; i++) {
    if(!comp[i]) {
      pr.push_back(i);
      di[i] = 2;
      cnt[i] = 1;
      pcnt[i] = i;
    }
    // cerr << i << ' ';
    // cerr << (int)pr.size();
    for(int j = 0; j < (int)pr.size(); j++) {
      if(1LL * pr[j] * i > N)
        break;
      comp[i * pr[j]] = true;
      // cerr << i << ' ';
      if(i % pr[j] != 0) {
        cnt[i * pr[j]] = 1;
        pcnt[i * pr[j]] = pr[j];
        di[i * pr[j]] = di[i] * 2;
      } else {
        ll temp;
        cnt[i * pr[j]] = cnt[i] + 1;
        pcnt[i * pr[j]] = pcnt[i] * pr[j];
        temp = cnt[i * pr[j]];
        di[i * pr[j]] = di[i / pcnt[i]] * (temp + 1);
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

  sieve();
  cin >> n;
  for(int i = 1; i <= n; i++) {
    ans += 1LL * i * di[i];
  }
  cout << ans << '\n';
  return 0;
}
