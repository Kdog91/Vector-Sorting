#include "Bid.h"
#include "CSVparser.hpp"
#include <iostream>
using namespace std;

void displayBid(Bid bid) {
    cout << bid.bidId << ": " << bid.title << " | "
        << bid.amount << " | " << bid.fund << endl;
}

vector<Bid> loadBids(string csvPath) {
    vector<Bid> bids;
    csv::Parser file = csv::Parser(csvPath);

    for (int i = 0; i < file.rowCount(); i++) {
        Bid bid;
        bid.bidId = file[i][0];
        bid.title = file[i][1];
        bid.fund = file[i][8];
        bid.amount = strtod(file[i][4].c_str(), nullptr);
        bids.push_back(bid);
    }

    return bids;
}

