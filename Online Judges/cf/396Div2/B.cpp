#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int N = 1e5 + 69;

int n;
int ar[N];

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
  sort(ar + 1, ar + 1 + n);
  for(int i = 1; i <= n - 2; i++) {
    if(ar[i] + ar[i + 1] > ar[i + 2]){
      cout << "YES" << '\n';
      return 0;
    }
  }
  cout << "NO" << '\n';
  return 0;
}
