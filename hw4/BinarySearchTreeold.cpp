/*
 * BinarySearchTree.cpp
 */

#include <iostream>
#include "BinarySearchTree.h"
using namespace std;

BinarySearchTree::BinarySearchTree() {
//constructor
	/// TODO: Students write code here
	root = NULL;
}

BinarySearchTree::~BinarySearchTree() {
//destructor
	// walk tree in post-order traversal and delete
	post_order_delete(root);
}

void BinarySearchTree::post_order_delete(Node *node) {
//pdelete
	/// TODO: students write code here
	
/////////////////////////////////////////
	//recursive algorithm:
	//base case: we are at a leaf (r & l are NULL)
	if (node == NULL){
		return;
	}
	//traverse left
	post_order_delete(node->left);
	//traverse right
	post_order_delete(node->right);
	//delete node
	delete node;
///////////////////////////////////////////
	// (hint: use a post-order traversal to remove all nodes)
}

BinarySearchTree::BinarySearchTree(const BinarySearchTree &source) {
//copy constructor
	// use pre-order traversal to copy the tree
	if (source.root == NULL) return;
	
	root = pre_order_copy(source.root);

}


BinarySearchTree& BinarySearchTree::operator=
		(const BinarySearchTree &source) {
// assignment overload
	/// TODO: Students write code here
	// check for self-assignment
	if (this == &source){
		return *this;
	}
	// delete current tree if it exists
	if (root != NULL){
		post_order_delete(root);
	}
	//check if source is NULL
	if (source.root == NULL) return *this;//nothing to do
	
	// use pre-order traversal to copy the tree
	root = pre_order_copy(source.root);//check into this

	// don't forget to "return *this"
	return *this;
}

Node * BinarySearchTree::pre_order_copy(Node *node) {
//pre order traversal copy (returns the root pointer)
	// TODO: Students write code here
	// (hint: use a pre-order traversal to copy details from the
	// node to a new_node)
	if (node == NULL) return NULL;
	Node *new_node = new Node();
	
	new_node->data = node->data;
	new_node->count = node->count;
	new_node->left = pre_order_copy(node->left);
	new_node->right = pre_order_copy(node->right);
	
	return new_node;

}

int BinarySearchTree::find_min() {
//degenerate case
	if (root == NULL) return INT_MIN;
	return find_min(root)->data;
}

Node *BinarySearchTree::find_min(Node *node) {
//find_min with included arguments
	//go left until the root's left is NULL
	//return data in root
	//BASE CASE: we are at the left most (smallest) node
	if (node->left == NULL) return node;
	return(find_min(node->left));//go left to work towards base case
	
	/// TODO: Students write code here
}

int BinarySearchTree::find_max() {

	if (root == NULL) return INT_MAX;
	return find_max(root)->data;
	/// TODO: Students write code here
}

Node *BinarySearchTree::find_max(Node *node) {
//find_max with included arguments
	//go right until the root's right is NULL
	//return data in root
	//BASE CASE: we are at the right most (largest) node
	if (node->right == NULL) return node;
	return(find_min(node->right));//recursion portion
	
	/// TODO: Students write code here
}

bool BinarySearchTree::contains(int value) {
//contains private function
	//traverse the tree
	//return true if the value is found
	contains(root, value);
	return false;///
	/// TODO: Students write code here
}

bool BinarySearchTree::contains(Node *node, int value) {
	/// TODO: Students write code here
	if (node == NULL) return false;
	if (node->data == value) return true;
	if(contains (node -> left, value)) return true;//check syntax//asymp bh
	if(contains (node -> right, value)) return true;//check syntax
	return false;
	
}

void BinarySearchTree::insert(int value) {
	insert(root,NULL,value);
}

void BinarySearchTree::insert(Node *node,Node *parent, int value) {
	/// TODO: Students write code here
//Base Case for recursion:
//We have reached the end of the
//tree and we are at NULL. We
//create a node with the correct
//information

	if(node == NULL)
	{
		cerr << "inserting first node" << endl;
		Node *newNode = new Node;
		newNode->data = value;
		newNode->left = NULL;
		newNode->right = NULL;
		newNode-> count = 1;
		if(root == NULL){
			root = newNode;
			return;
		}
		
		if(parent->data > value){
			parent->left = newNode;
		}else{
			parent->right = newNode;
		}
	}
	else if (node->data == value){///check this out for bugs
		node->count++;
		return;
	}
	else if(value < node->data)
	{
		insert(node->left, node, value);
	}
	else
	{
		insert(node->right, node, value);
	}
}

