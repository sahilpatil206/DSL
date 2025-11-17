#include <iostream>
#include <cstring>
using namespace std;

class Browser {
public:
    int page_id;
    char Description[20];
    char Timestamp[20];
    Browser *next, *prev;      // DLL links

    Browser* add_pages(Browser* head);     // add multiple pages
    void Navigate_pages(Browser* head);    // display forward & backward
    void visit_pages(Browser* head);       // search page
    Browser* Delete_page(Browser* head);   // delete page
};

Browser* head = NULL;   // global head pointer


// ADD MULTIPLE PAGES
Browser* Browser::add_pages(Browser* head) {
    int n;
    cout << "Enter the number of pages to be added: ";
    cin >> n;

    Browser *last = head;   // pointer to last node

    if (last != NULL) {
        while (last->next != NULL) last = last->next;   // go to last node
    }

    for (int i = 1; i <= n; i++) {
        Browser* newNode = new Browser;   // create new node

        cout << "\nWEBPAGE " << i << ":\n";
        cout << "\tEnter Page ID: ";
        cin >> newNode->page_id;
        cout << "\tEnter Description: ";
        cin >> newNode->Description;
        cout << "\tEnter Timestamp: ";
        cin >> newNode->Timestamp;

        newNode->next = NULL;   // set next link
        newNode->prev = NULL;   // set prev link

        if (head == NULL) {     // first node case
            head = newNode;
            last = newNode;
        } else {
            last->next = newNode;   // attach new node
            newNode->prev = last;
            last = newNode;         // update last pointer
        }
    }
    return head;   // return updated head
}


// NAVIGATE DLL
void Browser::Navigate_pages(Browser* head) {
    if (head == NULL) {
        cout << "No pages available.\n";
        return;
    }

    Browser* curr = head;    // start at head

    cout << "From Top to Bottom:\n\t";
    while (curr->next != NULL) {   // forward traversal
        cout << curr->Description << " --> ";
        curr = curr->next;
    }
    cout << curr->Description << endl;

    cout << "\nFrom Bottom to Top:\n\t";
    while (curr->prev != NULL) {   // backward traversal
        cout << curr->Description << " --> ";
        curr = curr->prev;
    }
    cout << curr->Description << endl;
}


// SEARCH PAGE
void Browser::visit_pages(Browser* head) {
    if (head == NULL) {
        cout << "No pages to search.\n";
        return;
    }

    char des[20];
    cout << "Enter the web page to be searched: ";
    cin >> des;

    Browser* curr = head;   // start searching

    while (curr != NULL) {
        if (strcmp(curr->Description, des) == 0) {   // match found
            cout << "\nPage Found:\n";
            cout << "\tPage ID: " << curr->page_id << endl;
            cout << "\tDescription: " << curr->Description << endl;
            cout << "\tTimestamp: " << curr->Timestamp << endl;
            return;
        }
        curr = curr->next;   // move next
    }

    cout << "WEBPAGE NOT FOUND!\n";   // not found message
}


// DELETE PAGE
Browser* Browser::Delete_page(Browser* head) {
    if (head == NULL) {
        cout << "No pages to delete.\n";
        return head;
    }

    char des[20];
    cout << "Enter the web page to be deleted: ";
    cin >> des;

    Browser* curr = head;   // start from head

    while (curr != NULL) {

        if (strcmp(curr->Description, des) == 0) {   // match found

            if (curr == head) {   // delete first node
                head = curr->next;
                if (head != NULL) head->prev = NULL;
                delete curr;
                cout << "Deletion Successful!\n";
                return head;
            }

            if (curr->next == NULL) {   // delete last node
                curr->prev->next = NULL;
                delete curr;
                cout << "Deletion Successful!\n";
                return head;
            }

            curr->prev->next = curr->next;   // adjust previous link
            curr->next->prev = curr->prev;   // adjust next link
            delete curr;
            cout << "Deletion Successful!\n";
            return head;
        }

        curr = curr->next;   // move ahead
    }

    cout << "WEBPAGE NOT FOUND!!!\n";   // not found message
    return head;
}


// MAIN MENU
int main() {

    Browser obj;   // object to call functions
    int choice;

    do {
        cout << "\n--- Browser Menu ---\n";
        cout << "1. Add Pages\n";
        cout << "2. Visit Page\n";
        cout << "3. Navigate Pages\n";
        cout << "4. Delete Page\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) head = obj.add_pages(head);    // add pages
        else if (choice == 2) obj.visit_pages(head);    // search page
        else if (choice == 3) obj.Navigate_pages(head); // navigate DLL
        else if (choice == 4) head = obj.Delete_page(head);  // delete page
        else if (choice == 0) {
            cout << "Exiting program.\n";   // exit message
            return 0;
        }
        else cout << "Invalid choice!\n";   // invalid input

    } while (choice != 0);   // loop until exit

    return 0;
}
