#include "Graph.h"

Graph::Graph(int vertexNums)
{
	this->vertexNums = vertexNums;
	adj = new list<int>[vertexNums];

	indegree = new int[vertexNums];
	for (int i = 0; i < vertexNums; ++i)
		indegree[i] = 0;     //入度初始化为零
}

//析构
Graph::~Graph()
{
	delete[] adj;
	delete[] indegree;
}

void Graph::addEdge(int vertexNums, int w)
{
	adj[vertexNums].push_back(w);
	++indegree[w];
}

bool Graph::topLogicalSort()
{
	for (int i = 0; i < vertexNums; ++i)
	{
		//将入读为零的顶点入队
		if (indegree[i] == 0)
			q.push(i);
	}
	int count = 0;   //计数器，记录当前已经输出的顶点数
	while (!q.empty())
	{
		int v = q.front();   //从队列中取出一个顶点
		q.pop();

		cout << v << " ";
		++count;

		//将所有v指向的顶点的入度减一，并将入度减为0的顶点入栈
		list<int>::iterator beg = adj[v].begin();
		for (; beg != adj[v].end(); ++beg)
		{
			if (!(--indegree[*beg]))
				q.push(*beg);//若出度为零，则入栈
		}

	}
	if (count < vertexNums)
		return false;   //没有输出全部的点，说明存在回路
	else
		return true;    //拓扑排序成功
}
