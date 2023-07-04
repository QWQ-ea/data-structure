#ifndef _TREE_NODE_H__
#define _TREE_NODE_H__

// ������������
template <class ElemType>
struct TreeNode
{
// ���ݳ�Ա:
	ElemType data;						// ������
	TreeNode<ElemType>  *firstChild;	// ��һ������ָ����
	TreeNode<ElemType>  *nextSibling;	// ��һ���ֵ�ָ����

//	���캯��:
	TreeNode();		// �޲����Ĺ��캯�� 
	TreeNode(const ElemType &d,// ��֪����Ԫ��ֵ,ָ�����ҽڵ��ָ�빹��һ�����
		TreeNode<ElemType> *lChild = NULL, 
		TreeNode<ElemType> *rSibling = NULL);
};

// ��������ʵ�ֲ���
template <class ElemType>
TreeNode<ElemType>::TreeNode()
// �������������һ��Ҷ���
{
	firstChild = nextSibling = NULL;	// Ҷ������ҽڵ�Ϊ��
}

template <class ElemType>
TreeNode<ElemType>::TreeNode(const ElemType &d, 
	TreeNode<ElemType> *lChild, TreeNode<ElemType> *rSibling)
// �������������һ��������Ϊd,��һ������ΪlChild,��һ���ֵ�ΪrChild�Ľ��
{	
	data = d;					// ����Ԫ��ֵ
	firstChild = lChild;			// ��һ������
	nextSibling = rSibling;		// ��һ���ֵ�
}

#endif

