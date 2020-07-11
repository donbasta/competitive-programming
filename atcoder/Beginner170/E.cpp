#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int N = 2e5 + 69;

int n, q;
multiset<int> kg[N];
multiset<int> even;
int inf[N], grup[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  cin >> n >> q;
  for(int i = 1; i <= n; i++) {
    int a, b;
    cin >> a >> b;
    inf[i] = a;
    grup[i] = b;
    kg[b].insert(a);
  }
  for(int i = 1; i <= N - 69; i++) {
    if(kg[i].empty())
      continue;
    even.insert(*kg[i].rbegin());
  }
  while(q--) {
    int c, d;
    cin >> c >> d;
    int rat = inf[c], cur = grup[c];
    if(rat == *kg[cur].rbegin()) {
      even.erase(even.find(rat));
      kg[cur].erase(kg[cur].find(rat));
      if(!kg[cur].empty())
        even.insert(*kg[cur].rbegin());
    } else {
      kg[cur].erase(kg[cur].find(rat));
    }
    grup[c] = d;
    if(!kg[d].empty() && rat > *kg[d].rbegin()) {
      even.erase(even.find(*kg[d].rbegin()));
      even.insert(rat);
      kg[d].insert(rat);
    } else if(kg[d].empty()) {
      even.insert(rat);
      kg[d].insert(rat);
    } else {
      kg[d].insert(rat);
    }
    cout << *even.begin() << '\n';
  }
  return 0;
}
