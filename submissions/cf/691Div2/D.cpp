#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 100;
int a[N + 5], b[N + 5];
int sum;
bool taken[N + 5];
vector<int> ans;

void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
    sum += b[i];    
  }
  int mx = 0, tmp = 0;
  // vector<int> idx;
  for (int i = 1; i <= n; i++) {
    int cur = min(2 * a[i], sum + b[i]);
    if (cur > mx) {
      mx = cur;
      tmp = i;
    }
  }
  // idx.emplace_back(tmp);
  ans.emplace_back(mx);
  taken[tmp] = 1;
  int A = a[tmp], B = b[tmp];
  cerr << tmp << '\n';
  for (int i = 2; i <= n; i++) {
    int l = 2 * A;
    int r = sum + B;
    cerr << l << ' ' << r << '\n';
    int lol = 0;
    int tmpIdx = 0;
    for (int j = 1; j <= n; j++) {
      if (taken[j]) continue;
      int tmp = min(l + 2 * a[j], r + b[j]);
      if (tmp > lol) {
        lol = tmp;
        tmpIdx = j;
      }
    }
    A += a[tmpIdx];
    B += b[tmpIdx];
    cerr << tmpIdx << '\n';
    taken[tmpIdx] = 1;
    ans.emplace_back(lol);
  }

  cout << fixed << setprecision(9);
  for (int i = 0; i < n; i++) {
    cout << ((ld)(ans[i])) / ((ld)2) << ' ';
  }
  cout << '\n';
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