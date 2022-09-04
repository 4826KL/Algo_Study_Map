#include "MGraph.h"

//�����ڽӾ���
MGraph::MGraph(char v[], int n, int e)
{
	int i, j, k;
	vertexNum = n;
	edgeNum = e;

	for (i = 0; i < vertexNum; i++)
	{
		vertex[i] = v[i]; //�洢����
	}

	for (i = 0; i < vertexNum; i++)
	{
		for (j = 0; j < vertexNum; j++)
		{
			edge[i][j] = 0;   //��ʼ���ڽӾ���
		}
	}

	for (k = 0; k < edgeNum; k++)
	{
		cout << "���������ڱ߹�ϵ�������������ƣ�\n";
		cin >> i >> j;
		edge[i][j] = 1;
	}
}

//���������ڽӾ����ͼ
MGraph::~MGraph()
{
	cout << "�����ڽӾ���\n";
}

void MGraph::showVertex()
{
	cout << "ͼ�Ķ�����Ϊ��\n";
	for (int i = 0; i < vertexNum; i++)
	{
		cout << vertex[i] << " ";
	}
	cout << endl;
}

void MGraph::showEdge()
{
	cout << "�ڽӾ���\n";
	for (int i = 0; i < vertexNum; i++)
	{
		for (int j = 0; j < vertexNum; j++)
		{
			cout << edge[i][j] << " ";
			if (j == vertexNum - 1) cout << endl;

		}
	}
}

//������ȱ���ͼ
void MGraph::DfTraverse(int v)
{
	cout << "������ȱ�����\n";
	visited[v] = 1;
	for (int j = 0; j < vertexNum; j++) 
	{
		if (edge[v][j] == 1 && visited[j] == 1)
		{
			DfTraverse(j);
		}
	}
}

//������ȱ���
void MGraph::BFTraverse(int v)
{
	cout << "������ȱ�����\n";
	int w, j, Q[MaxSize];   //����˳�����
	int front = -1, rear = -1;
	cout << vertex[v] << " ";
	visited[v] = 1;
	Q[++rear] = v;
	while (front != rear) //���зǿ�
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
 //ÿ�α��������³���hi��visited����
void MGraph::init()

{
	cout << "����visited����\n";
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
	cout << "һ����" << count << "�����Ϊ��Ķ���\n";
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
	cout << "һ����  " << count << "������Ϊ��Ķ���\n";
}
