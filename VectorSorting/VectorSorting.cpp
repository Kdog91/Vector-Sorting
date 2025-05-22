// VectorSorting.cpp
#include "CSVparser.hpp"
#include "Bid.h"
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

int main(int argc, char* argv[]) {
    string csvPath, choice;
    vector<Bid> bids;
    clock_t ticks;

    while (choice != "9") {
        cout << "\nMenu:" << endl;
        cout << "  1. Load Bids" << endl;
        cout << "  2. Display All Bids" << endl;
        cout << "  3. Selection Sort All Bids" << endl;
        cout << "  4. QuickSort All Bids" << endl;
        cout << "  9. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == "1") {
            csvPath = "eBid_Monthly_Sales.csv";
            ticks = clock();
            bids = loadBids(csvPath);
            ticks = clock() - ticks;
            cout << bids.size() << " bids read" << endl;
            cout << "time: " << ticks << " clock ticks" << endl;
            cout << "time: " << ((float)ticks) / CLOCKS_PER_SEC << " seconds" << endl;
        }
        else if (choice == "2") {
            for (Bid bid : bids) {
                displayBid(bid);
            }
        }
        else if (choice == "3") {
            ticks = clock();
            selectionSort(bids);
            ticks = clock() - ticks;
            cout << "Selection Sort complete." << endl;
            cout << "time: " << ticks << " clock ticks" << endl;
            cout << "time: " << ((float)ticks) / CLOCKS_PER_SEC << " seconds" << endl;
        }
        else if (choice == "4") {
            ticks = clock();
            quickSort(bids, 0, bids.size() - 1);
            ticks = clock() - ticks;
            cout << "QuickSort complete." << endl;
            cout << "time: " << ticks << " clock ticks" << endl;
            cout << "time: " << ((float)ticks) / CLOCKS_PER_SEC << " seconds" << endl;
        }
    }

    cout << "Goodbye." << endl;
    return 0;
}
