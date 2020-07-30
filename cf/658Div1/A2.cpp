#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n;
string a, b;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tc;
  cin >> tc;
  while(tc--) {
    cin >> n >> a >> b;
    vector<int> ans;
    bool isFlip = false;
    int idxFront = 0;
    for(int i = n; i >= 1; i--) {
      char curFront = a[idxFront];
      if(isFlip)
        if(curFront == '1')
          curFront = '0';
        else
          curFront = '1';
      if(b[i - 1] != curFront) {
        ans.push_back(i);
        if(isFlip)
          idxFront = idxFront - i + 1;
        else
          idxFront = idxFront + i - 1;
        isFlip ^= 1;
        //flip and reverse a dari 1..i
      } else {
        ans.push_back(1);
        //flip and reverse a1
        ans.push_back(i);
        if(isFlip)
          idxFront = idxFront - i + 1;
        else
          idxFront = idxFront + i - 1;
        isFlip ^= 1;
        //flip and reverse a dari 1..i
      }
    }
    cout << (int)ans.size() << ' ';
    for(auto i : ans) {
      cout << i << ' ';
    }
    cout << '\n';
  }
  return 0;
}