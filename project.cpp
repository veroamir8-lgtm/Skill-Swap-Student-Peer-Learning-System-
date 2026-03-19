#include <iostream>
#include <fstream>
#include <string>
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
    int MaxUserIndex=0;



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


    void CheckStudentFile() {
        ifstream CheckFile;
        CheckFile.open("database.txt");
        if (!CheckFile.is_open()) {  // Check File if Exists
            ofstream MyFile("database.txt");   // If Not Exists Make One and Put The Main Row
            MyFile.close();
        } CheckFile.close();
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

    bool isIDExist(long long temp_id) {  // Used in kermina function

        for (int i = 0; i <= MaxUserIndex; i++) {
            if (temp_id == stud[i].id) {
                return true;
            }
        }
        return false;
    }

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

    void DisplayUsers() {
        for (int i = 0; i < MaxUserIndex; i++) {
            cout << "============ Student " << i+1 << " =================\n\n";
            cout << "Student Name is: " << stud[i].name << endl;
            cout << "Student ID is: " << stud[i].id << endl;
            cout << "Student Email is: " << stud[i].email << endl;
            cout << "Student Pass is: " << stud[i].password << endl;
            cout << "Student Major is: " << stud[i].major << endl;
            cout << "Student Owned Skill is: " << stud[i].owned_skill << endl;
            cout << "Student Wanted Skill is: " << stud[i].wanted_skill << endl << endl;
        }
    }

int main() {
    CheckStudentFile();
    FillStruct();

    cout << "===========================================\n\tWelcome to Skill Swap System\n===========================================\nA Peer-Learning Platform where students\nteach each other and grow together!\n\n* Share your skills\n* Learn new ones\n* Connect with other students\nLet's get started!\n===========================================\n\n";
    
    int choice=0;
    while (choice!=5) {
        cout << "=========== Authentication Menu ===========\n1. Login\n2. Sign Up (Create New Account)\n3. Reset Password\n4. Show All Users In System\n5. Exit\n===========================================\n\nPlease choose an option (1-5): ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1:
                cout << "\n----------- Login -----------\n\n";
                Login();
                break;
            case 2:
                cout << "\n----------- Registration -----------\n\n";
                sign_up();
                break;
            case 3:
                cout << "\n----------- Reset Password -----------\n\n";
                ResetPass();
                break;
            case 4:
                cout << endl;
                DisplayUsers();
                break;
            case 5:
                cout << "Thanks For Using Our System :)";
                break;
            default:
                cout << "Enter a Valid Option From (1-5): ";
        } 
    }
}