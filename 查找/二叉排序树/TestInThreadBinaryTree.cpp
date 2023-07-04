#include "BinarySortTree.h"		  // ����������������

int main(void)
{
	int pre[]={39,11,8,23,34,68,46,75,71,86};		// ��������
	int in[]={8,11,23,34,39,46,68,71,75,86};		// ��������
	int n = 10;						  // ������
	BinarySortTree<int> bt;
	char c = 'x', e;
	BinTreeNode<int> *p;
    BinTreeNode<int> *q;
	bt = CreateBinarySortTree(pre, in, n);// ���������
	cout << "������39,11,8,23,34,68,46,75,71,86������8,11,23,34,39,46,68,71,75,86����Ķ�����:" << endl;
	DisplayBTWithTreeShape<int>(bt);
	cout << endl;
	system("PAUSE");	

	cout << "���������������������:" << endl;
	BinarySortTree<int> thrBt(bt);
	DisplayBTWithTreeShape<int>(thrBt);
	system("PAUSE");	
	
   	while (c != '0'){
        cout << endl << "1.����ֵ����ָ��ֵ�Ľڵ㲢�����丸�׽ڵ�";
		cout << endl << "2.����ڵ�";
		cout << endl << "3.ɾ���ڵ�";
		cout << endl << "4.�ж϶������Ƿ�Ϊ����������";
		cout << endl << "0. �˳�";
		cout << endl << "ѡ����(0~4):";
		cin >> c;
		switch (c) 	{
		    case '1':
            	p=thrBt.Find(46,q);
				cout<<p->data<<endl;
				cout<<q->data<<endl;
			    break;
           	case '2':
            	thrBt.Insert(17);
			    DisplayBTWithTreeShape<int>(thrBt);
			    break;
	         case '3':
			    p=thrBt.Find(68,q);
				thrBt.Delete(p);
				DisplayBTWithTreeShape<int>(thrBt);
				break;
	         case '4':
			    cout<<thrBt.BinarySorttreejudge()<<endl;
				break;
		}
	}
	
	system("PAUSE");	
	return 0;				
}

