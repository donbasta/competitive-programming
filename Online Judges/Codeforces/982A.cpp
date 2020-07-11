#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ff first
#define ss second

int main(){
  string s;
  int cur,n;
  bool ans=true,last;

  cin>>n>>s;

  s = '0' + s + '0';

  last = true; cur=1;
  for(int i=1; i<=n+1; i++){
    if(!last && s[i]=='0') {cur=1; last=true;}
    else if(last && s[i]=='0') cur++;
    else if(!last && s[i]=='1') ans=false;
    else if(s[i]=='1') last=false;
    if(cur>=3) ans=false;
  }

  if (ans) cout << "Yes"; else cout << "No";
}
