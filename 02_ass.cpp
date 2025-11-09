#include <iostream>
using namespace std;
void inputEmployee(string name[], float salary[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Name: ";
        getline(cin, name[i]);
        cout << "salary: ";
        cin >> salary[i];
        cin.ignore();
    }
}
void displayEmployee(string name[], float salary[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << name[i] << " - " << salary[i] << endl;
    }
}

void BubbleSort(string name[], float salary[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (salary[j] > salary[j + 1])
            {
                float temp = salary[j];
                salary[j] = salary[j + 1];
                salary[j + 1] = temp;

                string temp1 = name[j];
                name[j] = name[j + 1];
                name[j + 1] = temp1;
            }
        }
    }
}
void SelectionSort(string name[], float salary[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int small = i;
        for (int j = i + 1; j < n; j++)
        {
            if (salary[j] < salary[small])
            {
                small = j;
            }
        }
        float temp = salary[i];
        salary[i] = salary[small];
        salary[small] = temp;

        string temp1 = name[i];
        name[i] = name[small];
        name[small] = temp1;
    }
}
void InsertionSort(string name[], float salary[], int n)
{
    for (int i = 1; i < n; i++)
    {
        float current = salary[i];
        string current1 = name[i];
        int previous = i - 1;
        while (previous >= 0 && current < salary[previous])
        {
            salary[previous + 1] = salary[previous];
            name[previous + 1] = name[previous];
            previous--;
        }
        salary[previous + 1] = current;
        name[previous + 1] = current1;
    }
}

int main()
{
    string name[100];
    float salary[100];
    int size, method;
    cout << "Enter the number employee : ";
    cin >> size;
    cin.ignore();
    inputEmployee(name, salary, size);
    displayEmployee(name, salary, size);
    cout << "method 1 - Bubble sort" << endl
         << "method 2 - Selection sort" << endl
         << "method 3 - Insertion sort" << endl
         << "method 4 - Quick sort" << endl;
    cout << "Enter The Method: ";
    cin >> method;
    cin.ignore();
    switch (method)
    {
    case 1:
        cout << "Bubble sort - " << endl;
        BubbleSort(name, salary, size);
        cout << "----------------------------------------" << endl;
        break;
    case 2:
        cout << "Selection sort - " << endl;
        SelectionSort(name, salary, size);
        cout << "----------------------------------------" << endl;
        break;
    case 3:
        cout << "Insertion sort - " << endl;
        InsertionSort(name, salary, size);
        cout << "----------------------------------------" << endl;
        break;
    // case 4:

    //     cout << "Quick sort - " << endl;
    //     int start = 0, end = size - 1;
    //     QuickSort(name, salary, start, end);
    //     cout << "----------------------------------------" << endl;
    //     break;
    }
    displayEmployee(name, salary, size);

    return 0;
}