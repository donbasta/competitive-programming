#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int n, k, l, r, mid;
int ans1, ans2;
string que;
bool ok1, ok2;
int ca1, ca2;

void ask(int a, int b) {
  cout << 1 << ' ' << a << ' ' << b << endl;
  cin >> que;
  if(que == "TAK") {
    r = mid;
  } else if(que == "NIE") {
    l = mid + 1;
  }
}

void answer(int a, int b) {
  cout << 2 << ' ' << a << ' ' << b << endl;
  exit(0);
}

int main() {
  cin >> n >> k;
  l = 1;
  r = n;
  while(r > l) {
    mid = (l + r) >> 1;
    ask(mid, mid + 1);
  }
  ans1 = l;
  cerr << ans1 << " :D\n";
  if(ans1 < n) {
    l = ans1 + 1;
    r = n;
    while(r > l) {
      mid = (l + r) >> 1;
      ask(mid, mid + 1);
    }
    ca1 = l;
    if(l != ans1 + 1) {
      ok1 = true;
    }
  }
  if(ans1 > 1) {
    l = 1, r = ans1 - 1;
    while(r > l) {
      mid = (l + r) >> 1;
      ask(mid, mid + 1);
    }
    ca2 = l;
    if(l != ans1 - 1) {
      ok2 = true;
    }
  }
  if(!ok2) {
    answer(ans1, ca1);
  } else if(ok2) {
    answer(ans1, ca2);
  }
  cerr << "error";
  return 0;
}
