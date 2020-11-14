#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n, k;
  cin >> n >> k;
  ll tempSum = 0, curDiv = 0;
  vector<ll> ar(n+1), pre(n+1);
  for (int i = 1; i <= n; i++) {
    cin >> ar[i];
    pre[i] = pre[i-1] + ar[i];
  }
  if (k == 1) {
    if (pre[n] & 1) {
      cout << "YES\n" << n;
    } else {
      cout << "NO";
    }
    cout << '\n';
    return;
  }
  vector<int> ans;
  for (int i = 1; i <= n; i++) {
    tempSum += ar[i];
    if (tempSum & 1) {
      ans.push_back(i);
      tempSum = 0;
      curDiv++;
      if (curDiv == k-1) {
        break;
      }
    }
  }
  if (curDiv < k-1) {
    cout << "NO";
  } else if (curDiv == k-1) {
    ll sisa = pre[n] - pre[ans.back()];
    if (sisa % 2 == 0) {
      cout << "NO";
    } else {
      cout << "YES" << '\n';
      for (auto& e : ans) {
        cout << e << ' ';
      }
      cout << n;
    }
  } 
  cout << '\n';
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