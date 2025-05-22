// Bid.h
#ifndef BID_H
#define BID_H

#include <string>
#include <vector>
using namespace std;

struct Bid {
    string bidId;
    string title;
    string fund;
    double amount;
};

vector<Bid> loadBids(string csvPath);
void displayBid(Bid bid);
void selectionSort(vector<Bid>& bids);
void quickSort(vector<Bid>& bids, int begin, int end);
int partition(vector<Bid>& bids, int begin, int end);

#endif

