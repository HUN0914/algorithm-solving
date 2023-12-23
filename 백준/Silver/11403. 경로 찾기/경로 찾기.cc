#include <iostream>
using namespace std;

int n;

bool visited[101][101];

int main(void)
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> visited[i][j];
		}
	}

	for (int k = 0; k < n; k++) { // k : 거쳐가는 노드
		for (int i = 0; i < n; i++) { // i 출발 노드 
			for (int j = 0; j < n; j++) { // j 도착 노드
				if (visited[i][k] && visited[k][j]) {
					visited[i][j] = true;
				}
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << visited[i][j] << " ";
		}
		cout << "\n";
	}


	return 0;
}