#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ff first
#define ss second
#define MAXN 100000

int logg[MAXN+5], a[MAXN+5], qu[3*MAXN+5];
int gcdd[MAXN+5][20];
int n,q;
map<int, int> m;

void precompute(){
  logg[1]=0;
  for(int j=2; j<=MAXN; j++){
    logg[j]=logg[j/2]+1;
  }
}

int main(){
  precompute();
  scanf("%d", &n);
  for(int i=1; i<=n; i++){
    scanf("%d", &a[i]);
  }
  scanf("%d", &q);
  for(int i=1; i<=q; i++){
    scanf("%d", &qu[i]);
  }

  for(int i=1; i<=n; i++){
    gcdd[i][0]=a[i];
    m[gcdd[i][0]]++;
  }

  for(int j=1; j<=20; j++){
    for(int i=1; i+(1<<j) <= n; i++){
      gcdd[i][j] = __gcd(gcdd[i][j-1],gcdd[i+(1<<(j-1))][j-1]);
      m[gcdd[i][j]]++;
    }
  }

  for(int i=1; i<=q; i++){
    printf("%d\n", m[qu[i]]);
  }

}
