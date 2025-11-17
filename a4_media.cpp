#include <iostream>
#include <cstring>
#include <unistd.h>
using namespace std;

class Media {
public:
    int id, duration;
    char title[20];
    Media* next;   // pointer to next song node

    Media* insert_songs(Media* head);
    void display_songs(Media* head);
    Media* delete_songs(Media* head);
    void count_songs(Media* head);
    void sort_songs_by_duration(Media* head);
    void Loop_Songs(Media* head);
};


// ---------------- INSERT SONGS ----------------
Media* Media::insert_songs(Media* head) {
    int cnt;
    cout << "Enter the number of songs: ";
    cin >> cnt;

    Media *last = head;

    if (head != NULL) {
        while (last->next != NULL)
            last = last->next;  // move last pointer to end
    }

    for (int i = 0; i < cnt; i++) {
        Media* newNode = new Media; // create new node

        cout << "Song " << i + 1 << ":\n";
        cout << "\tEnter song id: ";
        cin >> newNode->id;
        cout << "\tEnter song title: ";
        cin >> newNode->title;
        cout << "\tEnter song duration: ";
        cin >> newNode->duration;

        newNode->next = NULL; // new node next = null

        if (head == NULL) {
            head = newNode; // first node becomes head
            last = newNode;
        } else {
            last->next = newNode; // attach at end
            last = newNode;
        }
    }

    return head;
}


// ---------------- DISPLAY SONGS ----------------
void Media::display_songs(Media* head) {
    cout << "\n\tID\tTITLE\tDURATION";
    Media* temp = head;

    while (temp != NULL) {
        cout << "\n\t" << temp->id << "\t" << temp->title << "\t" << temp->duration;
        temp = temp->next; // move to next node
    }
    cout << endl;
}


// ---------------- COUNT SONGS ----------------
void Media::count_songs(Media* head) {
    int count = 0;
    Media* temp = head;

    while (temp != NULL) {
        count++; // increment counter
        temp = temp->next;
    }

    cout << "Total Songs: " << count << endl;
}


// ---------------- SORT BY DURATION ----------------
void Media::sort_songs_by_duration(Media* head) {
    if (head == NULL || head->next == NULL) return; // no need to sort

    Media *i, *j;

    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->duration > j->duration) {
                // swap IDs
                int t = i->id;
                i->id = j->id;
                j->id = t;

                // swap duration
                t = i->duration;
                i->duration = j->duration;
                j->duration = t;

                // swap title
                char tempTitle[20];
                strcpy(tempTitle, i->title);
                strcpy(i->title, j->title);
                strcpy(j->title, tempTitle);
            }
        }
    }
}


// ---------------- DELETE SONG ----------------
Media* Media::delete_songs(Media* head) {
    int delId;
    cout << "Enter the song ID to delete: ";
    cin >> delId;

    Media* curr = head;
    Media* prev = NULL;

    while (curr != NULL) {
        if (curr->id == delId) { // found node
            if (curr == head) {
                head = head->next; // delete first node
                delete curr;
                return head;
            }
            prev->next = curr->next; // bypass node
            delete curr;             // free node
            return head;
        }
        prev = curr;       // track previous
        curr = curr->next; // move forward
    }

    cout << "Song not found\n"; // ID not found
    return head;
}


// ---------------- LOOP SONGS ----------------
void Media::Loop_Songs(Media* head) {
    int times;
    cout << "How many times do you want to loop: ";
    cin >> times;

    while (times--) { // loop n times
        Media* temp = head;

        while (temp != NULL) {
            cout << "\tPlaying: " << temp->title << endl;
            sleep(2); // delay for effect
            temp = temp->next;
        }
        cout << endl;
    }
}


// ---------------- MAIN FUNCTION ----------------
int main() {
    Media* head = NULL;
    Media m;

    cout << "1] INSERT SONGS\n";
    head = m.insert_songs(head);

    cout << "\n2] DISPLAY SONGS\n";
    m.display_songs(head);

    cout << "\n3] COUNT SONGS\n";
    m.count_songs(head);

    cout << "\n4] SORT SONGS AND DISPLAY\n";
    m.sort_songs_by_duration(head);
    m.display_songs(head);

    cout << "\n5] DELETE SONG AND DISPLAY\n";
    head = m.delete_songs(head);
    m.display_songs(head);

    cout << "\n6] LOOP SONGS\n";
    m.Loop_Songs(head);

    return 0;
}
