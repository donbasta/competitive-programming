#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int n;
int ar[1069];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> ar[i];
  }
  int ex = 0;
  for(int i = 2; i < n; i++) {
    if(ar[i] > ar[i - 1] && ar[i] > ar[i + 1])
      ex++;
    if(ar[i] < ar[i - 1] && ar[i] < ar[i + 1])
      ex++;
  }
  cout << ex << '\n';
  return 0;
}
