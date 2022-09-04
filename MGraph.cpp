#include "MGraph.h"

//构造邻接矩阵
MGraph::MGraph(char v[], int n, int e)
{
	int i, j, k;
	vertexNum = n;
	edgeNum = e;

	for (i = 0; i < vertexNum; i++)
	{
		vertex[i] = v[i]; //存储顶点
	}

	for (i = 0; i < vertexNum; i++)
	{
		for (j = 0; j < vertexNum; j++)
		{
			edge[i][j] = 0;   //初始化邻接矩阵
		}
	}

	for (k = 0; k < edgeNum; k++)
	{
		cout << "请输入有邻边关系的两个顶点名称：\n";
		cin >> i >> j;
		edge[i][j] = 1;
	}
}

//析构基于邻接矩阵的图
MGraph::~MGraph()
{
	cout << "析构邻接矩阵\n";
}

void MGraph::showVertex()
{
	cout << "图的顶点编号为：\n";
	for (int i = 0; i < vertexNum; i++)
	{
		cout << vertex[i] << " ";
	}
	cout << endl;
}

void MGraph::showEdge()
{
	cout << "邻接矩阵：\n";
	for (int i = 0; i < vertexNum; i++)
	{
		for (int j = 0; j < vertexNum; j++)
		{
			cout << edge[i][j] << " ";
			if (j == vertexNum - 1) cout << endl;

		}
	}
}

//深度优先遍历图
void MGraph::DfTraverse(int v)
{
	cout << "深度优先遍历：\n";
	visited[v] = 1;
	for (int j = 0; j < vertexNum; j++) 
	{
		if (edge[v][j] == 1 && visited[j] == 1)
		{
			DfTraverse(j);
		}
	}
}

//广度优先遍历
void MGraph::BFTraverse(int v)
{
	cout << "广度优先遍历：\n";
	int w, j, Q[MaxSize];   //采用顺序队列
	int front = -1, rear = -1;
	cout << vertex[v] << " ";
	visited[v] = 1;
	Q[++rear] = v;
	while (front != rear) //队列非空
	{
		w = Q[++front];
		for (j = 0; j < vertexNum; j++)
		{
			if (edge[w][j] == 1 && visited[j] == 0)
			{
				cout << vertex[j] << " ";
				visited[j] = 1;
				Q[++rear] = j;
			}
		}
	}
}
 //每次遍历后重新出现hi话visited数组
void MGraph::init()

{
	cout << "归零visited数组\n";
	for (int i = 0; i < MaxSize; i++)
	{
		this->visited[i] = 0;
	}
}

void MGraph::In0()
{
	int count = 0;
	for (int i = 0; i < vertexNum; i++) {
		int tag = 0;
		for (int j = 0; j < vertexNum; j++)
		{
			if (edge[j][i] != 0)
			{
				tag = 1;
				break;
			}
		}
		if (tag == 0) count++;

	}
	cout << "一共有" << count << "个入度为零的顶点\n";
}

void MGraph::Out0()
{
	int count = 0;
	for (int i = 0; i < vertexNum; i++)
	{
		int tag = 0;
		for (int j = 0; j < vertexNum; j++)
		{
			if (edge[i][j] != 0)
			{
				tag = 1;
				break;
			}
		}
		if (tag == 0) count++;
	}
	cout << "一共有  " << count << "个出度为零的顶点\n";
}
