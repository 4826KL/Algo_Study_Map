#pragma once
#include<iostream>

using namespace std;

const int MaxSize = 7; //最大顶点个数

class MGraph
{
public:
	MGraph(char v[], int n, int e);    //构造函数
	~MGraph();                         //析构函数
	void showVertex();                 
	void showEdge();
	void DfTraverse(int v);           //深度优先遍历；
	void BFTraverse(int v);           //广度优先遍历
	void init();                      //遍历后重新初始化visited;
	void In0();                       //计算入度为零的顶点数
	void Out0();                      //计算出度为0的顶点数

private:
	char vertex[MaxSize];           //用数组存放图的顶点
	int edge[MaxSize][MaxSize];     //二维数组，存放各顶点相连的边
	int vertexNum, edgeNum;         //图的顶点数和边数
	int visited[MaxSize] = { 0 };     

};

