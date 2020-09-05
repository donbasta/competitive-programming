#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  multiset<int> se;
  se.insert(10);
  se.insert(10);
  se.insert(20);
  cout << se.size() << '\n';
  se.erase(se.find(10));
  cout << se.size() << '\n';
  for(auto i : se) {
    cout << i << ' ';
  }
  
  return 0;
}