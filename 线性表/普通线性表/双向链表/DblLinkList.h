#ifndef __DBL_LK_LIST_H__
#define __DBL_LK_LIST_H__

#include "Assistance.h"				// ���������
#include "DblNode.h"				// ˫����������
#include "Point2D.h"
// ˫��������
template <class ElemType>
class DblLinkList 
{
protected:
//  ѭ����������ݳ�Ա:
	DblNode<ElemType> *head;			// ͷ���ָ��
	int length;							// Ԫ�ظ���

public:
	DblLinkList();				        // �޲����Ĺ��캯��
	DblLinkList(ElemType v[], int n);	// �в����Ĺ��캯��
 	virtual ~DblLinkList();		        // ��������
	int GetLength() const;			    // ��ѭ��������			 
	bool IsEmpty() const;			    // �ж�ѭ�������Ƿ�Ϊ��
	void Clear();				        // ��ѭ���������
	void Traverse(void (*Visit)(const ElemType &)) const;// ����ѭ������
	int LocateElem(const ElemType &e);	// Ԫ�ض�λ 
	Status GetElem(int i, ElemType &e) const;	 // ȡָ��λ�õ�Ԫ��	
	Status SetElem(int i, const ElemType &e);	// ����ָ��λ�õ�Ԫ��ֵ
	Status DeleteElem(int i, ElemType &e);		// ɾ��Ԫ��		
	Status InsertElem(int i, const ElemType &e);// ������λ�ò���Ԫ��
	Status InsertElem(const ElemType &e);	    // �ڱ�β����Ԫ��
	DblLinkList(const DblLinkList<ElemType> &la);// ���ƹ��캯��
	DblLinkList<ElemType> &operator =(const DblLinkList<ElemType> &la); // ���ظ�ֵ���� 
	DblNode<ElemType> * Gethead();
};


// �������ʵ�ֲ���
template <class ElemType>
DblLinkList<ElemType>::DblLinkList()
// �������������һ��������
{
	length = 0;						// ��ʼ��Ԫ�ظ���
}

template <class ElemType>
DblLinkList<ElemType>::DblLinkList(ElemType v[], int n)
// �����������������v�е�Ԫ�أ�����˫��ѭ������
{
    DblNode<ElemType> *p;
	p = head=new DblNode<ElemType>(v[0]);	// ����ͷ��� 
	assert(head);
	for (int i = 1; i < n; i++) {
	    p->next = new DblNode<ElemType>(v[i],p);
	    assert(p->next);                // ����Ԫ�ؽ��ʧ�ܣ���ֹ�������� 
	    p = p->next;
    }
	length = n;						    // ��ʼ��Ԫ�ظ���
    head->prior = p;                    //ͷ����priorָ��β��� 
    p->next = head;	                    //β����nextָ��ͷ��� 
}

template <class ElemType>
DblLinkList<ElemType>::~DblLinkList()
// �������������ѭ������
{
	Clear();			// ���ѭ������
}

template <class ElemType>
int DblLinkList<ElemType>::GetLength() const
// �������������ѭ������Ԫ�ظ���
{
	return length;
}

template <class ElemType>
bool DblLinkList<ElemType>::IsEmpty() const
// �����������ѭ������Ϊ�գ��򷵻�true�����򷵻�false
{
	return head==NULL;
}

template <class ElemType>
void DblLinkList<ElemType>::Clear()
// ������������ѭ������
{

	ElemType tmpElem;	// ��ʱԪ��ֵ
	while (length > 0)	// ѭ������ǿգ���ɾ����1��Ԫ��
		DeleteElem(1, tmpElem);
}

template <class ElemType>
void DblLinkList<ElemType>::Traverse(void (*Visit)(const ElemType &)) const
// ������������ζ�ѭ�������ÿ��Ԫ�ص��ú���(*visit)
{
    DblNode<ElemType> *p;
	int i=0;
	for (p = head; p!=head||i!=1; p = p->next)		// ��p���η���ÿ��Ԫ��
	{
	(*Visit)(p->data);// ��ѭ�������ÿ��Ԫ�ص��ú���(*visit)
	if(p==head->prior) i++;
	}
}

template <class ElemType>
int DblLinkList<ElemType>::LocateElem(const ElemType &e)
// �������������ָ��Ԫ����ѭ�������е�һ�γ��ֵ���ţ���������ڷ���0 
{
    DblNode<ElemType> *p = head;
    int count=1;int i;
	while (p != head->prior && p->data != e) {
	    count++;
		p = p->next;
	}
	if (p != head->prior)
	    return count;
	else if(p==head->prior&&p->data==e) return ++count;
    else 
        return 0;
}

template <class ElemType>
Status DblLinkList<ElemType>::GetElem(int i, ElemType &e) const
// �����������ѭ��������ڵ�i��Ԫ��ʱ����e������ֵ����������ENTRY_FOUND,
//	����������NOT_PRESENT
{
    DblNode<ElemType> *p = head;
    int count;
	if (i < 1 || i > length)		// i��Χ��
		return NOT_PRESENT;				
	else	{	// i�Ϸ�
		for (count = 1; count < i; count++)
		  p = p->next;	            // pָ���i�����	
		e = p->data;				// ��e���ص�i��Ԫ�ص�ֵ
		return ENTRY_FOUND;
	}
}

