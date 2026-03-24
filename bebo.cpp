// ================================================ Bebo code (LogIn fn) =============================================================

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

struct LearningSession {
    int sessionID;
    long long mentorID;
    long long learnerID;
    string skillName;
    string status;
};
const int nsessions = 10;
LearningSession session[nsessions];
int MaxSessionIndex = 0;
struct student {
    string name;
    string password;
    string major;
    long long id;
    string owned_skill;
    string wanted_skill;
    string email;
    string availability;
};
const int nstudents = 10;
student stud[nstudents];
int MaxUserIndex = 0;

void FillSessionStruct() 
{
    string sessionID, mentorID, learnerID, skillName, status;
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
        getline(string_splitter, skillName, '|');
        getline(string_splitter, status, '|');


        // storing data from a file to struct
        session[i].sessionID = stoi(sessionID);
        session[i].mentorID = stoll(mentorID);
        session[i].learnerID = stoll(learnerID);
        session[i].skillName = skillName;
        session[i].status = status;

    }
    // close file
    data_file.close();

}void FillStudenStruct() {
    string id, usernames, pass, email, major, OwnedSkill, WantedSkill, availability;
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
        getline(string_splitter, availability, '|');

        // storing data from a file to struct
        stud[i].id = stoll(id);
        stud[i].name = usernames;
        stud[i].email = email;
        stud[i].password = pass;
        stud[i].major = major;
        stud[i].owned_skill = OwnedSkill;
        stud[i].wanted_skill = WantedSkill;
        stud[i].availability = availability;

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


void CheckSessionFile() {
    ifstream CheckFile;
    CheckFile.open("sessions.txt");
    if (!CheckFile.is_open()) {  // Check File if Exists
        ofstream MyFile("sessions.txt");   // If Not Exists Make One and Put The Main Row
        MyFile.close();
    } CheckFile.close();
}

// ============================================================= Start of Function ==============================================================

void Dash()
{
    long long id;
    bool sessions=false;
    cout << "enter your id ";
    cin >> id;
    for (int i = 0; i < MaxSessionIndex; i++) 
    {
        if (id == session[i].mentorID) {
            for (int j = 0; j < MaxUserIndex; j++) {
                if (id == stud[j].id) {
                    cout << stud[j].name << endl;
                    cout << "MentorID:\t" << session[i].mentorID << " for skill  " << session[i].skillName << endl << session[i].status << endl;
                    sessions = true;
                    break;
                }
            }
        }
        if (id == session[i].learnerID) {
            for (int j = 0; j < MaxUserIndex; j++) {
                if (id == stud[j].id){
                    cout << stud[j].name << endl;
                    cout << "LearnerID:\t" << session[i].mentorID << " for skill  " << session[i].skillName << endl << session[i].status << endl;
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

// ============================================================= End of Function ==============================================================


// ============================================================= Call Function ==============================================================

int main() 
{
    CheckSessionFile();
    CheckStudentFile();
    FillSessionStruct();
    FillStudenStruct();
    Dash();
}