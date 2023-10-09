**********

근처에 갈 수 있는 경우의 수 찾기 = > bfs에서 cnt++을 해준다.

최단 거리 등을 찾는 문제 => 방문하지 않았다면 이전 방문 지점에서 +1을 해준다.

위 문제를 후자로 풀었다가 틀린 문제..

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>


using namespace std;

int px[4] = { -1,1,0,0 };
int py[4] = { 0,0,1,-1 };
int space[101][101];
bool visited[101][101];
queue<pair<int, int>>q;
int n, m;


int bfs(int y, int x)
{
	q.push({ y,x });
	visited[y][x] = true;
	int cnt = 1;

	while (!q.empty())
	{
		int x1 = q.front().second;
		int y1 = q.front().first;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x1 + px[i];
			int ny = y1 + py[i];

			if (nx > 0 && nx <= m && ny > 0 && ny <= n)
			{
				if (!visited[ny][nx])
				{
					visited[ny][nx] = true;
					q.push({ ny,nx });
					cnt++;
				}
			}

		}
	}

	return cnt;
}


int main(void)
{

	cin >> n >> m;

	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%1d", &space[i][j]);

			if (space[i][j] == 0)
			{
				visited[i][j] = true;
			}
		}
	}

	cout<<bfs(1, 1);



	return 0;
}


이렇게 했는데 안 나와서 답지 깠다 악 



*************


# [Silver I] 미로 탐색 - 2178 

[문제 링크](https://www.acmicpc.net/problem/2178) 

### 성능 요약

메모리: 2060 KB, 시간: 0 ms

### 분류

너비 우선 탐색, 그래프 이론, 그래프 탐색

### 문제 설명

<p>N×M크기의 배열로 표현되는 미로가 있다.</p>

<table class="table table-bordered" style="width:18%">
	<tbody>
		<tr>
			<td style="width:3%">1</td>
			<td style="width:3%">0</td>
			<td style="width:3%">1</td>
			<td style="width:3%">1</td>
			<td style="width:3%">1</td>
			<td style="width:3%">1</td>
		</tr>
		<tr>
			<td>1</td>
			<td>0</td>
			<td>1</td>
			<td>0</td>
			<td>1</td>
			<td>0</td>
		</tr>
		<tr>
			<td>1</td>
			<td>0</td>
			<td>1</td>
			<td>0</td>
			<td>1</td>
			<td>1</td>
		</tr>
		<tr>
			<td>1</td>
			<td>1</td>
			<td>1</td>
			<td>0</td>
			<td>1</td>
			<td>1</td>
		</tr>
	</tbody>
</table>

<p>미로에서 1은 이동할 수 있는 칸을 나타내고, 0은 이동할 수 없는 칸을 나타낸다. 이러한 미로가 주어졌을 때, (1, 1)에서 출발하여 (N, M)의 위치로 이동할 때 지나야 하는 최소의 칸 수를 구하는 프로그램을 작성하시오. 한 칸에서 다른 칸으로 이동할 때, 서로 인접한 칸으로만 이동할 수 있다.</p>

<p>위의 예에서는 15칸을 지나야 (N, M)의 위치로 이동할 수 있다. 칸을 셀 때에는 시작 위치와 도착 위치도 포함한다.</p>

### 입력 

 <p>첫째 줄에 두 정수 N, M(2 ≤ N, M ≤ 100)이 주어진다. 다음 N개의 줄에는 M개의 정수로 미로가 주어진다. 각각의 수들은 <strong>붙어서</strong> 입력으로 주어진다.</p>

### 출력 

 <p>첫째 줄에 지나야 하는 최소의 칸 수를 출력한다. 항상 도착위치로 이동할 수 있는 경우만 입력으로 주어진다.</p>

