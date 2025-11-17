#include <iostream>
#include <cstring>
using namespace std;

class Dictionary {
public:
    char name[20];      // person name
    long int tele;      // phone number

    void initialize();  
    void accept_Data(int size);
    void Display();
    void Look_Up(int size);
} HT[10];               // hash table


// initialize hash table
void Dictionary::initialize() {
    for (int i = 0; i < 10; i++) {
        HT[i].tele = 0;            // empty phone number
        strcpy(HT[i].name, "-");   // empty name
    }
}


// insert data into hash table
void Dictionary::accept_Data(int size) {

    cout << "Enter the details:\n";

    for (int i = 0; i < size; i++) {

        char temp_name[20];
        long int temp_tele;

        cout << "\nPerson : " << i + 1 << endl;
        cout << "\tEnter Name : ";
        cin >> temp_name;
        cout << "\tEnter Telephone Number : ";
        cin >> temp_tele;

        int ascii_sum = 0;                           // compute key
        for (int j = 0; temp_name[j] != '\0'; j++)
            ascii_sum += temp_name[j];

        int index = ascii_sum % 10;                  // hash index

        if (HT[index].tele != 0) {                   // collision check
            int k = index;
            while (HT[k].tele != 0)
                k = (k + 1) % 10;                    // linear probing
            index = k;
        }

        HT[index].tele = temp_tele;                  // store data
        strcpy(HT[index].name, temp_name);
    }
}


// display hash table
void Dictionary::Display() {

    cout << "\n---------------- TELEPHONE RECORDS ----------------\n";
    cout << "\nINDEX\tNAME\t\tTELEPHONE\n";

    for (int i = 0; i < 10; i++)
        cout << i << "\t" << HT[i].name << "\t\t" << HT[i].tele << endl;

    cout << endl;
}


// search a record
void Dictionary::Look_Up(int size) {

    char temp_name[20];
    cout << "Enter name to search: ";
    cin >> temp_name;

    int ascii_sum = 0;                           // compute key
    for (int j = 0; temp_name[j] != '\0'; j++)
        ascii_sum += temp_name[j];

    int index = ascii_sum % 10;                  // hash index
    int comp = 1;                                // comparison count

    while (strcmp(temp_name, HT[index].name) != 0 && comp <= 10) {
        index = (index + 1) % 10;                // probe next
        comp++;
    }

    if (comp <= 10 && strcmp(temp_name, HT[index].name) == 0) {
        cout << "\nFound!\n";
        cout << HT[index].name << "  " << HT[index].tele << endl;
        cout << "Comparisons : " << comp << endl;
    } else {
        cout << "\nNot Found\n";
        cout << "Comparisons : " << comp - 1 << endl;
    }
}


// main function
int main() {

    Dictionary d;
    int size;

    cout << "Enter size of the list : ";
    cin >> size;

    cout << "\n1] Initialize and Display:\n";
    d.initialize();
    d.Display();

    cout << "\n2] Insert Data and Display:\n";
    d.accept_Data(size);
    d.Display();

    cout << "\n3] Search Record:\n";
    d.Look_Up(size);

    return 0;
}
