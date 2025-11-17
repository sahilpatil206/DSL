#include <iostream>
#include <string.h>
using namespace std;

// Class stores one item and supports search operations
class Search {
public:
    char item[20];
    int price;

    void Display();          // Shows list of items
    void linearSearch();     // Normal linear search
    void sentinelSearch();   // Sentinel search (optimized)
} List[5]; // Stores 5 grocery items globally


// ---------------- DISPLAY FUNCTION ----------------
void Search::Display() {
    cout << "\n1) List of Groceries:\n";
    cout << "\tItem Name\tPrice\n";

    // Print all items stored in List[]
    for (int i = 0; i < 5; i++) {
        cout << "\t" << List[i].item << "\t\t" << List[i].price << endl;
    }
    cout << "--------------------------------------------\n";
}



// ---------------- LINEAR SEARCH ----------------
void Search::linearSearch() {
    cout << "\n2) Linear Search\n";
    char name[20];
    cout << "Enter item name to search: ";
    cin >> name;

    int comp = 0;   // Comparison counter

    // Check each item one by one
    for (int i = 0; i < 5; i++) {
        comp++;

        // Compare input with each item name
        if (strcmp(name, List[i].item) == 0) {
            cout << "--------------------------------\n";
            cout << "\tItem Found!\n";
            cout << "\tPrice: " << List[i].price << endl;
            cout << "\tComparisons: " << comp << endl;
            cout << "--------------------------------\n";
            return;
        }
    }

    // If no match found
    cout << "--------------------------------\n";
    cout << "\tItem NOT Found!\n";
    cout << "\tComparisons: " << comp << endl;
    cout << "--------------------------------\n";
}



// ---------------- SENTINEL SEARCH ----------------
void Search::sentinelSearch() {
    cout << "\n3) Sentinel Search\n";

    char key[20];
    cout << "Enter item name to search: ";
    cin >> key;

    // Save last element (because we will overwrite it)
    char lastItem[20];
    strcpy(lastItem, List[4].item);
    int lastPrice = List[4].price;

    // Put sentinel at last position
    strcpy(List[4].item, key);

    int i = 0;

    // Loop guaranteed to stop because sentinel is at last index
    while (strcmp(List[i].item, key) != 0)
        i++;

    // Restore original last element
    strcpy(List[4].item, lastItem);
    List[4].price = lastPrice;

    cout << "--------------------------------\n";

    // If found before sentinel → actual match
    if (strcmp(List[i].item, key) == 0 && i < 4) {
        cout << "\tItem Found!\n";
        cout << "\tPrice: " << List[i].price << endl;
        cout << "\tComparisons: " << i + 1 << endl;
    }
    else {
        // Means only sentinel was matched → item not present
        cout << "\tItem NOT Found!\n";
        cout << "\tComparisons: " << i + 1 << endl;
    }

    cout << "--------------------------------\n";
}



// ---------------- MAIN ----------------
int main() {
    cout << "--- Program to Search Grocery Items ---\n\n";

    Search s;

    cout << "Enter ITEM NAME and PRICE:\n";

    // Input 5 grocery items
    for (int i = 0; i < 5; i++) {
        cout << "Enter item " << i + 1 << " name: ";
        cin >> List[i].item;
        cout << "Enter price: ";
        cin >> List[i].price;
    }

    s.Display();
    s.linearSearch();       // Perform linear search
    s.sentinelSearch();     // Perform sentinel search

    return 0;
}
