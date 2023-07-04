#ifndef _TREE_H__
#define _TREE_H__

#include "LinkQueue.h"				// ������
#include "TreeNode.h"			// �������

// ����
template <class ElemType>
class Tree
{
protected:
//  �������ݳ�Ա:
	TreeNode<ElemType> *root;
//	��������:
	TreeNode<ElemType> *CopyTree(TreeNode<ElemType> *t);
// ������
	void Destroy(TreeNode<ElemType> * &r);	// ɾ����rΪ����
	void PreOrder(TreeNode<ElemType>*r,void(*Visit)(const ElemType&)) const;
		// ���������rΪ������
	void PostOrder(TreeNode<ElemType>*r,void (*Visit)(const ElemType &)) const;
		// ���������rΪ������
    int Height(const TreeNode<ElemType> *r) const;	
// ����rΪ�������ĸ�
	int NodeCount(const TreeNode<ElemType> *r) const;
// ����rΪ�������Ľ�����
    TreeNode<ElemType> *preSibling(TreeNode<ElemType>*r,const TreeNode<ElemType> *p) const;
// ����p��ǰһ���ֵ� 
    TreeNode<ElemType> *Parent(TreeNode<ElemType> *r, const TreeNode<ElemType>*p) const;//����rΪ����������p��˫�� 
	int degreeCount(const TreeNode<ElemType> *r) const;//����rΪ�������Ķ�
public:
//  ���������������ر���ϵͳĬ�Ϸ�������:
	Tree();						// �޲����Ĺ��캯��
	Tree(const ElemType &e);		// ������eΪ������
	virtual ~Tree();				// ��������
	int	Height() const;							    // �����ĸ�
	Tree(const Tree<ElemType> &t);	// ���ƹ��캯��
	Tree(TreeNode<ElemType> *r);			// ������rΪ������
	Tree<ElemType> &operator=(const Tree<ElemType>& t);
	// ��ֵ���������
	TreeNode<ElemType> *GetRoot() const;	// �������ĸ�
	bool IsEmpty() const;				// �ж����Ƿ�Ϊ��
	Status GetElem(const TreeNode<ElemType> *p, ElemType &e) const;
		// ��e���ؽ��pԪ��ֵ
	Status SetElem(TreeNode<ElemType> *p,ElemType &e);
		// �����p��ֵ��Ϊe
	void PostOrder(void (*Visit)(const ElemType &)) const;// ���ĺ������	
	void PreOrder(void (*Visit)(const ElemType &)) const;// �����������
	int NodeCount() const;				// �����Ľ�����
	TreeNode<ElemType> *firstChild(const TreeNode<ElemType> *p) const;
		//  ����p�ĵ�һ������
	TreeNode<ElemType> *nextSibling(const TreeNode<ElemType> *p) const;
		// ����p����һ���ֵ�
	TreeNode<ElemType> *preSibling(const TreeNode<ElemType> *p) const;//��ڵ��ǰһ���ֵܽڵ�
	TreeNode<ElemType> *Parent(const TreeNode<ElemType> *p) const;
	// ����p��˫��
	TreeNode<ElemType> *Find(const ElemType &e) const;
		// ����Ԫ��e�����ҳɹ����ؽ��ָ�룬���򷵻�NULL 
	Status InsertChild(TreeNode<ElemType> *p, const ElemType &e);
        // ����һ�����e��Ϊp�ĺ���
	void DeleteChild(TreeNode<ElemType> *p,int i);	// ɾ���Խڵ�p�ĵ�i������Ϊ��������
	void DeleteSubTree(TreeNode<ElemType> *p);// ɾ���Խڵ�pΪ��������
	int degreeCount() const;//�����Ķ�
};


template <class ElemType>
void DisplayTWithTreeShape(TreeNode<ElemType> *r, int level);
	//	����״��ʽ��ʾ��rΪ��������levelΪ���������������Ĳ����Ϊ1
