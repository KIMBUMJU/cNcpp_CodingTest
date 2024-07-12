#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

int main() {

	int n, m;
	printf("정점과 간선의 갯수를 입력하시오: ");
	scanf("%d %d", &n, &m); // 정점과 간선의 갯수를 입력받음

	vector<vector<int>> graph; 
	// vector의 2차원 동적 할당으로 그래프 생성
	// 그래프 문제를 풀 때,
	// 노드의 갯수 n의 범위가 매우 크면 벡터 크기를 함부로 설정하기 난감
	// ex) vector<int> graph[100000]; -> 메모리낭비
	// 그렇다고 너무 적게 할당하면 범위 초과 문제 발생
	// ex) vector<int> graph[10];

	graph.resize(n + 1); 
	// 그래프의 행은 push를 하여 동적 할당을 하지 않기에
	// 미리 사이즈 지정

	for (int i = 0;i < m;i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	// 단방향의 경우 위 2개 중 하나만 작성
	// 가중치가 있는 경우 vector<pair<int,int>> graph[n+1] 로 만들거나
	// 구조체 만들어서 가중치 같이 저장
	// ex) graph[u].push_back(make_pair(v,w)); u->v 가중치: w

	for (int i = 1;i <= n;i++) {
		printf("%d번 노드와 연결된 노드: ", i);
		for (int j = 0;j < graph[i].size();j++) {
			printf("%d ", graph[i][j]);
		}
		printf("\n");
	}
	// 노드 연결 상태 출력






	return 0;
}