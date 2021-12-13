#include <iostream>
#include <vector>

int main() {
	int unsorted[] = {5,7,12,-5,-4,3,2,1,56,890,-1043};
	std::vector<bool> tracker(11, false);
	const int n = 5; //we want the top n largest numbers
	std::vector<int> topN;
	
	for(int i = 0; i < n; i++) {
		//an integer needs to store the maximum in the list.
		//but it cannot be one that has already been marked
		//as true in tracker.
		//so first we will loop until the first un-marked number.
		int unmarked_index = 0;
		for(; unmarked_index < tracker.size(); unmarked_index++) {
			if(!tracker[unmarked_index]) {
				//we found one that has not been visited yet
				break;
			}
		}
		//the max variable will hold the maximum after the next
		//loop finishes.  first we must initialize it
		//and the loop we just came from gives us the
		//index to initialize with.
		//also, we must keep track of where the max is found
		//so that it can be marked in tracker after the loop
		int max = unsorted[unmarked_index];
		int max_index = unmarked_index;
		for(int j = unmarked_index+1; j < tracker.size(); j++) {
			if(!tracker[j] && unsorted[j] > max) {
				//if j is not marked and j is > max
				max = unsorted[j];
				max_index = j;
			}
		}
		//time to mark max as used
		tracker[max_index] = true;
		//and add max to topN
		topN.push_back(max);
	}
	
	for(int i = 0; i < topN.size(); i++) {
		std::cout << topN[i];
		if(i != topN.size() - 1) std::cout << ", ";
	}
	std::cout << std::endl;
	
	return 0;
}