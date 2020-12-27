#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;
using ld = double;
using cd = complex<ld>;
 
const ld PI = acos(-1);
 
void fft(vector<cd>& a, bool invert) {
  int n = (int)a.size();
  for(int i = 1, j = 0; i < n; i++) {
    int bit = n >> 1;
    for(; j & bit; bit >>= 1) { j ^= bit; }
    j ^= bit;
    if(i < j) { swap(a[i], a[j]); }
  }
  for(int len = 2; len <= n; len <<= 1) {
    ld ang = 2 * PI / len * (invert ? -1 : 1);
    cd wlen(cos(ang), sin(ang));
    for(int i = 0; i < n; i += len) {
      cd w(1);
      for(int j = 0; j < len / 2; j++) {
        cd u = a[i + j], v = a[i + j + len / 2] * w;
        a[i + j] = u + v;
        a[i + j + len / 2] = u - v;
        w *= wlen;
      }
    }
  }
  if(invert) {
    for(auto & x : a) { x /= n; }
  }
}
 
vector<cd> conv(vector<cd> const& a, vector<cd> const& b) {
  vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
  int n = 1;
  while(n < (int)a.size() + b.size()) { n <<= 1; }
  fa.resize(n), fb.resize(n);
  fft(fa, false), fft(fb, false);
  for(int i = 0; i < n; i++) { fa[i] *= fb[i]; }
  fft(fa, true);
  return fa;
}
 
const string gen = "ACGT";
const int N = 2e5;
int ls, lt, k;
string s, t;
int ans[N + 5];
 
void solve() {
  cin >> ls >> lt >> k;
  cin >> s >> t;
  for(int i = 0; i < 4; i += 2) {
    vector<int> t1(ls + 1), t2(ls + 1);
    for(int j = 0; j < ls; j++) {
      t1[j + 1] = t1[j] + (s[j] == gen[i]);
      t2[j + 1] = t2[j] + (s[j] == gen[i + 1]);
    }
    vector<cd> A(lt), B(ls);
    for(int j = 1; j <= ls; j++) {
      int l = max(1, j - k), r = min(ls, j + k);
      int lol1 = t1[r] - t1[l - 1];
      int lol2 = t2[r] - t2[l - 1];
      if(lol > 0) B[j - 1] = cd(1);
      else B[j - 1] = cd(0);
    }
    int cnt = 0;
    for(int j = 0; j < lt; j++) {
      if(t[j] == gen[i]) { A[j] = cd(1); cnt++; }
      else A[j] = cd(0);
    }
    reverse(B.begin(), B.end());
    vector<cd> Prod = conv(A, B);
    for(int j = 0; j < ls - lt + 1; j++) {
      int cur = (int) round(Prod[j + lt - 1].real());
      if(cur == cnt) { ans[j]++; }
    }
  }
  int Ans = 0;
  for(int i = 0; i < ls - lt + 1; i++) { if(ans[i] == 4) Ans++; }
  cout << Ans << '\n';
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