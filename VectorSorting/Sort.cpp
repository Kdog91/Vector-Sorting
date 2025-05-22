#include "Bid.h"
#include <algorithm>

void selectionSort(vector<Bid>& bids) {
    for (unsigned int i = 0; i < bids.size(); ++i) {
        unsigned int minIndex = i;
        for (unsigned int j = i + 1; j < bids.size(); ++j) {
            if (bids[j].title < bids[minIndex].title) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(bids[i], bids[minIndex]);
        }
    }
}

int partition(vector<Bid>& bids, int begin, int end) {
    int low = begin;
    int high = end;
    Bid pivot = bids[(begin + end) / 2];

    while (true) {
        while (bids[low].title < pivot.title) ++low;
        while (bids[high].title > pivot.title) --high;
        if (low >= high) return high;
        swap(bids[low], bids[high]);
        ++low;
        --high;
    }
}

void quickSort(vector<Bid>& bids, int begin, int end) {
    if (begin >= end) return;
    int mid = partition(bids, begin, end);
    quickSort(bids, begin, mid);
    quickSort(bids, mid + 1, end);
}
