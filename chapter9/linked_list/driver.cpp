/*
 * 打的
 */
#include <iostream>
#include "linked_list.h"

using namespace std;

int main()
{
	LinkedList<int> list;

	for (int i = 0; i < 10; i++)
	{
		Node<int> *nodePtr = new Node<int>(i);
		list.append(nodePtr);
		list.print();
		cout << endl;
	}


	return 0;
}