bool BinarySearchTree::remove(int value) {
	return remove(root,NULL,value);
}

bool BinarySearchTree::remove(Node *node, Node *parent, int value) {
	// (cannot be a lazy removal)
	//three cases

	if (node == NULL) return false;//Degenerate case
	//Case 1: node is a leaf
	if (node->data != value){
		if (node->data < value){
			return remove(node->right, node, value);
		}else{
			return remove(node->left, node, value);
		}
	}else{
		
		if ((node -> right == NULL) && (node -> left == NULL)){//check that node is leaf
			delete node;//delete the leaf
			return true;
		}
		if ((node -> right != NULL) || (node -> left != NULL)){
			if((node -> right != NULL) && (node -> left != NULL)){//Case 3: node has 2 children look at findparent()
				//cerr << "2 children" << endl;
				Node *temp;
				temp = find_min(node -> right);
				node->data = temp->data;
				node->count = temp->count;
				
				Node *parentMin = find_parent (node, temp);
				return remove(temp, parentMin, temp->data);
			}else{	//Case 2: node has 1 child (jump over)
				if (node -> right == NULL){
					if (parent->left == node){
						parent->left = node->left;
						delete node;
						
						return true;
					}else if (parent -> right == node){
						parent->right = node->left;
						delete node;
						return true;
					}
				}else if (node -> left == NULL){
					if(parent->left == node){
						parent -> left = node -> left;
						delete node;
						return true;
					}else if (parent -> right == node){
						parent->right = node->left;
						delete node;
						return true;
					}
				}
			}
			/*
				if (node -> right != NULL){
					//cerr << "we have a right child" << endl;
					node = node -> right;
					delete node -> right;//memory leak fix
					return true;
				}if (node -> left != NULL){
					//cerr << "we have a left child" << endl;
					node = node -> left;
					delete node -> left;//memory leak fix
					return true;
				}
			}*/
		}
	}
	return false;//if all tests fail, then no node was removed

}

int BinarySearchTree::tree_height() {
	return tree_height(root);
}

int BinarySearchTree::tree_height(Node *node) {
	// TODO: Students write code here
	int leftHeight = 0;
	int rightHeight = 0;
	if(node == NULL) return -1;
	else{
		leftHeight = tree_height(node->left);
		rightHeight = tree_height(node->right);
	}
	if (leftHeight > rightHeight){
		return leftHeight+1;
	}else{
		return rightHeight +1;
	}
}


int BinarySearchTree::node_count() {
// returns the total number of nodes
	return node_count(root);
}

int BinarySearchTree::node_count(Node *node) {
	// TODO: Students write code here
	//traverse the entire tree in any order (recursive)
	//use a counter for recursion
	int sum = 0;
	if (node == NULL){
		return 0;
	}else{
		sum = (node_count(node->right)+node_count(node->left)+1);
	}
	return sum;
}


int BinarySearchTree::count_total() {
// return the sum of all the node values (including duplicates)
	return count_total(root);
}

int BinarySearchTree::count_total(Node *node) {
	// TODO: Students write code here:
	//traverse the entire tree and add whatever is 
	//returned to a sum variable
	int data = 0;
	int count = 0;
	if (node == NULL){
		return 0;
	}else{
		count = node->count;
		data = node->data;
		return (count_total(node->left)+count_total(node->right)+(data*count));
	}
}

// use the printPretty helper to make the tree look nice
void BinarySearchTree::print_tree() {
	printPretty(root, 1, 0, std::cout);
}

Node *BinarySearchTree::find_parent(Node *node,Node *child) {
	if (node==NULL) return NULL;

	// if either the left or right is equal to the child,
	// we have found the parent
	if (node->left==child || node->right == child) {
		return node;
	}

	// Use the binary search tree invariant to walk the tree
	if (child->data > node->data) {
		return find_parent(node->right,child);
	}
	else {
		return find_parent(node->left,child);
	}
}
