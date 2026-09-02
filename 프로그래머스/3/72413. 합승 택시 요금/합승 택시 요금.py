# 문제 정보
# S에서 출발하여 A, B 각자의 집에 귀가하는데 예상 최저 택시 요금 계산
# 지점은 1부터 n까지 번호 사용
# 간선에 예상 택시요금 표시
# 무방향 그래프
# 합승하지 않고 각자의 예상 택시 요금 합이 더 낮다면 합승 안해도 된다.

# 입력 정보
# n -> 지점의 개수
# s -> 출발 지점
# a -> A의 도착 지점
# b -> B의 도착 지점
# fares -> 택시 요금 (출발, 도착, 요금)

# 반환 정보
# answer -> 최저 예상 택시요금

# 풀이 순서
# 1. 플루이드-워셜 알고리즘으로 행렬을 다익스트라로 전부 다 채움
# 2. 각 노드를 돌면서 노드에서 시작점을 가는 가중치(택시를 합승하고 가는 가중치) + A로 가는 가중치 + B로 가는 가중치의 최소값을 구함

import heapq

INF = float('inf')

def print_grid(grid):
    for row in grid:
        print(*row)
    print()
def solution(n, s, a, b, fares):
    answer = 0
    # graph = {i: {j: None for j in range(n + 1)} for i in range(n + 1)}
    visited = [[INF for _ in range(n + 1)] for _ in range(n + 1)]
    def init():
        for i in range(1, n + 1):
            visited[i][i] = 0
            
        for start, end, weight in fares:
            visited[start][end] = weight
            visited[end][start] = weight
            
    def floyd():
        for stop in range(1, n + 1):
            for start in range(1, n + 1):
                for end in range(1, n + 1):
                    if start == end:
                        continue
                    visited[start][end] = min(visited[start][end], visited[start][stop] + visited[stop][end])

    def calc():
        min_value = INF
        for i in range(1, n + 1):
            min_value = min(min_value, visited[i][s] + visited[i][a] + visited[i][b])
        return min_value
        
    init()
    floyd()
    answer = calc()
    return answer