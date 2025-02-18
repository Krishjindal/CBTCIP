#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
	char data[50];
	int n = 0, option = 0, count= 0;
	string empty = "00";
	string proctor = "";
	ifstream f("record.txt");
	string line;

	for (int i = 0; std::getline(f, line); ++i) {
		count++;
	}

	while (option != 6) {
		cout << "\nAvailable operations: \n1. Add New "
				"Students\n2."
			<< "Student Login\n3. Faculty Login\n4. "
				"Proctor Login\n5. Admin View\n"
			<< "6. Exit\nEnter option: ";
		cin >> option;

		if (option == 1) {
			cout << "Enter the number of students: ";
			cin >> n;
			count = count + n;
			for (int i = 0; i < n; i++) {
				ofstream outfile;
				outfile.open("record.txt", ios::app);
				cout << "Enter your registration number: ";
				cin >> data;
				outfile << data << "\t";

				cout << "Enter your name: ";
				cin >> data;
				int len = strlen(data);

				while (len < 15) {
					data[len] = ' ';
					len = len + 1;
				}
				outfile << data << "\t";
				outfile << empty << "\t";
				outfile << empty << "\t";

				cout << "Enter your proctor ID: ";
				cin >> proctor;

				outfile << proctor << endl;
			}
		}

		else if (option == 2) {
			char regno[3];
			cout << "Enter your registration number: ";
			cin >> regno;
			ifstream infile;
			int check = 0;
			infile.open("record.txt", ios::in);

			while (infile >> data) {
				if (strcmp(data, regno) == 0) {
					cout<< "\nRegistration Number: " << data<< endl;
					infile >> data;
					cout << "Name: " << data << endl;

					infile >> data;
					cout << "CSE1001 mark: " << data<< endl;

					infile >> data;
					cout << "CSE1002 mark: " << data<< endl;

					infile >> data;
					cout << "Proctor ID: " << data << endl;

					infile.close();
					check = 1;
				}
			}

			if (check == 0) {
				cout << "No such registration number found!"<< endl;
			}
		}

		else if (option == 3) {
			char subcode[7];
			cout << "Enter your subject code: ";
			cin >> subcode;
			string code1 = "CSE1001", code2 = "CSE1002",
				mark = "";
			ifstream infile;
			int check = 0;

			cout << "\nAvailable operations: \n1. Add data "
					"about marks\n"
				<< "2. View data\nEnter option: ";
			cin >> option;

			if (option == 1) {
				cout
					<< "Warning! You would need to add mark"
					<< "details for all the students!"
					<< endl;
				for (int i = 0; i < count; i++) {
					fstream file("record.txt");

					if (strcmp(subcode, code1.c_str())== 0) {
						file.seekp(26 + 37 * i,std::ios_base::beg);
						cout << "Enter the mark of student#"<< (i + 1) << " : ";
						cin >> mark;
						file.write(mark.c_str(), 2);
					}

					if (strcmp(subcode, code2.c_str())== 0) {
						file.seekp(29 + 37 * i,std::ios_base::beg);
						cout << "Enter the mark of student#"<< (i + 1) << " : ";
						cin >> mark;
						file.write(mark.c_str(), 2);
					}
				}
			}

			else if (option == 2) {
				infile.open("record.txt", ios::in);
				if (strcmp(subcode, code1.c_str()) == 0) {
					cout << "Registration number - Marks\n"<< endl;
					while (infile >> data) {
						cout << data;
						infile >> data;
						infile >> data;
						cout << " - " << data << endl;
						infile >> data;
						infile >> data;
						check = 1;
					}
				}

				infile.close();
				infile.open("record.txt", ios::in);

				if (strcmp(subcode, code2.c_str()) == 0) {
					cout << "Registration number - Marks\n"<< endl;
					while (infile >> data) {
						cout << data;
						infile >> data;
						infile >> data;
						infile >> data;
						cout << " - " << data << endl;
						infile >> data;
						check = 1;
					}
				}
			}

			infile.close();

			if (check == 0) {
				cout << "No such subject code found!"<< endl;
			}
		}

		else if (option == 4) {
			char procid[7];
			cout << "Enter your proctor ID: ";
			cin >> procid;
			int check = 0;
			char temp1[100], temp2[100], temp3[100];
			char temp4[100], id[100];
			ifstream infile;
			infile.open("record.txt", ios::in);

			while (infile >> temp1) {
				infile >> temp2;
				infile >> temp3;
				infile >> temp4;
				infile >> id;

				if (strcmp(id, procid) == 0) {
					cout << "\nRegistration Number: "
						<< temp1 << endl;
					cout << "Name: " << temp2 << endl;
					cout << "CSE1001 Mark: " << temp3
						<< endl;
					cout << "CSE1002 Mark: " << temp4
						<< endl;
					check = 1;
				}
			}

			if (check == 0) {
				cout << "No such proctor ID found!" << endl;
			}
		}
		else if (option == 5) {
			char password[25];
			cout << "Enter the admin password: ";
			cin >> password;
			string admin_pass = "admin";

			if (strcmp(password, admin_pass.c_str()) == 0) {
				cout << "Reg No.\tName\tCSE1001\tCSE1002\tProctorID"
					<< endl;
				ifstream infile;
				infile.open("record.txt", ios::in);
				char data[20];

				while (infile >> data) {
					cout << data << "\t";
					infile >> data;
					cout << data << "\t";
					infile >> data;
					cout << data << "\t";
					infile >> data;
					cout << data << "\t";
					infile >> data;
					cout << data << endl;
				}
			}
		}
	}
}
