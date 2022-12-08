#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

template <class T> 
class BSTNode{
	public:
		BSTNode(){
			left = right = NULL;
		}
		BSTNode(const T& e, BSTNode<T> *l = NULL, BSTNode<T> *r = NULL){
			el = e;
			left = l;
			right = r;
		}
		T el;
		BSTNode *left, *right;
};

template <class T>
class bst{
	public:
		bst(){//
			root = 0;
		}
		// ~bst(){//
		// 	// clear();
		// }
		void clear(){
			clear(root);
			root = NULL;
		}
		bool isEmpty() const{
			return root == NULL;
		}
		void preorder(){
			preorder(root);
		}
		void inorder(){
			inorder(root);
		}
		void postorder(){
			postorder(root);
		}
		T* search(const T& el)const{
			search(root, el);
		}
		int count_leaf(){
			return count_leaf(root);
		}
		void breadthFirst(BSTNode<T>* p);//
		void iterativePreorder(BSTNode<T>* p);//
		void iterativeInorder(BSTNode<T>* root);//
		void iterativePostorder(BSTNode<T>* root);//
		int count_leaf(BSTNode<T>* p);//
		int count_nonleaf(BSTNode<T>* p);//
		int Tree_height(BSTNode<T>* p);//
		void mirror(BSTNode<T>* p);//
		int swap(int* a, int* b){
			int t = *a;
			*a = *b;
			*b = t;
		}
		void insert(BSTNode<T>* el1, BSTNode<T>* el2);//
		void deleteByMerging(BSTNode<T>*& node);//
		void findAndDeleteByMerging(const T& el);//not working....
		void deleteByCopying(BSTNode<T>*& el);//
		void balance(T*, int, int);
		BSTNode<T>* root;//
		void clear(BSTNode<T>* p);//not working....
		T* search(BSTNode<T>*, const T&) const;//
		void preorder(BSTNode<T>*);//
		void inorder(BSTNode<T>*);//
		void postorder(BSTNode<T>*);//
		virtual void visit(BSTNode<T>* p){//
			cout<<p->el<<" ";
		}
		void display(BSTNode<T> *ptr, int level);//
		void insertElement(const T &el)
    	{
        	BSTNode<T> *p = root, *prev = NULL;

        	while (p != NULL)
        	{
            	prev = p;

            	if (p->key < el)
                	p = p->right;

            	else
                	p = p->left;
        	}

        	if (root == NULL)
            	root = new BSTNode<T>(el);

        	else if (prev->key < el)
            	prev->right = new BSTNode<T>(el);

        	else
            	prev->left = new BSTNode<T>(el);
    	}
		void se(BSTNode<T>* root,BSTNode<T>* s){
			BSTNode<T>* p = root;
			BSTNode<T>* q = s;
			bool r = search(root,q->el);
			if(r = true){
				cout<<"True";
				swap(&p->el,&q->el);
			}
			display(root,1);
			cout<<endl;
			while(root->el < root->left->el && root->el < root->right->el){
				if(root->el < root->left->el){
					swap(&root->el,&root->left->el);
				}
				else{
					swap(&root->el,&root->right->el);
				}
			}
			//cout<<root->el;
			display(root,1);
		}
};

template <class T>void bst<T> :: clear(BSTNode<T>* p){
	clear(p -> left);
	clear(p -> right);
	delete p;
	return ;
}

template <class T>
void bst<T> :: iterativePreorder(BSTNode<T>* root)
{
	stack<BSTNode<T>*> travStack;
	//BSTNode<T> *p = root;
	//if(p != NULL){
		travStack.push(root);
		while(!travStack.empty()){
			BSTNode<T> *p = travStack.top();
			cout<<p->el<<" ";
			travStack.pop();
			
			if(p -> right ){
				travStack.push(p -> right);
			}
			if(p -> left ){
				travStack.push(p -> left);
			}
		}
	//}
}

template <class T>
void bst<T> :: iterativeInorder(BSTNode<T>* root)
{
	stack<BSTNode<T>*> travStack;
	BSTNode<T>* p = root;
	while(!travStack.empty() || p != NULL){
		while(p != NULL){
			travStack.push(p);
			p = p->left;
		}
		p = travStack.top();
		travStack.pop();
		cout<<p->el<<" ";
		p = p->right;
	}
}

template <class T>
void bst<T> :: iterativePostorder(BSTNode<T>* root)
{
	if(root == NULL){
		return;
	}
	stack<BSTNode<T>*> travStack, s2;
	travStack.push(root);
	BSTNode<T>* p;
	while(!travStack.empty()){
		p = travStack.top();
		travStack.pop();
		s2.push(p);
		if(p->left){
			travStack.push(p->left);
		}
		if(p->right){
			travStack.push(p->right);
		}
	}
	while(!s2.empty()){
		p=s2.top();
		s2.pop();
		cout<<p->el<<" ";
	}
}

