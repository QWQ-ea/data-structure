#include "AdjMatrixUndirNetwork.h"					// Kruskal�㷨

int main(void)
{
    try									// ��try��װ���ܳ����쳣�Ĵ���
	{
	int infity = -1;
	char vexs[] = {'A', 'B', 'C', 'D', 'E', 'F'};
	int m[6][6] = {
		{0, 12, 3, infity, 9, 10},
		{12, 0, infity, 2, 6, infity},
		{3, infity, 0, 2, infity, 6},
		{infity, 2, 2, 0, 4, 7},
		{9, 6, infity, 4, 0, 4},
		{10, infity, 6, 7, 4, 0}
	};
		int n = 6;

		AdjMatrixUndirNetwork<char, int> net(vexs, n,10,infity);

		for (int u = 0; u < n; u++)	// �����ڽӾ������
			for (int v = u + 1; v < n; v++)	// �����ڽӾ���Ԫ�ص�ֵ
				if (m[u][v] != 0&&m[u][v]!=infity) net.InsertArc(u, v, m[u][v]);

		cout << "ԭ��:" << endl;
		net.Display();					// ��ʾ��net
		cout << endl;
		system("PAUSE");
		cout << "��Ȧ����������С�������ı�:" << endl;
	    net.DFSpoquan();		// ��Ȧ��
		cout << endl;
	}
	catch (Error err)					// ��׽�������쳣
	{
		err.Show();						// ��ʾ�쳣��Ϣ
	}

	system("PAUSE");					// ���ÿ⺯��system()
	return 0;							// ����ֵ0, ���ز���ϵͳ
}

