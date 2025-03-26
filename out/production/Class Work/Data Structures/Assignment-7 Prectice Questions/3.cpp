#include <iostream>

using namespace std;

struct Student {
    string name;
    int roll;
};
bool compare(Student& a, Student& b){
    return (a.name==b.name) && (a.roll==b.roll);
}
int main(int argc, char const *argv[]) {
    Student sudent1 = {"Ayush", 86};
    Student sudent2 = {"Ayush", 86};
    Student sudent3 = {"Sophia", 92};

    // copare if students are same
    bool areSame = compare(sudent1, sudent2);
    cout << "Are the students same? " << (areSame? "Yes" : "No") << endl;
    
    // compare if students are different
    areSame = compare(sudent1, sudent3);
    cout << "Are the students different? " << (areSame? "Yes" : "No") << endl;
    
    return 0;
}