template <class T>
T* bst<T> :: search(BSTNode <T>*p, const T& el)const
{
	while(p != 0){
		if(el == p-> el){
			return &p -> el;
		}
		else if(el < p -> el){
			p = p -> left;
		}
		else{
			p = p -> right;
		}
	}
	return 0;
}

template<class T>
void bst<T> :: breadthFirst(BSTNode<T>* root){
	queue<BSTNode<T> *> que;
	BSTNode<T> *p = root;
	if(p != NULL){
		que.push(p);
		while (!que.empty()){
			p=que.front();
			que.pop();
			cout<<p->el<<" ";
			if(p -> left != NULL){
				que.push(p -> left);
			}
			if(p -> right != NULL){
				que.push(p -> right);
			}
		}
	}
}

template <class T>
void bst<T> :: inorder(BSTNode<T> *p){
	if(p !=0 ){
		inorder(p -> left);
		visit(p);
		inorder(p -> right);
	}
}

template <class T>
void bst<T> :: preorder(BSTNode<T> *p){
	if(p !=0 ){
		visit(p);
		preorder(p -> left);
		preorder(p -> right);
	}
}

template <class T>
void bst<T> :: postorder(BSTNode<T> *p){
	if(p !=0 ){
		postorder(p -> left);
		postorder(p -> right);
		visit(p);
	}
}

template<class T>
void bst<T> ::insert(BSTNode<T> *root, BSTNode<T> *newnode)
{
    if (root == NULL)
    {
        root = new BSTNode<T>;
        root->el = newnode->el;
        root->left = NULL;
        root->right = NULL;
        //cout<<"Root Node is Added"<<endl;
        return;
    }
    if (root->el == newnode->el)
    {
        cout<<"Element already in the tree"<<endl;
        return;
    }
    if (root->el > newnode->el)
    {
        if (root->left != NULL)
        {
            insert(root->left, newnode);	
	}
	else
	{
            root->left = newnode;
            (root->left)->left = NULL;
            (root->left)->right = NULL;
            //cout<<"Node Added To Left"<<endl;
            return;
        }
    }
    else
    {
        if (root->right != NULL)
        {
            insert(root->right, newnode);
        }
        else
        {
            root->right = newnode;
            (root->right)->left = NULL;
            (root->right)->right = NULL;
            //cout<<"Node Added To Right"<<endl;
            return;
        }	
    }
    return ;
}

template <class T>
void bst<T> ::display(BSTNode<T> *ptr, int level)
{
    int i;
    if (ptr != NULL)
    {
        display(ptr->right, level+1);
        cout<<endl;
        if (ptr == root)
            cout<<"Root->:  ";
        else
        {
            for (i = 0;i < level;i++)
                cout<<"       ";
	}
        cout<<ptr->el;
        display(ptr->left, level+1);
    }
}

template <class T>
void bst<T> ::deleteByMerging(BSTNode<T>*& node){
	BSTNode<T> *tmp = node;
	if(node != 0){
		if(node -> right == 0){
			node = node -> left;
		}
		else if(node -> left == 0){
			node = node -> right;
		}
		else{
			tmp = node -> left;
			while(tmp -> right != 0){
				tmp = tmp -> right;
			}
			tmp -> right = node -> right;
			tmp = node;
			node = node -> left;
		}
		delete tmp;
	}
}
template <class T>
void bst<T> ::findAndDeleteByMerging(const T& el)
{
	BSTNode<T> *node = root, *prev = NULL;
    while (node != NULL)
    {
    	if(node -> el == el){
    		break;
		}
		prev = node;
		if(el < node -> el){
			node = node -> left;
		}
		else{
			node = node -> right;
		}
	}
	if(node != NULL && node -> el == el){
		if(node == root){
			deleteByMerging(root);
		}
		else if(prev -> left == node){
			deleteByMerging(prev -> left);
		}
		else{
			deleteByMerging(prev -> right);
		}
	}
	else if(root != NULL){
		cout<<"Element "<<el<<" is not the tree.";
	}
	else{
		cout<<"The tree is empty.";
	}
}

template <class T>
void bst<T> ::deleteByCopying(BSTNode<T>*& node)
{
	BSTNode<T> *previous, *tmp = node;
    if (node -> right == NULL)
    {
    	node = node -> left;
    }
    else if(node -> left == NULL){
    	node = node -> right;
	}
	else{
		tmp = node -> left;
		previous = node;
		while(tmp -> right != NULL){
			previous = node;
			tmp = tmp -> right;
		}
		node -> el = tmp -> el;
		if(previous == node){
			previous -> left = tmp -> left;
		}
		else{
			previous -> right = tmp -> left;
		}
	}
	delete tmp;
}

template <class T>
int bst<T> :: count_leaf(BSTNode<T>* p){
	if(p == NULL){
		return 0;
	}
	else if(p -> left == NULL && p -> right == NULL){
		return 1;
	}
	else{
		return count_leaf(p -> left) + count_leaf(p -> right);
	}
}

