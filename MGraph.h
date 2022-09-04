#pragma once
#include<iostream>

using namespace std;

const int MaxSize = 7; //��󶥵����

class MGraph
{
public:
	MGraph(char v[], int n, int e);    //���캯��
	~MGraph();                         //��������
	void showVertex();                 
	void showEdge();
	void DfTraverse(int v);           //������ȱ�����
	void BFTraverse(int v);           //������ȱ���
	void init();                      //���������³�ʼ��visited;
	void In0();                       //�������Ϊ��Ķ�����
	void Out0();                      //�������Ϊ0�Ķ�����

private:
	char vertex[MaxSize];           //��������ͼ�Ķ���
	int edge[MaxSize][MaxSize];     //��ά���飬��Ÿ����������ı�
	int vertexNum, edgeNum;         //ͼ�Ķ������ͱ���
	int visited[MaxSize] = { 0 };     

};

