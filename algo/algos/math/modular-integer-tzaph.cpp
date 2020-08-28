struct mint{
  int val;
  mint(){val=0;}
  mint(const ll& v){
    val=(-mod<=v && v<mod)?v:v%mod;
    if(val<0) val+=mod;
  }
  friend ostream& operator<<(ostream&os, const mint&a){return os<<a.val;}
  friend bool operator==(const mint&a, const mint&b){return a.val==b.val;}
  friend bool operator!=(const mint&a, const mint&b){return a.val!=b.val;}
  friend bool operator<(const mint&a, const mint&b){return a.val<b.val;}
  friend bool operator>(const mint&a, const mint&b){return a.val>b.val;}
  friend bool operator<=(const mint&a, const mint&b){return a.val<=b.val;}
  friend bool operator>=(const mint&a, const mint&b){return a.val>=b.val;}
 
  mint operator-(){return mint(-val);}
  mint& operator+=(const mint&m){if((val+=m.val)>=mod) val-=mod; return *this;}
  mint& operator-=(const mint&m){if((val-=m.val)<0) val+=mod; return *this;}
  mint& operator*=(const mint&m){val=(val*1ll*m.val)%mod; return *this;}
  friend mint pow(mint a, int p){
    mint ans=mint(1);
    for(; p; p/=2, a*=a)
      if(p%2==1) ans*=a;
    return ans;
  }
  friend mint inv(const mint&a){return pow(a, mod-2);}
  mint& operator/=(const mint&m){return (*this)*=inv(m);}
  friend mint operator+(mint a, const mint&b){return a+=b;}
  friend mint operator-(mint a, const mint&b){return a-=b;}
  friend mint operator*(mint a, const mint&b){return a*=b;}
  friend mint operator/(mint a, const mint&b){return a/=b;}
};