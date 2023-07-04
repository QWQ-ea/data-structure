#pragma once
#include<iostream>
using namespace std;


template<typename T>
class Node//�ڵ���
{
public:
	Node();
	Node(T t1, Node<T>*& N=NULL);//NΪ��һ�����
	T GetT() const{ return t; }

	T t;
	Node<T>* next;
};

template<typename T>
class LinkList//������
{
public:
	LinkList();
	LinkList(T* t1, int n);
	~LinkList();
	int GetLength()const { return Length; }
	bool IsEmpty() const { if (!Head || !(Head->next))return true; else return false; }
	void Clear();//�ڱ�λ�����
	void Traverse(void(*Visit)(const T&))const;
	int LocateElem(const T& t1);//��Ԫ�ص�����,��������ͷ�ڱ�,
	                                    //k���ҵ���k��ֵΪt1�Ľ��,�Ҳ�������-1
	Node<T>* GetElem(int i)const;//������Ϊi��Ԫ�ص�ָ��,����������򷵻�NULL
    void  SetElem(int i, const T& t1);//�޸�ָ��������ֵ
	void  DeleteElem(int i);//ɾ��
	void Insert(int i, const T& t1);//��t1���뵽����Ϊi��λ����
	void Push_back(const T& t1);//β��
	LinkList(const LinkList<T>& LK);
	LinkList<T>& operator=(const LinkList<T>& LK);


private:
	int Length;  //�����ڱ�λ
	Node<T>* Head;
};

//Node
template<typename T>
Node<T>::Node()
{
	this->next = NULL;
	
}
template<typename T>
Node<T>::Node(T t1, Node<T>*& N )
{
	this->t = t1;
	if(N)
	   N->next = this;
	this->next = NULL;
}


//LinkList
template<typename T>
LinkList<T>::LinkList()
{
	Head = new Node<T>;
	Length = 1;
}
template<typename T>
LinkList<T>::LinkList(T* t1, int n)
{
	Head = new Node<T>;
	Node<T>* prev = Head;
	for (int i = 0; i < n; i++)
	{
		new Node<T>(t1[i], prev);
		prev = prev->next;
	}
	Length = n + 1;
}
template<typename T>
void LinkList<T>::Clear()
{
	if (Head)
	{
		Node<T>* cur = Head->next;
		Node<T>* temp;
		while (cur)
		{
			temp = cur;
			cur = cur->next;
			delete temp;
			
		}
		Length = 1;
	}
	else return;
}
template<typename T>
LinkList<T>::~LinkList()
{
	this->Clear();
	delete Head;


}
template<typename T>
void LinkList<T>::Traverse(void(*Visit)(const T&)) const
{
	
	
		Node<T>* cur = Head->next;
		while (cur)
		{
			(*Visit)(cur->t);
			cur = cur->next;
		}

	
}
template<typename T>
int LinkList<T>::LocateElem(const T& t1)
{
	Node<T>* cur = Head->next;
	int i = 1; int k = 1;
	while (cur)
	{
		if (cur->t == t1)
			k--;
		if (k == 0)
			return i;
		cur = cur->next;
		i++;
	}
	return -1;
}
template<typename T>
Node<T>* LinkList<T>::GetElem(int i)const
{
	if (i == 0)
		return Head;
	else
	{
		int j = 1;
		Node<T>* cur = Head->next;
		
		while (cur&&j<i)
		{
			cur = cur->next;
			j++;
		}
		if (j == i)
			return cur;
		else if (!cur)
			return NULL;
	}
}
template<typename T>
void LinkList<T>::SetElem(int i, const T& t1)
{
	if (i <= 0)
	{
		cout << "�����������������" << endl;
		return;
	}
	Node<T>* cur = GetElem( i);
	if(cur)
	 cur->t = t1;
	else
	{
		cout << "�����������������" << endl;
		return;
	}
}
template<typename T>
void LinkList<T>::DeleteElem(int i)
{
	
	if (i>0&&i < Length)
	{
		Node<T>* prev = GetElem(i - 1);
		Node<T>* cur = GetElem(i);
		Node<T>* curr = cur->next;
		delete cur;
		prev->next = curr;
		Length--;
	}
	else
	{
		cout << "�����������������" << endl;
		return;
	}
	
}
template<typename T>
void LinkList<T>::Insert(int i, const T& t1)
{
	
	 if (i>0&&i < Length)
	{
		Node<T>* prev = GetElem(i-1);
		Node<T>* cur = GetElem(i);
		Node<T>* n=new Node<T> (t1, prev);
		n->next = cur;
		Length++;
	}
	else
	{
		cout << "�����������������" << endl;
		return;
	}
}
template<typename T>
void LinkList<T>::Push_back(const T& t1)
{
	Node<T>* tail = GetElem(Length - 1);
	new Node<T>(t1, tail);
	Length++;
}
template<typename T>
LinkList<T>::LinkList(const LinkList<T>& LK)
{
	this->Clear();
	Node<T>* tail = Head;
	for (int i = 1; i < LK.Length; i++)
	{
		new Node<T>(LK.GetElem(i)->GetT(), tail);
		tail = tail->next;
	}
	this->Length = LK.GetLength();

}
template<typename T>
LinkList<T>& LinkList<T>::operator=(const LinkList<T>& LK)
{
	this->LinkList(LK);
}