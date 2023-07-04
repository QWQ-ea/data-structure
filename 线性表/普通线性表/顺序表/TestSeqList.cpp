#include "SeqList.h"	// ˳�����
#include"Point2D.h"
#include<conio.h>
int main(void)
{
	char c = '*';
    SeqList<Point2D> la(6);
    Point2D e;
	int i;
    Status sta;
    
/*	SeqList<DataStudent> stu(3);
	DataStudent s1("00000001","Li",1,"11122233344",20,1);
	stu.InsertElem(s1);
	stu.Traverse(Write<DataStudent>);
*/
	while (c != '0')
	{
        cout << endl << "1. �������Ա�.";
        cout << endl << "2. ��ʾ���Ա�.";
        cout << endl << "3. ȡָ��Ԫ��.";
        cout << endl << "4. ����Ԫ��ֵ.";
        cout << endl << "5. ɾ��Ԫ��.";
        cout << endl << "6. ����Ԫ��.";
        cout << endl << "7. Ԫ�ض�λ.";
        cout << endl << "8. �����Ա���.";
		cout << endl << "9. ԭ�ص�������";
		cout << endl << "a. ɾ��������e��ͬԪ��";
		cout << endl << "0. �˳�";
		cout << endl << "ѡ����(0~a):";
		cin >> c;
		switch (c) 	{
			case '1':
			    la.Clear();
			    sta = SUCCESS;
				cout << endl << "����e;��( , )��ʽ";
				cin >> e;
				while (sta != OVER_FLOW)	{
					sta = la.InsertElem(e);
					if (sta == OVER_FLOW) 
						cout << "���Ա�����." << endl;
					else
						cin >> e;
				}
				break;
			case '2':
			    la.Traverse(Write<Point2D>);
				break;
			case '3':
			    cout << endl << "����Ԫ��λ��:";
			    cin >> i;
			    if (la.GetElem(i, e) == NOT_PRESENT) 
					cout << "Ԫ�ز��洢." << endl;
				else
					cout << "Ԫ��:" << e << endl;
			    break;
			case '4':
			    cout << endl << "����λ��:";
			    cin >> i;
			    cout << endl << "����Ԫ��ֵ:";
			    cin >> e;
				if (la.SetElem(i, e) == RANGE_ERROR)
					cout << "λ�÷�Χ��." << endl;
				else
					cout << "���óɹ�." << endl;
			    break;
			case '5':
			    cout << endl << "����λ��:";
			    cin >> i;
			    if (la.DeleteElem(i, e) == RANGE_ERROR) 
					cout << "λ�÷�Χ��." << endl;
				else
					cout << "��ɾ��Ԫ��ֵ:" << e << endl;
			    break;
			case '6':
			    cout << endl << "����λ��:";
			    cin >> i;
			    cout << endl << "����Ԫ��ֵ:";
			    cin >> e;
			    sta = la.InsertElem(i, e);
			    
			    if (sta == RANGE_ERROR) 
					cout << "λ�÷�Χ��." << endl;
				else if (sta == OVER_FLOW) 
					cout << "���Ա�����." << endl;
				else
					cout << "����ɹ�." << endl;	
			    break;
			case '7':
			    cout << endl << "����Ԫ��ֵ:";
			    cin >> e;
			    i = la.LocateElem(e); 
			    if (i != 0) 
					cout << "Ԫ��" << e << "�����Ϊ��" << i << endl;
				else
					cout << "Ԫ��" << e << "�����ڡ�"  << endl;
			    break;
			case '8':
			    cout << endl << "���Ա�ĳ���Ϊ:" << la.GetLength() << endl; 
			    break;
		    case '9':
				la.Reverse();
				cout<<endl<<"ԭ�ص��õ�����Ϊ��"<<endl;
				la.Traverse(Write<Point2D>);
				break;
		    case 'a':
				cin>>e;
				la.DelSameItem(e);
				cout<<endl<<"ɾ������e������Ϊ��"<<endl;
				la.Traverse(Write<Point2D>);
				break;
       	}
	}

   	system("PAUSE");        		// ���ÿ⺯��system()����ͣ�������� 
   	return 0;               		// ���ز���ϵͳ
}


