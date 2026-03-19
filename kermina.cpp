// ================================================ Kermina code (SignUp fn) =============================================================


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

bool isIDExist(long long temp_id) {
    for (int i = 0; i <= MaxUserIndex; i++) {
        if (temp_id == stud[i].id) {
            return true;
        }
    }
    return false;
}

// ============================================================= Start of Function ==============================================================

void sign_up() {

    // check the maximum array size
    if (MaxUserIndex >= nstudents) {
        cout << "Maximum capacity reached. No further registrations allowed.\n" << endl;
    }
    else {
        // name validation
        bool valid_name = false;
        while (!valid_name) {
            valid_name = true;
            cout << "Enter student Name :";
            getline(cin, stud[MaxUserIndex].name);

            // check empty name
            if (stud[MaxUserIndex].name.empty()) {
                cout << "Student Name are required.\nPlease try again.\n";
                valid_name = false;
            }
        } // end of name validation

        // id validation
        long long id;
        bool valid_id = false;

        while (!valid_id) {
            id = IDValidation();  // format Check

            if (isIDExist(id)) {
                cout << "This ID is already registered,\nPlease try again.\n";
            }
            else {
                valid_id = true;
                stud[MaxUserIndex].id = id;
            }
        }  //  End of Id Validation

        // email validation
        bool valid_email = false;
        while (!valid_email) {
            valid_email = true;
            string temp_email;
            cout << "Enter student email: ";
            getline(cin, temp_email);

            if (temp_email.empty()) { // check empty email
                cout << "Student Email are required.\nPlease try again.\n";
                valid_email = false;
                continue;  // if user enter empty email skip all conditions 
            }

            // check email format
            int gmail = temp_email.find("@gmail.com");
            int yahoo = temp_email.find("@yahoo.com");
            int spacePos = temp_email.find(' ');

            if ((gmail == -1 && yahoo == -1) || spacePos != -1) {
                cout << "Invalid email, Please try again\n";
                valid_email = false;
            }

            if (valid_email) { // if user enter a valid email
                stud[MaxUserIndex].email = temp_email;
                break;
            }
        }   // end of email validation


        // password validation
        string temp_password;
        bool valid_password = false;
        while (!valid_password) {
            valid_password = true;
            cout << "Enter student Password : ";
            getline(cin, temp_password);

            if (temp_password.empty()) { // check empty password
                cout << "Student password are required.\nPlease try again.\n";
                valid_password = false;
                continue;  // if user enter empty password skip all conditions 
            }

            if (temp_password.length() != 8) // check password length
            {
                cout << "Password must be 8 characters long,\nPlease try again.\n ";
                valid_password = false;

            }
            if (valid_password) { // if user enter a valid password
                stud[MaxUserIndex].password = temp_password;
                break;
            }
        } // end of password validation

        // major validation
        bool valid_major = false;
        while (!valid_major) {
            valid_major = true;
            cout << "Enter student major : ";
            getline(cin, stud[MaxUserIndex].major);

            if (stud[MaxUserIndex].major.empty()) { // check empty major
                cout << "Student Major are required.\nPlease try again.\n";
                valid_major = false;
            }
        } // end of major validation


        // skills validation
        string owned_skill_temp, wanted_skill_temp;
        bool valid_skills = false;
        while (!valid_skills) {

            valid_skills = true;

            cout << "Enter Owned skill : ";
            getline(cin, owned_skill_temp);
            cout << "Enter Wanted skill : ";
            getline(cin, wanted_skill_temp);

            // chech empty skills 
            if (wanted_skill_temp.empty() || owned_skill_temp.empty()) {
                cout << "Student Skills are required.\nPlease try again.\n";
                valid_skills = false;
                continue;  // if user enter empty skills skip all conditions 
            }

            if (owned_skill_temp == wanted_skill_temp) {
                cout << "Skills can't be the same, Please enter different skills \n";
                valid_skills = false;
            }
            // if user enter a valid skills 
            if (valid_skills) {
                stud[MaxUserIndex].owned_skill = owned_skill_temp;
                stud[MaxUserIndex].wanted_skill = wanted_skill_temp;
                break;

            }
        } // end of skills validation

        // storing data from struct to the file
        ofstream write_student_data("database.txt", ios::app);
        write_student_data << stud[MaxUserIndex].id <<
            "|" << stud[MaxUserIndex].name <<
            "|" << stud[MaxUserIndex].email <<
            "|" << stud[MaxUserIndex].password <<
            "|" << stud[MaxUserIndex].major <<
            "|" << stud[MaxUserIndex].owned_skill <<
            "|" << stud[MaxUserIndex].wanted_skill << endl;

        // close file
        write_student_data.close();
        MaxUserIndex++; // increment the index
        cout << "Registration completed successfully.\n Welcome aboard!\n";

    }
}


 // ============================================================= End of Function ==============================================================




 // ============================================================= Function Calling ==============================================================

int main() {
    ifstream CheckFile;
    CheckFile.open("database.txt");
    if (!CheckFile.is_open())  // Check File if Exists
    {
        ofstream MyFile("database.txt");   // If Not Make One And Put The Main Row
        MyFile.close();
    } CheckFile.close();

    FillStruct();
    sign_up();

}
