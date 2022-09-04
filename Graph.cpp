#include "Graph.h"

Graph::Graph(int vertexNums)
{
	this->vertexNums = vertexNums;
	adj = new list<int>[vertexNums];

	indegree = new int[vertexNums];
	for (int i = 0; i < vertexNums; ++i)
		indegree[i] = 0;     //��ȳ�ʼ��Ϊ��
}

//����
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
		//�����Ϊ��Ķ������
		if (indegree[i] == 0)
			q.push(i);
	}
	int count = 0;   //����������¼��ǰ�Ѿ�����Ķ�����
	while (!q.empty())
	{
		int v = q.front();   //�Ӷ�����ȡ��һ������
		q.pop();

		cout << v << " ";
		++count;

		//������vָ��Ķ������ȼ�һ��������ȼ�Ϊ0�Ķ�����ջ
		list<int>::iterator beg = adj[v].begin();
		for (; beg != adj[v].end(); ++beg)
		{
			if (!(--indegree[*beg]))
				q.push(*beg);//������Ϊ�㣬����ջ
		}

	}
	if (count < vertexNums)
		return false;   //û�����ȫ���ĵ㣬˵�����ڻ�·
	else
		return true;    //��������ɹ�
}
