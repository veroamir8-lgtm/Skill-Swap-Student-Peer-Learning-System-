// ================================================ Kevin code (Rest Pass fn) =============================================================


#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>

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


// ============================================================= Start of First Function ==============================================================

void ResetPass() {
    string temp_new_password; 

    // Id validation
    long long id = IDValidation();

    // password validation
    bool valid_password = false;
    while (!valid_password) {
        valid_password = true;
        cout << "Enter student Password : ";
        getline(cin, temp_new_password);
        //  Check If New Pass Empty or Not
        if (temp_new_password.empty()) {
            cout << "New Password are required.\nPlease try again.\n";
            valid_password = false;
            continue;
        }

        if (temp_new_password.length() != 8) // check password length
        {
            cout << "Password must be 8 characters long, Please try again.\n ";
            valid_password = false;

        }
        if (valid_password) { // if user enter a valid password
            break;
        }
    } // end of password validation




    // Search for student in array
    bool idFound = false;

    for (int i = 0; i < MaxUserIndex; i++) {
        if (stud[i].id == id) {
            idFound = true;
            stud[i].password = temp_new_password;
            cout << "Your Passwored Changed Successfully.\n";
        }
    }

    if (!idFound) {  // If User Not Found
        cout << "Account does not exist.\n";
    }

    

    ofstream file("database.txt", ios::trunc);  // Open file and remove everything in it



    //  Write All Data Again
    for (int i = 0; i < MaxUserIndex; i++) {
        file << stud[i].id << "|" << stud[i].name << "|" << stud[i].email << "|" << stud[i].password << "|" << stud[i].major << "|" << stud[i].owned_skill << "|" << stud[i].wanted_skill << "\n";
    }

}

// ============================================================= End of First Function ==============================================================



// ============================================================= Start of Second Function ==============================================================

void SearchandFilter(string search_word) {
    transform(search_word.begin(), search_word.end(), search_word.begin(), ::tolower);  // convert the input to lower case
    bool isexist = false;
    for (int i = 0; i < MaxUserIndex; i++) {
    transform(stud[i].owned_skill.begin(), stud[i].owned_skill.end(), stud[i].owned_skill.begin(), ::tolower);  // convert the owned skill to lower case
        if (stud[i].owned_skill == search_word) {
            cout << stud[i].name << " Has " << search_word << " skill and his ID is: " << stud[i].id << endl;
            isexist = true;
        }
    }

    if (!isexist) {
        cout << "No Students Has This Skill." << endl;
    }
}

// ============================================================= End of Second Function ==============================================================



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
    SearchandFilter("english");
}