template <class ElemType>
void DisplayTWithTreeShape(Tree<ElemType> &bt);
	//	��״��ʽ��ʾ�� 
template <class ElemType>
void CreateTree(TreeNode<ElemType> *&r, ElemType pre[], ElemType post[], 
	int preLeft, int preRight, int postLeft, int postRight);	
	// ��֪������������pre[preLeft..preRight]����������in[inLeft..inRight]������rΪ����
	// ��
template <class ElemType>
Tree<ElemType> &CreateTree(ElemType pre[], ElemType post[], int n);
	// ��֪������������й�����



// �����ʵ�ֲ���
template <class ElemType>
Tree<ElemType>::Tree()
// �������������һ������
{
	root = NULL;
}

template <class ElemType>
Tree<ElemType>::~Tree()
// ���������ɾ����--���캯��
{
	Destroy(root);
}

template <class ElemType>
TreeNode<ElemType> *Tree<ElemType>::GetRoot() const
// ����������������ĸ�
{
	return root;
}

template <class ElemType>
bool Tree<ElemType>::IsEmpty() const
// ����������ж����Ƿ�Ϊ��
{
	return root == NULL;
}

template <class ElemType>
Status Tree<ElemType>::GetElem(const TreeNode<ElemType> *p, ElemType &e) const
// �����������e���ؽ��pԪ��ֵ,��������ڽ��p,��������NOT_PRESENT,���򷵻�ENTRY_FOUND
{
	if (p == NULL)		// �����ڽ��p
		return NOT_PRESENT;			// ����NOT_PRESENT
	else	{	// ���ڽ��p
		e = p->data;				// ��e����Ԫ��ֵ
		return ENTRY_FOUND;			// ����ENTRY_FOUND
	}
}

template <class ElemType>
Status Tree<ElemType>::SetElem(TreeNode<ElemType> *p,ElemType &e)
// �����������������ڽ��p,�򷵻�FAIL,���򷵻�SUCCESS,�������p��ֵ����Ϊe
{
	if (p == NULL)		// �����ڽ��p
		return FAIL;				// ����FAIL
	else	{	// ���ڽ��p
		p->data = e;				// �����p��ֵ����Ϊe
		return SUCCESS;				// ����SUCCESS
	}
}

template <class ElemType>
void Tree<ElemType>::PreOrder(TreeNode<ElemType> *r, void (*Visit)(const ElemType &)) const
// ������������������rΪ������
{
	if (r != NULL)	{
		(*Visit)(r->data);				// ���ȷ��ʸ����r
		PreOrder(r->firstChild, Visit);	// �ٱ���r��������
		PreOrder(r->nextSibling, Visit);	// ������r��������
	}
}

template <class ElemType>
void Tree<ElemType>::PreOrder(void (*Visit)(const ElemType &)) const
// ������������������
{
	PreOrder(root, Visit);	
}	

template <class ElemType>
void Tree<ElemType>::PostOrder(TreeNode<ElemType> *r, void (*Visit)(const ElemType &)) const
// ������������������rΪ������
{
	if (r != NULL) 	{
		PostOrder(r->firstChild, Visit);	// ���ȱ���r��������
		(*Visit)(r->data);				// �ٷ��ʸ����r
		PostOrder(r->nextSibling, Visit);	// ������r��������
	}
}

template <class ElemType>
void Tree<ElemType>::PostOrder(void (*Visit)(const ElemType &)) const
// ������������������
{
	PostOrder(root, Visit);	
}	

template <class ElemType>
int Tree<ElemType>::Height(const TreeNode<ElemType> *r) const
// ���������������rΪ�������ĸ�
{
	if(r == NULL)	// ������Ϊ0
		return 0;
	else	{	// �ǿ�����Ϊ���������ĸߵ����ֵ�ټ�1
	int height;
	r=r->firstChild;
	height=Height(r);
	if(height!=0)
	while(r->nextSibling!=NULL) 
	{
		r=r->nextSibling;
		if(Height(r)>height) height=Height(r);
	}
	return height+1;
}
}
template <class ElemType>
int Tree<ElemType>::Height() const
// ����������������ĸ�
{
	return Height(root);
}

