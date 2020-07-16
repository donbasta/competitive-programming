// #include<bits/stdc++.h>
// using namespace std;

// using ll = long long;
// using ld = long double;

// const int N = 1e5;
// const int INF = 1e9;

// int n, m, k;
// int gr[N + 5], dis[N + 5];
// vector<int> to[N + 5], from[N + 5], pos, topo, start;
// bool vis[N + 5], con[N + 5]; 

// int mex(vector<int> ve) {
//   if(ve.empty())
//     return 0;
//   sort(ve.begin(), ve.end());
//   ve.resize(unique(ve.begin(), ve.end()) - ve.begin());
//   int sz = (int)ve.size();
//   for(int i = 0; i < sz; i++) {
//     if(i != ve[i])
//       return i;
//   }
//   return sz;
// }

// void dfs(int node){
//   vis[node] = true;
//   for(auto i : to[node]){
//     if(!vis[i]){
//       dfs(i);
//     }
//   }
//   topo.push_back(node);
// }

// void toposort(){
//   for(auto i : start) {
//     if(!vis[i])
//       dfs(i);
//   }
//   reverse(topo.begin(), topo.end());
// }

// void isi() {
//   for(auto i : topo) {
//     vector<int> lol;
//     for(auto j : from[i]) {
//       if(gr[j] >= 0)
//         lol.push_back(gr[j]);
//     }
//     gr[i] = mex(lol);
//     if(i == 1)
//       gr[i] = 0;
//     if((int)from[i].size() == 0)
//       gr[i] = 0;
//     if((int)from[i].size() == 1 && from[i][0] == 1)
//       gr[i] = -1;
//   }
// }

// int main() {
//   ios_base::sync_with_stdio(0);
//   cin.tie(0); cout.tie(0);

//   memset(gr, INF, sizeof(gr));
//   for(int i = 1; i <= N; i++) {
//     dis[i] = INF;
//   }

//   cin >> n >> m >> k;
//   bool lol = false;
//   for(int i = 1; i <= m; i++) {
//     int a, b;
//     cin >> a >> b;
//     if(b == 1)
//       con[a] = true;
//     to[b].push_back(a);
//     from[a].push_back(b);
//   }
//   for(int i = 1; i <= n; i++) {
//     if(from[i].empty()) {
//       start.push_back(i);
//     }
//   }
//   gr[1] = 0;
//   toposort();
//   isi();

//   for(int i = 0; i < k; i++) {
//     int a;
//     cin >> a;
//     pos.push_back(a);
//     if(con[a])
//       lol = true;
//   }
//   int ok = 0;
//   for(auto i : pos) {
//     ok ^= gr[i];
//   }
//   cout << ((ok || lol) ? "Chanek" : "Ganesh") << '\n';
//   return 0;
// }

#include<bits/stdc++.h>
using namespace std;
 
using ll = long long;
using ld = long double;
 
const int N = 1e5 + 10;
const int INF = 1e9;
 
int n, m, k;
int gr[N + 5];
vector<int> to[N + 5], from[N + 5], pos, topo;
bool vis[N + 5]; 
 
bool forbid[N];
 
int mex(vector<int> ve) {
  sort(ve.begin(), ve.end());
  int ret = 0;
  for (auto x : ve){
    if (ret == x) ret++;
    else if (x > ret) break;
  }
  return ret;
}
 
void dfs(int node){
  vis[node] = true;
  for(auto i : to[node]){
    if(!vis[i]){
      dfs(i);
    }
  }
  topo.push_back(node);
}
 
void toposort(){
  dfs(1);
  reverse(topo.begin(), topo.end());
}
 
void isi() {
  for(auto i : topo) {
    if (forbid[i] || i == 1) continue;
    vector<int> lol;
    for(auto j : from[i]) {
      if(gr[j] >= 0)
        lol.push_back(gr[j]);
    }
    gr[i] = mex(lol);
  }
}
 
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
 
  memset(gr, -1, sizeof(gr));
 
  cin >> n >> m >> k;
  bool lol = false;
  for(int i = 1; i <= m; i++) {
    int a, b;
    cin >> a >> b;
    to[b].push_back(a);
    from[a].push_back(b);
    if (b == 1){
      forbid[a] = 1;
      gr[a] = -1;
    }
  }
  gr[1] = 0;
  toposort();
  isi();
 
  for(int i = 0; i < k; i++) {
    int a;
    cin >> a;
    pos.push_back(a);
    if (forbid[a]){
      cout << "Chanek\n";
      return 0; 
    }
  }
  int ok = 0;
  for(auto i : pos) {
    ok ^= gr[i];
  }
  cout << (ok ? "Chanek" : "Ganesh") << '\n';
  return 0;
}