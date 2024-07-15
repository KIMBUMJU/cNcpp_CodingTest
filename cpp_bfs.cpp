#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

void bfs(int start, vector<vector<int>>graph, vector<int>check) {

	queue<int> q; // bfs 구현에 필요한 큐 준비
	q.push(start); // 큐에 시작 노드를 넣고
	check[start] = true; //  방문 체크

	// 이 상태에서 탐색 시~작
	while (!q.empty()) { // 큐 내부에 노드가 없을 때 까지 반복
		int temp = q.front();
		q.pop(); // 큐의 front 노드를 꺼내놓고
		for (int i = 0;i < graph[temp].size();i++) { // front 노드의 모든 childnode에 대하여
			int childnode = graph[temp][i];
			if (check[childnode] == false) { // 만약 childnode에 방문한 적이 없다면
				q.push(childnode); // childnode를 큐에 넣고
				check[childnode] = true; // 방문 체크
			}
			else { // 만약 childnode에 방문한 적이 있다면
				continue; //  다른 childnode로 위 과정 수행
			}
		}
		printf("%d ", temp); // childnode의 부모노드인 아까 꺼내놓은 front 노드 출력
	}

}



int main() {

	int n, m, start; // n: 정점,  m: 간선,  start: 시작노드
	vector<vector<int>> graph; // 그래프
	vector<int> check; // 방문 체크용 벡터

	scanf("%d %d %d", &n, &m, &start);

	graph.resize(n + 1);
	check.resize(n + 1); // 크기 넉넉하게 정점보다 1 크게 지정

	for (int i = 0;i < m;i++) { // 모든 간선에 대하여
		int u, v;
		scanf("%d %d", &u, &v); // 한 개의 간선을 이루는 두 정점을 입력 받고

		graph[u].push_back(v);
		graph[v].push_back(u); // 인접리스트 그래프에 넣어줌

	}

	for (int i = 1;i <= n;i++) {
		sort(graph[i].begin(), graph[i].end());
	}
	// 큐에 childnode를 담을 때 최상단부터 아래가 오름차순이 되기 위해
	// 그래프 내부의 노드 순서를 greater<>()을 사용하여 내림차순

	bfs(start, graph, check); // bfs 시작



	return 0;
}