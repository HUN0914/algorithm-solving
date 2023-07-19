#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//코드 구글링..
vector<int> height; //가로 좌표
vector<int> width; //세로 좌표
vector<int> height_length; //가로 길이
vector<int> width_length; //세로 길이
int w, h; //총 가로 길이, 총 세로 길이
int num; //좌표

int main() {
	cin >> w >> h;
	cin >> num;

	//x가 0이면 세로 좌표, x가 1이면 가로 좌표
	for (int i = 0; i < num; i++) {
		int x, n;
		cin >> x >> n;
		if (x == 0) {
			height.push_back(n);
		}
		else if (x == 1) {
			width.push_back(n);
		}
	}
	//마지막 좌표로 가로와 세로의 끝나는 지점을 넣는다.
	width.push_back(w);
	height.push_back(h);

	//가로와 세로의 좌표를 오름차순으로 정렬
	sort(width.begin(), width.end());
	sort(height.begin(), height.end());

	//가로의 길이를 좌표로 나누어 입력
	for (int i = 0; i < width.size(); i++) {
		if (i == 0) {
			width_length.push_back(width[i]); //처음 값 저장
		}
		else {
			width_length.push_back(width[i] - width[i - 1]);
			//어쩌피 정렬되어있는 상태. 그렇기에, 바로 직전과의 차이만 구해주면 된다.
		}
	}

	//세로의 길이를 좌표로 나누어 입력
	for (int i = 0; i < height.size(); i++) {
		if (i == 0) {
			height_length.push_back(height[i]);
		}
		else {
			height_length.push_back(height[i] - height[i - 1]);
			//어쩌피 정렬되어있는 상태. 그렇기에, 바로 직전과의 차이만 구해주면 된다.

		}
	}

	//가로의 길이와 세로의 길이를 오름차순으로 정렬
	sort(width_length.begin(), width_length.end());
	sort(height_length.begin(), height_length.end());


	cout << width_length[width_length.size() - 1] * height_length[height_length.size() - 1]; //맨 끝의 길이가 가장 기니까 서로 곱한다.
}