#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int N = 1e7;

ll ans[N + 69];

void sieve() {
  vector<int> pr, cnt(N + 1);
  vector<bool> comp(N + 1);
  ans[1] = 1;
  for(int i = 2; i <= N; i++) {
    if(!comp[i]) {
      pr.push_back(i);
      ans[i] = 1LL * i * i - i + 1;
      cnt[i] = i;
    }
    for(int j = 0; j < (int)pr.size(); j++) {
      if(1LL * pr[j] * i > N)
        break;
      comp[i * pr[j]] = true;
      if(i % pr[j] != 0) {
        cnt[i * pr[j]] = pr[j];
        ans[i * pr[j]] = ans[i] * ans[pr[j]];
      } else {
        ll temp;
        cnt[i * pr[j]] = cnt[i] * pr[j];
        temp = cnt[i * pr[j]];
        ans[i * pr[j]] = ans[i / cnt[i]] * (pr[j] * temp * temp + 1) / (pr[j] + 1);
        break;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  sieve();

  int tc;
  cin >> tc;
  while(tc--) {
    int a;
    cin >> a;
    cout << ans[a] << '\n';
  }

  return 0;
}
