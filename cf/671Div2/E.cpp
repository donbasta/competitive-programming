#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  ll n;
  cin >> n;

  vector<pair<ll, ll>> pr;

  for(ll i = 2; i * i <= n; i++) {
    if(n % i == 0) {
      int temp = 0;
      while(n % i == 0) {
        n /= i;
        temp++;
      }
      pr.emplace_back(temp, i);
    }
  }
  if(n > 1) { pr.emplace_back(1, pr); }

  sort(pr.begin(), pr.end());

  int sz = (int)pr.size();

  if(sz == 1) {
    ll lol = pr[0].second;
    for(int i = 1; i <= pr[0].first; i++) {
      cout << lol << ' ';
      lol *= pr[0].second;
    }
    cout << 0;
  } else if(sz == 2 &&  pr[0].first == 1 && pr[1].first == 1) {
    ll a = pr[0].second, b = pr[1].second;
    cout << a << ' ' << a * b << ' ' << b;
    cout << '\n';
    cout << 1;
  } else {
    vector<ll> temp;
    deque<ll> de;

    if(pr[0].first == 1 && pr[1].first == 1) {
      temp = {1, pr[0].second, pr[0].second * pr[1].second, pr[1].second};
      for(auto i : temp) {
        if(i > 1) de.push_back(i);
      }
    } else {
      if(pr[0].first == 1) {
        for(int i = 0; i <= pr[0].first; i++) {
          for(int j = 0; j <= pr[1].second; j++) {
            temp.push_back()
          }
        }


      } else {



      }
    }

    for(int i = 2; i < sz; i++) {
      ll depan = de.front(), belakang = de.back();
      ll x = depan * pr[i].second, y = belakang * pr[i].second;
      de.push_front(x * pr[i].second), de.push_back(y * pr[i].second);
      for(auto j : temp) {
        ll lul = pr[i].second;
        for(int k = 1; k <= pr[i].first; k++) {
          temp.push_back(lul * j);
          if(lul * j != x && lul * j != y) { de.push_front(lul); }
          lul *= pr[i].second;
        }
      }
    }

    while(!de.empty()) {
      cout << de.back() << ' ';
      de.pop_back();
    }
    cout << 0;
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