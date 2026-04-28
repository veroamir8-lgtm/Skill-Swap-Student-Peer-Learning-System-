// #include <iostream>
// #include <fstream>
// #include <string>
// #include <sstream>

// using namespace std;

// struct LearningSession {
//     int sessionID;
//     long long mentorID;
//     long long learnerID;
//     string skillName;
//     string status;
// };
// const int nsessions = 10;
// LearningSession session[nsessions];
// int MaxSessionIndex = 0;


// struct student {
//     string name;
//     string password;
//     string major;
//     long long id;
//     string owned_skill;
//     string wanted_skill;
//     string email;
//     string availability;
// };
// const int nstudents = 10;
// student stud[nstudents];
// int MaxUserIndex = 0;


// struct SkillCategory {
//     int CategoryId;
//     string CategoryName;
// };
// const int ncategories = 5;
// SkillCategory scateg[ncategories];
// int MaxCategIndex = 0;


// struct Skill {
//     string SkillName;
//     string DifficultyLevel;
//     SkillCategory Category;
// };
// const int nskills = 10;
// Skill skill[nskills];
// int MaxSkillIndex = 0;



// void FillSessionStruct()
// {
//     string sessionID, mentorID, learnerID, skillName, status;
//     string myText;
//     ifstream data_file("Sessions.txt"); // check array index
//     while (getline(data_file, myText)) {
//         MaxSessionIndex++;
//     }

//     data_file.clear();
//     data_file.seekg(0, ios::beg);

//     for (int i = 0; i < MaxSessionIndex; i++) {
//         getline(data_file, myText);
//         stringstream string_splitter(myText);

//         // read line until (/) appears 
//         // store in variables
//         getline(string_splitter, sessionID, '|');
//         getline(string_splitter, mentorID, '|');
//         getline(string_splitter, learnerID, '|');
//         getline(string_splitter, skillName, '|');
//         getline(string_splitter, status, '|');


//         // storing data from a file to struct
//         session[i].sessionID = stoi(sessionID);
//         session[i].mentorID = stoll(mentorID);
//         session[i].learnerID = stoll(learnerID);
//         session[i].skillName = skillName;
//         session[i].status = status;

//     }
//     // close file
//     data_file.close();

// }

// void FillStudenStruct() {
//     string id, usernames, pass, email, major, OwnedSkill, WantedSkill, availability;
//     string myText;
//     ifstream data_file("Users.txt"); // check array index
//     while (getline(data_file, myText)) {
//         MaxUserIndex++;
//     }
//     data_file.clear();
//     data_file.seekg(0, ios::beg);

//     for (int i = 0; i < MaxUserIndex; i++) {
//         getline(data_file, myText);
//         stringstream string_splitter(myText);
//         // read line until (/) appears 
//         // store in variables
//         getline(string_splitter, id, '|');
//         getline(string_splitter, usernames, '|');
//         getline(string_splitter, email, '|');
//         getline(string_splitter, pass, '|');
//         getline(string_splitter, major, '|');
//         getline(string_splitter, OwnedSkill, '|');
//         getline(string_splitter, WantedSkill, '|');
//         getline(string_splitter, availability, '|');

//         // storing data from a file to struct
//         stud[i].id = stoll(id);
//         stud[i].name = usernames;
//         stud[i].email = email;
//         stud[i].password = pass;
//         stud[i].major = major;
//         stud[i].owned_skill = OwnedSkill;
//         stud[i].wanted_skill = WantedSkill;
//         stud[i].availability = availability;

//     }
//     // close file
//     data_file.close();

// }

// void FillSkillCategStruct()
// {
//     string categid, categname;
//     string myText;
//     ifstream data_file("SkillCategory.txt"); // check array index
//     while (getline(data_file, myText)) {
//         MaxCategIndex++;
//     }

//     data_file.clear();
//     data_file.seekg(0, ios::beg);

//     for (int i = 0; i < MaxCategIndex; i++) {
//         getline(data_file, myText);
//         stringstream string_splitter(myText);

//         // read line until (/) appears 
//         // store in variables
//         getline(string_splitter, categid, '|');
//         getline(string_splitter, categname, '|');


//         // storing data from a file to struct
//         scateg[i].CategoryId = stoi(categid);
//         scateg[i].CategoryName = categname;

