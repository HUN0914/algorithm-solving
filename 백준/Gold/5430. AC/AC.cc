#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(void) {

	int t;
	cin >> t;
	while (t--) {
		string command;
		int n;
		deque<int>dq;
		string temp = "";
		cin >> command >> n;

		string input;
		cin >> input;

		for (int i = 1; i < input.size(); i++) {
			if (isdigit(input[i])) {
				temp += input[i];
			}

			if (input[i] == ',' || input[i] == ']') {
				if (!temp.empty()) {
					dq.push_back(stoi(temp));
					temp = "";
				}
			}
		}

		bool reverseflag = false;
		bool errorflag = false;

		//R의 여부는 D인 상황일 때에만 고려해주면 됨. 굳이 계속 바꿔치기하면서 시간복잡도 늘릴 필요가 없단 것 의미

		for (char c : command) {
			if (c == 'R') {
				reverseflag = !reverseflag;
			}
			else if (c == 'D') {
				if (dq.empty()) {
					errorflag = true;
					break;
				}
				
				if (reverseflag) {
					dq.pop_back();
				}
				else
				{
					dq.pop_front();
				}
			}
		}
		
		if (errorflag) {
			cout << "error" << "\n";
		}
		else
		{
			cout << "[";
			if (reverseflag) {
				for (auto i = dq.rbegin(); i != dq.rend(); i++) {
					cout << *i;
					if (i != dq.rend() - 1) {
						cout << ',';
					}
				}

			}
			else {
				for (auto i = dq.begin(); i != dq.end(); i++) {
					cout << *i;
					if (i != dq.end() - 1) {
						cout << ',';
					}
				}

			}

			cout << "]\n";
		}
	}


	return 0;
}