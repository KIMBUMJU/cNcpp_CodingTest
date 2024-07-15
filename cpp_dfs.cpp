#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

void dfs(int start, vector<vector<int>>graph, vector<bool>check) {

	stack<int> s;
	s.push(start);
	check[start] = true;

	while (!s.empty()) {
		int temp = s.top();
		s.pop();
		for (int i = 0;i < graph[temp].size();i++) {
			int childnode = graph[temp][i];
			if (check[childnode] == false) {
				s.push(childnode);
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
	scanf("%d %d %d", &n, &m, &start); // n: 정점,  m: 간선,  start: 시작노드

	vector<vector<int>> graph;
	vector<bool> check;

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
	// 스택에 childnode를 담을 때 최상단부터 아래가 오름차순이 되기 위해
	// 그래프 내부의 노드 순서를 greater<>()을 사용하여 내림차순

	dfs(start, graph, check);


	return 0;
}