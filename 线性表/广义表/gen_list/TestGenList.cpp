#include "GenList.h"			// �����
#define NUM 1000
int main(void)
{
	
	GenList<char> g,g1;
	char c = '*',e,s[NUM];
    int i;
    Status sta;
     
	while (c != '0')
	{
        cout << endl << "1. ���ɹ����.";
        cout << endl << "2. ��ʾ�����.";
        cout << endl << "3. �ڱ�ͷ����ԭ��Ԫ��.";
        cout << endl << "4. �ڱ�ͷ�����ӱ�Ԫ��.";
        cout << endl << "5. ɾ��Ԫ��.";
        cout << endl << "6. ����������.";
        cout << endl << "7. ������ĳ���.";
		cout << endl << "8. ��ָ��λ�ò���ԭ��Ԫ��.";
		cout << endl << "9. ��ָ��λ�ò����ӱ�Ԫ��.";
		cout << endl << "A. ���÷ǵݹ�����.";
		cout << endl << "B. ȡ��ͷ��β.";
  		cout << endl << "0. �˳�";
		cout << endl << "ѡ����(0~7):";
		cin >> c;
		switch (c) 	{
			case '1':
				GetChar();				// ��������Ļس��� 
				cout << "����������eg: (a,(b,c)):";
				g.Input();
				break;
			case '2':
				if (!g.IsEmpty())	{
					g.Show();
					cout << endl;
				}
				else
					cout  << "�����Ϊ�ձ�" << endl;
				break;
			case '3':
			    cout << endl << "����ԭ��Ԫ��:";
			    cin >> e;
			    g.Insert(e);
			    break;
			case '4':
				GetChar();				// ��������Ļس��� 
				cout << "�������ӱ�eg: (a,(b,c)):";
				g1.Input();
			    g.Insert(g1);
			    break;
			case '5':
			    cout << endl << "����λ��:";
			    cin >> i;
			    if (g.Delete(i) == RANGE_ERROR) 
					cout << "λ�÷�Χ��." << endl;
			    break;
			case '6':
				cout << endl << "���Ϊ:" << g.GetDepth() << endl;
			    break;
			case '7':
				cout << endl << "����Ϊ:" << g.GetLength() << endl;
			    break;
		    case '8':
				cout << endl << "����λ��:";
				cin>>i;
				cout << endl << "����ԭ��Ԫ��:";
				cin>>e;
				g.Insert(i,e);
				break;
			case '9':
					GetChar();				// ��������Ļس��� 
					cout << "�������ӱ�eg: (a,(b,c)):";
					g1.Input();
					cout << endl << "����λ��:";
					cin>>i;
					g.Insert(i,g1);
					break;
		    case 'A':
				    if(g.transpose(g.GetHead())==RANGE_ERROR) cout<<"�ձ�"<<endl;
					break;
		    case 'B':
				    cout<<"�������ַ���s:";
					getchar();
					cin.getline(s,NUM);
					g.show(s);
       	}
	}


	system("PAUSE");        // ���ÿ⺯��system()
	return 0;               // ����ֵ0, ���ز���ϵͳ
}


