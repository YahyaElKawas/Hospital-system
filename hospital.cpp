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
    if (first.status > second.status) return true;
    else return false;
}

void add_new_patient()
{
    cout << "Enter specialization, name, status: " << endl;
    int spec;
    cin >> spec;

    patients[spec][queue[spec]].spec = spec;
    cin >> patients[spec][queue[spec]].name;
    cin >> patients[spec][queue[spec]].status;

    queue[spec]++;

    sort(patients[spec] + 0, patients[spec] + 4, dying_first);
}

void print_all_patients()
{
    for (int i = 1; i < 21; i++)
    {
        if (patients[i][0].spec != -1)
        {
            cout << "There are " << queue[i] << " patients in specialaization " << i << endl;

            for (int y = 0; y < queue[i]; y++)
            {
                cout << patients[i][y].name << " " << patients[i][y].status << endl;
            }
        }
    }
}


void req_patient()
{
    cout << "Enter specialaization: ";
    int spec;
    cin >> spec;

    if (queue[spec] == 0) cout << "No patients found at the moment. Have rest, Dr" << endl;
    else
    {
        cout << patients[spec][0].name << " Please go with the Dr" << endl;

        for (int i = 0; i < queue[spec] - 1; i++)
        {
            patients[spec][i] = patients[spec][i + 1];
        }

        queue[spec]--;
    }
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
