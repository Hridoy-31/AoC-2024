#include <bits/stdc++.h>

using namespace std;

bool isOk (vector <int> a) {
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
	
	return (ok and (only_dec or only_inc));
}

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
		
		bool anyOk = false;
		
		auto purge = [&] (int i) {
			vector <int> b = a;
			b.erase(b.begin() + i);
			if (isOk(b)) {
				anyOk = true;
			}
		}; 
		
		purge(0);
		
		for (int i=0; i<a.size()-1; i++) {
			int diff = a[i+1] - a[i];
			if (abs(diff)<1 or abs(diff)>3) {
				purge(i);
				purge(i+1);
				break;
			}
			
			if (i+2 < a.size()) {
				int diff2 = a[i+2] - a[i+1];
				if ((diff > 0) != (diff2 > 0)) {
					purge(i);
					purge(i+1);
					purge(i+2);
					break;
				}
			} 
		}
		
		if (anyOk) {
			countSafe++;
		}	
	}
	
	cout << countSafe << endl;
	return 0;
}
