#include <iostream>
using namespace std;
#define size 100
string arr[100];
class Node
{
public:
    string url;
    Node *next;
    Node(string data) : url(data), next(NULL) {}
};
class StackWithLinkedList
{
    Node *top;

public:
    StackWithLinkedList() : top(NULL) {}

    void insert(string url)
    {
        Node *newNode = new Node(url);
        newNode->next = top;
        top = newNode;
    }
    void del()
    {
        if (!top)
            cout << "NO Element present" << endl;
        else
        {
            Node *temp = top;
            cout << "delete: " << temp->url << endl;
            top = temp->next;
            delete temp;
        }
    }
    void peek()
    {
        if (!top)
            cout << "NO Element present" << endl;
        else
        {
            cout << "Top: " << top->url << endl;
        }
    }

    void display()
    {
        Node *temp = top;
        while (temp)
        {
            cout << temp->url << "--->";
            temp = temp->next;
        }
        cout << "None" << endl;
    }
};
class StackWithArray
{
    int top = -1;

public:
    void insert(string url)
    {
        if (top == size)
            cout << "Stack is Full" << endl;
        else
            arr[++top] = url;
    }
    void del()
    {
        if (top == -1)
            cout << "NO Element present" << endl;
        else
        {
            cout << "Delete: " << arr[top];
            top--;
        }
    }
    void peek()
    {
        if (top == -1)
            cout << "NO Element present" << endl;
        else
            cout << "Top: " << arr[top] << endl;
    }

    void display()
    {
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << "--->";
        }
        cout << "None" << endl;
    }
};
int main()
{
    int choice, type;
    string url;
    StackWithArray A;
    StackWithLinkedList L;
    cout << "1.Stack with linked List" << endl
         << "2.Stack with Array" << endl;
    cout << "Enter Types: 1 or 2 :" << endl;
    cin >> type;

    do
    {
        cout << "Menu: " << endl
             << "1.Insert" << endl
             << "2.Delete" << endl
             << "3.Peek" << endl
             << "4.Display" << endl
             << "5.Exit" << endl;
        cout << "Enter the Choice: ";
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case 1:
            cout << "Enter url: ";
            getline(cin, url);

            if (type == 1)
                L.insert(url);

            else if (type == 2)
                A.insert(url);

            break;
        case 2:
            if (type == 1)
                L.del();
            else if (type == 2)
                A.del();

            break;
        case 3:
            if (type == 1)
                L.peek();
            else if (type == 2)
                A.peek();
            break;
        case 4:
            if (type == 1)
                L.display();
            else if (type == 2)
                A.display();
            break;
        case 5:
            cout << "Exit" << endl;
            break;
        }
    } while (choice != 5);

    return 0;
}