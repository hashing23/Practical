#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
};

class bst
{
public:
    node *root;
    int count;
    bst()
    {
        count = 0;
        root = NULL;
    }
    void insert();
    int search(int key);
    void inorder(node *root);
    void smallest();
    void largest();
    void mirror(node *root);
    int height(node *root);
};
void bst::insert()
{
    int flag = 0;
    node *new_node, *temp;
    new_node = new node(); // memory allocation
    new_node->left = NULL;
    new_node->right = NULL;
    
    cout << "Enter the data: ";
    cin >> new_node->data;
    if (root == NULL)
    {
        root = new_node;
    }
    else
    {
        temp = root;
        while (flag == 0)
        {
            if (new_node->data < temp->data)
            {
                if (temp->left == NULL)
                {
                    temp->left = new_node;
                    flag = 1;
                }
                else
                {
                    temp = temp->left;
                }
            }
            else if (new_node->data > temp->data)
            {
                if (temp->right == NULL)
                {
                    temp->right = new_node;
                    flag = 1;
                }
                else
                {
                    temp = temp->right;
                }
            }
            else
            {
                cout << "\nData already exists !!";
            }
        }
    }
}

int bst::search(int key)
{
    node *temp;
    temp = root;
    while (1)
    {
        if (key < temp->data)
        {
            if (temp->left != NULL)
            {
                temp = temp->left;
            }
            else
            {
                return 0;
            }
        }
        else if (key > temp->data)
        {
            if (temp->right != NULL)
            {
                temp = temp->right;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 1;
        }
    }
}

void bst::inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void bst::smallest()
{
    node *temp;
    temp = root;
    while (temp->left!=NULL)
    {
        temp = temp->left;
                
    }
    cout<<temp->data<<"\n";  	
}

void bst::largest()
{
    node *temp;
    temp = root;
    while (temp->right!=NULL)
    {
        temp = temp->right;
                
    }
    cout<<temp->data<<"\n";        	
}

void bst::mirror(node* root)
{
	node *temp;
	if(root!=NULL)
	{
		temp=root->left;
		root->left=root->right;
		root->right=temp;
		mirror(root->left);
		mirror(root->right);
	}	
}

int bst::height(node *root)
{
	int left_Height,right_Height;
	if(root==NULL)
	{
		return 0;
	}
	if(root->left==NULL && root->right==NULL)
	{
		return 0;
	}
	left_Height=height(root->left);
	right_Height=height(root->right);
	if(left_Height > right_Height)
	{
		return(left_Height+1);
	}
	else
	{
		return(right_Height+1);	
	}
}

int main()
{
    int choice, key, pos,val;
    bst b;
    do
    {
        cout << "\n1.Insert Node in BST\n";
        cout << "2.Search Node in BST \n";
        cout << "3.Display BST \n";
        cout << "4.Smallest Node Value\n";
        cout << "5.Largest Node Value\n";
        cout << "6.Mirror of BST\n";
        cout << "7.Height of BST\n";
        cout << "8.Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            b.insert();
            break;
        case 2:
            cout << "\nEnter the node to be searched: ";
            cin >> key;
            if (pos = b.search(key))
            {
                cout << "\nNode found !!";
            }
            else
            {
                cout << "\nNode not found !!";
            }
            break;
        case 3:
            b.inorder(b.root);
            cout<<"\n";
            break;
        case 4:
            b.smallest();
            break;
         case 5:
            b.largest();
            break;
        case 6:
            b.mirror(b.root);
            b.inorder(b.root);
            break;
        case 7:
            val=b.height(b.root);
            cout<<val;
            break;
        case 8:
            cout << "Exit";
            break;
        default:
            cout << "Wrong choice entered!";
            break;
        }
    } while (choice != 8);
}
