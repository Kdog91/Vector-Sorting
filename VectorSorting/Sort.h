#pragma once
#include <vector>
#include "Bid.h"

void selectionSort(std::vector<Bid>& bids);
void quickSort(std::vector<Bid>& bids, int begin, int end);
int partition(std::vector<Bid>& bids, int begin, int end);





