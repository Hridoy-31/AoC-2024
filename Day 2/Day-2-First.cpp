#include <bits/stdc++.h>

using namespace std;

int main() {
	int countSafe = 0;
		
	ifstream inputFile("Day-2-input.txt");
	
	string line;
	while(getline(inputFile, line)) {
		istringstream iss (line);
		int level;
		
		vector <int> a;
		
		while(iss >> level) {
			a.push_back(level);
		}
		
		bool only_dec = true;
		bool only_inc = true;
		bool ok = true;
		
		for (int j=0; j<a.size()-1; j++) {
			int diff = a[j+1] - a[j];
			
			if (diff > 0) {
				only_dec = false;
			}
			if (diff < 0) {
				only_inc = false;
			}
			if (!(1 <= abs(diff) and abs(diff) <= 3)) {
				
				ok = false;
				break;
			}
		}
		
		if (ok and (only_dec or only_inc)) {
			countSafe++;
		}	
	}
	
	cout << countSafe << endl;
	return 0;
}
