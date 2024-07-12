#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main() {

	int n, m;
	scanf("%d %d", &n, &m); // 정점과 간선의 갯수를 입력받음

	int** graph;
	graph = (int**)malloc(n * sizeof(int));
	for (int i = 0;i < n;i++) {
		graph[i] = (int*)malloc(n * sizeof(int));
	}
	// graph 2차원 배열 동적 할당
	// 행을 동적 할당 해주고
	// 각 행의 원소들을 동적할당 해준다

	// 그래프 값들을 전부 0으로 초기화
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			graph[i][j] = 0;
		}
	}

	for (int i = 0;i < m;i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		graph[u][v] = 1;
		graph[v][u] = 1;
		// 위의 그래프는 무방향 그래프를 가정함
		// 단방향 그래프는 graph[u][v] = 1; 만 사용
		// 가중치가 있는 경우 1 대신 가중치값을 적용
	}

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			printf("%d ", graph[i][j]);
		}
		printf("\n");
	}
	// 그래프 출력



	return 0;
}