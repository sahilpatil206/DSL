/*===========================================================================
 Assignment No: 2
 Title : E-commerce Product Sorting
 Roll No : 21164
 Batch : G1

 An E-commerce website has products with:
 product_id, name, manufacturer, price, quality rating (out of 5).

 Display products:
 1) Increasing order of Product ID   (Bubble Sort)
 2) Increasing order of Product Price (Selection Sort)
 3) Decreasing order of Quality Rating (Insertion Sort)
===========================================================================*/

#include <iostream>
#include <cstring>
using namespace std;

class Products {
public:
    int id;
    char name[20];
    char make[20];
    int price;
    int quality;

    void accept_details(int size);
    void display_details(int size);
    void bubble_sort(int size);
    void selection_sort(int size);
    void insertion_sort(int size);
} List[50];


// ---------------- ACCEPT DETAILS ----------------
void Products::accept_details(int size)
{
    for (int i = 0; i < size; i++) {
        cout << "\nProduct " << i + 1 << ":\n";
        cout << "\tEnter Product Id: ";
        cin >> List[i].id;
        cout << "\tEnter Product Name: ";
        cin >> List[i].name;
        cout << "\tEnter Product Manufacturer: ";
        cin >> List[i].make;
        cout << "\tEnter Product Price: ";
        cin >> List[i].price;
        cout << "\tEnter Product Quality (1–5): ";
        cin >> List[i].quality;
    }
}


// ---------------- DISPLAY ----------------
void Products::display_details(int size)
{
    cout << "\nID\tName\tMaker\tPrice\tQuality\n";
    cout << "----------------------------------------------\n";

    for (int i = 0; i < size; i++) {
        cout << List[i].id << "\t"
             << List[i].name << "\t"
             << List[i].make << "\t"
             << List[i].price << "\t"
             << List[i].quality << endl;
    }
}


// ---------------- BUBBLE SORT (ID ↑) ----------------
void Products::bubble_sort(int size)
{
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (List[j].id > List[j + 1].id) {
                Products temp = List[j];
                List[j] = List[j + 1];
                List[j + 1] = temp;
            }
        }
        cout << "\nPASS " << i + 1 << ":\n";
        display_details(size);
    }
}


// ---------------- SELECTION SORT (Price ↑) ----------------
void Products::selection_sort(int size)
{
    for (int i = 0; i < size - 1; i++) {
        int min_index = i;

        for (int j = i + 1; j < size; j++) {
            if (List[j].price < List[min_index].price)
                min_index = j;
        }

        Products temp = List[i];
        List[i] = List[min_index];
        List[min_index] = temp;

        cout << "\nPASS " << i + 1 << ":\n";
        display_details(size);
    }
}


// ---------------- INSERTION SORT (Quality ↓) ----------------
void Products::insertion_sort(int size)
{
    for (int i = 1; i < size; i++) {
        Products key = List[i];
        int j = i - 1;

        // Descending order for quality
        while (j >= 0 && List[j].quality < key.quality) {
            List[j + 1] = List[j];
            j--;
        }

        List[j + 1] = key;

        cout << "\nPASS " << i << ":\n";
        display_details(size);
    }
}


// ---------------- MAIN ----------------
int main()
{
    Products p;
    int size;

    cout << "\n--------- Product Sorting Program ---------\n";
    cout << "Enter number of products: ";
    cin >> size;

    p.accept_details(size);

    cout << "\nA] Entered Product Details:";
    p.display_details(size);

    cout << "\nB] Bubble Sort (By Product ID - Increasing):";
    p.bubble_sort(size);

    cout << "\nC] Selection Sort (By Product Price - Increasing):";
    p.selection_sort(size);

    cout << "\nD] Insertion Sort (By Product Quality - Decreasing):";
    p.insertion_sort(size);

    cout << "\n\nFinal Sorted List:";
    p.display_details(size);

    return 0;
}
