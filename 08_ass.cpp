#include <iostream>
using namespace std;
#define size 10
class Emp
{
public:
    string name;
    int empId;
    float salary;
    bool isEmpty;
    Emp() : name(""), empId(-1), salary(0.0), isEmpty(true) {}
};
class HashMap
{
private:
    Emp HashTable[size];
    int HashFun(int key)
    {
        return key % size;
    }

public:
    void insert(Emp e)
    {
        int idx = HashFun(e.empId);
        while (!HashTable[idx].isEmpty)
        {
            idx = (idx + 1) % 10;
        }
        HashTable[idx] = e;
        HashTable[idx].isEmpty = false;
        cout << "Inserted" << endl;
    }
    void search(int empId)
    {
        int idx = HashFun(empId);
        int start = idx;
        while (!HashTable[idx].isEmpty)
        {
            if (HashTable[idx].empId == empId)
            {
                cout << "found";
                return;
            }
            idx = (idx + 1) % 10;
            if (start == idx)
                break;
        }
        cout << "Not found" << endl;
    }
    void remove(int empId)
    {
        int idx = HashFun(empId);
        int start = idx;
        while (!HashTable[idx].isEmpty)
        {
            if (HashTable[idx].empId == empId)
            {
                HashTable[idx].isEmpty = true;
                return;
            }
            idx = (idx + 1) % 10;
            if (start == idx)
                break;
        }
        cout << "Not found" << endl;
    }
    void display()
    {
        for(int i = 0 ; i < size ; i++)
        {   bool con = true;
            cout<<i<<":";
            if(!HashTable[i].isEmpty)
            {
                cout<<HashTable[i].empId<<"|"<<HashTable[i].name<<"|"<<HashTable[i].salary<<endl;
                con = false;
            }
            if(con)
            {
                cout<<"[Empty]"<<endl;
            }
        }

    }
};
int main()
{
    HashMap h1;
    Emp e;
    cout<<"empId: ";
    cin>>e.empId;
    cout<<"name: ";
    cin>>e.name;
    cout<<"salary: ";
    cin>>e.salary;
    h1.insert(e);
    h1.search(123);
    h1.search(12);
    h1.display();
    h1.remove(123);
    h1.display();
    return 0;
}