// ================================================ Bavly code (LogIn fn) =============================================================

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
struct student {
    string name;
    string password;
    string major;
    long long id;
    string owned_skill;
    string wanted_skill;
    string email;
};
const int nstudents = 10;
student stud[nstudents];
int MaxUserIndex = 0;
void FillStruct() {
    string id, usernames, pass, email, major, OwnedSkill, WantedSkill;
    string myText;
    ifstream data_file("database.txt"); // check array index
    while (getline(data_file, myText)) {
        MaxUserIndex++;
    }

    data_file.clear();
    data_file.seekg(0, ios::beg);

    for (int i = 0; i < MaxUserIndex; i++) {
        getline(data_file, myText);
        stringstream string_splitter(myText);

        // read line until (/) appears 
        // store in variables
        getline(string_splitter, id, '|');
        getline(string_splitter, usernames, '|');
        getline(string_splitter, email, '|');
        getline(string_splitter, pass, '|');
        getline(string_splitter, major, '|');
        getline(string_splitter, OwnedSkill, '|');
        getline(string_splitter, WantedSkill, '|');

        // storing data from a file to struct
        stud[i].id = stoll(id);
        stud[i].name = usernames;
        stud[i].email = email;
        stud[i].password = pass;
        stud[i].major = major;
        stud[i].owned_skill = OwnedSkill;
        stud[i].wanted_skill = WantedSkill;

    }
    // close file
    data_file.close();

}


// ============================================================= Start of Function ==============================================================

void findsmartmatches() {
    bool found = false;
    for (int i = 0; i < MaxUserIndex; i++) {//student resevation

        for (int j = i + 1; j < MaxUserIndex; j++) {//the other students are compared to the student in loop1
            //to avoid comparing the student to himself // don't deny the same husband twice
            if ((stud[i].owned_skill == stud[j].wanted_skill) && (stud[j].owned_skill == stud[i].wanted_skill)) {
                cout << "match found:" << stud[i].name << "," << stud[j].name << endl;
                cout << "skill exchange:" << stud[i].owned_skill << " for " << stud[j].owned_skill << endl;
                found = true;
            }
        }
    }

    if (!found) {//found=false
        cout << "no perfect matches found at this time " << endl;


    }

}


// ============================================================= End of Function ==============================================================



// ============================================================= Call Function ==============================================================



int main() {
    ifstream CheckFile;
    CheckFile.open("database.txt");
    if (!CheckFile.is_open())  // Check File if Exists
    {
        ofstream MyFile("database.txt");   // If Not Make One And Put The Main Row
        MyFile.close();
    } CheckFile.close();

    FillStruct();
    findsmartmatches();
}