template <class T>
int bst<T> :: count_nonleaf(BSTNode<T>* p){
	if(p == NULL){
		return 0;
	}
	else if(p -> left == NULL && p -> right == NULL){
		return 0;
	}
	else{
		return count_nonleaf(p -> left) + count_nonleaf(p -> right) + 1;
	}
}

template <class T>
int bst<T> :: Tree_height(BSTNode<T>* p){
	if(p == NULL){
		return 0;
	}
	else{
		return max(Tree_height(p->left),Tree_height(p->right))+1;
	}
}

template <class T>
void bst<T> :: mirror(BSTNode<T>* p){
	if(p == NULL){
		return ;
	}
	else{
		BSTNode<T>* tmp;
		mirror(p->left);
		mirror(p->right);
		tmp = p->left;;
		p->left = p->right;
		p->right = tmp;
	}
}

int main(){
	bst<int> obj;
	BSTNode<int>* temp1;
	BSTNode<int>* temp2;
	BSTNode<int>* temp3;
	BSTNode<int>* temp4;
	BSTNode<int>* temp5;
	BSTNode<int>* temp6;
	BSTNode<int>* root;
	temp1 = new BSTNode<int>;
	temp2 = new BSTNode<int>;
	temp3 = new BSTNode<int>;
	temp4 = new BSTNode<int>;
	temp5 = new BSTNode<int>;
	temp6 = new BSTNode<int>;
	root = new BSTNode<int>;
	root->el = 30;
	temp1->el = 18;
	temp2->el = 43;
	temp3->el = 10;
	temp4->el = 25;
	temp5->el = 48;
	temp6->el = 32;
	cout<<"Root node is : 30"<<endl;
    cout<<"Non-leaf node is : 18"<<endl;
	cout<<"Non-leaf node is : 43"<<endl;
	cout<<"Leaf node is : 10"<<endl;
	cout<<"Leaf node is : 25"<<endl;
	cout<<"Leaf node is : 48"<<endl;
	cout<<"Leaf node is : 32"<<endl;
	obj.insert(root,temp1);
	obj.insert(root,temp2);
	obj.insert(root,temp3);
	obj.insert(root,temp4);
	obj.insert(root,temp5);
	obj.insert(root,temp6);
	cout<<endl;
	cout<<"Binary Search Tree is : "<<endl;
	obj.display(root,1);
	cout<<endl;
	
	cout<<endl;
	
	cout<<"Recursive preorder tree is : ";
	obj.preorder(root);
	cout<<endl;
	cout<<"Recursive inorder tree is : ";
	obj.inorder(root);
	cout<<endl;
	cout<<"Recursive postorder tree is : ";
	obj.postorder(root);
	cout<<endl;
	
	cout<<endl;
	
	cout<<"Iterative preorder tree is : ";
	obj.iterativePreorder(root);
	cout<<endl;
	cout<<"Iterative inorder tree is : ";
	obj.iterativeInorder(root);
	cout<<endl;
	cout<<"Iterative postorder tree is : ";
	obj.iterativePostorder(root);
	cout<<endl;
	
	cout<<endl;
	
	cout<<"Breadth first traversal of BST is : ";
	obj.breadthFirst(root);
	cout<<endl;
	
	cout<<endl;
	
	cout<<"Mirror image of BST is : "<<endl;
	obj.mirror(root);
	obj.display(root,1);
	cout<<endl;
	
	cout<<endl;
	
	cout<<"Count of leaf nodes : "<<obj.count_leaf(root)<<endl;
	cout<<"Count of non-leaf nodes : "<<obj.count_nonleaf(root)<<endl;
	cout<<"Height of a BST is : "<<obj.Tree_height(root)<<endl;
	
	cout<<endl;
	
	cout<<"Delete by copying : ";
	obj.deleteByCopying(temp1);
	obj.display(root,1);
	cout<<endl;
	
	cout<<endl;
	
	bool res = obj.search(root,30);
	if(res == true)
	{
		cout<<"Element found.";
	}
	else
	{
		cout<<"Element not found.";
	}
	
	cout<<endl;
	
	obj.search(43);
	obj.display(root,1);
	cout<<endl;

	cout<<"On swapping " << root->el<<" with "<<temp1->el<<" : ";
	obj.swap(&root->el,&temp1->el);
	obj.display(root,1);
	cout<<endl;

	cout<<"On swapping " << root->el<<" with "<<temp2->el<<" : ";
	obj.swap(&root->el,&temp2->el);
	obj.display(root,1);
	cout<<endl;

	cout<<"On swapping " << root->el<<" with "<<temp3->el<<" : ";
	obj.swap(&root->el,&temp3->el);
	obj.display(root,1);
	cout<<endl;
	
	cout<<endl;


	return 0;
}
