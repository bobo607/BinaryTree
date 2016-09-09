#include <iostream>
using namespace std;
#include <stack>
#include <assert.h>
#include <queue>

template <class T>
struct Binarytreenode
{
	struct Binarytreenode(T _data)
	:data(_data)
	,PRight(NULL)
	,PLeft(NULL)
	{}
	T data;
	Binarytreenode<T>* PLeft;
	Binarytreenode<T>* PRight;
};

template<class T>
class Binarytree
{
public:
	Binarytree()
		:PRoot(NULL)
	{}

	Binarytree(Binarytreenode<T>*& PRoot, size_t size, size_t& iIdx, const T arr[])
	{
		PRoot = createBinarytree(PRoot, size,iIdx, arr);
		
	}

	Binarytreenode<T>* createBinarytree(Binarytreenode<T>*& PRoot, size_t size, size_t& iIdx, const T arr[])
	{
		if (PRoot == NULL)
			assert(false);
		Binarytreenode<T>* a = PRoot;
		
		if (iIdx < size&& arr[iIdx] != '#')
		{
			a = new Binarytreenode<T>(arr[iIdx]);
			a->PLeft = createBinarytree(a, size, ++iIdx, arr);
			a->PRight = createBinarytree(a, size, ++iIdx, arr);

		}
		else
		{
			a = NULL;
		}
		return a;
	}

	Binarytree(const Binarytreenode<T>*& a) //拷贝构造
	{
	
			_pRoot = CopyBinaryTree(b._pRoot);
	}

	/*BinaryTreeNode<T>* CopyBinaryTree(BinaryTreeNode<T>* pNode)
	{
		BinaryTreeNode<T>* pNewNode = NULL;
		if (pNode == NULL)
		{
			return NULL;
		}
		pNewNode = new BinaryTreeNode<T>(pNode->_data);
		pNewNode->pLeft = CopyBinaryTree(pNode->pLeft);
		pNewNode->pRight = CopyBinaryTree(pNode->pRight);
		return pNewNode;
	}*/





	/*BinaryTree<T>& operator=(BinaryTree*<T> b)
	{
			swap(_pRoot, b._pRoot);
			return *this;
	}
*/
	





	Binarytreenode<T>& operator=(const Binarytreenode<T>& a)
	{
		data(a.data);
		PRight(a.PLeft);
		PLeft(a.PRight);
		return *this;
	}




	~Binarytree()
	{
		void destroy(Binarytree<T>& PRoot);
		PRoot = NULL;
	}

	void destroy(Binarytree<T>& PRoot)
	{
		if (PRoot != NULL)
			destroy(PRoot)
			destroy()
			delete(PRoot);
	}


	/*void inorder(Binarytreenode<T>* a)const
	{
		stack<Binarytreenode<T>> s;
		Binarytreenode<T>* Pcur = a;
		if (Pcur != NULL)
		{
			s.push(Pcur);
			Binarytreenode<T>* Pcur = Pcur->PLeft;
			while (Pcur != NULL)
			{
				s.push(Pcur);
				Pcur = Pcur->PLeft;
			}
			while (!s.empty)
			{
				Binarytreenode<T>* ret = s.top;
				cout << ret->data << " ";
				s.pop;
				if (ret->PRight != NULL)
				{
				
					while (ret->PRight)
					{ 
						ret = ret->PRight
						s.push(ret); 	
					}
					cout << ret->PRight->data << " ";
				}
	
			}
		}


	}
*/

	void inorder(Binarytreenode<T>* PRoot)const //中序遍历
	{
		stack<Binarytreenode<T>*> s;
		Binarytreenode<T>* Pcur = PRoot;
		while (Pcur || !s.empty)
		{
			if (Pcur!=NULL)
			{
				s.push(Pcur);
				Pcur = Pcur->PLeft;
			}
			else
			{
				Pcur = s.top;
				cout << Pcur->data << " ";
				s.pop;
				Pcur = Pcur->PRight;
			}

		}


	}

	void frontorder(Binarytreenode<T>* PRoot)const //先序遍历
	{
		stack<Binarytreenode<T>> s;
		Binarytreenode<T>* Pcur = PRoot;
		while (!s.empty || Pcur)
		{
			if (Pcur != NULL)
			{
				s.push(Pcur);
				cout << Pcur->data << " ";
				Pcur = Pcur->PLeft;
			}
			else
			{
				Pcur = s.top;
				s.pop();
				Pcur = Pcur->PRight;
			}
		}

	}
	

	void backorder(Binarytreenode<T>* PRoot)const //后序遍历
	{
		stack<Binarytreenode<T>> s;
		Binarytreenode<T>* Pcur = PRoot;

	}


	void levelorder(Binarytreenode<T>* PRoot)const //层序遍历
	{
		queue <Binarytreenode<T>> q;
		Binarytreenode<T>* Pcur = PRoot;
		if (PRoot != NULL)
		{	
			q.push(Pcur);
			while(!q.empty())
			{
				if (Pcur->PLeft != NULL)
				{
					q.push(Pcur->PLeft);
				}
				if (Pcur->PRight != NULL)
				{
					q.push(Pcur->PRight);
				}
				cout<< Pcur<< " ";
				q.pop();
				Pcur = q.front();
			}
		}
	}

private:
	Binarytreenode<T>* PRoot;
};


int main()
{
	char arr[] = {'1','2','#','#','3'};
	size_t size = sizeof(arr) / sizeof(arr[0]);
	size_t iIdx = 0;
	Binarytreenode<char>* PRoot;
	Binarytree<char> a(PRoot,size,iIdx,arr);
	a.levelorder(PRoot);
	return 0;
}