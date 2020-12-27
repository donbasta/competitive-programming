#include<bits/stdc++.h>
using namespace std;

#define pii pair<int, pair<int, int>> 

using ll = long long;
using ld = long double;

const int N = 1e5 + 69;

priority_queue<pii, vector<pii>, greater<pii>> edges;
vector<pair<int,int>> a, b;
ll ans;
int n, cnt;
int par[N], sz[N];

int fpar(int a) {
  return (a == par[a] ? a : par[a] = fpar(par[a]));
}

void merge(int a, int b) {
  int pa, pb;
  pa = fpar(a);
  pb = fpar(b);
  if(pa == pb)
    return;
  if(sz[a] > sz[b])
    swap(a, b);
  par[pa] = pb;
  sz[pb] += sz[pa];
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin >> n;
  for(int i = 1; i <= n; i++)
    par[i] = i, sz[i] = 1;
  for(int i = 1; i <= n; i++) {
    int x, y;
    cin >> x >> y;
    a.emplace_back(x, i);
    b.emplace_back(y, i);
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  for(int i = 1; i < n; i++) {
    edges.emplace(a[i].first - a[i - 1].first, make_pair(a[i].second, a[i - 1].second));
    edges.emplace(b[i].first - b[i - 1].first, make_pair(b[i].second, b[i - 1].second));
  }
  while(cnt < n - 1) {
    pii cur = edges.top();
    edges.pop();
    if(fpar(cur.second.first) == fpar(cur.second.second))
      continue;
    merge(cur.second.first, cur.second.second);
    ans += cur.first;
    cnt++;
  }
  cout << ans << '\n';
  return 0;
}