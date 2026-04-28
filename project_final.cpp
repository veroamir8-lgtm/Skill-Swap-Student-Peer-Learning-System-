#include <iostream>

#include <fstream>

#include <string>

#include <sstream>

#include <windows.h>

using namespace std;

int UserIndex=-1;




struct SkillCategory {
    int CategoryId;
    string CategoryName;
};
const int ncategories = 5;  //Done
SkillCategory scateg[ncategories];
int MaxCategIndex = 0;


struct Skill {
    SkillCategory Category; // cateid, categname
    string SkillName;
};
const int nskills = 10;  //Done
Skill skill[nskills];
int MaxSkillIndex = 0;


struct LearningSession {
    int sessionID;
    long long mentorID;
    long long learnerID;
    Skill skill;
    string status;
};
const int nsessions = 10;  //Done
LearningSession session[nsessions];
int MaxSessionIndex = 0;

struct SessionRequest {
    int requestId;
    long long mentorId;
    long long learnerId;
    Skill skill;
    string status;
};
const int nrequests = 20;
SessionRequest request[nrequests];
int MaxRequestIndex = 0;

struct student {
    long long id;
    string name;
    string email;
    string password;
    string major;
    Skill owned_skill;
    string DifficultyLevel;
    Skill wanted_skill;
    string availability;
    string role;
};
const int nstudents = 10;  //Done
student stud[nstudents];
int MaxUserIndex = 0;

// Done
void FillSessionStruct()
{
    string sessionID, mentorID, learnerID, categoryId, categoryName, skillName, status;
    string myText;
    ifstream data_file("Sessions.txt"); // check array index
    while (getline(data_file, myText)) {
        MaxSessionIndex++;
    }

    data_file.clear();
    data_file.seekg(0, ios::beg);

    for (int i = 0; i < MaxSessionIndex; i++) {
        getline(data_file, myText);
        stringstream string_splitter(myText);

        // read line until (/) appears 
        // store in variables
        getline(string_splitter, sessionID, '|');
        getline(string_splitter, mentorID, '|');
        getline(string_splitter, learnerID, '|');
        getline(string_splitter, categoryId, '|');
        getline(string_splitter, categoryName, '|');
        getline(string_splitter, skillName, '|');
        getline(string_splitter, status, '|');


        // storing data from a file to struct
        session[i].sessionID = stoi(sessionID);
        session[i].mentorID = stoll(mentorID);
        session[i].learnerID = stoll(learnerID);
        session[i].skill.Category.CategoryId = stoi(categoryId);
        session[i].skill.Category.CategoryName = categoryName;
        session[i].skill.SkillName = skillName;
        session[i].status = status;

    }
    // close file
    data_file.close();

}

// Done
void FillStudenStruct() {
    string id, usernames, email, pass, major, OsCategid, OsCategname, OwnedSkill, OsDiffLevel, WsCategId, WsCategName, WantedSkill, WsDiffLevel, availability, role;
    string myText;
    ifstream data_file("Users.txt"); // check array index
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
        getline(string_splitter, OsCategid, '|');
        getline(string_splitter, OsCategname, '|');
        getline(string_splitter, OwnedSkill, '|');
        getline(string_splitter, OsDiffLevel, '|');
        getline(string_splitter, WsCategId, '|');
        getline(string_splitter, WsCategName, '|');
        getline(string_splitter, WantedSkill, '|');
        getline(string_splitter, availability, '|');
        getline(string_splitter, role, '|');


        // storing data from a file to struct
        stud[i].id = stoll(id); // long long type
        stud[i].name = usernames;
        stud[i].email = email;
        stud[i].password = pass;
        stud[i].major = major;
        stud[i].owned_skill.Category.CategoryId = stoi(OsCategid);  // int type
        stud[i].owned_skill.Category.CategoryName = OsCategname;
        stud[i].owned_skill.SkillName = OwnedSkill;
        stud[i].DifficultyLevel = OsDiffLevel;
        stud[i].wanted_skill.Category.CategoryId = stoi(WsCategId);
        stud[i].wanted_skill.Category.CategoryName = WsCategName;
        stud[i].wanted_skill.SkillName = WantedSkill;
        stud[i].availability = availability;
        stud[i].role = role;


    }
    // close file
    data_file.close();

}

// Done
void FillSkillCategStruct()
{
    string categid, categname;
    string myText;
    ifstream data_file("SkillCategory.txt"); // check array index
    while (getline(data_file, myText)) {
        MaxCategIndex++;
    }

    data_file.clear();
    data_file.seekg(0, ios::beg);

    for (int i = 0; i < MaxCategIndex; i++) {
        getline(data_file, myText);
        stringstream string_splitter(myText);

        // read line until (/) appears 
        // store in variables
        getline(string_splitter, categid, '|');
        getline(string_splitter, categname, '|');


        // storing data from a file to struct
        scateg[i].CategoryId = stoi(categid);
        scateg[i].CategoryName = categname;

    }
    // close file
    data_file.close();
}

