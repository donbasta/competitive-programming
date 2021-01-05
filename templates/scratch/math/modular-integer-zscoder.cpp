struct mi {
  typedef decay<decltype(MOD)>::type T; 
  /// don't silently convert to T
  T v; explicit operator T() const { return v; }
  mi() { v = 0; }
  mi(ll _v) { 
    v = (-MOD < _v && _v < MOD) ? _v : _v % MOD;
    if (v < 0) v += MOD;
  }
  friend bool operator==(const mi& a, const mi& b) { 
    return a.v == b.v; }
  friend bool operator!=(const mi& a, const mi& b) { 
    return !(a == b); }
  friend bool operator<(const mi& a, const mi& b) { 
    return a.v < b.v; }
   
  mi& operator+=(const mi& m) { 
    if ((v += m.v) >= MOD) v -= MOD; 
    return *this; }
  mi& operator-=(const mi& m) { 
    if ((v -= m.v) < 0) v += MOD; 
    return *this; }
  mi& operator*=(const mi& m) { 
    v = (ll)v*m.v%MOD; return *this; }
  mi& operator/=(const mi& m) { return (*this) *= inv(m); }
  friend mi pow(mi a, ll p) {
    mi ans = 1; assert(p >= 0);
    for (; p; p /= 2, a *= a) if (p&1) ans *= a;
    return ans;
  }
  friend mi inv(const mi& a) { assert(a.v != 0); 
    return pow(a,MOD-2); }
    
  mi operator-() const { return mi(-v); }
  mi& operator++() { return *this += 1; }
  mi& operator--() { return *this -= 1; }
  friend mi operator+(mi a, const mi& b) { return a += b; }
  friend mi operator-(mi a, const mi& b) { return a -= b; }
  friend mi operator*(mi a, const mi& b) { return a *= b; }
  friend mi operator/(mi a, const mi& b) { return a /= b; }
  friend ostream& operator<<(ostream& os, const mi &m)
  {
    os<<int(m);
    return os;
  }
};