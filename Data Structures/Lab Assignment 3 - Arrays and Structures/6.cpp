#include <bits/stdc++.h>
using namespace std;

struct student {
    string fname;
    string lname;
    float grade;
};

struct employee {
    string fname;
    string lname;
    float salary;
};

int main() {
    int n;
    cout << "enter number of records:";
    cin >> n;

    struct student s[n];
    struct employee e[n];

    cout << "enter student details:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "enter firstname:";
        cin >> s[i].fname;
        cout << "enter lastname:";
        cin >> s[i].lname;
        cout << "enter grade:";
        cin >> s[i].grade;
    }
    cout << "enter employee details:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "enter firstname:";
        cin >> e[i].fname;
        cout << "enter lastname:";
        cin >> e[i].lname;
        cout << "enter salary:";
        cin >> e[i].salary;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (s[i].fname == e[j].fname && s[i].lname == e[j].lname && s[i].grade > 3.0) {
                e[j].salary *= 1.1;
            }
        }
    }
    cout << "updated salary of each employee is given below:" << endl;
    for (int i = 0; i < n; i++) {
        cout << e[i].fname << " " << e[i].lname << " has a salary of: " << e[i].salary << endl;
    }
}
