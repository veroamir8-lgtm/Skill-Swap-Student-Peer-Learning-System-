// ================================================ Jana code (LogIn fn) =============================================================


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


long long IDValidation() {
    string temp_id;

    // id validation
    bool valid_id = false;
    while (!valid_id) {
        cout << "Enter student ID :";

        getline(cin, temp_id);
        valid_id = true;

        if (temp_id.empty()) { // check empty id
            cout << "Student ID are required.\nPlease try again.\n";
            valid_id = false;
            continue;  // if the user enter empty id skip all conditions
        }

        int spaces = temp_id.find(' '); // check spaces
        if (spaces != -1) {
            cout << "Spaces are not allowed.\nPlease remove any spaces and try again.\n";
            valid_id = false;
            continue;  //if the user enter spaces skip the rest of block of while loop to prevent repeated msgs
        }

        for (char c : temp_id) { // check if each character is a number
            if (!isdigit(c)) {
                cout << "Invalid input.\nID must contain exactly 11 numeric digits.\nPlease try again\n" << endl;
                valid_id = false;
                break;
            }
        }
        if (!valid_id)    //if the user enter chars instead of digits skip the rest of block of while loop to prevent repeated msgs
            continue;

        if (temp_id.length() != 11) { // check the id length
            cout << "Invalid input.\nID must contain exactly 11 numeric digits.\nPlease try again\n " << endl;
            valid_id = false;
            continue;
        }

        if (valid_id) { // if user enter a valid id
            break;
        }
    }  // End of Id Validation 

    return stoll(temp_id);
}


// ============================================================= Start of Function ==============================================================

void Login() {
    long long id = IDValidation();
    string pass;

    
    bool pass_valid = false;
    while (!pass_valid) {
        cout << "Enter Password: ";
        getline(cin, pass);
        pass_valid = true;
        if (pass.empty()) {
            pass_valid = false;
            cout << "Password Cannot Be Empty\n";
        }
    }

    // Search for student in array
    bool idFound = false;

    for (int i = 0; i < MaxUserIndex; i++) {  // check if id exists and if exists check the password if wrie or not
        if (stud[i].id == id) {
            idFound = true;

            if (stud[i].password == pass) {
                cout << "Login successful! Welcome " << stud[i].name << "\n";
            }
            else {
                cout << "Incorrect password.\n";

            }
        }
    }

    if (!idFound) {
        cout << "Account does not exist.\n";
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
    Login();
}
