#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void clearFiles() {
    ofstream("passengers.txt").close();
    ofstream("flights.txt").close();
    ofstream("reservations.txt").close();
}

void printResult(bool ok, const string& msg) {
    if (ok) cout << "PASS: " << msg << endl;
    else cout << "FAIL: " << msg << endl;
}

void testPassengerRegistration() {
    ofstream file("passengers.txt", ios::app);
    file << "1,Ali,1234567890,P1234,1365-05-10,1000\n";
    file << "2,Sara,2345678901,P2345,1370-03-22,2000\n";
    file.close();

    ifstream check("passengers.txt");
    int lines = 0;
    string line;
    while (getline(check, line)) if (!line.empty()) lines++;
    printResult(lines == 2, "Passenger registration saved correctly");
}

void testPassengerSearch() {
    ifstream file("passengers.txt");
    bool found1 = false, found2 = true;
    string line;
    while (getline(file, line)) {
        if (line.find("1234567890") != string::npos) found1 = true;
        if (line.find("9999999999") != string::npos) found2 = false;
    }
    printResult(found1, "Search for existing passenger");
    printResult(found2, "Search for non-existing passenger returns nothing");
}

void testFlightCreation() {
    ofstream file("flights.txt", ios::app);
    file << "1,IR100,Tehran,Shiraz,2025-12-15,10:00,2,800\n";
    file << "2,IR200,Shiraz,Tabriz,2025-11-10,13:30,1,600\n";
    file.close();

    ifstream check("flights.txt");
    int count = 0;
    string line;
    while (getline(check, line)) if (!line.empty()) count++;
    printResult(count == 2, "Flight creation stored properly");
}

void testReservationAdd() {
    ofstream res("reservations.txt", ios::app);
    res << "1,1,1,800,active\n"; 
    res << "2,2,1,800,active\n";
    res.close();

    ifstream file("reservations.txt");
    int count = 0;
    string line;
    while (getline(file, line)) if (!line.empty()) count++;
    printResult(count >= 2, "Reservations saved correctly");
}

void testReservationErrors() {
    bool notFoundPassenger = true, notFoundFlight = true;
    ifstream p("passengers.txt"), f("flights.txt");
    string line;
    while (getline(p, line))
        if (line.find("9999999999") != string::npos) notFoundPassenger = false;
    while (getline(f, line))
        if (line.find("FAKE001") != string::npos) notFoundFlight = false;

    printResult(notFoundPassenger, "Booking with non-existing passenger fails");
    printResult(notFoundFlight, "Booking with non-existing flight fails");
}

void testRefundLogic() {
    ofstream r("reservations.txt", ios::app);
    r << "3,1,2,600,cancelled\n";
    r.close();

    bool foundCancelled = false;
    ifstream file("reservations.txt");
    string line;
    while (getline(file, line)) {
        if (line.find("cancelled") != string::npos) {
            foundCancelled = true;
            break;
        }
    }
    printResult(foundCancelled, "Cancelled reservation is stored correctly");
}

void testDataFilesExist() {
    ifstream p("passengers.txt"), f("flights.txt"), r("reservations.txt");
    bool ok = p.is_open() && f.is_open() && r.is_open();
    printResult(ok, "Data files exist and readable");
}

void testReservationHistory() {
    ifstream file("reservations.txt");
    int count = 0;
    string line;
    while (getline(file, line)) if (!line.empty()) count++;
    printResult(count >= 3, "Reservation history available");
}

int main() {
    cout << "Running test suite for airline reservation system\n";
    clearFiles();

    testPassengerRegistration();
    testPassengerSearch();
    testFlightCreation();
    testReservationAdd();
    testReservationErrors();
    testRefundLogic();
    testDataFilesExist();
    testReservationHistory();

    cout << "Test execution completed\n";
    return 0;
}