// Done
void FillSkillStruct()
{
    string sname, categid, categname;
    string myText;
    ifstream data_file("Skills.txt"); // check array index
    while (getline(data_file, myText)) {
        MaxSkillIndex++;
    }

    data_file.clear();
    data_file.seekg(0, ios::beg);

    for (int i = 0; i < MaxSkillIndex; i++) {
        getline(data_file, myText);
        stringstream string_splitter(myText);

        // read line until (/) appears 
        // store in variables
        getline(string_splitter, categid, '|');
        getline(string_splitter, categname, '|');
        getline(string_splitter, sname, '|');



        // storing data from a file to struct
        skill[i].SkillName = sname;
        skill[i].Category.CategoryId = stoi(categid);
        skill[i].Category.CategoryName = categname;

    }
    // close file
    data_file.close();

}

// Done
void FillRequestStruct()
{
    string reqid, mentorid, learnerid, categid, categname, skillname, status;
    string myText;
    ifstream data_file("Requests.txt"); // check array index
    while (getline(data_file, myText)) {
        MaxRequestIndex++;
    }
    data_file.clear();
    data_file.seekg(0, ios::beg);

    for (int i = 0; i < MaxRequestIndex; i++) {
        getline(data_file, myText);
        stringstream string_splitter(myText);

        // read line until (/) appears 
        // store in variables
        getline(string_splitter, reqid, '|');
        getline(string_splitter, mentorid, '|');
        getline(string_splitter, learnerid, '|');
        getline(string_splitter, categid, '|');
        getline(string_splitter, categname, '|');
        getline(string_splitter, skillname, '|');
        getline(string_splitter, status, '|');





        // storing data from a file to struct
        request[i].requestId = stoi(reqid);
        request[i].mentorId = stoll(mentorid);
        request[i].learnerId = stoll(learnerid);
        request[i].skill.Category.CategoryId = stoi(categid);
        request[i].skill.Category.CategoryName = categname;
        request[i].skill.SkillName = skillname;
        request[i].status = status;
    }
    // close file
    data_file.close();

}

// Done
void CheckStudentFile() {
    ifstream CheckFile;
    CheckFile.open("Users.txt");
    if (!CheckFile.is_open()) {  // Check File if Exists
        ofstream MyFile("Users.txt");   // If Not Exists Make One and Put The Main Row
        MyFile.close();
    } CheckFile.close();
}

// Done
void CheckSessionFile() {
    ifstream CheckFile;
    CheckFile.open("Sessions.txt");
    if (!CheckFile.is_open()) {  // Check File if Exists
        ofstream MyFile("Sessions.txt");   // If Not Exists Make One and Put The Main Row
        MyFile.close();
    } CheckFile.close();
}

// Done
void CheckSkillCategFile() {
    ifstream CheckFile;
    CheckFile.open("SkillCategory.txt");
    if (!CheckFile.is_open()) {  // Check File if Exists
        ofstream MyFile("SkillCategory.txt");   // If Not Exists Make One and Put The Main Row
        MyFile.close();
    } CheckFile.close();
}

// Done
void CheckSkillFile() {
    ifstream CheckFile;
    CheckFile.open("Skills.txt");
    if (!CheckFile.is_open()) {  // Check File if Exists
        ofstream MyFile("Skills.txt");   // If Not Exists Make One and Put The Main Row
        MyFile.close();
    } CheckFile.close();
}

// Done
void CheckRequestsFile() {
    ifstream CheckFile;
    CheckFile.open("Requests.txt");
    if (!CheckFile.is_open()) {  // Check File if Exists
        ofstream MyFile("Requests.txt");   // If Not Exists Make One and Put The Main Row
        MyFile.close();
    } CheckFile.close();
}

// Done
long long IDValidation() {  // Used in kermina, jana, kevin functions
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

// Done
bool isIDExist(long long temp_id) {  // Used in kermina function

    for (int i = 0; i <= MaxUserIndex; i++) {
        if (temp_id == stud[i].id) {
            return true;
        }
    }
    return false;
}

// Done
Skill GetOrCreateSkill(string skillName, string category)
{

for (int i = 0; i < MaxSkillIndex; i++) {
    if (skillName == skill[i].SkillName && category == skill[i].Category.CategoryName) {      
        return skill[i];   // if skill exist -> copy it to student
    }
}

// check the maximum array size
if (MaxSkillIndex >= nskills) {
    cout << "Maximum capacity reached. No further Skills allowed.\n" << endl;
    return Skill();
}

else {

    // if Skill does NOT exist → create new one
    Skill newSkill;

        // find category id
        int category_id = -1;
        for (int i = 0; i < MaxCategIndex; i++) {
            if (category == scateg[i].CategoryName) {
                category_id = scateg[i].CategoryId;
                break;
            }
        }

        // fill the skill struct
        newSkill.Category.CategoryId = category_id;
        newSkill.Category.CategoryName = category;
        newSkill.SkillName = skillName;

        // assign to student
        skill[MaxSkillIndex] = newSkill;
        MaxSkillIndex++;


        // write to file
        ofstream write_skill("Skills.txt", ios::app);
        write_skill << newSkill.Category.CategoryId << "|"
            << newSkill.Category.CategoryName << "|"
            << newSkill.SkillName << endl;

        write_skill.close();

        return newSkill;
    }
}

// Done (this function removed in gui)
string toLowerCase(string text)
{
    for (char& c : text)
        c = tolower(c);

    return text;
}

// Done
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
                UserIndex = i;
            }
            else {
                cout << "Incorrect password.\n";

            }
        }
    }

    if (!idFound) {
        cout << "Account does not exist. To Sign up press 2\n";
    }
}

