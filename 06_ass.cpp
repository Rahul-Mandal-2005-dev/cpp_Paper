#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

class BinarySearchTree
{
private:
    Node *root;

    Node *insert(Node *root, int val)
    {
        if (!root)
            return new Node(val);
        else if (val < root->data)
            root->left = insert(root->left, val);
        else if (val > root->data)
            root->right = insert(root->right, val);
        else
            cout << "NO Duplicate element" << endl;

        return root;
    }
    Node *InOrderMin(Node *root)
    {
        while (root && root->left)
        {
            root = root->left;
        }
        return root;
    }
    Node *del(Node *root, int target)
    {
        if (!root)
            return root;
        else if (target < root->data)
            root->left = del(root->left, target);
        else if (target > root->data)
            root->right = del(root->right, target);
        else
        {
            if (!root->left)
            {
                Node *temp = root->right;
                delete root;
                return temp;
            }
            if (!root->right)
            {
                Node *temp = root->left;
                delete root;
                return temp;
            }
            Node *temp = InOrderMin(root->right);
            root->data = temp->data;
            root->right = del(root->right, temp->data);
        }
        return root;
    }
    bool search(Node *root, int key)
    {
        if (!root)
            return false;
        if (root->data == key)
            return true;
        else if (key < root->data)
            search(root->left, key);
        else if (key > root->data)
            search(root->right, key);
    }
    void inOrder(Node *root)
    {
        if (!root)
            return;
        inOrder(root->left);
        cout << root->data << "--->";
        inOrder(root->right);
    }
    void preOrder(Node *root)
    {
        if (!root)
            return;
        cout << root->data << "--->";
        inOrder(root->left);
        inOrder(root->right);
    }
    void postOrder(Node *root)
    {
        if (!root)
            return;
        inOrder(root->left);
        inOrder(root->right);
        cout << root->data << "--->";
    }

public:
    BinarySearchTree() : root(NULL) {}
    void insert(int val)
    {
        root = insert(root, val);
    }
    void del(int target)
    {
        root = del(root, target);
    }
    void search(int key)
    {
        bool boolean = search(root, key);
        if (boolean)
            cout << key << "--->Found" << endl;
        else
            cout << key << "--->Not Found" << endl;
    }
    void inOrder()
    {
        inOrder(root);
        cout << "None" << endl;
    }
    void preOrder()
    {
        preOrder(root);
        cout << "None" << endl;
    }
    void postOrder()
    {
        postOrder(root);
        cout << "None" << endl;
    }

    void LevelOrder()
    {
        if (!root)
            return;
        Node *arr[100];
        int head = 0, tail = 0;
        arr[tail] = root;
        tail++;
        while (head < tail)
        {
            Node *cur = arr[head];
            head++;
            cout << cur->data<< "--->";
            if (cur->left)
                arr[tail++] = cur->left;
            if (cur->right)
                arr[tail++] = cur->right;
        }
        cout << "None" << endl;
    }
};
int main()
{
    BinarySearchTree b;
    b.insert(50);
    b.insert(90);
    b.insert(25);
    b.insert(60);
    b.insert(30);
    b.inOrder();
    b.preOrder();
    b.postOrder();
    b.LevelOrder();
    b.search(90);
    b.search(98);
    b.del(50);
    b.inOrder();

    return 0;
}