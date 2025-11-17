#include <iostream>
#include <iomanip>
using namespace std;

// Node structure for each seat
class theatre {
public:
    char seatno[5];      // Seat number (A1, A2, ...)
    bool isbooked;       // Booking status
    theatre *prev, *next;

    theatre() {
        isbooked = false;
        prev = next = NULL;
    }
};

// Ticket class handles seat creation & operations
class ticket {
public:
    // Create doubly linked list for one row
    theatre* create_seats(int seats, char rowLetter) {
        theatre *head = NULL, *temp = NULL, *newnode = NULL;

        for (int i = 1; i <= seats; i++) {
            newnode = new theatre;

            // Assign seat number (A1, A2, ...)
            sprintf(newnode->seatno, "%c%d", rowLetter, i);

            if (head == NULL) {
                head = newnode;
                temp = head;
            } else {
                temp->next = newnode;
                newnode->prev = temp;
                temp = newnode;
            }
        }
        return head;
    }

    // Display all seats of a row
    void show_seats(theatre* head) {
        theatre* temp = head;
        while (temp != NULL) {
            cout << setw(4) << temp->seatno << "(" 
                 << (temp->isbooked ? "X" : "O") << ")";
            temp = temp->next;
        }
        cout << endl;
    }

    // Book a specific seat
    void book_seat(theatre* head, string seat) {
        theatre* temp = head;
        while (temp != NULL) {
            if (seat == temp->seatno) {
                if (!temp->isbooked) {
                    temp->isbooked = true;
                    cout << "Seat " << seat << " booked successfully!" << endl;
                } else {
                    cout << "Seat " << seat << " is already booked!" << endl;
                }
                return;
            }
            temp = temp->next;
        }
        cout << "Seat " << seat << " not found!" << endl;
    }

    // Cancel booking of a seat
    void cancel_seat(theatre* head, string seat) {
        theatre* temp = head;
        while (temp != NULL) {
            if (seat == temp->seatno) {
                if (temp->isbooked) {
                    temp->isbooked = false;
                    cout << "Booking for " << seat << " cancelled!" << endl;
                } else {
                    cout << "Seat " << seat << " is not booked!" << endl;
                }
                return;
            }
            temp = temp->next;
        }
        cout << "Seat " << seat << " not found!" << endl;
    }
};

int main() {
    ticket t1;
    int rows, seats;

    cout << "How many rows in multiplex: ";
    cin >> rows;
    cout << "How many seats per row in multiplex: ";
    cin >> seats;

    theatre* arr[rows];

    // Create all rows
    for (int i = 0; i < rows; i++) {
        arr[i] = t1.create_seats(seats, 'A' + i);
    }

    // Menu
    int choice;
    string seat;
    do {
        cout << "\n1. Show Seats\n2. Book Seat\n3. Cancel Seat\n4. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            for (int i = 0; i < rows; i++) {
                cout << "Row " << char('A' + i) << ": ";
                t1.show_seats(arr[i]);
            }
            break;

        case 2:
            cout << "Enter seat to book (e.g. A1): ";
            cin >> seat;
            t1.book_seat(arr[seat[0] - 'A'], seat);
            break;

        case 3:
            cout << "Enter seat to cancel (e.g. A1): ";
            cin >> seat;
            t1.cancel_seat(arr[seat[0] - 'A'], seat);
            break;
        }

    } while (choice != 4);

    return 0;
}
