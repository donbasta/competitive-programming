
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int N = 2e5 + 69;

int n, k;
int ar[N], bit1[N << 1], bit2[N << 1];
bool ok;

void upd1(int a) {
  a += (n + 1);
  while(a > 0) {
    bit1[a]++;
    a -= a & -a;
  }
}

int get1(int a) {
  a += (n + 1);
  int ret = 0;
  while(a < n + n) {
    ret += bit1[a];
    a += a & -a;
  }
  return ret;
}

void upd2(int a) {
  a += (n + 1);
  while(a > 0) {
    bit2[a]++;
    a -= a & -a;
  }
}

int get2(int a) {
  a += (n + 1);
  int ret = 0;
  while(a < n + n) {
    ret += bit2[a];
    a += a & -a;
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  cin >> n >> k;
  for(int i = 1; i <= n; i++) {
    cin >> ar[i];
  }
  int cur = 0;
  while(!ok && cur < k) {
    vector<int> kiri(n + 1), kanan(n + 1);
    memset(bit1, 0, sizeof(bit1));
    memset(bit2, 0, sizeof(bit2));
    bool yes = true;
    cerr << "hi" << '\n';
    for(int i = 1; i <= n; i++) {
      kiri[i] = get1(-i);
      upd1(-i - ar[i]);
      cerr << i << ' ';
    }
    cerr << "hi" << '\n';
    for(int i = n; i >= 1; i--) {
      kanan[i] = get2(i);
      upd2(i - ar[i]);
    }
    cerr << "hi" << '\n';
    for(int i = 1; i <= n; i++) {
      ar[i] = 1 + kiri[i] + kanan[i];
      yes &= (ar[i] == n);
    }
    if(yes)
      ok = true;
  }
  for(int i = 1; i <= n; i++) {
    cout << ar[i] << ' ';
  }
  cout << '\n';
  return 0;
}
