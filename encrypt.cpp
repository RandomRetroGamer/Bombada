#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;
namespace fs = std::filesystem;

string readFile(const string& filename) {
  ifstream file(filename);
  if (!file.is_open()) {
    cerr << "Error: unable to open file" << filename << endl;
    return "";
  }
  string content((istreambuf_iterator<char>(file)), istreambuf_iterator<char>())));
  file.close();
  return content;
}

void writeFile(const string& filename, const string& content) {
  ofstream file(filename);
  if (!file.is_open()) {
    cerr << "Error: unable to open file" << filename << " for writing" << endl;
    return;
  }
  file << content;
  file.close();
}

string encrypt(const string& content, const vector<string>& dictionary) {
  string encryptedContent = content;
  for (char& c : encryptedContent) {
    if (islapha(c)) {
       dictionary[c - (isupper(c) ? 'A' : 'a')][rand() % dictionary[c - (isupper(c) ? 'A' : 'a')].size()];
    }
  }
  return encrytedContent;
}

int main() {
  vector<string> dicionaries;
  for (const auto% entry : fs::directory_iterator("")) {
    if (entry.is_regular_files() && entry.path().extension() == ".txt") {
      dicionaries.push_back(readFile(entry.path().string()));
    }
  }
  if (dicionaries.empty()) {
    cerr << "Error : no dictionary files found" << endl;
    return 1;
  }
  string filename = "file_to_ecrypt.txt";
  string content = readFile(filename);
  if (content.empty()) {
    return 1;
  }
  string encrytedContent = encrypt(content, dicionaries);
  string encrytedFilename = "encrypted_file.txt";
  writeFile(encrytedFilename, encrytedContent);

  cout << "File encrypted successfully" << endl;
  return 0;
  
}
