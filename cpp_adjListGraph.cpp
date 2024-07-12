#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

int main() {

	int n, m;
	printf("������ ������ ������ �Է��Ͻÿ�: ");
	scanf("%d %d", &n, &m); // ������ ������ ������ �Է¹���

	vector<vector<int>> graph; 
	// vector�� 2���� ���� �Ҵ����� �׷��� ����
	// �׷��� ������ Ǯ ��,
	// ����� ���� n�� ������ �ſ� ũ�� ���� ũ�⸦ �Ժη� �����ϱ� ����
	// ex) vector<int> graph[100000]; -> �޸𸮳���
	// �׷��ٰ� �ʹ� ���� �Ҵ��ϸ� ���� �ʰ� ���� �߻�
	// ex) vector<int> graph[10];

	graph.resize(n + 1); 
	// �׷����� ���� push�� �Ͽ� ���� �Ҵ��� ���� �ʱ⿡
	// �̸� ������ ����

	for (int i = 0;i < m;i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	// �ܹ����� ��� �� 2�� �� �ϳ��� �ۼ�
	// ����ġ�� �ִ� ��� vector<pair<int,int>> graph[n+1] �� ����ų�
	// ����ü ���� ����ġ ���� ����
	// ex) graph[u].push_back(make_pair(v,w)); u->v ����ġ: w

	for (int i = 1;i <= n;i++) {
		printf("%d�� ���� ����� ���: ", i);
		for (int j = 0;j < graph[i].size();j++) {
			printf("%d ", graph[i][j]);
		}
		printf("\n");
	}
	// ��� ���� ���� ���






	return 0;
}