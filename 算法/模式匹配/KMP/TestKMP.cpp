#include "KMP.h"		      // KMP�㷨
int main(void)
{
	String ob("This is a string");
	String pat="is";
	char c ='1';
	int p;
	while (c != '0'){
		cout << endl << "1. �����ַ���1";
		cout << endl << "2. �����ַ���2";  
		cout << endl << "3. ����KMP_find()";
		cout << endl << "4. ����kMP_findall()";
		cout << endl << "0. �˳�";
		cout << endl << "ѡ����(0~9):";
		cin >> c;
		switch (c) 	{
		case '1':
			cout << endl << "�����ַ���1��";
			Read(ob);
			break;
		case '2':
			cout << endl << "�����ַ���2��";
			Read(pat);
			break;
		case '3':
			cout << "�ַ���s1Ϊ��";
			Write(ob);
			cout << "�ַ���s2Ϊ��";
			Write(pat);
			cout << "����p:";
			cin >> p;
			cout << "�������дӵ�"<<p<<"��λ�ÿ�ʼѰ�ҵ�һ����ģʽ��ƥ����Ӵ�"<<endl;
			cout << "���ҵ���ƥ��λ����ϢΪ��"<<KMP_find(ob,pat,p)<<endl;
			break;
		case '4':
             cout << "�ַ���s1Ϊ��";
			 Write(ob);
			 cout << "�ַ���s2Ϊ��";
			 Write(pat);
             cout << "��������Ѱ��������ģʽ��ƥ����Ӵ���Ϣ��";
			 KMP_findall(ob,pat);
			 cout << endl;
			 break;
		}
	}
	system("PAUSE");        
	return 0;               
}
