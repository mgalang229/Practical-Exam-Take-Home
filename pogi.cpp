#include <iostream>
#include <fstream>
using namespace std;

class Record{
	public:
		void writeRecord(int, char fname[255], char lname[255], double);
		void readRecord(int, char fname[255], char lname[255], double);
		void searchRecord(int, char fname[255], char lname[255], double);
		void editRecord(int, char fname[255], char lname[255], double);
		void deleteRecord(int, char fname[255], char lname[255], double);
	private:
		int accountNumber;
		char fname[255];
		char lname[255];
		double balance;
};
int main(){
	
	Record rec;
	int account, choice;
	char firstName[255], lastName[255];
	double bal;
	
	while(1){
		
		cout << "\nMENU\n";
		cout << "\n1. Write a record";
		cout << "\n2. Read record";
		cout << "\n3. Search record";
		cout << "\n4. Edit record";
		cout << "\n5. Delete record";
		cout << "\n6. Exit";
		cout << "\n\nEnter choice: ";
		cin >> choice;
		if(choice == 1){
			cout << "Enter Account Number: ";
			cin >> account;
			cout << "Enter First Name: ";
			cin >> firstName;
			cout << "Enter Last Name: ";
			cin >> lastName;
			cout << "Enter Balance: ";
			cin >> bal;
			rec.writeRecord(account, firstName, lastName, bal);
			system("cls");
		} else if(choice == 2){
			rec.readRecord(account, firstName, lastName, bal);
			system("pause");
			system("cls");
		} else if(choice == 3){
			rec.searchRecord(account, firstName, lastName, bal);
			system("pause");
			system("cls");
		} else if(choice == 4){
			rec.editRecord(account, firstName, lastName, bal);
			system("pause");
			system("cls");
		} else if(choice == 5){
			rec.deleteRecord(account, firstName, lastName, bal);
			system("pause");
			system("cls");
		} else if(choice == 6){
			exit(1);
		}
	}
	
	return 0;
	
}
void Record::writeRecord(int accountNumber, char fname[255], char lname[255], double balance){
	
	accountNumber = accountNumber;
	fname = fname;
	lname = lname;
	balance = balance;
	
	ofstream outFile;
	outFile.open("Records.txt", fstream::app);
	outFile << accountNumber << endl;
	outFile << fname << endl;
	outFile << lname << endl;
	outFile << balance << endl << endl;
	outFile.close();
	
}
void Record::readRecord(int accountNumber, char fname[255], char lname[255], double balance){
	
	accountNumber = accountNumber;
	fname = fname;
	lname = lname;
	balance = balance;
	
	ifstream inFile;
	inFile.open("Records.txt");
	
	inFile >> accountNumber;
	inFile >> fname;
	inFile >> lname;
	inFile >> balance;
	
	while(!inFile.eof()){
		cout << "\nAccount Number: " << accountNumber;
		cout << "\nName: " << fname << " " << lname;
		cout << "\nBalance: " << balance << endl << endl;
		
		inFile >> accountNumber;
		inFile >> fname;
		inFile >> lname;
		inFile >> balance;
	}
	
	inFile.close();
	
}
void Record::searchRecord(int accountNumber, char fname[255], char lname[255], double balance){
	
	int search;
	bool checker = false;
	
	cout << "\nEnter Account Number: ";
	cin >> search;
	
	accountNumber = accountNumber;
	fname = fname;
	lname = lname;
	balance = balance;
	
	ifstream inFile;
	inFile.open("Records.txt");
	
	inFile >> accountNumber;
	inFile >> fname;
	inFile >> lname;
	inFile >> balance;
	
	while(!inFile.eof()){
		if(search == accountNumber){
			cout << "\nAccount Number: " << accountNumber;
			cout << "\nName: " << fname << " " << lname;
			cout << "\nBalance: " << balance << endl << endl;
			checker = true;
		}
		
		inFile >> accountNumber;
		inFile >> fname;
		inFile >> lname;
		inFile >> balance;
	}
	
	if(checker == false){
		cout << "\nDoes not exist.\n";
	}
	
	inFile.close();

}
void Record::editRecord(int accountNumber, char fname[255], char lname[255], double balance){
	
	int search, newAccountNumber;
	char newFname[255], newLname[255];
	double newBalance;
	bool checker = false;
	
	cout << "\nEnter Account Number: ";
	cin >> search;
	
	accountNumber = accountNumber;
	fname = fname;
	lname = lname;
	balance = balance;
	
	ifstream inFile;
	inFile.open("Records.txt");
	ofstream outFile;
	outFile.open("Records2.txt");
	
	inFile >> accountNumber;
	inFile >> fname;
	inFile >> lname;
	inFile >> balance;
	
	while(!inFile.eof()){
		
		if(accountNumber != search){		
			outFile << accountNumber << endl;
			outFile << fname << endl;
			outFile << lname << endl;
			outFile << balance << endl << endl;
		} else{
			cout << "\nEnter New Account Number: ";
			cin >> newAccountNumber;
			cout << "\nEnter New First Name: ";
			cin >> newFname;
			cout << "\nEnter New Last Name: ";
			cin >> newLname;
			cout << "\nEnter New Balance: ";
			cin >> newBalance;
			
			outFile << newAccountNumber << endl;
			outFile << newFname << endl;
			outFile << newLname << endl;
			outFile << newBalance << endl << endl;
			
			checker = true;
		}
		
		inFile >> accountNumber;
		inFile >> fname;
		inFile >> lname;
		inFile >> balance;
		
	}
	
	if(checker == false){
		cout << "\nDoes not exist.\n";
	}
	
	outFile.close();
	inFile.close();
	
	remove("Records.txt");
	rename("Records2.txt", "Records.txt");
	
}
void Record::deleteRecord(int accountNumber, char fname[255], char lname[255], double balance){
	
	int search;
	bool checker = false;
	
	cout << "\nEnter Account Number: ";
	cin >> search;
	
	accountNumber = accountNumber;
	fname = fname;
	lname = lname;
	balance = balance;
	
	ifstream inFile;
	inFile.open("Records.txt");
	ofstream outFile;
	outFile.open("Records2.txt");
	
	inFile >> accountNumber;
	inFile >> fname;
	inFile >> lname;
	inFile >> balance;
	
	while(!inFile.eof()){
		
		if(accountNumber != search){		
			outFile << accountNumber << endl;
			outFile << fname << endl;
			outFile << lname << endl;
			outFile << balance << endl << endl;
		} else{
			cout << "\nRecord deleted.\n";
			checker = true;
		}
		
		inFile >> accountNumber;
		inFile >> fname;
		inFile >> lname;
		inFile >> balance;
		
	}
	
	if(checker == false){
		cout << "\nDoes not exist.\n";
	}
	
	outFile.close();
	inFile.close();
	
	remove("Records.txt");
	rename("Records2.txt", "Records.txt");
	
}
