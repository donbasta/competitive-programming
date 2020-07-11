#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int N = 1e7;

vector<pair<int, int>> ve;
vector<pair<int, int>> idx(N + 1, make_pair(-1, -1));
int gpf[N + 5], ar[N + 5];
pair<int, int> ans;


void rec(int curIdx, int curDiv, const vector<pair<int, int>>& primes, int id) {
  if(curIdx == (int)primes.size()) {
    if(idx[curDiv].first == -1) {
      idx[curDiv].first = id;
    } else if(idx[curDiv].second == -1) {
      idx[curDiv].second = id;
    }
    return;
  }
  for(int i = 0; i <= primes[curIdx].first; i++) {
    rec(curIdx + 1, curDiv, primes, id);
    curDiv *= primes[curIdx].second;
  }
}

void add(int x, int id) {
  vector<pair<int, int>> pr;
  int temp = x;
  while(temp > 1) {
    int curPrime = gpf[temp];
    int cnt = 0;
    while(temp % curPrime == 0) {
      temp /= curPrime;
      cnt++;
    }
    pr.emplace_back(cnt, curPrime);
  }
  rec(0, 1, pr, id);
}

void sieve() {
  for(int i = 2; i <= N; i++) {
    if(gpf[i])
      continue;
    for(int j = i; j <= N; j += i) {
      gpf[j] = i;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  sieve();

  int n;
  cin >> n;
  for(int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    ve.emplace_back(a, i);
    ar[i] = a;
  }
  sort(ve.begin(), ve.end());
  for(int i = 0; i < n; i++) {
    // cerr << i << ' ';
    add(ve[i].first, ve[i].second);
  }
  ll curMin = 1e18;
  for(int i = 1; i <= N; i++) {
    if(idx[i].first == -1 || idx[i].second == -1)
      continue;
    ll temp = 1LL * ar[idx[i].first] * ar[idx[i].second] / i;
    if(curMin >= temp) {
      curMin = temp;
      ans = idx[i];
    }
  }
  int ans1 = ans.first, ans2 = ans.second;
  if(ans1 > ans2)
    swap(ans1, ans2);
  cout << ans1 << ' ' << ans2 << '\n';
  return 0;
}