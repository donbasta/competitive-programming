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
  l = ans1;
  r = n;
  while(r > l) {
    mid = (l + r) >> 1;
    ask(mid, mid + 1);
  }
  if(l != ans1) {
    ok1 = true;
    ca1 = l;
  }
  l = 1, r = ans1;
  while(r > l) {
    mid = (l + r) >> 1;
    ask(mid, mid + 1);
  }
  if(l != ans1) {
    ok2 = true;
    ca2 = l;
  }
  if(ok1) {
    answer(ans1, ca1);
  } else if(ok2) {
    answer(ans1, ca2);
  }
  cerr << "error";
  return 0;
}
