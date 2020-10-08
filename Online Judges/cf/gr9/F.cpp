#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int ge;
vector<pair<long long, int>> ve;
ll add;

int main() {

  for(int i = 1; i <= 3; i++) {
    ll x;
    cin >> x;
    ve.emplace_back(x, i);
  }
  sort(ve.begin(), ve.end());

  cout << "First" << endl;
  add = ve[2].first + 1LL - ve[0].first;
  cout << add << endl;
  cin >> ge;

  for(int i = 0; i < 3; i++) {
    if(ve[i].second == ge) {
      ve[i].first += add;
      break;
    }
  }

  sort(ve.begin(), ve.end());
  add = ve[1].first - ve[0].first + 2LL * (ve[2].first - ve[1].first);
  cout << add << endl;
  cin >> ge;

  for(int i = 0; i < 3; i++) {
    if(ve[i].second == ge) {
      ve[i].first += add;
      break;
    }
  }

  sort(ve.begin(), ve.end());
  add = ve[1].first - ve[0].first;
  cout << add << endl;
  cin >> ge;
  assert(ge == 0);
  return 0;
}