template <class ElemType>
Tree<ElemType>::Tree(const ElemType &e)
// ���������������eΪ������
{
	root = new TreeNode<ElemType>(e);
}

template <class ElemType>
int Tree<ElemType>::NodeCount(const TreeNode<ElemType> *r) const
// ���������������rΪ�������Ľ�����
{
	if (r ==NULL)
       return 0;			// ����������Ϊ0
	else
       return NodeCount(r->firstChild) + NodeCount(r->nextSibling) + 1;
		// �ǿ�������Ϊ���������Ľ�����֮���ټ�1
}

template <class ElemType>
int Tree<ElemType>::NodeCount() const
// ����������������Ľ�����
{
	return NodeCount(root);
}

template <class ElemType>
int Tree<ElemType>::degreeCount(const TreeNode<ElemType> *r) const
{
int degree=0;
if(r->firstChild!=NULL) 
{
r=r->firstChild;degree++;
while(r->nextSibling!=NULL) {r=r->nextSibling;degree++;}
}
return degree;
}

template <class ElemType>
int Tree<ElemType>::degreeCount() const
{
	LinkQueue<TreeNode<ElemType> *> q;	// �������q
	TreeNode<ElemType> *p;
	int degree=0;
	if (root != NULL) q.EnQueue(root);		// ������ǿ�,�����
	while (!q.IsEmpty())	{	            // q�ǿ�,˵�����н��δ����
		q.DelQueue(p);                      // ��ͷԪ�س��ӣ�������֮ 
		if (degreeCount(p)>degree)
			degree=degreeCount(p);
		if (p->firstChild != NULL)			// ��ͷԪ�����ӷǿ�
			q.EnQueue(p->firstChild);		// �������
		if (p->nextSibling != NULL)			// ��ͷԪ���Һ��ӷǿ�
			q.EnQueue(p->nextSibling);		// �Һ������
	}
	return degree;
}

template <class ElemType>
TreeNode<ElemType> *Tree<ElemType>::firstChild(const TreeNode<ElemType> *p) const
// ������������������p������
{
	return p->firstChild;
}

template <class ElemType>
TreeNode<ElemType> *Tree<ElemType>::nextSibling(const TreeNode<ElemType> *p) const
// ������������������p����һ���ֵ�
{
	return p->nextSibling;
}

template <class ElemType>
TreeNode<ElemType> *Tree<ElemType>::preSibling(TreeNode<ElemType> *r,const TreeNode<ElemType> *p) const
// ���������������rΪ�������н��p��ǰһ���ֵ� 
{
if(r==NULL||r==p||r->firstChild==p) return NULL;
else if(r->nextSibling==p) return r;
else 
{
TreeNode<ElemType> *tmp;
tmp=preSibling(r->firstChild,p);
if(tmp!=NULL) return tmp;
tmp=preSibling(r->nextSibling,p);
if(tmp!=NULL) return tmp;
else return NULL;
}
}

template <class ElemType>
TreeNode<ElemType> *Tree<ElemType>::preSibling(const TreeNode<ElemType> *p) const
{
return preSibling(root,p);
}

template <class ElemType>
TreeNode<ElemType> * Tree<ElemType>::Parent(TreeNode<ElemType> *r, const TreeNode<ElemType> *p) const
// ���������������rΪ������, ���p��˫��
{
	if (r == NULL||r==p)
		return NULL;		// ����
	else if (r->firstChild == p)
		return r; // rΪp��˫��
	else if(r->nextSibling==p)
	{
	while(preSibling(r)!=NULL) r=preSibling(r);
	return Parent(root,r);
	}
		else	{	// ����������˫��
		TreeNode<ElemType> *tmp;
		tmp = Parent(r->firstChild, p);	// ������������p��˫��	
		if (tmp != NULL)
			return tmp;			        // ˫������������
		
		tmp = Parent(r->nextSibling, p);	// ������������p��˫��	
		if (tmp != NULL)
			return tmp;			        // ˫������������
		else
			return NULL;				    // ��ʾp��˫��
	}
}

