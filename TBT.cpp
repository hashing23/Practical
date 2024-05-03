#include<iostream>
using namespace std;

class Tnode 
{
public:
    int data;
    Tnode *left;
    Tnode *right;
    int lbit, rbit;
};

class TBT 
{
    Tnode *root, *head;
public:
    TBT() {
        root = NULL;
        head = NULL;
    }
    void createTBT();
    void inorder();
};

void TBT::inorder() 
{
    Tnode *temp;
    temp = root;

    if (root == NULL) 
	{
        cout << "\nTree is empty";
        return;
    }

    while (temp != head) 
	{
        while (temp->lbit == 1) 
		{
            temp = temp->left;
        }
        cout << " " << temp->data;
        while (temp->rbit == 0 || temp->right == head) 
		{
            temp = temp->right;
            if (temp == head) return;
            cout << " " << temp->data;
        }
        temp = temp->right;
    }
}

void TBT::createTBT() {
    int flag = 0;
    char ans;
    Tnode *new_node, *temp;

    head = new Tnode();
    head->data = -1;
    head->left = head;
    head->right = head;
    head->lbit = 0;
    head->rbit = 1;

    root = new Tnode();
    cout << "Enter Root Node: ";
    cin >> root->data;
    head->left = root;
    head->lbit = 1;
    root->left = head;
    root->right = head;
    root->lbit = 0;
    root->rbit = 0;

    do {
        new_node = new Tnode();
        cout << "\nEnter New Node: ";
        cin >> new_node->data;
        new_node->lbit = 0;
        new_node->rbit = 0;

        temp = root;
        flag = 0;
        while (flag == 0) 
		{
            if (new_node->data < temp->data) 
			{
                if (temp->lbit == 0) 
				{
                    new_node->left = temp->left;
                    temp->left = new_node;
                    temp->lbit = 1;
                    new_node->right = temp;
                    flag = 1;
                    cout<<"\nNode Inserted Successfully";
                }
                else 
				{
                    temp = temp->left;
                }
            }
            else if (new_node->data > temp->data) 
			{
                if (temp->rbit == 0) 
				{
                    new_node->right = temp->right;
                    temp->right = new_node;
                    temp->rbit = 1;
                    new_node->left = temp;
                    flag = 1;
                    cout<<"\nNode Inserted Successfully";
                }
                else 
				{
                    temp = temp->right;
                }
            }
            else 
			{
                cout << "\nData already exists in tree !!";
                break;
            }
        }
        cout << "\nDo you want to continue(Y/y): ";
        cin >> ans;
    } while (ans == 'Y' || ans == 'y');
}

int main() 
{
    TBT T;
    T.createTBT();
    cout<<"\nINORDER TRAVERSAL OF TBT: ";
    T.inorder();

    return 0;
}
