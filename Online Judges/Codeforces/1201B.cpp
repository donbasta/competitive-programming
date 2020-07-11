#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ff first
#define ss second

int main(){

  int n,x,cur=0;
  vector<int> v,prefix;

  scanf("%d\n", &n);
  for(int i=0; i<n; i++){
    scanf("%d\n", &x);
    v.pb(x);
  }

  sort(v.begin(), v.end());

  prefix.pb(v[0]); cur=v[0];
  for(int i=1; i<n; i++){
    cur += v[i];
    prefix.pb(cur);
  }

  if(cur%2==1){
    printf("NO");
  } else {

  }

  



}
