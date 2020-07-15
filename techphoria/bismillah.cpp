#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define foru(i,a,b) for(int i = (int) a; i < (int) b; i++)
#define ford(i,a,b) for(int i = (int) a; i > (int) b; i--)
#define fors(i,n) for(int i = 0; i < n; i++)
#define fill(a,b) memset(a, (b), sizeof(a))
#define pii pair<int, int>
#define pll pair<long long, long long>

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
	cout.tie(NULL);
	
	string s,t;
	cin>>s>>t;
	int a = (int) s.length();
	int a1[a+5], a2[a+5], cur;
	a1[0] = 0; a2[0] = 0;

	//a1[i] is the number of prefix of t in the first i letters of s
	cur=0;
	for(int i=0; i<a; i++){
		if(s[i]==t[cur]) {
			a1[i+1]=cur+1; cur++;
		} else {
			a1[i+1]=cur;
		}
	}

	//a2[i] is the number of suffix of t in the last i letters of s
	cur=(int) t.length()-1;
	for(int i=s.length()-1; i--){
		if(s[i]==t[cur]) {
			a2[s.length()-i]=t.length()-cur; cur--;
		} else {
			a2[s.length()-i]=t.length()-cur-1;
		}
	}

	int lo,hi;
	for(int i=0; i<a; i++){
		int depan,belakang;
		lo=i; hi=s.length();
		while(lo<=hi){
			depan = a1[lo];
			belakang = a2[s.length()-hi];
			if(depan + belakang < t.length()){
				hi = med-1;
			} else {
				lo = med;
			}
		}
	}
}