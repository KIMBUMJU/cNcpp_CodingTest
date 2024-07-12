#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main() {

	int n, m;
	scanf("%d %d", &n, &m); // ������ ������ ������ �Է¹���

	int** graph;
	graph = (int**)malloc(n * sizeof(int));
	for (int i = 0;i < n;i++) {
		graph[i] = (int*)malloc(n * sizeof(int));
	}
	// graph 2���� �迭 ���� �Ҵ�
	// ���� ���� �Ҵ� ���ְ�
	// �� ���� ���ҵ��� �����Ҵ� ���ش�

	// �׷��� ������ ���� 0���� �ʱ�ȭ
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
		// ���� �׷����� ������ �׷����� ������
		// �ܹ��� �׷����� graph[u][v] = 1; �� ���
		// ����ġ�� �ִ� ��� 1 ��� ����ġ���� ����
	}

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			printf("%d ", graph[i][j]);
		}
		printf("\n");
	}
	// �׷��� ���



	return 0;
}