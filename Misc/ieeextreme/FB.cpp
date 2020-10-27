#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  string S;
  cin >> S;
  vector<int> tape(100);
  int ptr = 0;
  bool isLooping  = false;
  vector<int> loopStack;
  int innerLoops = 0;

  for (int i = 0; i < (int)S.length(); i++) {
    char c = S[i];
    if (isLooping) {
      if (c == '[') innerLoops++;
      if (c == ']') {
        if (innerLoops == 0) isLooping = 0;
        else innerLoops--;
      }
      continue;
    }
    if (c == '+') {
      tape[ptr]++;
    } else if (c == '-') {
      tape[ptr]--;
    } else if (c == ',') {
      tape[ptr] = 
    } else if (c == '.') {

    } else if (c == '>') {

    } else if (c == '<') {

    } else if (c == '[') {

    } else if (c == ']') {

    }
    break;
  }
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