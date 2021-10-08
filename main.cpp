#include "heap.h"

int main() {

	Heap<int> tree;

	tree.insert(5);
	tree.insert(2);
	tree.insert(7);
	tree.insert(8);
	tree.insert(6);
	tree.insert(4);
	tree.insert(1);
	tree.insert(9);

	tree.print_levelorder();
	tree.print_inorder();

	return 0;
}