template <class ElemType>
TreeNode<ElemType> *Tree<ElemType>::Parent(const TreeNode<ElemType> *p) const
// ������������������p��˫��
{
	return Parent(root, p);
}


template <class ElemType>
Status Tree<ElemType>::InsertChild(TreeNode<ElemType> *p, const ElemType &e)
// ��ʼ������p�ǿգ�
// �������������Ԫ��ֵΪe�Ľ��Ϊp�����ӣ����p�����ӷǿգ���pԭ����������Ϊe��������
{
	if (p == NULL)	// p�գ�����
		return FAIL;
	else 	{	// ��������
		TreeNode<ElemType> *child =  new TreeNode<ElemType>(e);// Ԫ��ֵΪe���
		if (p->firstChild != NULL)	// p�����ӷǿ�
			child->nextSibling = p->firstChild;	// pԭ����������Ϊe��������
		p->firstChild = child;					// e��Ϊp������
		return SUCCESS;
	}
}

template <class ElemType>
void Tree<ElemType>::DeleteChild(TreeNode<ElemType> *p,int i)
// ��ʼ������p�ǿ�
// ���������ɾ����p�ĵ�i�����ӽڵ�Ϊ��������
{
	if (p == NULL)	// pΪ��
		return;
	else	// p�ǿ�
	{
	int j=1;
	p=p->firstChild;
	while(j<i&&p!=NULL) {p=p->nextSibling;j++;}
	if(p==NULL) return;
	Destroy(p);
	return;
}
}

template <class ElemType>
void Tree<ElemType>::DeleteSubTree(TreeNode<ElemType> *p)
// ��ʼ������p�ǿ�
// ���������ɾ����pΪ��������
{
	if (p == NULL)	// pΪ��
		return;
	else	// p�ǿ�
		Destroy(p);	
}

template <class ElemType>
void Tree<ElemType>::Destroy(TreeNode<ElemType> *&r)
// ���������ɾ����r����
{
	if(r != NULL)	{	// r�ǿ�,ʵʩɾ��
		if(r->nextSibling!=NULL)
		{
			if(preSibling(r)!=NULL) preSibling(r)->nextSibling=r->nextSibling;
			else if(preSibling(r)==NULL&&Parent(r)!=NULL) Parent(r)->firstChild=r->nextSibling;	
			r->nextSibling=NULL;
		}
		else
		{
			if(preSibling(r)!=NULL) preSibling(r)->nextSibling=NULL;
			else if(preSibling(r)==NULL&&Parent(r)!=NULL) Parent(r)->firstChild=NULL;	
		}
		Destroy(r->firstChild);
		delete r;					// ɾ�������
		r = NULL;
	}
	else return;
}

template <class ElemType>
TreeNode<ElemType> *Tree<ElemType>::Find(const ElemType &e) const
// ������������ؽڵ���ֵΪe�Ľڵ�
{
	LinkQueue<TreeNode<ElemType> *> q;	// �������q
	TreeNode<ElemType> *p;
	
	if (root != NULL) q.EnQueue(root);		// ������ǿ�,�����
	while (!q.IsEmpty())	{	            // q�ǿ�,˵�����н��δ����
		q.DelQueue(p);                      // ��ͷԪ�س��ӣ�������֮ 
		if (p->data == e)
			return p;
		if (p->firstChild != NULL)			// ��ͷԪ�����ӷǿ�
			q.EnQueue(p->firstChild);		// �������
		if (p->nextSibling != NULL)			// ��ͷԪ���Һ��ӷǿ�
			q.EnQueue(p->nextSibling);		// �Һ������
	}
	return NULL;
}


