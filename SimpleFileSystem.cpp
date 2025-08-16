#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
using namespace std;

// Function to create a new file
void createFile(const string &filename) {
    ofstream file(filename);
    if (!file) {
        cout << "Error: Could not create file!" << endl;
        return;
    }
    cout << "File '" << filename << "' created successfully!" << endl;
    file.close();
}

// Function to write data to file
void writeFile(const string &filename) {
    ofstream file(filename, ios::app);
    if (!file) {
        cout << "Error: File not found!" << endl;
        return;
    }
    string data;
    cout << "Enter text to write (end with ';' on a new line):" << endl;
    while (true) {
        getline(cin, data);
        if (data == ";") break;
        file << data << endl;
    }
    cout << "Data written successfully!" << endl;
    file.close();
}

// Function to read data from file
void readFile(const string &filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Error: File not found!" << endl;
        return;
    }
    string line;
    cout << "--- File Content ---" << endl;
    while (getline(file, line)) {
        cout << line << endl;
    }
    cout << "---------------------" << endl;
    file.close();
}

// Function to delete a file
void deleteFile(const string &filename) {
    if (remove(filename.c_str()) == 0) {
        cout << "File '" << filename << "' deleted successfully!" << endl;
    } else {
        cout << "Error: Could not delete file!" << endl;
    }
}

int main() {
    int choice;
    string filename;

    while (true) {
        cout << "\n--- Simple File System Simulation ---" << endl;
        cout << "1. Create File" << endl;
        cout << "2. Write to File" << endl;
        cout << "3. Read File" << endl;
        cout << "4. Delete File" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // clear input buffer

        switch (choice) {
            case 1:
                cout << "Enter filename to create: ";
                getline(cin, filename);
                createFile(filename);
                break;
            case 2:
                cout << "Enter filename to write: ";
                getline(cin, filename);
                writeFile(filename);
                break;
            case 3:
                cout << "Enter filename to read: ";
                getline(cin, filename);
                readFile(filename);
                break;
            case 4:
                cout << "Enter filename to delete: ";
                getline(cin, filename);
                deleteFile(filename);
                break;
            case 5:
                cout << "Exiting program..." << endl;
                return 0;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    }
    return 0;
}
