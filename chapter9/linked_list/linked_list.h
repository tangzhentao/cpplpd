#include<iostream>

using namespace std;

template<class T>
struct Node
{
	Node(T d, Node *n = NULL): data(d), next(n)
	{
	}

	T data;
	Node *next;
};

template<class T>
class LinkedList
{
	public:
		LinkedList();
		/* 把新节点插入到指定节点之后 */
		void insert(Node<T> *newNode, Node<T> *node);
		/* 把新节点插入到指定位置*/
		//void insert(Node<T> *newNode, int position);
		/* 把指定节点添加到尾部 */
		void append(Node<T> *node);
		/* 删除指定节点 */
		void remove(Node<T> *node);
		/* 删除指定位置上的节点 */
		//void reomve(int position);
		/* 获取指定位置上的节点 */
		//void getNode(int position);
		bool isEmpty() const;
		int getSize() const;

		void print() const;

	private:
		Node<T> *_head;
		Node<T> *_tail;
		Node<T> *_currentNode;
		Node<T> *_preNode;
		int _size;

};

template<class T>
LinkedList<T>::LinkedList():
	_head(NULL), _tail(NULL), _size(0), _currentNode(NULL), _preNode(NULL)
{
}

template<class T>
void LinkedList<T>::insert(Node<T> *newNode, Node<T> *node)
{
	// 为空，直接返回
	if (NULL == newNode || NULL == node)
		return;
	/*
	 * 1. 如果链表为空，则把该节点作为头结点
	 * 2. 如果链表非空，则把该节点插入到尾节点之后
	 */
	newNode->next = node->next;
	node->next = newNode;

	// 累加_size
	++_size;
}

/*
template<class T>
void LinkedList<T>::insert(Node<T> *newNode, int position)
{
	// 为空，直接返回
	if (NULL == newNode || (poisition < 0 || position >= ))
		return;
}
*/

template<class T>
void LinkedList<T>::append(Node<T> *newNode)
{
	/*
	 * 1. 如果链表为空，则把该节点作为头结点
	 * 2. 如果链表非空，则把该节点插入到尾节点之后
	 */
	if (isEmpty())
	{
		_head = newNode;
		_tail = newNode;
	} else 
	{
		_tail->next = newNode;
		_tail = newNode;
	}

	// 累加_size;
	++_size;
}

template<class T>
void LinkedList<T>::remove(Node<T> *node)
{
	/* 1、查找node的前驱
	 * 2、如果没找到，直接返回
	 * 3、如果找到了，删除node
	 */

	// 如果链表为空或node为空，直接返回
	if (isEmpty() || NULL == node) 
		return;

	if (_head == node)
	{
		// 如果要删的是头节点，就直接删掉
		_head = NULL;
		delete node;
		--_size;
	} else
	{
		// 如果要删的不是头节点，则先找到前驱，再删除
		Node<T> *preNode = NULL;
		Node<T> *tmpNode = _head;

		while (tmpNode)
		{
			if (tmpNode->next == node)
			{
				preNode = tmpNode;
				break;
			}

			tmpNode = tmpNode->next;
		}

		// 如果找到前驱了，就删除
		if (preNode)
		{
			preNode->next = node->next;
			delete node;
			--_size;
		}
	}
}
template<class T>
bool LinkedList<T>::isEmpty() const
{
	return (NULL == _head);
}

template<class T>
int LinkedList<T>::getSize() const
{
	return _size; 
}

template<class T>
void LinkedList<T>::print() const
{
	Node<T> *tmpPtr = _head;
	while(tmpPtr)
	{
		cout << tmpPtr->data << " ";
		tmpPtr = tmpPtr->next;
	}
	cout << endl;
}
