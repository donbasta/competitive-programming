#include<bits/stdc++.h>
using namespace std;

vector<int> ZAlgorithm(string S) {
  int n = (int)S.length();
  vector z(n);
  int l, r;
  for(int i = 1, l = 0, r = 0; i < n; i++) {
    if(i <= r)
      z[i] = min(r - i + 1, z[i - l]);
    while(i + z[i] < n && S[i + z[i]] == S[z[i]]) 
      z[i]++;
    if(z[i] > r - i + 1) 
      l = i, r = i + z[i] - 1;
  }
  return z;
}


int main() {
  
  return 0;
}