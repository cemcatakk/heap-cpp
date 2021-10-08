#include <iostream>
#include <stack>
#include <cmath>

using namespace std;

template<class T>
class HeapNode {
public:
   T data;
   HeapNode<T> *left;
   HeapNode<T> *right;
   HeapNode<T> *parent;


   HeapNode(const T &new_data) {
       data = new_data;
       left = NULL;
       right = NULL;
       parent = NULL;
   }
};


template<class T>
class Heap {
private:
   HeapNode<T> *root;
   int node_count;

public:
   Heap();

   void insert(const T&);
   void print_inorder() const;
   void print_levelorder() const;

private:
   HeapNode<T>* insert(const T&, HeapNode<T>*, stack<int>&);
   void print_inorder(HeapNode<T>*) const; 
   void print_levelorder(HeapNode<T>*, int) const; 
   void swap(T*, T*);
};


template<class T>
Heap<T>::Heap() {
   root = NULL;
   node_count = 0;
}

template<class T>
void Heap<T>::insert(const T &new_data) {

   if (root == NULL) {
       {root = new HeapNode<T>(new_data); node_count++;} 
   } else {
       node_count++;
       int tmp = node_count;
       stack<int> dir;
       if (tmp > 2) {
           while (tmp != 1) {
               dir.push(tmp % 2);
               tmp = floor(tmp / 2);
           }
       } else {
           dir.push(0);
       }
       stack<int> tmpdir=dir; 
       HeapNode<T> *tmp_node = insert(new_data, root, dir); 
	    while(true)
	    { 
	        if(tmpdir.top()!=0)
	        {
	            tmp_node=tmp_node->right;
	        }
	        else
	        {   
	            tmp_node=tmp_node->left;
	        }
	        tmpdir.pop();
	        if(tmpdir.empty()==true){
	        	break;
			}
	    }
       while(tmp_node->parent->data>tmp_node->data)
       {
           swap(&tmp_node->parent->data,&tmp_node->data);
           tmp_node=tmp_node->parent;
           if(tmp_node==root){
           	break;
		   }
       }
   }
}
template<class T>
HeapNode<T>* Heap<T>::insert(const T &new_data, HeapNode<T> *node, stack<int> &dir) {
   int tempval;
   if(node==NULL) 
    {
	    HeapNode<T> *tmp=new HeapNode<T>(new_data);
	    return tmp;
    }
    if(dir.empty()==true)return NULL;
	tempval=dir.top();
    dir.pop();
    if(tempval!=0)
    {  
		node->right=insert(new_data,node->right,dir);
	    node->right->parent=node;
	    return node;
    }
    else
    {
    	node->left= insert(new_data,node->left,dir);
		node->left->parent=node;
		return node;
    }
}

template<class T>
void Heap<T>::print_inorder() const {
   print_inorder(root);
   std::cout << std::endl;
}

template<class T>
void Heap<T>::print_inorder(HeapNode<T> *node) const {
   if (node) {
       print_inorder(node->left);
       std::cout << node->data << " ";
       print_inorder(node->right);
   }
}

template<class T>
void Heap<T>::print_levelorder() const {
   int h = floor(log2(node_count)) + 1; 
   int i;

   for (i = 1; i <= h; i++) { 
       for (int a = 0; a <= h - i; a++) {
           std::cout<<" ";
       }
       print_levelorder(root, i);
       std::cout<<std::endl;
   }
}
using namespace::std;
template<class T>
void Heap<T>::print_levelorder(HeapNode<T> *node, int level) const {
   if(node != NULL){
    if (level > 1) 
    {
        print_levelorder(node->left, level-1);
        print_levelorder(node->right, level-1);
    }
    else if(level <= 1){
    	cout<<" "<<node->data;
	}
   }
}
template<class T>
void Heap<T>::swap(T *x, T *y) {
   T temp = *x;
   *x = *y;
   *y = temp;
}

