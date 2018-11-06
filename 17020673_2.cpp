#include <iostream>
using namespace std;

struct Node{
	Node *left;
	Node *right;
	int data;
};

typedef Node *Tree;

void Init(Tree &t){
	t=NULL;
}

Node *creatNode(int x){
	Node *p=new Node;
	if(p==NULL) exit(1);
	p->data=x;
	p->left=NULL;
	p->right=NULL;
	return p;
}

int insert(Tree &t, Tree p){
	if(t==NULL){
		t = new Node;
		if(t==NULL) return 0;
		t = p;
		return 1;
	}
	else{
		if(p->data == t->data) return -1;
		else if(p->data < t->data) return insert(t->left, p );
			else return insert(t->right, p );
	}
}

void Input(Tree &t){
	cout << "Enter the tree: (Enter 0 to Exit)" << endl;
	while(1){
		int x;
		cin >> x;
		if(x){
			Node *p=creatNode(x);
			insert(t, p);
		}
		else break;
	}
}
int dem=0;
int soLa(Tree t){
	if(t){
		if(t->left==NULL && t->right==NULL) dem++;
		soLa(t->left);
		soLa(t->right);
	}
	return dem;
}
int heigh=0;
int high(Tree t){
	if(t){
		if(t->left!=NULL || t->right!=NULL) heigh++;
		high(t->left);
		high(t->right);
	}
	return heigh;
}

void NLR(Tree t){
	if(t){
		cout << t->data << " ";
		NLR(t->left);
		NLR(t->right);
	}
}

void LNR(Tree t){
	if(t){
		LNR(t->left);
		cout << t->data << " ";
		LNR(t->right);
	}
}

void RNL(Tree t){
	if(t){
		RNL(t->right);
		cout << t->data << " ";
		RNL(t->left);
	}
}

void xoaLa(Tree &t){
	if(t){
		if(t->left==NULL && t->right==NULL) t=NULL;
		else{
			xoaLa(t->left);
			xoaLa(t->right);
		}
	}
}

void Search(Tree t, int x){
	if(t){
		if(t->data==x){
			if(t->left) cout << "The left position's value: " << t->left->data << endl;
			else cout << "Not have the left position's value!'" << endl;
			if(t->right) cout << "The right position's value: " << t->right->data << endl;
			else cout << "Not have the right position's value!'" << endl;
		}
		Search(t->right,x);
		Search(t->left,x);
	}
}

int main (){
	Tree t;
	Init(t);
	Input(t);
	cout << "The tree which "<< endl;
	cout << "is sorted by NLR: "; NLR(t);
	cout << endl;
	cout << "is sorted by LNR: "; LNR(t);
	cout << endl;
	cout << "is sorted by RNL: "; RNL(t);
	int x;
	cout << "\nEnter a value to search: ";
	cin >> x;
	cout << "This value : " << x << endl;
	Search(t,x);
	return 0;
}
