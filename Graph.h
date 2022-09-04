#pragma once
#include<iostream>

#include<list>
#include<queue>

using namespace std;
class Graph
{
private:
	int vertexNums; //�ܶ�����
	list<int>* adj; //�ڽӱ�
	queue<int> q;   //ά��һ�����Ϊ��Ķ���ļ���
	int* indegree;  //��¼ÿ����������

public:
	Graph(int vertexNums);
	~Graph();
	void addEdge(int vertexNums, int w);    //��ӱ�
	bool topLogicalSort();                   //��������
};