// Done
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

        // Skills validation
        string wanted_skill_category, wanted_skill_temp;
        string owned_skill_category, owned_skill_temp, owned_difficulty_level;
        bool valid_skills = false;
        while (!valid_skills) {

            valid_skills = true;

            //============================= Start of Owned skill =======================================

            cout << "Enter Owned skill : ";
            getline(cin, owned_skill_temp);
            owned_skill_temp = toLowerCase(owned_skill_temp);

            // check empty skills 
            if (owned_skill_temp.empty()) {
                cout << "Student Owned Skill is required.\nPlease try again.\n";
                valid_skills = false;
                continue;  // if user enter empty skills skip all conditions 
            }

            cout << "Enter Skill Category  ";
            // ====================================================================
            cout << "(";
            for (int i = 0; i < MaxCategIndex; i++) {  // Show All Categories
                if (i==MaxCategIndex-1)
                    cout << scateg[i].CategoryName;
                else                                                // format the text will remove in gui
                    cout << scateg[i].CategoryName << ", ";
            }
            cout << "):";
            getline(cin, owned_skill_category);
            //====================================================================

            if (owned_skill_category.empty()) {
                cout << "Student Skill Category is required.\nPlease try again.\n";
                valid_skills = false;
                continue;  // if user enter empty skills skip all conditions 
            }

            cout << "Enter Skill Difficulty Level: (Beginner, Intermediate, Advanced) ";
            getline(cin, owned_difficulty_level);

            if (owned_difficulty_level.empty()) {
                cout << "Skill Difficulty is required.\nPlease try again.\n";
                valid_skills = false;
                continue;
            }

            //============================= End of Owned skill =======================================


            //============================= Start of Wanted skill =======================================

            cout << "Enter Wanted skill : ";
            getline(cin, wanted_skill_temp);
            wanted_skill_temp = toLowerCase(wanted_skill_temp);

            // check empty skills 
            if (wanted_skill_temp.empty()) {
                cout << "Student Wanted Skill is required.\nPlease try again.\n";
                valid_skills = false;
                continue;  // if user enter empty skills skip all conditions 
            }

            cout << "Enter Skill Category  ";
            // ====================================================================
            cout << "(";
            for (int i = 0; i < MaxCategIndex; i++) {  // Show All Categories
                if (i == MaxCategIndex - 1)
                    cout << scateg[i].CategoryName;
                else                                                // format the text will remove in gui
                    cout << scateg[i].CategoryName << ", ";
            }
            cout << "):";
            getline(cin, wanted_skill_category);
            //====================================================================

            if (wanted_skill_category.empty()) {
                cout << "Student Skill Category is required.\nPlease try again.\n";
                valid_skills = false;
                continue;  // if user enter empty skills skip all conditions 
            }

            //============================= End of Wanted skill =======================================

            if (wanted_skill_temp == owned_skill_temp) {
                cout << "Enter different skills";
                continue;
            }



            // if user enter a valid skills 
            if (valid_skills) {
                

                stud[MaxUserIndex].owned_skill = GetOrCreateSkill(owned_skill_temp, owned_skill_category);
                if (stud[MaxUserIndex].owned_skill.SkillName == "") {
                    return;
                }
                stud[MaxUserIndex].DifficultyLevel = owned_difficulty_level;

                stud[MaxUserIndex].wanted_skill = GetOrCreateSkill(wanted_skill_temp, wanted_skill_category);
                if (stud[MaxUserIndex].wanted_skill.SkillName == "") {
                    return;
                }
            }
        } // end of skills validation


        // availability validation
        bool valid_availability = false;
        string availability;
        while (!valid_availability) {
            valid_availability = true;
            cout << "Enter Your Availability (Weekdays, Weekends, Flexible) :";
            getline(cin, availability);
            availability = toLowerCase(availability);

            // check empty name
            if (availability.empty()) {
                cout << "Availability are required.\nPlease try again.\n";
                valid_availability = false;
            }
        } // end of name validation

        stud[MaxUserIndex].availability = availability;
        stud[MaxUserIndex].role = "user";


         //storing data from struct to the file
        ofstream write_student_data("Users.txt", ios::app);
        write_student_data << stud[MaxUserIndex].id <<
            "|" << stud[MaxUserIndex].name <<
            "|" << stud[MaxUserIndex].email <<
            "|" << stud[MaxUserIndex].password <<
            "|" << stud[MaxUserIndex].major <<
            "|" << stud[MaxUserIndex].owned_skill.Category.CategoryId <<
            "|" << stud[MaxUserIndex].owned_skill.Category.CategoryName <<
            "|" << stud[MaxUserIndex].owned_skill.SkillName <<
            "|" << stud[MaxUserIndex].DifficultyLevel <<
            "|" << stud[MaxUserIndex].wanted_skill.Category.CategoryId <<
            "|" << stud[MaxUserIndex].wanted_skill.Category.CategoryName <<
            "|" << stud[MaxUserIndex].wanted_skill.SkillName <<
            "|" << stud[MaxUserIndex].availability <<
            "|" << stud[MaxUserIndex].role << endl;

        // close file
        write_student_data.close();
        MaxUserIndex++; // increment the index
        cout << "Registration completed successfully.\n Welcome aboard!\n";

    }
}

