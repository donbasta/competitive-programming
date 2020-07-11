#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const ll MAX = 1e18;

vector<ll> res;
map<pair<int, int>, int> mp;
vector<pair<int, int>> ve;
vector<int> adj[2500];
map<ll, int> bt[2500];
ll val[2500];
int cur = 0;

void precomp() {
  ll pw2 = 1;
  for(int i = 0; i <= 60; i++) {
    ll prod = pw2;
    for(int j = 0; j <= 40; j++) {
      if(prod > MAX)
        break;
      // mp[make_pair(i, j)] = cur;
      ve.emplace_back(i, j);
      val[cur] = prod;
      cur++;
      prod *= 3;
    }
    pw2 *= 2;
  }
  for(int i = 0; i < cur; i++) {
    for(int j = 0; j < cur; j++) {
      if(ve[i].first < ve[j].first && ve[i].second > ve[j].second) {
        adj[i].push_back(j);
      }
    }
  }
}

void dfs(int v, ll now) {
  ll temp = val[v];
  cerr << v << '\n';
  for(auto child : adj[v]) {
    bt[child][now + temp] = v;
    dfs(child, now + temp);
  }
}

void go() {
  for(int i = 0; i < cur; i++) {
    bt[i][-1] = val[i];
    dfs(i, val[i]);
  }
}

void backtrack(int v, ll now) {
  if(v == -1) {
    return;
  }
  res.emplace_back(val[v]);
  int next = bt[v][now];
  backtrack(next, now - val[next]);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  freopen("input.in", "r", stdin);
  freopen("output.out", "w", stdout);

  cerr << "lol";
  precomp();
  cerr << "lol";
  go();
  cerr << "lol";

  int tc;
  cin >> tc;
  while(tc--) {

    ll n;
    cin >> n;
    for(int i = 0; i < cur; i++) {
      if(bt[i].find(n) != bt[i].end()){
        backtrack(i, n);
        break;
      }
    }
    cout << (int)res.size() << '\n';
    for(auto i : res) {
      cout << i << ' ';
    }
    cout << '\n';

    //reset
    for(int i = 0; i < cur; i++) bt[i].clear();
    res.clear();
  }
  return 0;
}
