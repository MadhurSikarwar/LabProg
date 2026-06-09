#include <iostream>
#include <string>

using namespace std;

int shiftTable[256];

void generateShiftTable(string pattern) {
    int m = pattern.length();
    
    for (int i = 0; i < 256; i++) {
        shiftTable[i] = m;
    }

    for (int i = 0; i < m - 1; i++) {
        shiftTable[pattern[i]] = m - 1 - i;
    }
}

int horspoolSearch(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();

    if (m == 0) return 0;
    if (m > n) return -1;

    generateShiftTable(pattern);

    int i = m - 1;
    
    while (i < n) {
        int k = 0;
        
        while (k < m && pattern[m - 1 - k] == text[i - k]) {
            k++;
        }

        if (k == m) {
            return i - m + 1;
        } else {
            i += shiftTable[text[i]];
        }
    }

    return -1;
}

int main() {
    string text, pattern;

    cout << "Enter the text string: ";
    getline(cin, text);
    
    cout << "Enter the pattern to search: ";
    getline(cin, pattern);

    int matchIndex = horspoolSearch(text, pattern);

    if (matchIndex != -1) {
        cout << "\nPattern found! Starting at index: " << matchIndex << endl;
    } else {
        cout << "\nPattern not found in the text." << endl;
    }

    return 0;
}
