#include <bits/stdc++.h>

using namespace std;

int main(void) {

	string str;
	string bomb;

	stack<char>s;

	cin >> str;
	cin >> bomb;

	char word = bomb[bomb.size() - 1];

	for (int i = 0; i < str.size(); i++) {
		
		s.push(str[i]);

		if (str[i] == word&& s.size() >= bomb.size()) {

			string chk;
			for (int j = 0; j < bomb.size(); j++) {
				chk += s.top();
				s.pop();
			}
			reverse(chk.begin(), chk.end());
			if (chk != bomb) {
				for (int i = 0; i < chk.size(); i++) {
					s.push(chk[i]);
				}
			}
		}

	}

	string st;
	while(!s.empty()){
	char w = s.top();
		st += w;
		s.pop();
	}

	if (st.size() == 0) {
		cout << "FRULA";
	}
	else{
		reverse(st.begin(), st.end());

		cout << st;
	}

	
	return 0;
}