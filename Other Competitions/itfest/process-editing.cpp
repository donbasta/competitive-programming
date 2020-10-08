#include <bits/stdc++.h>
using namespace std;

const char SEP = ' ';

string LOW(string a){
	string ans = "";
	for(auto i : a){
		ans += tolower(i);
	}
	return ans;
}

int main(){

	ifstream fin ("input.txt");

	int N;
	fin >> N;
	fin.ignore();
	// cin >> N;
	// cin.ignore();
	while(N--){
		string s;
		getline(fin, s);

		bool kata;
		string tmp = "";
		int cur = 0;

		vector<int> space;
		vector<string> words;

		if(s[0]==SEP){
			kata = false;
			cur++;
		} else {
			kata = true;
			tmp += s[0];
		}

		if(kata) space.push_back(0);

		int i = 1;
		while(i<(int)s.length()){
			if(s[i]!=SEP && kata){
				tmp += s[i];
			} else if(s[i]!=SEP && !kata){
				kata = true;
				space.push_back(cur);
				tmp = ""; tmp += s[i];
			} else if(s[i]==SEP && !kata){
				cur++;
			} else if(s[i]==SEP && kata){
				kata = false;
				words.push_back(tmp);
				cur = 1;
			}
			i++;
		}

		if(kata){
			words.push_back(tmp);
		}

		if((int)words.size()==0) cout << "\n";
		else {
			string temp = LOW(words[0]);
			for(int i=1; i<(int)words.size(); i++){
				if(LOW(words[i])==LOW(temp)){
					words[i] = "";
				} else {
					temp = LOW(words[i]);
				}
			}

			// for(int i=0; i<(int)words.size(); i++){
			// 	for(int j=0; j<space[i]; j++) cout << SEP;
			// 	cout << words[i];
			// }

			for(auto i : words){
				if(i!="") cout << i << " ";
			}

			if(N>0) cout << "\n";
		}
		


	}

}
