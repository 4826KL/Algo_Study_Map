#include"MGraph.h"

int main()
{
	cout << "�����ڽӾ��������ͼ \n";
	//����汾
    char data[] = { 'A', 'B', 'C', 'D', 'E' };
    MGraph m1(data, 5, 4);
    m1.showVertex();
    m1.showEdge();
    m1.init();
    cout << "������ȱ�����";
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