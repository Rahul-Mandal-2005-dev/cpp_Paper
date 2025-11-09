#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int val) : data(val), next(NULL) {}
};

class SingleLinkedList
{
private:
    Node *head;

public:
    SingleLinkedList() : head(NULL) {}

    void insert(int val)
    {
        Node *newNode = new Node(val);
        if (!head)
            head = newNode;
        else
        {
            Node *temp = head;
            while (temp->next)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    void del(int target)
    {
        if (!head)
            return;
        if (head->data == target)
        {
            Node *delNode = head;
            cout << "delete: " << head->data << endl;
            head = head->next;
            delete delNode;
        }
        Node *temp = head;
        while (temp->next && temp->next->data != target)
        {
            temp = temp->next;
        }
        if (temp->next)
        {
            Node *delNode = temp->next;
            cout << "delete: " << delNode->data << endl;
            temp->next = temp->next->next;
            delete delNode;
        }
    }
    void search(int key)
    {
        Node *temp = head;
        int pos = 1;
        bool con = true;
        while (temp)
        {
            if (temp->data == key)
            {
                cout << "Found : " << key << " -> idx : " << pos << endl;
                con = false;
                break;
            }
            else
            {
                temp = temp->next;
                pos++;
            }
        }
        if (con)
        {
            cout << "Not Found : " << key << endl;
        }
    }
    void display()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << "--->";
            temp = temp->next;
        }
        cout << "None" << endl;
    }
    void sorting()
    {
        for (Node *i = head; i->next; i = i->next)
        {
            for (Node *j = head; j->next; j = j->next)
            {
                if (j->data > j->next->data)
                {
                    int temp = j->data;
                    j->data = j->next->data;
                    j->next->data = temp;
                }
            }
        }
    }
    void concatenate(SingleLinkedList &list2)
    {
        if (!head)
            head = list2.head;
        Node *temp = head;
        while (temp->next)
            temp = temp->next;

        temp->next = list2.head;
        list2.head = NULL;
    }
};
int main()
{
    int choose, val;
    SingleLinkedList list1, list2;
    do
    {
        cout << "Menu: " << endl
             << "1.Insert" << endl
             << "2.Delete" << endl
             << "3.Searching" << endl
             << "4.Display" << endl
             << "5.Sorting" << endl
             << "6.Concatenate" << endl
             << "7.Exit" << endl;

        cout << "Enter the choice: ";
        cin >> choose;

        switch (choose)
        {
        case 1:
            cout << "Enter the value: ";
            cin >> val;
            list1.insert(val);
            break;
        case 2:
            cout << "Enter the target: ";
            cin >> val;
            list1.del(val);
            break;
        case 3:
            cout << "Enter the key: ";
            cin >> val;
            list1.search(val);
            break;
        case 4:
            list1.display();
            break;
        case 5:
            list1.sorting();
            break;
        case 6:
            cout << "Enter -1 to stop " << endl;
            while (true)
            {
                cout << "Enter List2 val: ";
                cin >> val;
                if (val == -1)
                    break;
                list2.insert(val);
            }
            list1.concatenate(list2);
            break;
        case 7:
            cout << "Exit";
            break;
        }
    } while (choose != 7);

    return 0;
}