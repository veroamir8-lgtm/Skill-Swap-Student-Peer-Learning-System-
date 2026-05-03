// ================================================ Vero code (LogIn fn) =============================================================


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
	string availability;
};
const int nstudents = 10;
student stud[nstudents];
int MaxUserIndex = 0;
void FillStruct() {
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

void profilemanagement() {
	bool foundid = false;
	string myid;
	int numofcase;
	string newowned, newwanted, newavailability;
	//while shroot el id string
	//checks if the id is okay or not and stored in new id var (long long type)
	long long newid = IDValidation();
	//ask if the student want to update
	for (int i = 0; i < MaxUserIndex; i++) {
		if (stud[i].id == newid) {
			foundid = true;
			//by using the swich to know what to update
			cout << "What do you want to update?" << endl << "1 : to update the owned skill" << endl
				<< "2 : to update the wanted skill" << endl << "3 : to update the availability status" << endl
				<< "4 : cancel";
			cin >> numofcase;
			switch (numofcase) {
			case 1:
				cout << "Enter your update for the owned skill";
				//to neglect the space after the entering the input
				cin.ignore();
				getline(cin, newowned);
				//edge cases
				//if the user didnt enter somthing
				if (newowned.empty()) {
					cout << "The skill is empty!";
				}
				//if the user entered the same his wanted skill
				else if (newowned == stud[i].wanted_skill) {
					cout << "The skill you entered is the same you want";
				}
                else if (newowned == stud[i].owned_skill) {
					cout << "The skill you entered is the same you Own";
				}
				else {
					stud[i].owned_skill = newowned;
					cout << "Updated successfully!\n";
				}
				break;
			case 2:
				cout << "Enter your update for the wanted skill";
				//to neglect the space after the entering the input
				cin.ignore();
				getline(cin, newwanted);
				//edge cases
				//if the user didnt enter somthing
				if (newwanted.empty()) {
					cout << "The skill is empty!";
				}
				//if the user entered the same his owned skill
				else if (newwanted == stud[i].owned_skill) {
					cout << "You already own this skill";
				}
                else if (newwanted == stud[i].wanted_skill) {
					cout << "You already have this skill in wanted skill";
				}
				else {
					stud[i].wanted_skill = newwanted;
					cout << "Updated successfully!\n";
				}
				break;
			case 3:
				cout << "Enter your update for the availability status";
				cin >> newavailability;
				if (newavailability.empty()) {
					cout << "You didnt enter your update!";
				}
				if (newavailability == stud[i].availability) {
					cout << "This is your old availability status! The new one must be different";
				}
				else{
					stud[i].availability = newavailability;
				cout << "Updated successfully!\n";}
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
	if (!foundid) {
		cout << "Id is not found, please try again";
	}
	ofstream data_file("database.txt");
	for (int i = 0; i < MaxUserIndex; i++) {
		data_file << stud[i].id << '|'
			<< stud[i].name << '|'
			<< stud[i].email << '|' << stud[i].password << '|' <<
			stud[i].major << '|' << stud[i].owned_skill << '|' << stud[i].wanted_skill <<
			'|' << stud[i].availability << endl;
	}
	data_file.close();
}


// ============================================================= End of Function ==============================================================



// ============================================================= Call Function ==============================================================



int main() {
    CheckStudentFile();
    FillStruct();
    profilemanagement();
}
