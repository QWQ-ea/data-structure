#include "MedianFinder"
int main()
{
	MedianFinder<int> finder,finder1,finder2,Finder;
	int a[12]={80,57,99,35,23,11,74,29,62,16,9,100};
	int b[13]={99,1000,233,22,11,3,7,86,108,89,66,78,666};
	int e;
	char c = 'x',s='x'; 
	cout<<endl;
    while (c != '0')	{
        cout << endl << "1. �ҳ�����a��b�е���λ��(����0����a,1����b)";
        cout << endl << "2. �ҳ����⼯���е���λ��";
		cout << endl << "3. �����ļ��е�30�������";
		cout << endl << "0. �˳�";
		cout << endl << "ѡ����(0~3):";
		cin >> c;
		switch (c) 	{
		    case '1':
            	cout << endl << "����ָ���ļ���:";//(0����a,1����b)
			    cin >> e;
				if(e==0) {for(int i=0;i<12;i++) finder1.Makeheap(a[i]);cout<<endl<<"��λ��Ϊ��"<<finder1.findMedian()<<endl;}
				else if(e==1) {for(int i=0;i<13;i++) finder2.Makeheap(b[i]);cout<<endl<<"��λ��Ϊ��"<<finder2.findMedian()<<endl;}
			    break;
		    case '2':
				cout<<"����Ҫ���Եļ��ϣ�";
			    while(s!='\n')
				{
				cin>>e;
				s=getchar();
				finder.Makeheap(e);
				}
				cout<<endl<<"Ҫ���Եļ�����λ��Ϊ��"<<finder.findMedian()<<endl;
				break;
		     case '3':
				for(int i=1;i<=300000;i++)
				{
					cin>>e;
					Finder.Makeheap(e);
				}
				cout<<Finder.findMedian()<<endl;
				break;
		}
	}

	
	system("pause");
	return 0;
}