template <class ElemType>
Status DblLinkList<ElemType>::SetElem(int i, const ElemType &e)
// �����������ѭ������ĵ�i��λ�õ�Ԫ�ظ�ֵΪe,
//	i��ȡֵ��ΧΪ1��i��length,
//	i�Ϸ�ʱ��������SUCCESS,����������RANGE_ERROR
{
    DblNode<ElemType> *p = head;
    int count;
	if (i < 1 || i > length)
		return RANGE_ERROR;
	else	{	// i�Ϸ�
		for (count = 1; count < i; count++)
		  p = p->next;	// pָ���i�����	
		p->data = e;	// ���õ�i��Ԫ�ص�ֵ
		return SUCCESS;
	}
}

template <class ElemType>
Status DblLinkList<ElemType>::DeleteElem(int i, ElemType &e)
// ���������ɾ��ѭ������ĵ�i��λ�õ�Ԫ��, ����e������ֵ,
//	i��ȡֵ��ΧΪ1��i��length,
//	i�Ϸ�ʱ��������SUCCESS,����������RANGE_ERROR
{
    DblNode<ElemType> *p = head;
    int count;
	if (i < 1 || i > length)
		return RANGE_ERROR;
	else	{	// i�Ϸ�
		for (count = 1; count < i; count++)
		  p = p->next;	// pָ���i�����	
		p->prior->next = p->next;	// p��ǰ������nextָ��p���ĺ�̽�� 
		p->next->prior = p->prior;	// p�ĺ�̽���priorָ��p����ǰ�����
		e = p->data;				// ��e���ر�ɾ���Ԫ��ֵ	
		length--;// ɾ���ɹ���Ԫ�ظ�����1 
		if(p==head&&length!=0) head=p->next;
		delete p;				    // �ͷű�ɾ���
		return SUCCESS;
	}
}

template <class ElemType>
Status DblLinkList<ElemType>::InsertElem(int i, const ElemType &e)
// �����������ѭ������ĵ�i��λ��ǰ����Ԫ��e
//	i��ȡֵ��ΧΪ1��i��length+1
//	i�Ϸ�ʱ����SUCCESS, ����������RANGE_ERROR
{
    DblNode<ElemType> *p = head,*q;
    int count;
	if (i < 1 || i > length + 1)	// i��Χ��,λ�ò��Ϸ�
		return RANGE_ERROR; 
	else	
	{	// i�Ϸ�
		for (count = 1; count < i; count++)
		  p = p->next;	// pָ���i�����	
		q = new DblNode<ElemType>(e, p->prior, p);// �����½��q
		p->prior->next = q;			// p��ǰ������nextָ��q���
		p->prior = q;				// p��priorָ��q���
		length++;					// ����ɹ���Ԫ�ظ�����1 
		return SUCCESS;
	}
}
template <class ElemType>
Status DblLinkList<ElemType>::InsertElem(const ElemType &e)
{
	if(length==0)
	{
		head=new DblNode<ElemType>(e);
		head->prior=head;
		head->next=head;
		length++;
		return SUCCESS;
	}
	else{
	DblNode<ElemType> *p=head,*q;
    while(e>p->data&&p!=head->prior) p=p->next;
	if(e<p->data)
	{
	q=new DblNode<ElemType>(e,p->prior,p);
	p->prior->next=q;
	p->prior=q;
	if(p==head) head=q;
	length++;						// ����ɹ���Ԫ�ظ�����1 
	return SUCCESS;
	}
	else if(e>p->data)
	{
		q=new DblNode<ElemType>(e,p,head);
		head->prior=q;
		p->next=q;
		length++;
		return SUCCESS;
	}
	}
}
template <class ElemType>
DblLinkList<ElemType>::DblLinkList(const DblLinkList<ElemType> &la)
// ������������ƹ��캯�����ɵ�����la�����µ�����
{
	int laLength = la.GetLength();	// ȡ�����Ƶ�����ĳ���
	ElemType e;la.GetElem(1,e);
	head = new DblNode<ElemType>(e);	// ����ͷָ��
	head->prior=head;
	head->next=head;
	assert(head);                   // ����ͷָ��ʧ�ܣ���ֹ�������� 
	length = 1;						// ��ʼ��Ԫ�ظ���
	for (int i = 2; i <laLength; i++)	{	// ��������Ԫ��
		la.GetElem(i, e);	// ȡ����i��Ԫ�ص�ֵ����e�� 
		InsertElem(e);		// ��e���뵽��ǰ������ı�β 
	}
}

template <class ElemType>
DblLinkList<ElemType> &DblLinkList<ElemType>::operator=(const DblLinkList<ElemType> &la)
// ������������ظ�ֵ���������������la��ֵ����ǰ������
{
	if (&la != this)	{
		int laLength = la.GetLength();// ȡ����ֵ������ĳ���
		ElemType e;
		Clear();
		for (int i = 1; i <= laLength; i++)		{
			la.GetElem(i, e);		    // ȡ����i��Ԫ�ص�ֵ����e��
			InsertElem(e);		            // ��e���뵽��ǰ������ı�β
		}
	}
	return *this;
}
template <class ElemType>
DblNode<ElemType> * DblLinkList<ElemType>::Gethead()
{
	return head;
}
#endif
