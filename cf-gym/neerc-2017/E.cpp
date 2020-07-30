#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int M = 1000;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;
  vector<int> ar, cnt(M + 1, 0);
  for(int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    if(x > 0) {
      cnt[x]++;
    } else if(x < 0) {
      if(cnt[-x] > 0) {
        cnt[-x]--;
      } else {
        ar.push_back(x);
      }
    } else {
      ar.push_back(x);
    }
  }
  vector<int> ans;
  queue<int> need;
  for(int i = (int)ar.size() - 1; i >= 0; i--) {
    if(ar[i] == 0) {
      if(need.empty()) {
        ans.push_back(1);
      } else {
        ans.push_back(need.front());
        need.pop();
      }
    } else if(ar[i] < 0) {
      need.push(-ar[i]);
    }
  }
  if(!need.empty()) {
    cout << "No";
  } else {
    cout << "Yes\n";
    reverse(ans.begin(), ans.end());
    for(auto i : ans) {
      cout << i << ' ';
    }
  }
  cout << '\n';
  
  return 0;
}