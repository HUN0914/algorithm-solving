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

def solution(n, s, a, b, fares):
    answer = 0
    graph = {i: {j: None for j in range(n + 1)} for i in range(n + 1)}
    visited = [[INF for _ in range(n + 1)] for _ in range(n + 1)]
    def init():
        for start, end, weight in fares:
            graph[start][end] = weight
            graph[end][start] = weight
            
    def dijkstra(start):
        hq = []
        visited[start][start] = 0
        for i in graph[start].keys():
            if graph[start][i] is not None:
                heapq.heappush(hq, (graph[start][i], i))
        
        while hq:
            curr_weight, curr_node = heapq.heappop(hq)
            if visited[start][curr_node] <= curr_weight:
                continue
            
            visited[start][curr_node] = curr_weight
            for i in graph[curr_node].keys():
                if graph[curr_node][i] is not None and visited[start][i] > visited[start][curr_node] + graph[curr_node][i]:
                    heapq.heappush(hq, (graph[curr_node][i] + visited[start][curr_node], i))

    def calc():
        min_value = INF
        for i in range(1, n + 1):
            min_value = min(min_value, visited[i][s] + visited[i][a] + visited[i][b])
        return min_value
        
    init()
    for i in range(1, n + 1):
        dijkstra(i)
    
    answer_visited = [False for _ in range(n + 1)]
    answer_visited[s] = True
    
    answer = calc()
    return answer