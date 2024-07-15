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

	queue<int> q;
	q.push(start);
	check[start] = true;

	while (!q.empty()) {
		int temp = q.front();
		q.pop();
		for (int i = 0;i < graph[temp].size();i++) {
			int childnode = graph[temp][i];
			if (check[childnode] == false) {
				q.push(childnode);
				check[childnode] = true;
			}
			else {
				continue;
			}
		}
		printf("%d ", temp);
	}

}



int main() {

	int n, m, start;
	vector<vector<int>> graph;
	vector<int> check;

	scanf("%d %d %d", &n, &m, &start);

	graph.resize(n + 1);
	check.resize(n + 1);

	for (int i = 0;i < m;i++) {
		int u, v;
		scanf("%d %d", &u, &v);

		graph[u].push_back(v);
		graph[v].push_back(u);

	}

	for (int i = 1;i <= n;i++) {
		sort(graph[i].begin(), graph[i].end());
	}
	// 큐에 childnode를 담을 때 최상단부터 아래가 오름차순이 되기 위해
	// 그래프 내부의 노드 순서를 greater<>()을 사용하여 내림차순

	bfs(start, graph, check);



	return 0;
}