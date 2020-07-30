#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;

template <int _MOD> struct mint {
  static constexpr int MOD = _MOD;

private:
  int val;
  static int minv(int a, int m) { //inverse of a in modulo m
    a %= m;
    assert(a);
    return a == 1 ? 1 : int(m - 1LL * minv(m, a) * m / a);
  }
public:
  mint() : val(0) {}
  mint(long long _val) : val((int) (_val % MOD)) {if (val < 0) val += MOD;}
  friend ostream& operator<< (ostream& out, const mint& m) {return out << m.val;}
  friend istream& operator>> (istream& in, mint& m) { ll _val; in >> _val; m = mint(_val); return in;}

  friend bool operator== (const mint& a, const mint& b) {return a.val == b.val;}
  friend bool operator!= (const mint& a, const mint& b) {return a.val != b.val;}
  mint inv() const {mint ret; ret.val = minv(val, MOD); return ret;}
  friend mint inv(const mint& m) {return m.inv();}
  mint neg() const {mint ret; ret.val = val ? (MOD - val) : 0; return ret;}
  friend mint neg(const mint& m) {return m.neg();}
  mint operator-() const {return neg();}
  mint operator+() const {return *this;}
  mint& operator++() {val++; if(val == MOD) val = 0; return *this;}
  mint& operator--() {if(val == 0) val = MOD; val--; return *this;}
  mint& operator+=(const mint& other) {val += other.val; if(val >= MOD) val -= MOD; return *this;}
  mint& operator-=(const mint& other) {val -= other.val; if(val < 0) val += MOD; return *this;}
  mint& operator*=(const mint& other) {val = (1LL * val * other.val % MOD); return *this;}
  mint& operator/=(const mint& other) {return *this *= other.inv();}

  friend mint operator++ (mint& a, int) { mint r = a; ++a; return r; }
  friend mint operator-- (mint& a, int) { mint r = a; --a; return r; }
  friend mint operator+ (const mint& a, const mint& b) { return mint(a) += b; }
  friend mint operator- (const mint& a, const mint& b) { return mint(a) -= b; }
  friend mint operator* (const mint& a, const mint& b) { return mint(a) *= b; }
  friend mint operator/ (const mint& a, const mint& b) { return mint(a) /= b; }
  friend mint pow(mint a, ll b) {
    mint ret = 1;
    while(b) {if(b & 1) ret *= a; a *= a; b >>= 1;}
    return ret;
  }

};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  mint<mod> lol = 3;
  cout << pow(lol, 7) << ' ' << pow(lol + 1, 3) << '\n'; //2187 64
  lol++; //lol = 4
  cout << pow(lol, 2) * inv(lol) *  inv(lol) << '\n'; //1
  
  return 0;
}