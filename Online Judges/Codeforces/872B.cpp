#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ff first
#define ss second
#define MIN -1000000000;

int main(){

  int n,k,ans;
  scanf("%d %d", &n, &k);
  int a[n+5], maks=MIN;
  int pre[n+5], post[n+5];
  pre[0]=-MIN; post[n+1]=-MIN;
  for(int i=1; i<=n; i++){
    scanf("%d", &a[i]);
    maks = max(maks,a[i]);
    pre[i] = min(a[i],pre[i-1]);
  }

  for(int i=n; i>=1; i--){
    post[i] = min(a[i],post[i+1]);
  }

  if(k==1) ans=pre[n];
  else if(k==2){
    if(a[1]==maks || a[n]==maks) ans=maks;
    else{
      maks = MIN;
      for(int i=1; i<=n-1; i++){
        maks = max(maks,max(pre[i],post[i+1]));
      }
      ans=maks;
    }
  }
  else {
    ans=maks;
  }

  printf("%d", ans);






}
