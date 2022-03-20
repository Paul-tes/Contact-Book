#include <iostream>
#include <iomanip>
#include <cstring>
#define SIZE_NAME 30
#define SIZE_CONTACT 200
#define SIZE_EMAIL 40
#define SIZE_COUNTRY_CODE 5
#define SIZE_PHONE_NUMBER 15

using namespace std;

int ContactTable();
void AddContact(char FullName[][SIZE_NAME], char CountryCode[][SIZE_COUNTRY_CODE], char PhoneNumber[][SIZE_PHONE_NUMBER], char Email[][SIZE_EMAIL], int &Maxindex);
void Sort(char FullName[][SIZE_NAME], char CountryCode[][SIZE_COUNTRY_CODE], char PhoneNumber[][SIZE_PHONE_NUMBER], char Email[][SIZE_EMAIL], int &Maxindex);
void DisplayContact(char FullName[][SIZE_NAME], char CountryCode[][SIZE_COUNTRY_CODE], char PhoneNumber[][SIZE_PHONE_NUMBER], char Email[][SIZE_EMAIL], int &Maxindex);
void DelletContact(char FullName[][SIZE_NAME], char CountryCode[][SIZE_COUNTRY_CODE], char PhoneNumber[][SIZE_PHONE_NUMBER], char Email[][SIZE_EMAIL], int &Maxindex);
void SearchContact();

int main () {
    char FullName[SIZE_CONTACT][SIZE_NAME], Email [SIZE_CONTACT][SIZE_EMAIL], CountryCode[SIZE_CONTACT][SIZE_COUNTRY_CODE], PhoneNumber[SIZE_CONTACT][SIZE_PHONE_NUMBER];
    int operation = 0, NumberOfContact = 0;

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
            AddContact(FullName, CountryCode, PhoneNumber, Email, NumberOfContact);
            break;
        case 2:
            DisplayContact(FullName, CountryCode, PhoneNumber, Email, NumberOfContact);
            break;
        case 3:
            DelletContact(FullName, CountryCode, PhoneNumber, Email, NumberOfContact);
        // default:
        //     cerr << "NO operation YOU DEED!";
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
         if (cin) { // if thire is somthing in the buffer check out
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
void AddContact(char FullName[][SIZE_NAME], char CountryCode[][SIZE_COUNTRY_CODE], char PhoneNumber[][SIZE_PHONE_NUMBER], char Email[][SIZE_EMAIL], int &Maxindex){ 
    // filling the data.
    //&Maxindex is the allians of NumberOfContact
    cout << endl << "Adding contact....." << endl;
    cout << "Name: [ Pawlos Tesfaye ]";
    cin.ignore(); // clearing the buffer.
    cin.getline(FullName[Maxindex], SIZE_NAME - 1);  // SIZE_NAME - 1 (1) for the delimeter. 
    cout << "coutru code [ +251 ] ";
    cin.getline(CountryCode[Maxindex], SIZE_COUNTRY_CODE - 1);
    cout << "Phone number [ 984796312 ] ";
    cin.getline(PhoneNumber[Maxindex], SIZE_PHONE_NUMBER - 1);
    cout << "Email adderes [ paulasca8462@gmail.com ]";
    cin.getline(Email[Maxindex], SIZE_EMAIL - 1);
    Maxindex++;

}


//SORT CONTACT
void Sort(char FullName[][SIZE_NAME], char CountryCode[][SIZE_COUNTRY_CODE], char PhoneNumber[][SIZE_PHONE_NUMBER], char Email[][SIZE_EMAIL], int &Maxindex) {
    char TempName[SIZE_NAME], TempCountyCode[SIZE_COUNTRY_CODE], TempPhondNumber[SIZE_PHONE_NUMBER], TempEmail[SIZE_EMAIL];

    for (int i = 0; i < Maxindex; i++) { // Maxindex is the stack since that it is the last number of the contact
        for (int j = i + 1; j < Maxindex - 1;  j++) {
            if (FullName[i] != " " && FullName[j] != " ") {
                if (strcmp(FullName[i], FullName[j]) > 0) { // if FullName[i] is greater than FullName[j] need to swap (case sensetive strcmpi is not working on linux on windos machine you can use it to compute sith out case sensetive).
                    //swap Name
                    strcpy(TempName, FullName[j]);
                    strcpy(FullName[i], FullName[j]);
                    strcpy(FullName[j], TempName);

                    //swap Country Cod
                    strcpy(TempCountyCode, CountryCode[i]);
                    strcpy(CountryCode[i], CountryCode[j]);
                    strcpy(CountryCode[j], TempCountyCode);

                    //swap number
                    strcpy(TempPhondNumber, PhoneNumber[i]);
                    strcpy(PhoneNumber[i], PhoneNumber[j]);
                    strcpy(PhoneNumber[j], TempPhondNumber);

                    //swap Email
                    strcpy(TempEmail, Email[i]);
                    strcpy(Email[i], Email[j]);
                    strcpy(Email[j], TempEmail);
                }
            }
        }
    }

}

// DISPLAY CONTACT

void DisplayContact(char FullName[][SIZE_NAME], char CountryCode[][SIZE_COUNTRY_CODE], char PhoneNumber[][SIZE_PHONE_NUMBER], char Email[][SIZE_EMAIL], int &Maxindex){
    char empty[] = "";
    int count = 0; // counter variable
    //Sort(FullName, CountryCode, PhoneNumber, Email, Maxindex); // always before display we need to sort it.

    cout << left << setw(80) << setfill('=') <<  "" << endl << setfill(' ');
    cout << setw(5) << "No" << setw(30) << "Name" << setw(25) << "Phone" << "Email" << endl;
    cout << left << setw(80) << setfill('-') <<  "" << endl << setfill(' ');

    for (int i = 0; i < Maxindex; i++) {
        if(strcmp(FullName[i], empty) != 0) { // if the index is empty it was delleted so no need to display
            count ++;
            cout << left <<setw(5) << count << setw(30) << FullName[i] << setw(5) << CountryCode[i] << setw(19) << PhoneNumber[i] << Email[i]<<endl;
        }
    }
    if (!count) {
        cout << "NO CONTACT FOUND!!!\nPlease Select [1] To Add \n";
    }
}

//DELETE CONTACT

void DelletContact(char FullName[][SIZE_NAME], char CountryCode[][SIZE_COUNTRY_CODE], char PhoneNumber[][SIZE_PHONE_NUMBER], char Email[][SIZE_EMAIL], int &Maxindex){
    char DeleteName[SIZE_NAME], empty[] = "";
    bool found = false;
    cout << "Enter The name You want to Delete: ";
    cin.ignore();
    cin.getline(DeleteName, SIZE_NAME - 1);

    for (int i = 0; i < Maxindex; i++) {
        if (strcmp(DeleteName, FullName[i]) == 0) { // if the name to delete is find in the indexes.
            //removing the data coresponding to that name follows.
            strcpy(FullName[i], empty); 
            strcpy(CountryCode[i], empty);
            strcpy(PhoneNumber[i], empty);
            strcpy(Email[i], empty);
            found = true;
            break; // once got the name should be stop the itration.
        }
    }
    if (found) {
        cout << DeleteName << " is Successfully DELETED ..... \n";
    }else {
        cout << DeleteName << " is not EXIST in Contact\n";
    }
}
