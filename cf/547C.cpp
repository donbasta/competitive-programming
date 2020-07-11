#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int N = 2e5;
const int MAXN = 5e5;

int n, q;
int ar[N + 69], cnt[MAXN + 69], gpf[MAXN + 69];
bool ada[N + 69];
ll sum;

ll calc(int x) {
  return 1LL * x * (x - 1) / 2;
}

void sieve() {
  for(int i = 2; i <= MAXN; i++) {
    if(gpf[i])
      continue;
    for(int j = i; j <= MAXN; j += i) {
      gpf[j] = i;
    }
  }
}

vector<int> getPrime(int a) {
  vector<int> ret;
  while(a > 1) {
    int curPrime = gpf[a];
    ret.push_back(curPrime);
    while(a % curPrime == 0) {
      a /= curPrime;
    }
  }
  return ret;
}

void add(int a) {
  vector<int> ve = getPrime(a);
  int sz = (int) ve.size();
  for(int i = 0; i < (1 << sz); i++) {
    int numBit = __builtin_popcount(i);
    int temp = 1;
    for(int j = 0; j < sz; j++)
      if((i >> j) & 1)
        temp *= ve[j];
    if(numBit & 1) {
      sum += calc(cnt[temp]);
      cnt[temp]++;
      sum -= calc(cnt[temp]);
    } else {
      sum -= calc(cnt[temp]);
      cnt[temp]++;
      sum += calc(cnt[temp]);
    }
  }
}

void remove(int a) {
  vector<int> ve = getPrime(a);
  int sz = (int) ve.size();
  for(int i = 0; i < (1 << sz); i++) {
    int numBit = __builtin_popcount(i);
    int temp = 1;
    for(int j = 0; j < sz; j++)
      if((i >> j) & 1)
        temp *= ve[j];
    if(numBit & 1) {
      sum += calc(cnt[temp]);
      cnt[temp]--;
      sum -= calc(cnt[temp]);
    } else {
      sum -= calc(cnt[temp]);
      cnt[temp]--;
      sum += calc(cnt[temp]);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  sieve();

  cin >> n >> q;
  for(int i = 1; i <= n; i++) {
    cin >> ar[i];
  }
  while(q--) {
    int x;
    cin >> x;
    if(!ada[x]) {
      add(ar[x]);
    } else {
      remove(ar[x]);
    }
    ada[x] ^= 1;
    cout << sum << '\n';
  }
  return 0;
}
