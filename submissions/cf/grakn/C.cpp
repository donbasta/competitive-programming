#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {

  cout << fixed << setprecision(12);

  int n, l;
  cin >> n >> l;

  vector<int> ar(n + 5);
  for(int i = 1; i <= n; i++) {
    cin >> ar[i];
  }
  ar[0] = 0, ar[n + 1] = l;
  int n1 = 1, n2 = n;
  ld s1 = 0, s2 = l;
  ld time_total = 0;
  int v1 = 1, v2 = 1;

  while(n1 <= n2) {
    ld t1, t2;
    t1 = ((ld)ar[n1] - s1) / (ld)v1;
    t2 = (s2 - (ld)ar[n2]) / (ld)v2;
    if(t1 < t2) {
      s1 = ar[n1];
      s2 = s2 - t1 * (ld)v2;
      n1++;
      v1++;
      time_total += t1;
    } else if(t1 == t2) {
      s1 = ar[n1], s2 = ar[n2];
      n1++, n2--;
      v1++, v2++;
      time_total += t1;
    } else if(t1 > t2) {
      s2 = ar[n2];
      s1 = s1 + t2 * (ld)v1;
      n2--;
      v2++;
      time_total += t2;
    }
  }

  time_total += (s2 - s1) / (v1 + v2);
  cout << time_total << '\n';
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