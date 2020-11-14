#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void print_deque(deque<int>* DE) {
  for (int i = 0; i < DE->size(); i++) {
    cout << (*DE)[i] << ' ';
  }
  cout << '\n';
}

unordered_map<int, deque<int>*> lol;

void solve() {
  // deque<int>* de;
  // de = new deque<int>();
  // // cerr << "tes";
  // de->push_back(1);
  // // cerr << "tes";
  // cerr << de->size() << '\n';
  // de->push_back(5);
  // print_deque(de);
  // de->push_back(7);
  // print_deque(de);
  // de->push_back(100);
  // print_deque(de);
  // de->push_back(21);
  // print_deque(de);
  // de->push_back(23);
  // print_deque(de);
  // de->pop_front();
  // print_deque(de);
  // de->pop_back();
  // print_deque(de);
  // (*de)[2] = 90;
  // print_deque(de);

  (*lol[69]).push_back(1);
  print_deque(lol[69]);
  cout << (*lol[69])[0];


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