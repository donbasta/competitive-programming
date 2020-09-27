#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 1e3;

int n;
string name[N + 5];
int skor[N + 5];
map<string, int> pt, pt1;

void solve() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> name[i] >> skor[i];
    pt[name[i]] += skor[i];
  }
  int cnt = 0;
  int mx = 0;
  string winner;
  for(auto i : pt) {
    if(i.second > mx) {
      mx = i.second, cnt = 1;
      winner = i.first;
    } else if(i.second == mx) {
      cnt++;
    }
  }
  if(cnt == 1) {
    cout << winner;
  } else {
    for(int i = 0; i < n; i++) {
      pt1[name[i]] += skor[i];
      if(pt1[name[i]] >= mx && pt[name[i]] == mx) {
        cout << name[i];
        break;
      }
    }
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