#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 2e5 + 69;

int n;
int ar[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;
  for(int i = 1; i <= n; i++)
    cin >> ar[i];
  for(int i = n; i >= 1; i -= 2)
    cout << ar[i] << ' ';
  int cur = 1 + (n & 1);
  for(int i = cur; i <= n; i += 2)
    cout << ar[i] << ' ';
  
  return 0;
}