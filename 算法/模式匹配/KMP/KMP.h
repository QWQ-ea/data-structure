#ifndef __KMP_H__
#define __KMP_H__

#include "String.h"				// ����

// KMPƥ���㷨
void GetFailure(const String &pat, int f[])
// �������: ��ģʽ��pat��ʧЧ����ֵ
{
	f[0]=-1;				             // ��ʼf[0]��ֵΪ-1
	int j = 0, k = -1;		
	while (j < pat.GetLength() - 1)
		if (k == -1 || pat[k] == pat[j])	
			f[++j]=++k;
		else		                     // pat[k]��pat[j]��ƥ��
			k = f[k];		             // Ѱ���µ�ƥ���ַ�
}


int KMP_find(const String &ob, const String &pat, int p = 0)
// �������: ����ģʽ��pat��һ����Ŀ�괮ob�дӵ�p���ַ���ʼ���ֵ�λ��
{
	int *f = new int[pat.GetLength()];      // ΪʧЧ����ֵ����f����ռ�
	GetFailure(pat, f);				     // ��ģʽ��pat��f�����Ԫ��ֵ
	int i = p, j = 0;			
	while (i < ob.GetLength() && j < pat.GetLength() && pat.GetLength() - j <= ob.GetLength() - i)
    if (j == -1 || pat[j] == ob[i])		{
		i++; j++;			             // ģʽ��pat��Ŀ�괮ob�ĵ�ǰλ�������
    }
	else 	                             // pat[j]��ob[i]��ƥ��
	{ char a=pat[j];
	  while(pat[j]==a) j=f[j];           // Ѱ���µ�ģʽ��pat��ƥ���ַ�λ��
	}
    delete []f;				             // ��f��ռ�õĴ洢�ռ�
	if (j < pat.GetLength())
        return -1;		                 // ƥ��ʧ��
	else
        return i - j;			         // ƥ��ɹ�
}
void KMP_findall(const String &ob,const String &pat)
{
int p=0;
while(p<=ob.GetLength()-pat.GetLength())
{
int q;
q=KMP_find(ob,pat,p);
if(q!=-1) {cout<<q<<' ';p=q+1;}
else if(q==-1&&p==0) {cout<<-1<<' ';break;}
else break;
}
}
#endif

