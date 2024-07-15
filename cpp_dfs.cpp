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

	stack<int> s; // dfs ������ �ʿ��� ���� �غ�
	s.push(start); // ���ÿ� ���� ��� �����ְ�
	check[start] = true; //  �湮 üũ

	// �� ���¿��� Ž�� ��~��
	while (!s.empty()) { // ���� ���ο� ��尡 ���� �� ���� �ݺ�
		int temp = s.top();
		s.pop(); // ������ �ֻ�� ��带 ��������
		for (int i = 0;i < graph[temp].size();i++) { // �ֻ�� ����� ��� childnode�� ���Ͽ�
			int childnode = graph[temp][i];
			if (check[childnode] == false) { // ���� childnode�� �湮�� ���� ���ٸ�
				s.push(childnode); // childnode�� ���ÿ� �ְ�
				check[childnode] = true; // �湮 üũ
			}
			else { // ���� childnode�� �湮�� ���� �ִٸ�
				continue; // �ٸ� childnode�� �� ���� ����
			}
		 }
		printf("%d ", temp); // childnode�� �θ����� �Ʊ� �������� �ֻ�� ��� ���
	}

}

int main() {

	int n, m, start;
	scanf("%d %d %d", &n, &m, &start); // n: ����,  m: ����,  start: ���۳��

	vector<vector<int>> graph; // �׷���
	vector<bool> check; // �湮 üũ�� ����

	graph.resize(n + 1); 
	check.resize(n + 1); // ũ�� �˳��ϰ� �������� 1 ũ�� ����

	for (int i = 0;i < m;i++) { // ��� ������ ���Ͽ�
		int u, v;
		scanf("%d %d", &u, &v); //  �Ѱ��� ������ �̷�� �� ������ �Է� �ް�
		graph[u].push_back(v);
		graph[v].push_back(u); // ��������Ʈ �׷����� �־���.
	}

	for (int i = 1;i <= n;i++) {
		sort(graph[i].begin(), graph[i].end());
	}
	// ���ÿ� childnode�� ���� �� �ֻ�ܺ��� �Ʒ��� ���������� �Ǳ� ����
	// �׷��� ������ ��� ������ greater<>()�� ����Ͽ� ��������

	dfs(start, graph, check); // dfs ����


	return 0;
}