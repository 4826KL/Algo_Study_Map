#include"MGraph.h"

int main()
{
	cout << "基于邻接矩阵的有向图 \n";
	//常规版本
    char data[] = { 'A', 'B', 'C', 'D', 'E' };
    MGraph m1(data, 5, 4);
    m1.showVertex();
    m1.showEdge();
    m1.init();
    cout << "深度优先遍历：";
    m1.DfTraverse(0);
    cout << endl;
    m1.init();
    m1.BFTraverse(0);
    cout << endl;

    m1.In0();
    m1.Out0();


    system("pause");
    return 0;
}