//     }
//     // close file
//     data_file.close();

// }

// void FillSkillStruct()
// {
//     string sname, difflevel, categid, categname;
//     string myText;
//     ifstream data_file("Skills.txt"); // check array index
//     while (getline(data_file, myText)) {
//         MaxSkillIndex++;
//     }

//     data_file.clear();
//     data_file.seekg(0, ios::beg);

//     for (int i = 0; i < MaxSkillIndex; i++) {
//         getline(data_file, myText);
//         stringstream string_splitter(myText);

//         // read line until (/) appears 
//         // store in variables
//         getline(string_splitter, sname, '|');
//         getline(string_splitter, difflevel, '|');
//         getline(string_splitter, categid, '|');
//         getline(string_splitter, categname, '|');



//         // storing data from a file to struct
//         skill[i].SkillName = sname;
//         skill[i].DifficultyLevel = difflevel;
//         skill[i].Category.CategoryId = stoi(categid);
//         skill[i].Category.CategoryName = categname;

//     }
//     // close file
//     data_file.close();

// }

// void CheckStudentFile() {
//     ifstream CheckFile;
//     CheckFile.open("Users.txt");
//     if (!CheckFile.is_open()) {  // Check File if Exists
//         ofstream MyFile("Users.txt");   // If Not Exists Make One and Put The Main Row
//         MyFile.close();
//     } CheckFile.close();
// }

// void CheckSessionFile() {
//     ifstream CheckFile;
//     CheckFile.open("sessions.txt");
//     if (!CheckFile.is_open()) {  // Check File if Exists
//         ofstream MyFile("sessions.txt");   // If Not Exists Make One and Put The Main Row
//         MyFile.close();
//     } CheckFile.close();
// }

// void CheckSkillCategFile() {
//     ifstream CheckFile;
//     CheckFile.open("SkillCategory.txt");
//     if (!CheckFile.is_open()) {  // Check File if Exists
//         ofstream MyFile("SkillCategory.txt");   // If Not Exists Make One and Put The Main Row
//         MyFile.close();
//     } CheckFile.close();
// }

// void CheckSkillFile() {
//     ifstream CheckFile;
//     CheckFile.open("Skills.txt");
//     if (!CheckFile.is_open()) {  // Check File if Exists
//         ofstream MyFile("Skills.txt");   // If Not Exists Make One and Put The Main Row
//         MyFile.close();
//     } CheckFile.close();
// }



// long long IDValidation() {  // Used in kermina, jana, kevin functions
//     string temp_id;

//     // id validation
//     bool valid_id = false;
//     while (!valid_id) {
//         cout << "Enter student ID :";

//         getline(cin, temp_id);
//         valid_id = true;

//         if (temp_id.empty()) { // check empty id
//             cout << "Student ID are required.\nPlease try again.\n";
//             valid_id = false;
//             continue;  // if the user enter empty id skip all conditions
//         }

//         int spaces = temp_id.find(' '); // check spaces
//         if (spaces != -1) {
//             cout << "Spaces are not allowed.\nPlease remove any spaces and try again.\n";
//             valid_id = false;
//             continue;  //if the user enter spaces skip the rest of block of while loop to prevent repeated msgs
//         }

//         for (char c : temp_id) { // check if each character is a number
//             if (!isdigit(c)) {
//                 cout << "Invalid input.\nID must contain exactly 11 numeric digits.\nPlease try again\n" << endl;
//                 valid_id = false;
//                 break;
//             }
//         }
//         if (!valid_id)    //if the user enter chars instead of digits skip the rest of block of while loop to prevent repeated msgs
//             continue;

//         if (temp_id.length() != 11) { // check the id length
//             cout << "Invalid input.\nID must contain exactly 11 numeric digits.\nPlease try again\n " << endl;
//             valid_id = false;
//             continue;
//         }

//         if (valid_id) { // if user enter a valid id
//             break;
//         }
//     }  // End of Id Validation 

//     return stoll(temp_id);
// }



// bool isIDExist(long long temp_id) {  // Used in kermina function

//     for (int i = 0; i <= MaxUserIndex; i++) {
//         if (temp_id == stud[i].id) {
//             return true;
//         }
//     }
//     return false;
// }








#include <iostream>

using namespace std;

int main() {
    int x = 20;
    cout << &x;
}