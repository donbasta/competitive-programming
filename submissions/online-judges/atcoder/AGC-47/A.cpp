#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void build(int v, int s, int e) {
  if(s == e) {
    t[v] = vector<int>(1, );
  } else {
    build(v << 1, s, mid);
    build(v << 1 | 1, mid + 1, e);
    merge(t[v << 1].begin(), t[v << 1].end(), t[v << 1 | 1].begin(), t[v << 1 | 1].end(), back_inserter(t[v]));
  }
}

int que(int v, int s, int e, int l, int r, int val1, int val2) {
  if()
}

int vp(int a, ll b) {
  int ret = 0;
  while(b % a == 0) {
    b /= a;
    ret++;
  }
  return ret;
}

void solve() {
  cin >> n;
  vector<int> vepe
  for(int i = 0; i < n; i++) {
    string x;
    cin >> x;
    string temp = "";
    bool on = false;
    int num = 0;
    for(auto i : x) {
      if(i == '.') {on = true;}
      temp += i;
      if(on) num++;
    }
    ar[i] = stoll(temp);
    pw[i] = num;
    vepe[i].first = vp(2, ar[i]);
    vepe[i].second = vp(2, ar[i]);
  }
  for(int i = 0; i < n; i++) {
    
  }


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