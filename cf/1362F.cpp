#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int n;
vector<pair<int, int>> dom;



void run(int x) {
  
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  cin >> n;
  for(int i = 1; i <= n; i++) {
    int a, b;
    cin >> a >> b;
    dom.emplace_back(a, b);
  }

  for(int i = 20; i >= 0; i--) {
    run(i);
  }

  return 0;
}
