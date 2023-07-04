#ifndef __GEN_NODE_H__
#define __GEN_NODE_H__

#ifndef __REF_GEN_LIST_NODE_TYPE__
#define __REF_GEN_LIST_NODE_TYPE__
enum GenListNodeType {HEAD, ATOM, LIST};
#endif

#include<string>
// ���������
template<class ElemType>
struct GenListNode
{
public:
// ���ݳ�Ա:
	GenListNodeType tag;				
		// ��־��,HEAD(0):ͷ���, ATOM(1):ԭ�ӽṹ, LIST(2):����
	GenListNode<ElemType> *tLink;	// ָ��ͬһ���е���һ�����ָ����
	
	
		int ref;						// tag=HEAD,ͷ���,���������
		ElemType atom;					// tag=ATOM,���ԭ�ӽ���������
		GenListNode<ElemType> *hLink;	// tag=LIST,���ָ���ӱ��ָ����
	 

// ���캯��:
	GenListNode(GenListNodeType tg = HEAD, GenListNode<ElemType> *next = NULL);
		// �ɱ�־tg��ָ��next����������
	GenListNode( GenListNodeType tg , GenListNode<ElemType>* next , ElemType data);
	~GenListNode();
	
};

// ����������ʵ�ֲ���
template<class ElemType>
GenListNode<ElemType>::GenListNode(GenListNodeType tg, GenListNode<ElemType> *next)
// ����������ɱ�־tg��ָ��next����������
{
	tag = tg;						// ��־
	tLink = next;					// ���
	if (tg == HEAD)
		ref = 1;
	
	
}
/*template<class ElemType>
GenListNode<ElemType>::GenListNode(int a, GenListNodeType tg, GenListNode<ElemType>* next, GenListNode<ElemType>* Hlink)
{
	if (tg == LIST)
	{
		tag = tg;
		tLink = next;
		hLink = Hlink;
	}
}*/
template<class ElemType>
GenListNode<ElemType>::~GenListNode()
{

}
template<class ElemType>
GenListNode<ElemType>::GenListNode( GenListNodeType tg, GenListNode<ElemType>* next, ElemType data)
{
	if (tg == ATOM)
	{
		tag = ATOM;
		tLink = next;
		atom = data;
	}
}
#endif
