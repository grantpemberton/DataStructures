#include "BSTree.h"


BST::BST()
{
	root = NULL;	
}

//
// Insert: public version of Insert takes a value only and
// 	   inserts in the tree at the root
//

BST::~BST()
{
//destructor!!!
	pdelete(root);
}

void BST::pdelete(BSTNode* root)
{
	//recursive algorithm:
		//base case: we are at a leaf (r & l are NULL)
	if (root == NULL){
		return;
	}
		//traverse left
	pdelete(root->left);
		//traverse right
	pdelete(root->right);
	//delete node
	delete root;
}

void BST::unbalancedInsert(int v)
{
	root = unbalancedInsert(root, v);
}

//
// Insert: private version inserts a value at any subtree
//         given by the 'root' of that tree
//
//   returns: the current tree NOW WITH the value inserted
//   note: ALWAYS adds a leaf
//
BSTNode* BST::unbalancedInsert(BSTNode* r, int v)
{
	//Base Case for recursion:
	//We have reached the end of the
	//tree and we are at NULL. We
	//create a node with the correct
	//information and return a pointer
	//to the new data. This return sets
	//the value for the parent which made
	//the function call

	if(r == NULL)
	{
		r = new BSTNode;
		r->value = v;
		r->left = NULL;
		r->right = NULL;
		return r;
	}

	//notice we asked NULL first so that
	//r->left and r->right will not seg fault

	else if(v < r->value)
	{
		r->left = unbalancedInsert(r->left, v);
		return r;

	}

	else
	{
		r->right = unbalancedInsert(r->right, v);
		return r;


	}
}


//****************** inorder *****************//

void BST::inOrder()
{
	inOrder(root);		// calls the next one
}


void BST::inOrder(BSTNode* root)
{
	//TODO: your code here
	//recursive algorithm:
		//base case: we are at a leaf (r & l are NULL)
	if (root == NULL){
		return;
	}
		//traverse left
	inOrder(root->left);
		//print node
	cout << root->value << " ";
		//traverse right
	inOrder(root->right);

}



//****************** postorder *****************//



void BST::postOrder()
{	
	postOrder(root);	// calls the next one
}

void BST::postOrder(BSTNode* root)
{
	//TODO: your code here --- if you want

	//recursive algorithm:
		//base case: we are at a leaf (r & l are NULL)
	if (root == NULL){
		return;
	}
		//traverse left
	inOrder(root->left);
		//traverse right
	inOrder(root->right);
	//print node
	cout << root->value << " ";
}



//****************** preorder *****************//



// print the tree in preOrder using the next function
// Question to ponder: can we do this without a helper function?
void BST::preOrder()
{
	preOrder(root);		// calls the next one (really needed?)
}

//
// preOrder traversal using a stack of our own, not
// the one from the compiler

void BST::preOrder(BSTNode* root)
{
	//preorder with a stack
	//TODO: stack defined here:
	stack <BSTNode *> s;
	BSTNode* temp;
	//TODO: your code here
	s.push(root);
	//while loop
	while (!s.empty()){
		//temp = top stack
		temp = s.top();
		//pop the stack (
		s.pop();
		//print temp
		cout << temp->value << " ";
		//if there is a right child, push it
		if (temp->right != NULL){
			s.push(temp->right);
		}
		//if there is a left child, push it
		if (temp->left != NULL){
			s.push(temp->left);
		}
	}

}



//****************** levelorder *****************//



void BST::levelOrder()
{
	levelOrder(root);
}


void BST::levelOrder(BSTNode* root)
{

	//TODO: Use a queue, declare it here

	//TODO: your code here

	//preorder with a stack
	//TODO: stack defined here:
	queue <BSTNode *> q;
	BSTNode* temp;
	//TODO: your code here
	q.push(root);
	//while loop
	while (!q.empty()){
		//temp = top stack
		temp = q.front();
		//pop the stack (
		q.pop();
		//print temp
		cout << temp->value << " ";
		//(left right is reversed because FIFO vs FILO)
		//if there is a left child, push it
		if (temp->left != NULL){
			q.push(temp->left);
		}
		//if there is a right child, push it
		if (temp->right != NULL){
			q.push(temp->right);
		}

	}

}
