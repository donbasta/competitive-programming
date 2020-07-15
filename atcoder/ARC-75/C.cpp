#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  vector<int> ve;
  cin >> n;
  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    ve.emplace_back(x);
  }
  sort(ve.begin(), ve.end());
  int sum = 0, idx = -1;
  bool ada = 0;
  for(int i = 0; i < n; i++) {
    sum += ve[i];
    if(!ada && ve[i] % 10 != 0) {
      ada = true;
      idx = i;
    }
  }
  if(sum % 10 != 0) {
    cout << sum;
  } else {
    cout << (ada ? sum - ve[idx] : 0);
  }
  cout << '\n';
  return 0;
}