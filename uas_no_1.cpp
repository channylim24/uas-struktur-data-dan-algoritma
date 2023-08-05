#include <iostream>
#include <string>
using namespace std;

struct Person {
    string name;
    string address;
};

// Function to swap two Person objects
void swapPersons(Person &a, Person &b) {
    Person temp = a;
    a = b;
    b = temp;
}

// Bubble Sort implementation
void bubbleSort(Person arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].name > arr[j + 1].name) {
                swapPersons(arr[j], arr[j + 1]);
            }
        }
    }
}

// Selection Sort implementation
void selectionSort(Person arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j].name < arr[min_idx].name) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swapPersons(arr[i], arr[min_idx]);
        }
    }
}

int main() {
    const int n = 8;
    Person people[n] = {
        {"Fahmi", "Jakarta"},
        {"Romi", "Solo"},
        {"Andri", "Jakarta"},
        {"Fadillah", "Banyuwangi"},
        {"Ruli", "Bandung"},
        {"Rudi", "Bali"},
        {"Dendi", "Purwokerto"},
        {"Zaki", "Madiun"}
    };

    // Sorting using Bubble Sort
    bubbleSort(people, n);

    cout << "Hasil Bubble Sort:\n";
    cout << "Nama\tAlamat\n";
    for (int i = 0; i < n; i++) {
        cout << people[i].name << "\t" << people[i].address << endl;
    }

    // Restore the initial order for next sorting
    Person reset[n] = {
        {"Fahmi", "Jakarta"},
        {"Romi", "Solo"},
        {"Andri", "Jakarta"},
        {"Fadillah", "Banyuwangi"},
        {"Ruli", "Bandung"},
        {"Rudi", "Bali"},
        {"Dendi", "Purwokerto"},
        {"Zaki", "Madiun"}
    };

    // Sorting using Selection Sort
    selectionSort(reset, n);

    cout << "\nHasil Selection Sort:\n";
    cout << "Nama\tAlamat\n";
    for (int i = 0; i < n; i++) {
        cout << reset[i].name << "\t" << reset[i].address << endl;
    }

    return 0;
}
