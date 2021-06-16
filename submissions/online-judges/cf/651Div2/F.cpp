#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int N = 1e3 + 69;

int n, root, len, mx = -1;
int qnode, qlen;
int n1, n2;
vector<int> adj[N], dp[N];
string verdict;

void askAll() {
  cout << "? " << n;
  for(int i = 1; i <= n; i++) {
    cout << ' ' << i;
  }
  cout << endl;
  cin >> root >> len;
  // if(root == -1 && len == -1) {
  //   exit(0);
  // }
}

bool askDepth(int depth) {
  cout << "? " << (int)dp[depth].size();
  for(auto i : dp[depth]) {
    cout << ' ' << i;
  }
  cout << endl;
  cin >> qnode >> qlen;
  // if(qnode == -1 && qlen == -1)
  //   exit(0);
  if(qlen > len) {
    return 1;
  }
  assert(qlen == len);
  return 0;
}

void dfs(int node, int par, int depth) {
  mx = max(mx, depth);
  dp[depth].push_back(node);
  for(auto i : adj[node]) {
    if(i == par)
      continue;
    dfs(i, node, depth + 1);
  }
}

int main() {

  int tc;
  cin >> tc;
  while(tc--) {
    cin >> n;
    for(int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    askAll();
    dfs(root, -1, 0);
    int le = (len + 1) / 2, ri = min(len, mx), dep1 = le;
    while(ri >= le) {
      int mid = (le + ri) / 2;
      if(askDepth(mid)) {
        ri = mid - 1;
      } else {
        dep1 = mid;
        le = mid + 1;
      }
    }
    askDepth(dep1);
    n1 = qnode;
    int t = len - dep1;
    if(t != dep1) {
      askDepth(t);
      n2 = qnode;
    } else {
      cout << "? " << (int)dp[t].size() - 1;
      for(auto i : dp[t]) {
        if(i == n1)
          continue;
        cout << ' ' << i;
      }
      cout << endl;
      cin >> n2;
    }
    cout << "! " << n1 << ' ' << n2 << endl;
    cin >> verdict;
    for(int i = 0; i <= N - 60; i++) {
      adj[i].clear();
      dp[i].clear();
    }
    mx = -1;
  }
  return 0;
}
