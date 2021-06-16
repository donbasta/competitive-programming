#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 2e5;

int pos[N + 5];
vector<int> ve;
unordered_map<int, int> mp;

void fastscan(int &number) 
{ 
    //variable to indicate sign of input number 
    bool negative = false; 
    register int c; 
  
    number = 0; 
  
    // extract current character from buffer 
    c = getchar(); 
    if (c=='-') 
    { 
        // number is negative 
        negative = true; 
  
        // extract the next character from the buffer 
        c = getchar(); 
    } 
  
    // Keep on extracting characters if they are integers 
    // i.e ASCII Value lies from '0'(48) to '9' (57) 
    for (; (c>47 && c<58); c=getchar()) 
        number = number *10 + c - 48; 
  
    // if scanned input has a negative sign, negate the 
    // value of the input number 
    if (negative) 
        number *= -1; 
} 

void solve() {
  int n;
  fastscan(n);
  vector<int> k(n + 1);
  for(int i = 1; i <= n; i++) {
    int x;
    fastscan(x);
    k[i] = x;
    ve.push_back(x);
  }
  sort(ve.begin(), ve.end());
  ve.resize(unique(ve.begin(), ve.end()) - ve.begin());
  for(int i = 0; i < (int)ve.size(); i++) {
    mp[ve[i]] = i;
  }
  int ans = 1, r = 0;
  for(int i = 1; i <= n; i++) {
    int last = pos[mp[k[i]]];
    r = max(r, last);
    ans = max(ans, i - r);
    pos[mp[k[i]]] = i;
  }
  cout << ans << '\n';
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