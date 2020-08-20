#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 3;
int ar[(1<<N) + 5][(1<<N) + 5], cnt[(1<<N) + 5][(1<<N) + 5];
long long fact[(1<<N) + 5];

void simulate(const vector<int>& ve) {
  memset(cnt, 0, sizeof(cnt));
  int len = (1 << N);
  vector<int> cur = ve;
  while(len > 1) {
    // cerr << len << ":D\n";
    vector<int> temp;
    for(int i = 0; i < len; i += 2) {
      int a = cur[i];
      int b = cur[i + 1];
      temp.push_back(min(a, b));
      cnt[a][b]++;
      cnt[b][a]++;
    }
    cur = temp;
    len = (int)cur.size();
  }
}

void solve() {
  int n = N;
  vector<int> ve;
  for(int i = 1; i <= (1 << n); i++) {
    ve.push_back(i);
  }
  int cntz = 0;
  do {
    simulate(ve);
    for(int i = 1; i <= (1 << n); i++) {
      for(int j = 1; j <= (1 << n); j++) {
        ar[i][j] += cnt[i][j];
      }
    }
    // cerr << ++cntz;
  } while(next_permutation(ve.begin(), ve.end()));
  fact[0] = 1;
  for(int i = 1; i <= (1 << n); i++) {
    fact[i] = fact[i - 1] * i;
  }
  int fpb = ar[1][2];
  int tot = 0;
  for(int i = 1; i <= (1 << n); i++) {
    for(int j = i + 1; j <= (1 << n); j++) {
      tot += ar[i][j];
      fpb = __gcd(fpb, ar[i][j]);
      // cerr << i << ' ' << j << ' ' << ar[i][j] << '\n';
    }
  }
  cerr << fpb << ":(\n";
  cerr << tot / fpb << ":(\n";
  for(int i = 1; i <= (1 << n); i++) {
    for(int j = 1; j < i; j++) {
      cerr << j << ' ' << i << ' ' << ar[j][i] / fpb << '\n';
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int TC = 1;
  for(int i = 1; i <= TC; i++) {
    solve();
  }
  
  return 0;
}