template <class ElemType>
TreeNode<ElemType> *Tree<ElemType>::CopyTree(TreeNode<ElemType> *t)
// �������������tΪ���������Ƴ��µ���,���������ĸ�
{
	if (t == NULL)	// ���ƿ���
		return NULL;					// ������Ϊ��	
	else	{	// ���Ʒǿ���
		TreeNode<ElemType> *lChild = CopyTree(t->firstChild);	// ����������
		TreeNode<ElemType> *rSibling = CopyTree(t->nextSibling);	// ����������
		TreeNode<ElemType> *r = new TreeNode<ElemType>(t->data, lChild, rSibling);
			// ���Ƹ����
		return r;
	}
}

template <class ElemType>
Tree<ElemType>::Tree(const Tree<ElemType> &t)
// �������������֪�����������������ƹ��캯��
{
	root = CopyTree(t.root);	// ������
}

template <class ElemType>
Tree<ElemType>::Tree(TreeNode<ElemType> *r)
// ���������������rΪ������
{	
	root = r;	// ������
}

template <class ElemType>
Tree<ElemType> &Tree<ElemType>::operator=(const Tree<ElemType> &t)
// �������������֪��t���Ƶ���ǰ��--��ֵ���������
{
	if (&t != this)	{
		Destroy(root);				// �ͷ�ԭ����ռ�ÿռ�
		root = CopyTree(t.root);	// ������
	}
	return *this;
}

template <class ElemType>
void DisplayTWithTreeShape(TreeNode<ElemType> *r, int level)
// �������������״��ʽ��ʾ��rΪ��������levelΪ���������������Ĳ����Ϊ1
{
	if(r != NULL)	{	// ��������ʽ��ֻ��ʽ�ǿ���
		DisplayTWithTreeShape<ElemType>(r->nextSibling, level);//��ʾ������
		cout << endl;					//��ʾ����	
		for(int i = 0; i < level - 1; i++)
			cout << "  ";				//ȷ���ڵ�level����ʾ���
		cout << r->data;				//��ʾ���
		DisplayTWithTreeShape<ElemType>(r->firstChild, level + 1);//��ʾ������
	}
}

template <class ElemType>
void DisplayTWithTreeShape(Tree<ElemType> &bt)
// �����������״��ʽ��ʾ�� 
{
	DisplayTWithTreeShape<ElemType>(bt.GetRoot(), 1);	
		// ��״��ʾ��bt.GetRoot()Ϊ������
	cout << endl;
}

template <class ElemType>
void CreateTree(TreeNode<ElemType> *&r, ElemType pre[], ElemType post[], 
							int preLeft, int preRight, int postLeft, int postRight)	
// �����������֪������������pre[preLeft..preRight]�ͺ�������post[postLeft..postRight]����
//	��rΪ������
{
	if (postLeft > postRight)	// ���޽��,����
		r = NULL;			// ������Ϊ��
	else	{	// ���н��,�ǿ���
		r = new TreeNode<ElemType>(pre[preLeft]);// ���ɸ����
		int mid = postLeft;
		while (post[mid] != pre[preLeft]) 	// ����pre[preLeft]��in[]�е�λ��,Ҳ���Ǻ��������и���λ��
			mid++;
		CreateTree(r->firstChild, pre, post, preLeft+1, preLeft + mid - postLeft, postLeft, mid - 1);
			// ����������
		CreateTree(r->nextSibling, pre, post, preLeft + mid - postLeft + 1, preRight, mid + 1, 
			postRight);								// ����������
	}
} 

template <class ElemType>
Tree<ElemType> &CreateTree(ElemType pre[], ElemType post[], int n)
// �����������֪����ͺ������й�����
{
	TreeNode<ElemType> *r;						// ���ĸ�
	CreateTree<ElemType>(r, pre,post, 0, n - 1, 0, n - 1);
		// ������ͺ������й�����rΪ������ 
	Tree<ElemType> *bt = new Tree<ElemType>(r);	// ������
	return *bt;
}

#endif
