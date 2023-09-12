#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
int n, m;
vector<int>v;
bool sel[8] = { 0, };
vector<int>cho;
//끝 값만 다르면 됨
//값을 저장하고 비교하기?

int val2=0;

void dfs(int cnt) {
    if (cnt == m) {
        for (int i = 0; i < m; i++) {
            cout << cho[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        if (i > 0 && v[i] == v[i - 1]) {
            continue; // 중복된 숫자 건너뛰기
        } 
        /*sort 했을 때 v에서 직전과 다음 값과 같으면
        볼 필요가 없기 때문에, 위와 같이 지정 
        cho[i]==cho[i-1] 가 아니라, v[i]==v[i-1]이다!
        
        */
        cho.push_back(v[i]);
        dfs(cnt + 1);
        cho.pop_back();
    }
}





int main(void) {


	cin >> n >> m;
	
	int val;

	for (int i = 0; i < n; i++)
	{
		cin >> val;
		v.push_back(val);

	}

	sort(v.begin(), v.end());

	dfs(0);



}
