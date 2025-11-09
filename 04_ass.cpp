#include <iostream>
using namespace std;
class Node
{
public:
    string name;
    int priority;
    Node *next;
    Node(string val, int pri = 0) : name(val), next(NULL), priority(pri) {}
};
class NormalQueues
{
private:
    Node *head;
    Node *tail;

public:
    NormalQueues() : head(NULL), tail(NULL) {}

    void insert(string name)
    {
        Node *newNode = new Node(name);
        if (!head)
            head = tail = newNode;
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop()
    {
        Node *temp = head;
        cout << "pop: " << temp->name << endl;
        head = temp->next;
        delete temp;
    }
    void display()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->name << "--->";
            temp = temp->next;
        }
        cout << "None" << endl;
    }
};
class CircularQueues
{
private:
    Node *head;
    Node *tail;

public:
    CircularQueues() : head(NULL), tail(NULL) {}
    void insert(string name)
    {
        Node *newNode = new Node(name);
        if (!head)
            head = tail = newNode;
        else
        {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
    }
    void pop()
    {
        Node *temp = head;
        cout << "pop: " << temp->name << endl;
        head = temp->next;
        delete temp;
    }
    void display()
    {
        Node *temp = head;
        do
        {
            cout << temp->name << "--->";
            temp = temp->next;
        } while (temp != tail->next);
        cout << "None" << endl;
    }
};
class PriorityQueues
{
private:
    Node *head;

public:
    PriorityQueues() : head(NULL) {}
    void insert(string name, int pri)
    {
        Node *newNode = new Node(name, pri);
        if (!head || pri < head->priority)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next && pri >= temp->priority)
            {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
    void pop()
    {
        Node *temp = head;
        cout << "pop: " << temp->name << endl;
        head = temp->next;
        delete temp;
    }
    void display()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->name << "--->";
            temp = temp->next;
        }
        cout << "None" << endl;
    }
};

int main()
{
    cout << "Normal Queues: " << endl;
    NormalQueues n;
    n.insert("Rahul");
    n.insert("Ranjan");
    n.insert("Mandal");
    n.display();
    n.pop();
    n.display();

    cout << "Circular Queues: " << endl;
    CircularQueues c;
    c.insert("Rahul");
    c.insert("Ranjan");
    c.insert("Mandal");
    c.display();
    c.pop();
    c.display();

    cout << "Priority Queues: " << endl;
    PriorityQueues p;
    p.insert("Rahul", 2);
    p.insert("Ranjan", 3);
    p.insert("Mandal", 1);
    p.display();
    p.pop();
    p.display();

    return 0;
}