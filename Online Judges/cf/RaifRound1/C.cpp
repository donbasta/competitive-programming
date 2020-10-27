#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  stack<char> st;
  string s;
  cin >> s;
  for(auto& c : s) {
    if(st.empty()) {
      st.push(c);
    } else {
      char top = st.top();
      if(c == 'B') {
        st.pop();
      } else {
        st.push(c);
      }
    }
  }
  cout << (int)st.size() << '\n';
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