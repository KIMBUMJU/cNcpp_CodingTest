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

	queue<int> q; // bfs ������ �ʿ��� ť �غ�
	q.push(start); // ť�� ���� ��带 �ְ�
	check[start] = true; //  �湮 üũ

	// �� ���¿��� Ž�� ��~��
	while (!q.empty()) { // ť ���ο� ��尡 ���� �� ���� �ݺ�
		int temp = q.front();
		q.pop(); // ť�� front ��带 ��������
		for (int i = 0;i < graph[temp].size();i++) { // front ����� ��� childnode�� ���Ͽ�
			int childnode = graph[temp][i];
			if (check[childnode] == false) { // ���� childnode�� �湮�� ���� ���ٸ�
				q.push(childnode); // childnode�� ť�� �ְ�
				check[childnode] = true; // �湮 üũ
			}
			else { // ���� childnode�� �湮�� ���� �ִٸ�
				continue; //  �ٸ� childnode�� �� ���� ����
			}
		}
		printf("%d ", temp); // childnode�� �θ����� �Ʊ� �������� front ��� ���
	}

}



int main() {

	int n, m, start; // n: ����,  m: ����,  start: ���۳��
	vector<vector<int>> graph; // �׷���
	vector<int> check; // �湮 üũ�� ����

	scanf("%d %d %d", &n, &m, &start);

	graph.resize(n + 1);
	check.resize(n + 1); // ũ�� �˳��ϰ� �������� 1 ũ�� ����

	for (int i = 0;i < m;i++) { // ��� ������ ���Ͽ�
		int u, v;
		scanf("%d %d", &u, &v); // �� ���� ������ �̷�� �� ������ �Է� �ް�

		graph[u].push_back(v);
		graph[v].push_back(u); // ��������Ʈ �׷����� �־���

	}

	for (int i = 1;i <= n;i++) {
		sort(graph[i].begin(), graph[i].end());
	}
	// ť�� childnode�� ���� �� �ֻ�ܺ��� �Ʒ��� ���������� �Ǳ� ����
	// �׷��� ������ ��� ������ greater<>()�� ����Ͽ� ��������

	bfs(start, graph, check); // bfs ����



	return 0;
}