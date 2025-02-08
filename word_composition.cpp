#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <chrono>

using namespace std;

// Function to check if a word is a compounded word

bool isCompoundedWord(const string& word, unordered_set<string>& wordSet, unordered_map<string, bool>& memo) {
    if (memo.find(word) != memo.end()) return memo[word];
    
    for (int i = 1; i < word.length(); ++i) {
        string prefix = word.substr(0, i);
        string suffix = word.substr(i);
        
        if (wordSet.find(prefix) != wordSet.end() && 
            (wordSet.find(suffix) != wordSet.end() || isCompoundedWord(suffix, wordSet, memo))) {
            return memo[word] = true;
        }
    }
    return memo[word] = false;
}

// Function to find the longest and second-longest compounded words

void findLongestCompoundedWords(vector<string>& wordList) {
    auto start = chrono::high_resolution_clock::now();
    unordered_set<string> wordSet(wordList.begin(), wordList.end());
    unordered_map<string, bool> memo;
    
    sort(wordList.begin(), wordList.end(), [](const string& a, const string& b) {
        return a.length() > b.length();
    });
    
    string longest = "", 
    secondLongest = "";
    
    for (const string& word : wordList) {
        wordSet.erase(word);
        if (isCompoundedWord(word, wordSet, memo)) {
            if (longest.empty()) {
                longest = word;
            } else if (secondLongest.empty()) {
                secondLongest = word;
                break;
            }
        }
        wordSet.insert(word);
    }
    
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();
    
    cout << "\nResults:" << endl;
    cout << "Longest Compound Word: " << longest << endl;
    cout << "Second Longest Compound Word: " << secondLongest << endl;
    cout << "Time taken to process file: " << duration << " milliseconds\n" << endl;
}

// Function to read input words from a file
vector<string> readFile(const string& filename) {
    vector<string> words;
    ifstream file(filename);
    if (!file) {
        cerr << "Error: Could not open file " << filename << endl;
        exit(EXIT_FAILURE);
    }
    string word;
    while (getline(file, word)) {
        words.push_back(word);
    }
    return words;
}

int main() {
    string filename;
    cout << "Enter the input filename: ";
    cin >> filename;
    
    vector<string> words = readFile(filename);
    findLongestCompoundedWords(words);
    
    return 0;
}
