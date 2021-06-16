#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int N = 1e4 + 69;

string t, resp;
int n;
int pos1[N], pos2[N], pos3[N];

void ask1() {
  string query(n, ' ');
  bool ok = false;
  for(int i = 0; i < 26; i++) {
    for(int j = 0; j < 676; j++) {
      int cur = i * 676 + j;
      if(cur >= n){
        ok = true;
        break;
      }
      query[cur] = (char) (i + 97);
    }
    if(ok) break;
  }
  cout << "? " << query << endl;
}

void upd1() {
  for(int i = 0; i < n; i++) {
    pos1[i] = resp[i] - 'a';
  }
}

void ask2() {
  string query(n, ' ');
  bool ok = false;
  for(int i = 0; i < 26; i++) {
    for(int j = 0; j < 26; j++) {
      for(int k = 0; k < 26; k++) {
        int cur = i * 676 + j * 26 + k;
        if(cur >= n) {
          ok = true;
          break;
        }
        query[cur] = (char) (j + 97);
      }
      if(ok) break;
    }
    if(ok) break;
  }
  cout << "? " << query << endl;
}

void upd2() {
  for(int i = 0; i < n; i++) {
    pos2[i] = pos1[i] * 26 + (resp[i] - 'a');
  }
}

void ask3() {
  string query(n, ' ');
  bool ok = false;
  for(int i = 0; i < n; i++) {
    query[i] = (char) ((i % 26) + 97);
  }
  cout << "? " << query << endl;
}

void upd3() {
  for(int i = 0; i < n; i++) {
    pos3[i] = 26 * pos2[i] + (resp[i] - 'a');
  }
}

void ans() {
  string query(n, ' ');
  for(int i = 0; i < n; i++) {
    assert(pos3[i] < n);
    query[pos3[i]] = t[i];
  }
  cout << "! " << query << endl;
  // string fin;
  // cin >> fin;
  exit(0);
}

int main() {
  cin >> t;
  n = (int)t.length();

  ask1();
  cin >> resp;
  upd1();

  ask2();
  cin >> resp;
  upd2();

  ask3();
  cin >> resp;
  upd3();

  ans();
  return 0;
}
