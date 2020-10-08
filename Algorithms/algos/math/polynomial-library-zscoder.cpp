
 
typedef vector<mi> vmi;
typedef pair<mi,mi> pmi;
typedef vector<pmi> vpmi;
 
vector<vmi> comb;
void genComb(int SZ) {
  comb.assign(SZ,vmi(SZ)); comb[0][0] = 1;
  FOR(i,1,SZ) F0R(j,i+1) 
    comb[i][j] = comb[i-1][j]+(j?comb[i-1][j-1]:0);
}
 
// For p < 2^30 there is also e.g. (5<<25, 3), (7<<26, 3) 
/// (479<<21, 3) and (483<<21, 5). Last two are > 10^9.
void genRoots(vmi& roots) { // REPLACE DEF OF MOD
  int n = sz(roots); mi r = pow(mi(root),(MOD-1)/n);
  roots[0] = 1; FOR(i,1,n) roots[i] = roots[i-1]*r; 
}
int size(int s) { return s > 1 ? 32-__builtin_clz(s-1) : 0; }
template<class T> void fft(vector<T>& a, 
  const vector<T>& rts, bool inv = 0) {
  int n = sz(a);
  for (int i = 1, j = 0; i < n; i++) { 
    int bit = n>>1; for (; j&bit; bit /= 2) j ^= bit;
    j ^= bit; if (i < j) swap(a[i],a[j]);
  } // sort #s from 0 to n-1 by reverse binary
  for (int len = 1; len < n; len *= 2)
    for (int i = 0; i < n; i += 2*len) F0R(j,len) {
      T u = a[i+j], v = a[i+j+len]*rts[n/2/len*j];
      a[i+j] = u+v, a[i+j+len] = u-v;
    }
  if (inv) {
    reverse(1+all(a));
    T i = T(1)/T(n); trav(x,a) x *= i; 
  }
}
template<class T> vector<T> mul(vector<T> a, vector<T> b) {
  if (!min(sz(a),sz(b))) return {};
  int s = sz(a)+sz(b)-1, n = 1<<size(s);
  vector<T> roots(n); genRoots(roots);
  a.rsz(n), fft(a,roots); b.rsz(n), fft(b,roots);
  F0R(i,n) a[i] *= b[i];
  fft(a,roots,1); a.rsz(s); return a;
}
typedef mi T; using poly = vector<T>;
void remz(poly& p) { while (sz(p) && p.bk==0) p.pop_back(); }
poly rev(poly p) { reverse(all(p)); return p; }
poly shift(poly p, int x) { p.insert(begin(p),x,0); return p; }
poly RSZ(poly p, int x) { p.rsz(x); return p; }
T eval(const poly& p, T x) {
  T res = 0; R0F(i,sz(p)) res = x*res+p[i]; 
  return res; }
poly dif(const poly& p) { // differentiate
  poly res; FOR(i,1,sz(p)) res.pb(i*p[i]); 
  return res; }
poly integ(const poly& p) { // integrate
  poly res(sz(p)+1); F0R(i,sz(p)) res[i+1] = p[i]/(i+1);
  return res; }
 
poly& operator+=(poly& l, const poly& r) {
  l.rsz(max(sz(l),sz(r))); F0R(i,sz(r)) l[i] += r[i]; 
  return l; }
poly& operator-=(poly& l, const poly& r) {
  l.rsz(max(sz(l),sz(r))); F0R(i,sz(r)) l[i] -= r[i]; 
  return l; }
poly& operator*=(poly& l, const T& r) { trav(t,l) t *= r; 
  return l;  }
poly& operator/=(poly& l, const T& r) { trav(t,l) t /= r; 
  return l; }
poly operator+(poly l, const poly& r) { return l += r; }
poly operator-(poly l, const poly& r) { return l -= r; }
poly operator-(poly l) { trav(t,l) t *= -1; return l; }
poly operator*(poly l, const T& r) { return l *= r; }
poly operator*(const T& r, const poly& l) { return l*r; }
poly operator/(poly l, const T& r) { return l /= r;  }
poly operator*(const poly& l, const poly& r) {
  if (!min(sz(l),sz(r))) return {};
  poly x(sz(l)+sz(r)-1); 
  F0R(i,sz(l)) F0R(j,sz(r)) x[i+j] += l[i]*r[j];
  return x;
}
poly& operator*=(poly& l, const poly& r) { return l = l*r; }
 
pair<poly,poly> quoRem(poly a, poly b) { 
  assert(sz(b)); auto B = b.bk; assert(B != 0);
  B = 1/B; trav(t,b) t *= B;
  remz(a); poly q(max(sz(a)-sz(b)+1,0));
  while (sz(a) >= sz(b)) {
    q[sz(a)-sz(b)] = a.bk;
    F0R(i,sz(b)) a[i+sz(a)-sz(b)] -= a.bk*b[i];
    remz(a);
  }
  trav(t,q) t *= B; 
  return {q,a};
}
poly interpolate(vector<pair<T,T>> v) {
  poly ret, prod = {1}; trav(t,v) prod *= poly({-t.f,1});
  F0R(i,sz(v)) {
    T fac = 1; F0R(j,sz(v)) if (i != j) fac *= v[i].f-v[j].f;
    ret += v[i].s/fac*quoRem(prod,{-v[i].f,1}).f;
  }
  return ret;
}
bool small(const poly& a, const poly& b) { // multiply directly
  return (ll)sz(a)*sz(b) <= 5000; } 
vmi smart(const vmi& a, const vmi& b) { return mul(a,b); }
poly conv(const poly& a, const poly& b) {
  return small(a,b) ? a*b : smart(a,b); } 
  
poly inv(poly A, int n) { // Q-(1/Q-A)/(-Q^{-2})
  poly B = {1/A[0]};
  while (sz(B) < n) {
    int x = 2*sz(B);
    B = RSZ(2*B-conv(RSZ(A,x),conv(B,B)),x);
  }
  return RSZ(B,n);
}
poly sqrt(const poly& A, int n) {  // Q-(Q^2-A)/(2Q)
  assert(A[0] == 1); poly B = {1};
  while (sz(B) < n) {
    int x = 2*sz(B);
    B = T(1)/T(2)*RSZ(B+mul(RSZ(A,x),inv(B,x)),x);
  }
  return RSZ(B,n);
}
pair<poly,poly> divi(const poly& f, const poly& g) { 
  if (sz(f) < sz(g)) return {{},f};
  auto q = mul(inv(rev(g),sz(f)-sz(g)+1),rev(f));
  q = rev(RSZ(q,sz(f)-sz(g)+1));
  auto r = RSZ(f-mul(q,g),sz(g)-1); return {q,r};
}
poly log(poly A, int n) { assert(A[0] == 1); // (ln A)' = A'/A
  return RSZ(integ(conv(dif(A),inv(A,n))),n); }
poly exp(poly A, int n) { // Q-(lnQ-A)/(1/Q)
  assert(A[0] == 0); poly B = {1};
  while (sz(B) < n) {
    int x = 2*sz(B);
    B = RSZ(B+conv(B,RSZ(A,x)-log(B,x)),x);
  }
  return RSZ(B,n);
}
poly power(const poly &A, int n, int N)
{
  poly bad = log(A,N);
  for(int i=0;i<bad.size();i++) bad[i]*=mi(n);
  bad=exp(bad,N);
  return bad;
}