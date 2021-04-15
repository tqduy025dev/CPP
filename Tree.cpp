#include <iostream>
using namespace std;

class node
{
	private:
    int data;
    node *left;
    node *right;
    public:
    	friend class BinaryTree;
};

class BinaryTree{
	public:
		node *create_node(int value);
		void *create_tree(node *root);
		bool empty_tree(node *t);
		node *insert_node(node *t, int x);
		void printTreeNLR(node *t);
		void printTreeLNR(node *t);
		void printTreeLRN(node *t);
		void printTreeRNL(node *t);

};
node *BinaryTree::create_node(int value)
{
    node *element = new node;
    element->data = value;
    element->left = NULL;
    element->right = NULL;
    return element;
}

bool BinaryTree::empty_tree(node *t)
{
    if (t == NULL)
        return true;
    return false;
}
node *BinaryTree::insert_node(node *t, int x)
{
    if (t == NULL)
    {
        node *temp = new node;
        temp->data = x;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }
    else
    {
        if (x < t->data)
        {
            t->left = insert_node(t->left, x);
        }
        else
        {
            t->right = insert_node(t->right, x);
        }
    }
}

void BinaryTree::printTreeNLR(node *t) 
{
    if (t != NULL)
    {
        cout << t->data << " ";
        this->printTreeNLR(t->left);
        this->printTreeNLR(t->right);
    }
}
void BinaryTree::printTreeLNR(node *t) 
{
    if (t != NULL)
    {
        this->printTreeLNR(t->left);
        cout << t->data << " ";
        this->printTreeLNR(t->right);
    }
}
void BinaryTree::printTreeLRN(node *t) 
{
    if (t != NULL)
    {
        printTreeLRN(t->left);
        printTreeLRN(t->right);
        cout << t->data << " ";
    }
}
void BinaryTree::printTreeRNL(node *t) 
{
    if (t != NULL)
    {
       
        this->printTreeLRN(t->right);
        cout << t->data << " ";
        this->printTreeLRN(t->left);
    }
}


int main()
{
	BinaryTree a;
	node *t = NULL;
    int n, x;
    cout << "Nhap so phan tu cua cay n= ";
    cin >> n;
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        t = a.insert_node(t, x);
    }
    
    cout << endl;
    a.printTreeLNR(t);

    system("pause");
    return 0;
}