// Done
void ResetPass() {
    string temp_new_password;

    // Id validation
    long long id = IDValidation();

    // password validation
    bool valid_password = false;
    while (!valid_password) {
        valid_password = true;
        cout << "Enter student New Password : ";
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



    ofstream file("Users.txt", ios::trunc);  // Open file and remove everything in it


    //  Write All Data Again
    for (int i = 0; i < MaxUserIndex; i++) {
        file << stud[i].id << "|" << stud[i].name << "|" << stud[i].email << "|" << stud[i].password << "|" << stud[i].major << "|" << stud[i].owned_skill.Category.CategoryId << "|" << stud[i].owned_skill.Category.CategoryName << "|" << stud[i].owned_skill.SkillName << "|" << stud[i].DifficultyLevel << "|" << stud[i].wanted_skill.Category.CategoryId << "|" << stud[i].wanted_skill.Category.CategoryName << "|" << stud[i].wanted_skill.SkillName << "|" << stud[i].availability << "|" << stud[i].role << "\n";
    }

    file.close();
}

// Done
void profilemanagement(long long UserID) {
    bool foundid = false;
    int numofcase;
    string newowned, newwanted, difflevel, newcateg, newavailability;
    //while shroot el id string
    //checks if the id is okay or not and stored in new id var (long long type)
    //ask if the student want to update
    for (int i = 0; i < MaxUserIndex; i++) {
        if (stud[i].id == UserID) {
            foundid = true;
            //by using the swich to know what to update
            cout << "What do you want to update?" << endl << "1 : to update the owned skill" << endl
                << "2 : to update the wanted skill" << endl << "3 : to update the availability status" << endl
                << "4 : cancel\n";
            cout << "Enter option from (1-4): ";
            cin >> numofcase;
            switch (numofcase) {
            case 1:
                cin.ignore();
                //to neglect the space after the entering the input
                cout << "Enter Skill Category  ";
                // ====================================================================
                cout << "(";
                for (int i = 0; i < MaxCategIndex; i++) {  // Show All Categories
                    if (i == MaxCategIndex - 1)
                        cout << scateg[i].CategoryName;
                    else                                                // format the text will remove in gui
                        cout << scateg[i].CategoryName << ", ";
                }
                cout << "):";
                getline(cin, newcateg);
                // ====================================================================
                cout << "Enter your update for the owned skill: ";
                getline(cin, newowned);
                cout << "Enter your update for the availability status (Begginer, Intermediate, Advanced): ";
                getline(cin, difflevel);
                //edge cases
                //if the user didnt enter somthing
                if (newowned.empty() || difflevel.empty() || newcateg.empty()) {
                    cout << "The category or skill or difflevel is empty!";
                }
                //if the user entered the same his wanted skill
                else if (newowned == stud[i].wanted_skill.SkillName) {
                    cout << "The skill you entered is the same you want";
                }
                else if (newowned == stud[i].owned_skill.SkillName) {
                    cout << "The skill you entered is the same you Own";
                }
                else {
                    stud[i].owned_skill = GetOrCreateSkill(newowned, newcateg);
                    stud[i].DifficultyLevel = difflevel;
                }
                break;
            case 2:
                //to neglect the space after the entering the input
                cin.ignore();
                cout << "Enter Skill Category  ";
                // ====================================================================
                cout << "(";
                for (int i = 0; i < MaxCategIndex; i++) {  // Show All Categories
                    if (i == MaxCategIndex - 1)
                        cout << scateg[i].CategoryName;
                    else                                                // format the text will remove in gui
                        cout << scateg[i].CategoryName << ", ";
                }
                cout << "):";
                getline(cin, newcateg);
                // ====================================================================
                cout << "Enter your update for the wanted skill: ";
                getline(cin, newwanted);
                //edge cases
                //if the user didnt enter somthing
                if (newwanted.empty() || newcateg.empty()) {
                    cout << "The skill or category is empty!";
                }
                //if the user entered the same his owned skill
                else if (newwanted == stud[i].owned_skill.SkillName) {
                    cout << "You already own this skill";
                }
                else if (newwanted == stud[i].wanted_skill.SkillName) {
                    cout << "You already have this skill in wanted skill";
                }
                else {
                    stud[i].wanted_skill = GetOrCreateSkill(newwanted, newcateg);
                }
                cout << "Updated Successfully";

                break;
            case 3:
                cout << "Enter your update for the availability status: ";
                cin >> newavailability;
                if (newavailability.empty()) {
                    cout << "You didnt enter your update!";
                }
                if (newavailability == stud[i].availability) {
                    cout << "This is your old availability status! The new one must be different";
                }
                else
                    stud[i].availability = newavailability;
                cout << "Updated Successfully";

                break;
            case 4:
                cout << "the update is cancelled";
                break;
            default:
                cout << "Invalid choice. please ty again";
                break;
            }
        }
    }

    ofstream data_file("Users.txt");
    for (int i = 0; i < MaxUserIndex; i++) {
        data_file << stud[i].id <<
            "|" << stud[i].name <<
            "|" << stud[i].email <<
            "|" << stud[i].password <<
            "|" << stud[i].major <<
            "|" << stud[i].owned_skill.Category.CategoryId <<
            "|" << stud[i].owned_skill.Category.CategoryName <<
            "|" << stud[i].owned_skill.SkillName <<
            "|" << stud[i].DifficultyLevel <<
            "|" << stud[i].wanted_skill.Category.CategoryId <<
            "|" << stud[i].wanted_skill.Category.CategoryName <<
            "|" << stud[i].wanted_skill.SkillName <<
            "|" << stud[i].availability <<
            "|" << stud[i].role << endl;
    }
    data_file.close();
    
}

// Done
void findsmartmatches() {
    bool found = false;
    for (int i = 0; i < MaxUserIndex; i++) {//student resevation

        for (int j = i + 1; j < MaxUserIndex; j++) {//the other students are compared to the student in loop1
            //to avoid comparing the student to himself // don't deny the same husband twice
            if ((stud[i].owned_skill.SkillName == stud[j].wanted_skill.SkillName) && (stud[j].owned_skill.SkillName == stud[i].wanted_skill.SkillName)) {
                cout << "match found:" << stud[i].name << "," << stud[j].name << endl;
                cout << "skill exchange:" << stud[i].owned_skill.SkillName << " for " << stud[j].owned_skill.SkillName << endl;
                found = true;
            }
        }
    }

    if (!found) {//found=false
        cout << "no perfect matches found at this time " << endl;


    }

}

// Done
void Dash(long long id)
{
    bool sessions = false;
    for (int i = 0; i < MaxSessionIndex; i++)
    {
        if (id == session[i].mentorID) {
            for (int j = 0; j < MaxUserIndex; j++) {
                if (id == stud[j].id) {
                    cout << stud[j].name << endl;
                    cout << "MentorID:\t" << session[i].mentorID << " for skill  " << session[i].skill.SkillName << endl << session[i].status << endl;
                    sessions = true;
                    break;
                }
            }
        }
        if (id == session[i].learnerID) {
            for (int j = 0; j < MaxUserIndex; j++) {
                if (id == stud[j].id) {
                    cout << stud[j].name << endl;
                    cout << "LearnerID:\t" << session[i].learnerID << " for skill  " << session[i].skill.SkillName << endl << session[i].status << endl;
                    sessions = true;
                    break;
                }
            }

        }
    }
    if (!sessions) {
        cout << "Empty Sessions";
    }
}

// Done
void requestsession(long long learnerloginID) {
    // check the maximum array size
    if (MaxRequestIndex >= nrequests) {
        cout << "Maximum capacity reached. No further Requests allowed.\n" << endl;
    }

    else {
        long long ifIDvalid;
        string ifSkillvalid;
        bool skillvalid = false, IDvalid = false;

        do {
            cout << "Enter mentor ID" << endl;
            ifIDvalid = IDValidation();

            cout << "enter skillname :";
            getline(cin, ifSkillvalid);

            for (int i = 0;i < MaxUserIndex;i++)        //Validation of Id
            {

                if (ifIDvalid == stud[i].id){
                    IDvalid = true;
                    break;
                }
            }

            for (int i = 0;i < MaxSkillIndex;i++) {        //Validation of SkillName 

                if (ifSkillvalid == skill[i].SkillName){
                    request[MaxRequestIndex].skill.Category.CategoryId = skill[i].Category.CategoryId;
                    request[MaxRequestIndex].skill.Category.CategoryName = skill[i].Category.CategoryName;
                    skillvalid = true;
                    break;
                }
            }

        

            if (!IDvalid)
                cout << "invalid id" << endl;
            if (!skillvalid)
                cout << "invalid skillname" << endl;           // to let them enter again

        } while (IDvalid == false || skillvalid == false);


        request[MaxRequestIndex].requestId = MaxRequestIndex + 1;
        request[MaxRequestIndex].mentorId = ifIDvalid;
        request[MaxRequestIndex].learnerId = learnerloginID;
        request[MaxRequestIndex].skill.SkillName = ifSkillvalid;
        request[MaxRequestIndex].status = "pending";

        // storing data From Session struct to the file
        ofstream write_request_data("Requests.txt", ios::app);
        write_request_data << request[MaxRequestIndex].requestId <<
            "|" << request[MaxRequestIndex].mentorId <<
            "|" << request[MaxRequestIndex].learnerId <<
            "|" << request[MaxRequestIndex].skill.Category.CategoryId <<
            "|" << request[MaxRequestIndex].skill.Category.CategoryName <<
            "|" << request[MaxRequestIndex].skill.SkillName <<
            "|" << request[MaxRequestIndex].status << endl;


        // close file
        write_request_data.close();


        // increment the index
        MaxRequestIndex++;
    }

}

// Done
void viewrequests(long long mentorid) {
    bool requestsexist=false;
    for (int i = 0; i < MaxRequestIndex; i++) {
        if (request[i].mentorId == mentorid && request[i].status == "pending") {
            requestsexist=true;
            cout << "learner ID: " << request[i].learnerId << endl;
            cout << "skill: " << request[i].skill.SkillName << endl;

            cout << "1.Accept\t2.Reject\n";
            int choice;
            cin >> choice;

            if (choice == 1) {
                // check the maximum array size
                if (MaxSessionIndex >= nsessions) {
                    cout << "Maximum capacity reached. No further Sessions allowed.\n" << endl;
                }
                else {
                    request[i].status = "accepted";

                    ofstream file("Requests.txt", ios::trunc);  // update status to accepted in requests file

                    for (int j = 0; j < MaxRequestIndex; j++) {
                        file << request[j].requestId << "|"
                            << request[j].mentorId << "|"
                            << request[j].learnerId << "|"
                            << request[j].skill.Category.CategoryId << "|"
                            << request[j].skill.Category.CategoryName << "|"
                            << request[j].skill.SkillName << "|"
                            << request[j].status << endl;
                    }

                    file.close();

                    session[MaxSessionIndex].sessionID = MaxSessionIndex+1;
                    session[MaxSessionIndex].mentorID = request[i].mentorId;
                    session[MaxSessionIndex].learnerID = request[i].learnerId;
                    session[MaxSessionIndex].skill.Category.CategoryId = request[i].skill.Category.CategoryId;
                    session[MaxSessionIndex].skill.Category.CategoryName = request[i].skill.Category.CategoryName;
                    session[MaxSessionIndex].skill.SkillName = request[i].skill.SkillName;
                    session[MaxSessionIndex].status = "scheduled";
                    


                    // storing data From Session struct to the file
                    ofstream write_session_data("Sessions.txt", ios::app);
                    write_session_data << session[MaxSessionIndex].sessionID <<
                        "|" << session[MaxSessionIndex].mentorID <<
                        "|" << session[MaxSessionIndex].learnerID <<
                        "|" << session[MaxSessionIndex].skill.Category.CategoryId <<
                        "|" << session[MaxSessionIndex].skill.Category.CategoryName <<
                        "|" << session[MaxSessionIndex].skill.SkillName <<
                        "|" << session[MaxSessionIndex].status << endl;


                    // close file
                    write_session_data.close();


                    // increment the index
                    MaxSessionIndex++;

                    cout << "Session scheduled!\n";
                }
            }
            else if (choice == 2) {

                request[i].status = "rejected";
                cout << "Request rejected.\n";


                ofstream file("Requests.txt", ios::trunc); // update status to rejected in requests file

                for (int j = 0; j < MaxRequestIndex; j++) {
                    file << request[i].requestId << "|"
                        << request[j].mentorId << "|"
                        << request[j].learnerId << "|"
                        << request[j].skill.Category.CategoryId << "|"
                        << request[j].skill.Category.CategoryName << "|"
                        << request[j].skill.SkillName << "|"
                        << request[j].status << endl;
                }

                file.close();

              }
              else {
                    cout << "Enter valid option 1.for accept    2.for reject";
              }
                

        }
    }
        if (!requestsexist) {
            cout << "No Requests Now";
        }

}

// Done
void SearchandFilter(long long current_user) {
    string search_word;
    cout << "Enter the Skill that you Need to Search: ";
    getline(cin, search_word);
    search_word = toLowerCase(search_word);  // convert the input to lower case
    bool isexist = false;
    string owned_skill;
    for (int i = 0; i < MaxUserIndex; i++) {
        owned_skill = stud[i].owned_skill.SkillName;  // convert the owned skill to lower case
        if (stud[i].owned_skill.SkillName == search_word && current_user != stud[i].id) {
            cout << stud[i].name << " Has " << search_word << " skill and his ID is: " << stud[i].id << endl;
            isexist = true;
        }
    }

    if (!isexist) {
        cout << "No Students Has This Skill." << endl;
    }
}

// Done
void SkillAnalytics() {
    string owned_skills[nskills];
    int count_owned_skills[nskills]={};
    string owned_skill, wanted_skill;
    int storedSkills = 0;

    // ==================================== Most offered Skills ====================================

    for (int i = 0; i < MaxUserIndex; i++) {  // count owned skills (Most Offered)
        bool OwnedSkillFound=false;
        owned_skill = stud[i].owned_skill.SkillName;
        for (int j = 0; j < storedSkills; j++) {
            if (owned_skill == owned_skills[j]) {
                count_owned_skills[j]++;
                OwnedSkillFound = true;
                break;
            }
        }
        if (!OwnedSkillFound) {
            owned_skills[storedSkills] = owned_skill;
            count_owned_skills[storedSkills] = 1;
            storedSkills++;
        }
    }
    int max=0;
    for (int i = 0; i < storedSkills; i++) { // find the most number of owned skill
        if (count_owned_skills[i] > max) {
            max = count_owned_skills[i];
        }
    }

    cout << "\n===== Most Offered Skills =====\n";

    for (int i = 0; i < storedSkills; i++) {    // print all the most skills of owned skill
        if (count_owned_skills[i] == max) {
            cout << owned_skills[i] << " : " << count_owned_skills[i] << endl;
        }
    }

    // ==================================== Most Requested Skills ====================================
    string wanted_skills[nskills];
    int count_wanted_skills[nskills] = {};
    storedSkills = 0;
    for (int i = 0; i < MaxUserIndex; i++) {  // count wanted skills (Most Requested)
        bool WantedSkillFound = false;
        wanted_skill = stud[i].wanted_skill.SkillName;
        for (int j = 0; j < storedSkills; j++) {
            if (wanted_skill == wanted_skills[j]) {
                count_wanted_skills[j]++;
                WantedSkillFound = true;
                break;
            }
        }
        if (!WantedSkillFound) {
            wanted_skills[storedSkills] = wanted_skill;
            count_wanted_skills[storedSkills] = 1;
            storedSkills++;
        }
    }
   
    max = 0;
    for (int i = 0; i < storedSkills; i++) { // find the most number of wanted skill
        if (count_wanted_skills[i] > max) {
            max = count_wanted_skills[i];
        }
    }

    cout << "\n===== Most Requested Skills =====\n";

    for (int i = 0; i < storedSkills; i++) {    // print all the most skills of wanted skill
        if (count_wanted_skills[i] == max) {
            cout << wanted_skills[i] << " : " << count_wanted_skills[i] << endl;
        }

    }

}

void SystemMaintenance() {

    cout << "Choose option: \n \
    1. Add Category \n \
    2. Delete Category \n \
    3. Search and Delete Student\n \
    4. Change Role for Student\n \
    Enter option from (1-4): ";
    int choice;
    cin >> choice;
    cin.ignore();
    if (choice == 1) {
        // check the maximum array size
        if (MaxCategIndex >= ncategories) {
            cout << "Maximum capacity reached. No further Categories allowed.\n" << endl;
        }
        else {
            string categname;
            cout << "Enter the Category Name: ";
            cin >> categname;
            scateg[MaxCategIndex].CategoryId = MaxCategIndex+1;
            scateg[MaxCategIndex].CategoryName = categname;

            ofstream write_category_data("SkillCategory.txt", ios::app);

            write_category_data << scateg[MaxCategIndex].CategoryId
            << "|" << scateg[MaxCategIndex].CategoryName << endl;

            write_category_data.close();

            MaxCategIndex++;
        }

    }
    else if (choice == 2) {
        string categname;
        cout << "Enter the Category Name that you need to delete";
        cin >> categname;
        bool categexistance=false;
        for (int i = 0; i < MaxCategIndex; i++) {
            if (categname == scateg[i].CategoryName) {
                categexistance = true;
                break;
            }
        }
        if (!categexistance) {
            cout << "Enter valid Category name";
        }
        else {
            bool delete_validation = true;
            for (int i = 0; i < MaxUserIndex; i++) {
                if (categname == stud[i].owned_skill.Category.CategoryName || categname == stud[i].wanted_skill.Category.CategoryName) {
                    cout << "Delete All Skills that Related to this Category First From Users." << endl;
                    delete_validation = false;
                    break;
                }
            }

            for (int i = 0; i < MaxSkillIndex; i++) {
                if (categname == skill[i].Category.CategoryName) {
                    cout << "Delete Skills That Inside this Category First." << endl;
                    delete_validation = false;
                    break;
                }
            }

            if (delete_validation) {

                int delIndex = -1;
                for (int i = 0; i < MaxCategIndex; i++) {
                    if (scateg[i].CategoryName == categname) {
                        delIndex = i;
                        break;
                    }
                }

                if (delIndex != -1) {
                    for (int i = delIndex; i < MaxCategIndex - 1; i++) {
                        scateg[i] = scateg[i + 1];
                    }
                    MaxCategIndex--;

                    // Rewrite file
                    ofstream write_category_data("SkillCategory.txt");
                    for (int i = 0; i < MaxCategIndex; i++) {
                        write_category_data << scateg[i].CategoryId << "|" << scateg[i].CategoryName << endl;
                    }
                    write_category_data.close();

                    cout << "Category deleted successfully.\n";
                }

            }

        }


    }
    
    else if (choice == 3) {
        long long id = IDValidation();
        bool idexist = false;
        char choice;
        int delIndex = -1;
        for (int i = 0; i < MaxUserIndex; i++) {
            if (id == stud[i].id) {
                cout << "Are you Sure To Delete this Student his Name is: " << stud[i].name << "? (Y/N)";
                cin >> choice;

                if (choice == 'y' || choice == 'Y') {
                    delIndex = i;

                    for (int i = delIndex; i < MaxUserIndex - 1; i++) {
                        stud[i] = stud[i + 1];
                    }
                    MaxUserIndex--;
                }
                else {
                    cout << "You Cancelled the operation\n";
                    
                }
                idexist = true;
                break;
            }
        }

        if (!idexist) {
            cout << "Enter ID Exist in database\n";
        }
        else {
            // Rewrite file
            ofstream write_user_data("Users.txt");
            for (int i = 0; i < MaxUserIndex; i++) {
                write_user_data << stud[i].id <<
                    "|" << stud[i].name <<
                    "|" << stud[i].email <<
                    "|" << stud[i].password <<
                    "|" << stud[i].major <<
                    "|" << stud[i].owned_skill.Category.CategoryId <<
                    "|" << stud[i].owned_skill.Category.CategoryName <<
                    "|" << stud[i].owned_skill.SkillName <<
                    "|" << stud[i].DifficultyLevel <<
                    "|" << stud[i].wanted_skill.Category.CategoryId <<
                    "|" << stud[i].wanted_skill.Category.CategoryName <<
                    "|" << stud[i].wanted_skill.SkillName <<
                    "|" << stud[i].availability <<
                    "|" << stud[i].role << endl;
            }
            write_user_data.close();

            cout << "User deleted successfully.\n";
        }


    }

    else if (choice == 4) {
        bool idexist = false;
        long long id = IDValidation();
        for (int i = 0; i < MaxUserIndex; i++) {
            if (id == stud[i].id) {
                stud[i].role = "admin";
                idexist = true;
                break;
            }
        }

        if (!idexist) {
            cout << "Enter ID Exist in database\n";
        }else {

        // Rewrite file
        ofstream write_user_data("Users.txt");
        for (int i = 0; i < MaxUserIndex; i++) {
            write_user_data << stud[i].id <<
                "|" << stud[i].name <<
                "|" << stud[i].email <<
                "|" << stud[i].password <<
                "|" << stud[i].major <<
                "|" << stud[i].owned_skill.Category.CategoryId <<
                "|" << stud[i].owned_skill.Category.CategoryName <<
                "|" << stud[i].owned_skill.SkillName <<
                "|" << stud[i].DifficultyLevel <<
                "|" << stud[i].wanted_skill.Category.CategoryId <<
                "|" << stud[i].wanted_skill.Category.CategoryName <<
                "|" << stud[i].wanted_skill.SkillName <<
                "|" << stud[i].availability <<
                "|" << stud[i].role << endl;
        }
        write_user_data.close();

        cout << "User Role Updated successfully.\n";
        }
    }

}

// Not in gui
void AuthenticationMenu() {
    int choice;
    do {
        cout << "================ Authentication Menu ================\n1. Login If You Have Account \n2. Sign Up (Create New Account) If You Don't Have One\n3. Reset Password If You Forget It\n4. Exit\n=====================================================\n\nPlease choose an option (1-4): ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
        case 1:
            system("cls");
            cout << "\n************* Login *************n\n";
            Login();
            break;
        case 2:
            system("cls");
            cout << "\n************* Registration *************\n\n";
            sign_up();
            break;
        case 3:
            system("cls");
            cout << "\n************* Reset Password *************\n\n";
            ResetPass();
            break;
        case 4:
            system("cls");
            cout << "Thanks for using Our Programm 🌹🌹🌹🌹";
            break;
        default:
            cout << "******************* Enter a Valid Option From (1-4) *******************\n";
        }

        if (UserIndex != -1) {
            break;
        }

    } while (choice != 4);

}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    //=============================================================================
    CheckSessionFile();
    CheckStudentFile();
    CheckSkillCategFile();                                   
    CheckSkillFile();   //functions for fill structs and check files
    CheckRequestsFile();
    FillSessionStruct();
    FillStudenStruct();
    FillSkillCategStruct();
    FillSkillStruct();
    FillRequestStruct();
    //=============================================================================


    //============================= (Authentication Part Start) ======================================

    //cout << "===========================================\n\tWelcome to Skill Swap System\n===========================================\nA Peer-Learning Platform where students\nteach each other and grow together!\n\n* Share your skills\n* Learn new ones\n* Connect with other students\nLet's get started!\n===========================================\n\n";

    AuthenticationMenu();
    while (true) {

    if (stud[UserIndex].role == "admin") { // if admin

        int choice;
        do {
            cout << "\n======= Main Menu =======\n";
            cout << "\n***** Admin Portals *****\n";
            cout << "1. Samrt Matchmaking\n";
            cout << "2. Skill Analytics\n";
            cout << "3. System Maintenance\n";
            cout << "========================\n\n";

            cout << "========================\n";
            cout << "***** User Portals *****\n";
            cout << "4. Profile Management\n";
            cout << "5. Search & Filter\n";
            cout << "6. Swap Request\n";
            cout << "7. View Request\n";
            cout << "8. My Dashboard\n";
            cout << "9. Logout\n";
            cout << "========================\n";
            cout << "Choose option (1-9): ";

            cin >> choice;
            cin.ignore();
            switch (choice) {
                case 1:
                    system("cls");
                    findsmartmatches();
                    break;
                case 2:
                    system("cls");
                    SkillAnalytics();
                    break;
                case 3:
                    system("cls");
                    SystemMaintenance();
                    break;
                case 4:
                    system("cls");
                    profilemanagement(stud[UserIndex].id);
                    break;
                case 5:
                    system("cls");
                    SearchandFilter(stud[UserIndex].id);
                    break;
                case 6:
                    system("cls");
                    requestsession(stud[UserIndex].id);
                    break;
                case 7:
                    system("cls");
                    viewrequests(stud[UserIndex].id);
                    break;
                case 8:
                    system("cls");
                    Dash(stud[UserIndex].id);
                    break;
                case 9:
                    system("cls");
                    UserIndex = -1;
                    AuthenticationMenu();
                    break;
            }


        }while (choice != 9);
    }

    else if (stud[UserIndex].role == "user"){
        int choice;
        do {
            cout << "\n===== Main Menu =====\n";
            cout << "1. Profile Management\n";
            cout << "2. Search & Filter\n";
            cout << "3. Swap Request\n";
            cout << "4. View Request\n";
            cout << "5. My Dashboard\n";
            cout << "6. Logout\n";
            cout << "=====================\n";
            cout << "Choose option (1-6): ";

            cin >> choice;
            cin.ignore();
            switch (choice) {
            case 1:
                system("cls");
                profilemanagement(stud[UserIndex].id);
                break;
            case 2:
                system("cls");
                SearchandFilter(stud[UserIndex].id);
                break;
            case 3:
                system("cls");
                requestsession(stud[UserIndex].id);
                break;
            case 4:
                system("cls");
                viewrequests(stud[UserIndex].id);
                break;
            case 5:
                system("cls");
                Dash(stud[UserIndex].id);
                break;
            case 6:
                system("cls");
                UserIndex = -1;
                AuthenticationMenu();
                break;
            }


        } while (choice != 6);
    }

    }
}
