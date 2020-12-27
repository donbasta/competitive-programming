#include <bits/stdc++.h>

int n;
vector<vector<int>> adj(n);
vector<int> deg(n);

for(int i = 0; i < n; i++) {
  deg[i] = (int) adj[i].size();
}

//find starting vertex
int fi = 0;
while(!deg[fi])
  fi++;

int v1 = -1, v2 = -1;
bool bad = false;
for(int i = 0; i < n; i++) {
  if(deg[i] & 1) {
    if(v1 == -1) v1 = i;
    else if(v2 == -1) v2 == i;
    else bad = true;
  }
}

if(v1 != -1 && v2 == -1)
  bad = true;

if(bad)
  //gaada euler tour, lgsg break aja

if(v1 != -1){
  first = v1;
  adj[v1].push_back(v2), adj[v2].push_back(v1);
}

stack<int> st;
st.emplace(first);
vector<int> res;
while(!st.empty()) {
  int v = st.top();
  if(deg[v] == 0) {
    res.push_back(v);
    st.pop();
  } else {
    for(int i = deg[v] - 1; i >= 0; i--) {
      int cur = adj[i];
      adj[v].pop_back();
      if(del[cur].find(v) != del[cur].end())
        continue;
      else {
        
      }
    }
    int next = adj[v].back();
    if(del[next].find())
    adj[v].pop_back();
    //di adj[next], buang v
    deg[v]--;
    deg[next]--;
    st.push(next);
  }
}

for(int x : res) {
  cout << x << ' ';
}
