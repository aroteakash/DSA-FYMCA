// 09 Tree

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *right;
    Node *left;
};

Node *createNode(int data)
{
    Node *temp = new Node();
    temp->data = data;
    temp->right = temp->left = NULL;
    return temp;
}

class Tree_Traversal
{
public:
    void insertNode(Node *&root, int data)
    {
        if (root == NULL)
        {
            root = createNode(data);
        }
        else if (root->data > data)
        {
            insertNode(root->left, data);
        }
        else
        {
            insertNode(root->right, data);
        }
    }

    void inorder(Node *root)
    {
        if (root != NULL)
        {
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }

    void preorder(Node *root)
    {
        if (root != NULL)
        {
            cout << root->data << " ";
            preorder(root->left);
            preorder(root->right);
        }
    }

    void postorder(Node *root)
    {
        if (root != NULL)
        {
            postorder(root->left);
            postorder(root->right);
            cout << root->data << " ";
        }
    }
};
int main()
{
    Tree_Traversal obj;

    Node *root = NULL;
    int n, val;
    int ch;
    cout << "\n************Binary Search Tree*************\n";
    cout << "-------------------------------------------\n";
    while(1)
    {
        cout << "\n| 1. Insert Element(s) | 2.Inorder Traversal | 3.Preorder Traversal | 4.Postorder Traversal | 5.Exit.. |\n";

        cout << "\nEnter the Choice : ";
        cin >> ch;
        cout << endl;

        switch (ch)
        {
        case 1:
            cout << "How many elements will you insert: ";
            cin >> n;
            cout << "\nInsert " << n << " elements, hit enter after each:\n";
            for (int i = 0; i < n; i++)
            {
                cin >> val, obj.insertNode(root, val);
            }
            cout << "\nElement(s) inserted!" << endl;
            break;

        case 2:
            if (root == NULL)
            {
                cout << "\nNo elements found!\n";
            }
            else
            {
                cout << "Inorder Traversal : " << endl;
                obj.inorder(root);
                cout << endl;
            }
            break;

        case 3:
            if (root == NULL)
            {
                cout << "\nNo elements found!\n";
            }
            else
            {
                cout << "Preorder Traversal : " << endl;
                obj.preorder(root);
                cout << endl;
            }
            break;

        case 4:
            if (root == NULL)
            {
                cout << "\nNo elements found!\n";
            }
            else
            {
                cout << "Postorder Traversal : " << endl;
                obj.postorder(root);
                cout << endl;
            }
            break;

        case 5:
            return 0;
            break;

        default:
            cout << "\nInvalid Choice..!\n";
        }
    }
    
    return 0;
}

