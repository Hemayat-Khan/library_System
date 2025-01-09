#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
//ok
//ok 2
// Structure to hold patient details
struct Patient {
    int id;
    string name;
    int age;
    string disease;
    int roomNumber;
};
//hi
// Function to add a new patient
void addPatient(vector<Patient>& patients) {
    Patient newPatient;
    cout << "Enter Patient ID: ";
    cin >> newPatient.id;
    cout << "Enter Patient Name: ";
    cin.ignore(); // Clear the newline character
    getline(cin, newPatient.name);
    cout << "Enter Patient Age: ";
    cin >> newPatient.age;
    cout << "Enter Patient Disease: ";
    cin.ignore();
    getline(cin, newPatient.disease);
    cout << "Enter Room Number: ";
    cin >> newPatient.roomNumber;

    patients.push_back(newPatient);
    cout << "Patient added successfully.\n";
}

// Function to search for a patient by ID
void searchPatient(const vector<Patient>& patients) {
    int searchId;
    cout << "Enter Patient ID to search: ";
    cin >> searchId;

    for (const auto& patient : patients) {
        if (patient.id == searchId) {
            cout << "\nPatient Details:\n";
            cout << "ID: " << patient.id << "\n";
            cout << "Name: " << patient.name << "\n";
            cout << "Age: " << patient.age << "\n";
            cout << "Disease: " << patient.disease << "\n";
            cout << "Room Number: " << patient.roomNumber << "\n";
            return;
        }
    }
    cout << "Patient not found.\n";
}

// Function to display all admitted patients
void displayPatients(const vector<Patient>& patients) {
    if (patients.empty()) {
        cout << "No patients admitted.\n";
        return;
    }

    cout << "\nAll Admitted Patients:\n";
    for (const auto& patient : patients) {
        cout << "ID: " << patient.id << ", Name: " << patient.name
             << ", Age: " << patient.age << ", Disease: " << patient.disease
             << ", Room Number: " << patient.roomNumber << "\n";
    }
}

// Function to save patient records to a file
void saveToFile(const vector<Patient>& patients, const string& filename) {
    ofstream file(filename, ios::out);
    if (!file) {
        cout << "Error opening file for saving.\n";
        return;
    }

    for (const auto& patient : patients) {
        file << patient.id << "," << patient.name << "," << patient.age << ","
             << patient.disease << "," << patient.roomNumber << "\n";
    }
    file.close();
    cout << "Patient records saved successfully.\n";
}

// Function to load patient records from a file
void loadFromFile(vector<Patient>& patients, const string& filename) {
    ifstream file(filename, ios::in);
    if (!file) {
        cout << "Error opening file for loading.\n";
        return;
    }

    Patient temp;
    string line;
    while (getline(file, line)) {
        size_t pos = 0;
        string token;
        vector<string> tokens;

        // Parse the line by comma
        while ((pos = line.find(',')) != string::npos) {
            token = line.substr(0, pos);
            tokens.push_back(token);
            line.erase(0, pos + 1);
        }
        tokens.push_back(line); // Add the last token

        // Assign values to the structure
        temp.id = stoi(tokens[0]);
        temp.name = tokens[1];
        temp.age = stoi(tokens[2]);
        temp.disease = tokens[3];
        temp.roomNumber = stoi(tokens[4]);

        patients.push_back(temp);
    }
    file.close();
    cout << "Patient records loaded successfully.\n";
}

// Main menu for the hospital management system
void hospitalManagementSystem() {
    vector<Patient> patients;
    const string filename = "patient_records.txt";

    // Load records at the start
    loadFromFile(patients, filename);

    int choice;
    do {
        cout << "\nHospital Patient Management System\n";
        cout << "1. Add New Patient\n";
        cout << "2. Search Patient by ID\n";
        cout << "3. Display All Patients\n";
        cout << "4. Save Records to File\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addPatient(patients);
                break;
            case 2:
                searchPatient(patients);
                break;
            case 3:
                displayPatients(patients);
                break;
            case 4:
                saveToFile(patients, filename);
                break;
            case 5:
                cout << "Exiting the system. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);
}

int main() {
    hospitalManagementSystem();
    return 0;
}
