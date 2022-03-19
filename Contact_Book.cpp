#include <iostream>
#include <iomanip>
#define SIZE_NAME 50
#define SIZE_CONTACT 200
#define SIZE_EMAIL 50
#define SIZE_COUNTRY_CODE 10
#define SIZE_PHONE_NUMBER 15

using namespace std;

int ContactTable();
void AddContact(char FullName[][SIZE_NAME], char CountryCode[][SIZE_COUNTRY_CODE], char PhoneNumber[][SIZE_PHONE_NUMBER], char Email[][SIZE_EMAIL]);
void Sort();
void DisplayContact();
void DelletContact();
void SearchContact();

int main () {
    char FullName[SIZE_CONTACT][SIZE_NAME], Email [SIZE_CONTACT][SIZE_EMAIL], CountryCode[SIZE_CONTACT][SIZE_COUNTRY_CODE], PhoneNumber[SIZE_CONTACT][SIZE_PHONE_NUMBER];
    int operation;

    operation = ContactTable(); //the ContactTable returns the number of what the user choses.

    /* oprations 
        [1] AddConatct()
        [2] DisplayContact()
        [3] DeleteContact()
        [4] SearchContact()
        [6] Exit 
    
    */
    while(operation != 5) {
        switch (operation)
        {
        case 1:
            AddContact(FullName, CountryCode, PhoneNumber, Email);
            break;

        default:
            cerr << "NO operation YOU DEED!";
        }

        operation = ContactTable();
    }
    if(operation == 5) {
            cout << "Exiting......" << endl;
        }


    return 0;
}


// this is the menue table to chose the user and it returns what the user chose 

int ContactTable() {
    int chose;

    do {
        cout << "Choice to Select"<< endl;
        cout << "[1] Add Contact" << endl;
        cout << "[2] Display Contact" << endl;
        cout << "[3] Delete Contact" << endl;
        cout << "[4] Search Contact" << endl;
        cout << "[5] Exit Contact" << endl;
        cout << "      >>> ";
        cin >> chose;

        if (cin) {
            if (chose < 0 || chose > 5) {
                cerr << "Envalid Entery Please chose CARFULLY!\n";
            }
        }

    }while(chose < 0 || chose > 5);

    return chose;
}

// this is the Add contact operation to add the information in array 
// the parameter is constant pointer the array name is the constant in deed the second dimension is must be specifid.
// any alter of the arry in AddContact the efect is alos in the main function array.
void AddContact(char FullName[][SIZE_NAME], char CountryCode[][SIZE_COUNTRY_CODE], char PhoneNumber[][SIZE_PHONE_NUMBER], char Email[][SIZE_EMAIL]){ 
    static int index = 0; // once starting filling the index is increasing so saving the last index is must.

    // filling the data.

    cout << endl << "Adding contact....." << endl;
    cout << "Name: [ Pawlos Tesfaye ]";
    cin.ignore(); // clearing the buffer.
    cin.getline(FullName[index], SIZE_NAME - 1);  // SIZE_NAME - 1 (1) for the delimeter. 
    cout << "coutru code [ +(251) ] ";
    cin.getline(CountryCode[index], SIZE_COUNTRY_CODE - 1);
    cout << "Phone number [ 984796312 ] ";
    cin.getline(PhoneNumber[index], SIZE_PHONE_NUMBER - 1);
    cout << "Email adderes [ paulasca8462@gmail.com ]";
    cin.getline(Email[index], SIZE_EMAIL - 1);

    index++;

}