#pragma once
#include<iostream>

#include<list>
#include<queue>

using namespace std;
class Graph
{
private:
	int vertexNums; //总顶点数
	list<int>* adj; //邻接表
	queue<int> q;   //维护一个入度为零的顶点的集合
	int* indegree;  //记录每个顶点的入度

public:
	Graph(int vertexNums);
	~Graph();
	void addEdge(int vertexNums, int w);    //添加边
	bool topLogicalSort();                   //拓扑排序
};

