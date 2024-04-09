#include <iostream>
#include <algorithm>
using namespace std;

struct patient
{
    int spec = -1;
    string name;
    string status;
};

patient patients[21][5];
int queue[21] = { 0 };

bool dying_first(patient first, patient second)
{
}

void add_new_patient()
{   
}

void print_all_patients()
{
}

void req_patient()
{ 
}

int main()
{
    while (true)
    {
        cout << "Enter your choice: " << endl;
        cout << "1) Add new patient" << endl;
        cout << "2) Print all patients" << endl;
        cout << "3) Get next patient" << endl;
        cout << "4) Exit" << endl;

        int choice;
        cin >> choice;

        if (choice == 1)
        {
            add_new_patient();
        }

        else if (choice == 2)
        {
            print_all_patients();
        }

        else if (choice == 3)
        {
            req_patient();
        }

        else if (choice == 4) break;
    }

    return 0;
}
