#include "Tree.h"		// ����������

int main(void)
{
	TreeNode<char> *p;
	char pre[]={'A','B','E','F','K','L','C','G','D','H','I','M','N','J'}; // ��������
	char post[]={'E','K','L','F','B','G','C','H','M','N','I','J','D','A'};  // ��������
	int n = 14,i;						                  // ������
    Tree<char> bt;
    char c = 'x', e;
	
	
	bt = CreateTree(pre, post, n);           // ������
		
	cout << "������A,B,D,E,G,H,C,F,I�ͺ���D,B,G,E,H,A,C,F,I�������:" << endl;
	DisplayTWithTreeShape<char>(bt);
	cout << endl;

	system("PAUSE");

    while (c != '0')	{
        cout << endl << "1. ���뺢��.";
        cout << endl << "2. ɾ����ָ���ڵ�Ϊ��������.";
        cout << endl << "3. ɾ����ָ���ڵ�Ϊ���ĵ�i������";
        cout << endl << "4. �������.";
        cout << endl << "5. �������.";
		cout << endl << "6. �����Ķ�.";
        cout << endl << "7. �����Ľ����.";
        cout << endl << "8. �����ĸ߶�.";
        cout << endl << "9. ��ʾ��.";
		cout << endl << "0. �˳�";
		cout << endl << "ѡ����(0~7):";
		cin >> c;
		switch (c) 	{
		    case '1':
            	cout << endl << "���뱻����Ԫ�ص�ֵ:";
			    cin >> e;
			    p = bt.Find(e);
			    if (p == NULL)
			    	cout << "�ý�㲻���ڣ�" << endl;
			    else {
            		cout << endl << "�������Ԫ�ص�ֵ:";
			    	cin >> e;
					bt.InsertChild(p, e);	// ��������
			    }
			    break;
           	case '2':
            	cout << endl << "����ɾ��������Ԫ�ص�ֵ:";
			    cin >> e;
			    p = bt.Find(e);
			    if (p == NULL)
			    	cout << "�ý�㲻���ڣ�" << endl;
			    else 
					bt.DeleteSubTree(p);					
			    break;
		    case '3':
				cout << endl << "����ɾ������˫��Ԫ�ص�ֵ:";
				cin >> e;
				p = bt.Find(e);
				if (p == NULL)
					cout << "�ý�㲻���ڣ�" << endl;
				else 
				{
				cout<<endl<<"����ɾ���ĵ�i��������";
				cin>>i;
				bt.DeleteChild(p,i);
				}
				break;
	         case '4':
				cout << endl;
				bt.PreOrder(Write<char>);
				break;
	         case '5':
				cout << endl;
				bt.PostOrder(Write<char>);
				break;
	         case '6':
				cout << endl;
			    cout << "���Ķ�Ϊ��"<<bt.degreeCount()<<endl;
				break;
	         case '7':
				cout << endl;
				cout << "���Ľ����Ϊ��" << bt.NodeCount() << endl;
				break;
	         case '8':
				cout << endl;
				cout << "���ĸ߶�Ϊ��" << bt.Height() << endl;
				break;
	         case '9':
				cout << endl;
				DisplayTWithTreeShape(bt);
				break;
		}                              
	}

	system("PAUSE");
	return 0;
}

