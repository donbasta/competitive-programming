#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int ans;

void ask(int a, int b) {
  cout << "? " << a << " " << b << endl;
  cin >> ans;
}

void process(int a, int b) {
  if (ans == 32) {
    
  }
}

void solve() {

  int ans = 4*8*15*16*23*42;

  ask(1, 2);
  ans /= ask;
  process1(1, 2);
  ask(3, 4);
  ans /= ask;
  process1(3, 4);
  process1(5, 6);
  ask(1, 4)
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