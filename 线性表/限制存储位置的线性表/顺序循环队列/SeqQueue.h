#ifndef __SQ_QUEUE_H__
#define __SQ_QUEUE_H__
#include "Assistance.h"	// ���������

// ѭ��������

template<class ElemType>
class SeqQueue 
{
protected:
	int front,maxSize,length;
	ElemType *elems=NULL;									 // Ԫ�ش洢�ռ�

public:
	SeqQueue(int size = DEFAULT_SIZE);					 // ���캯��
	virtual ~SeqQueue();								 // ��������
	int GetLength() const;								 // ����г���			 
	bool IsEmpty() const;								 // �ж϶����Ƿ�Ϊ��
	void Clear();										 // ���������
	void Traverse(void (*Visit)(const ElemType &)) const;// ��������
	Status DelQueue(ElemType &e);					     // ���Ӳ���
	Status GetHead(ElemType &e) const;				     // ȡ��ͷ����
	Status EnQueue(const ElemType e);				     // ��Ӳ���
	SeqQueue(const SeqQueue<ElemType> &q);			 // ���ƹ��캯��
	SeqQueue<ElemType> &operator =(const SeqQueue<ElemType> &q);// ��ֵ�������
};

// ѭ���������ʵ�ֲ���

template<class ElemType>
SeqQueue<ElemType>::SeqQueue(int size)
// �������������һ������Ϊsize�Ŀ�ѭ������
{
	maxSize = size;							// ���ö�������
	if (elems != NULL) delete []elems;	// �ͷ����д洢�ռ�
	elems = new ElemType[maxSize];			// ����Ԫ�ش洢�ռ�
	length=front=0;
}

template <class ElemType>
SeqQueue<ElemType>::~SeqQueue()
// ������������ٶ���
{
	delete []elems;							// �ͷ�Ԫ�ش洢�ռ�
}

template<class ElemType>
int SeqQueue<ElemType>::GetLength() const
// ������������ض��г���			 
{
	return length;
}

template<class ElemType>
bool SeqQueue<ElemType>::IsEmpty() const
// ��������������Ϊ�գ��򷵻�true�����򷵻�false
{
   return length==0;
}

template<class ElemType>
void SeqQueue<ElemType>::Clear() 
// �����������ն���
{
	front=length=0;
}

template <class ElemType>
void SeqQueue<ElemType>::Traverse(void (*Visit)(const ElemType &)) const
// ������������ζԶ��е�ÿ��Ԫ�ص��ú���(*visit)
{
	for (int i = front; i != front+length; i++)
	{
		(*Visit)(elems[i%maxSize]);
	}
}
template<class ElemType>
Status SeqQueue<ElemType>::DelQueue(ElemType &e)
// ���������������зǿգ���ôɾ����ͷԪ�أ�����e������ֵ����������SUCCESS,
// ����������UNDER_FLOW��
{
	if (!IsEmpty()) 	{	// ���зǿ�
		e = elems[front];					// ��e���ض�ͷԪ��
		front = (front + 1) % maxSize;		// frontָ����һԪ��
		length--;
		return SUCCESS;
	}
	else	// ����Ϊ��
		return UNDER_FLOW;
}

template<class ElemType>
Status SeqQueue<ElemType>::GetHead(ElemType &e) const
// ���������������зǿգ���ô��e���ض�ͷԪ�أ���������SUCCESS,
// ����������UNDER_FLOW��
{
	if (!IsEmpty()) 	{	    // ���зǿ�
		e = elems[front];		// ��e���ض�ͷԪ��
		return SUCCESS;
	}
	else
		return UNDER_FLOW;
}

template<class ElemType>
Status SeqQueue<ElemType>::EnQueue(const ElemType e)
// ��������������������������OVER_FLOW,
// �������Ԫ��eΪ�µĶ�β������SUCCESS
{
	if (length==maxSize)
		return OVER_FLOW;
	else	{	// ����δ������ӳɹ�
		elems[(front+length)%maxSize] = e;					// ����eΪ�¶�β
	    length++;		// rearָ���¶�β
		return SUCCESS;
	}
}

template<class ElemType>
SeqQueue<ElemType>::SeqQueue(const SeqQueue<ElemType> &q)
// ����������ɶ���q�����¶���--���ƹ��캯��
{
    maxSize = q.maxSize;				    // ���ö�������
	    if (elems != NULL) delete []elems;	// �ͷŴ洢�ռ�
    elems = new ElemType[maxSize];			// ����洢�ռ�
	front = q.front;						// ���ƶ�ͷλ��	
    length=q.length;					// ���ƶ�βλ��
	for (int i = front; i != front+length; i++)
	{	
			elems[i%maxSize] = q.elems[i%maxSize];
	}
}
template<class ElemType>
SeqQueue<ElemType> &SeqQueue<ElemType>::operator =(const SeqQueue<ElemType> &q)
// ���������������q��ֵ����ǰ����--��ֵ�������
{
	if (&q != this)	{
        maxSize = q.maxSize;				// ���ö�������
	    if (elems != NULL) delete []elems;	// �ͷŴ洢�ռ�
	    elems = new ElemType[maxSize];		// ����洢�ռ�
		front = q.front;					// ���ƶ�ͷλ��	
	    length=q.length;				// ���ƶ�βλ��
	for (int i = front; i != front+length; i++)
	{	
		elems[i%maxSize] = q.elems[i%maxSize];
	}
	}
	return *this;
}

#endif
