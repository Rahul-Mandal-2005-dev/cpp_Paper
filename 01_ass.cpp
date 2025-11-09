#include <iostream>
using namespace std;
int main()
{
    string BookName[100];
    int BookCode[100];
    int bookSize, method;
    string target1;
    int target2;
    cout << "How much Book to store: ";
    cin >> bookSize;
    cin.ignore();

    for (int i = 0; i < bookSize; i++)
    {
        cout << i + 1 << ".Book Name: ";
        getline(cin, BookName[i]);
        cout << i + 1 << ".Book Code: ";
        cin >> BookCode[i];
        cin.ignore();
    }

    cout << endl
         << "Books List: " << endl;
    for (int i = 0; i < bookSize; i++)
    {
        cout << i + 1 << "." << BookName[i] << "(" << BookCode[i] << ")" << endl;
    }
    cout << "Menu" << endl
         << "1.Linear Search" << endl
         << "2.Binary Search" << endl;
    cout << "Enter Method : ";
    cin >> method;

    if (method == 1)
    {
        cout << "Enter book name: ";
        cin >> target1;
        for (int i = 0; i < bookSize; i++)
        {
            if (target1 == BookName[i])
                cout << "Found: " << BookName[i] << "(" << BookCode[i] << ") --> " << i; 
        }
    }
    int mid, left = 0, right = bookSize - 1;
    if (method == 2)
    {
        cout << "Enter book code: ";
        cin >> target2;
        for (int i = 0; i < bookSize; i++)
        {
            mid = int((left + right) / 2);
            if (target2 == BookCode[i])
            {
                cout << "Found: " << BookName[i] << "(" << BookCode[i] << ") --> " << i;
                break;
            }
            else if (BookCode[mid] < target2)
                left = mid + 1;
            else
                right = mid - 1;
        }
    }

    return 0;
}