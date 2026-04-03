#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
#ifndef FILEWRITER_H
#define FILEWRITER_H
class FileWriter {
public:
FileWriter() : fileName("Mydata.txt") {}
bool FileExists() {
    ifstream MyReadFile(fileName);
    if (MyReadFile.is_open()) {
        MyReadFile.close();
        return true;
    } else {
        cout << "File does not exist. Creating file." << endl;
        ofstream MyWriteFile(fileName);
        MyWriteFile.close();
        return false;
    }
}
void writeToFile(string text) {
    if (text.empty()) {
        cout << "No text provided." << endl;
        return;
    }
        ofstream MyWriteFile("Mydata.txt");
        if (FileExists() == false) {
            cout << "Unable to open file for writing." << endl;
            return;
        }
        MyWriteFile << text;
        MyWriteFile.close();
}
void readFile() {
    ifstream MyReadFile("Mydata.txt");
    string line;
    while (getline(MyReadFile, line)) {
        cout << line << endl;
    }
    MyReadFile.close();
}
void appendToFile(string text) {
    ifstream MyReadFile("Mydata.txt");
    stringstream buffer;
    buffer << MyReadFile.rdbuf();
    string oldContent = buffer.str();
    MyReadFile.close();
    ofstream MyWriteFile("Mydata.txt");
    if (MyWriteFile.is_open()) {
        MyWriteFile << text << oldContent;
        MyWriteFile.close();
    } else {
        cout << "Unable to open file for appending." << endl;
    }
}
void clearFile() {
    ofstream MyWriteFile("Mydata.txt");
    MyWriteFile << "";
    MyWriteFile.close();
}
private:
string fileName;
};
#endif // FILEWRITER_H



int main() {
FileWriter File;

bool go = 1;
int choice;
while (go == 1) {
cout << "Enter number corresponding to action: " << endl;
cout << "1. Write to file" << endl;
cout << "2. Append to file" << endl;
cout << "3. Read from file" << endl;
cout << "4. Clear file" << endl;
cout << "5. Exit" << endl;
cin >> choice;
switch (choice) {
    case 1: {
        string text;
        cout << "Enter text to write to file: ";
        cin.ignore();
        getline(cin, text);
        File.writeToFile(text);
        break;
    }
    case 2: {
        string text;
        cout << "Enter text to append to file: ";
        cin.ignore();
        getline(cin, text);
        File.appendToFile(text);
        break;
    }
    case 3: {
        File.readFile();
        break;
    }
    case 4: {
        File.clearFile();
        break;
    }
    case 5: {
        go = 0;
        break;
    }
    default: {
        cout << "Choose something else" << endl;
        break;
    }
}
}


return 0;
}