#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream inputFile("Day-1-First.txt");

    if (!inputFile) {
        cout << "Error opening the file" << endl;
        return 1;
    }

    vector <int> a, b;
    int first, second;

    while(inputFile >> first >> second) {
        a.push_back(first);
        b.push_back(second);
    }

    inputFile.close();

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int sum = 0;

    for (int i=0; i<a.size(); i++) {
        sum += abs(a[i] - b[i]);
    }

    // cout << sum << endl;

    int similarityScore = 0;

    for (int i=0; i<a.size(); i++) {
        similarityScore += (a[i]*count(b.begin(), b.end(), a[i]));
    }

    cout << similarityScore << endl;

    return 0;
}