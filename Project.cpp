#include<iostream> 
#include<fstream> 
#include<string> 
#include <ctime>
#include<cctype> 
#include <sstream>
using namespace  std ; 

void PrintPassengerLine(const string& line) {
    int p1 = line.find(',');
    int p2 = line.find(',', p1 + 1);
    int p3 = line.find(',', p2 + 1);
    int p4 = line.find(',', p3 + 1);
    int p5 = line.find(',', p4 + 1);

    string id = line.substr(0, p1);
    string name = line.substr(p1 + 1, p2 - p1 - 1);
    string nationalCode = line.substr(p2 + 1, p3 - p2 - 1);
    string passport = line.substr(p3 + 1, p4 - p3 - 1);
    string birth = line.substr(p4 + 1, p5 - p4 - 1);
    string balance = line.substr(p5 + 1);

    cout << "ID : " << id << endl<< "Name : " << name <<endl<< "National Code : " << nationalCode<<endl
         << "Passport : " << passport<<endl << "Nationality : " << birth <<endl<< "Balance : " << balance << endl;
}

void PrintFlightLine(const string& line) {
    int p1 = line.find(',');
    int p2 = line.find(',', p1 + 1);
    int p3 = line.find(',', p2 + 1);
    int p4 = line.find(',', p3 + 1);
    int p5 = line.find(',', p4 + 1);
    int p6 = line.find(',', p5 + 1);
    int p7 = line.find(',', p6 + 1);

    string id = line.substr(0, p1);
    string number = line.substr(p1 + 1, p2 - p1 - 1);
    string origin = line.substr(p2 + 1, p3 - p2 - 1);
    string dest = line.substr(p3 + 1, p4 - p3 - 1);
    string date = line.substr(p4 + 1, p5 - p4 - 1);
    string time = line.substr(p5 + 1, p6 - p5 - 1);
    string capacity = line.substr(p6 + 1, p7 - p6 - 1);
    string price = line.substr(p7 + 1);

    cout << "ID : " << id << endl
         << "Flight Number : " << number << endl
         << "Origin : " << origin << endl
         << "Destination : " << dest << endl
         << "Date : " << date << endl
         << "Time : " << time << endl
         << "Capacity : " << capacity << endl
         << "Price : " << price << endl ;
        
}

void PrintReservationLine(const string& line) {
    int p1 = line.find(',');
    int p2 = line.find(',', p1 + 1);
    int p3 = line.find(',', p2 + 1);
    int p4 = line.find(',', p3 + 1);

    string id = line.substr(0, p1);
    string pid = line.substr(p1 + 1, p2 - p1 - 1);
    string fid = line.substr(p2 + 1, p3 - p2 - 1);
    string amount = line.substr(p3 + 1, p4 - p3 - 1);
    string status = line.substr(p4 + 1);

    cout << "Reservation ID : " << id << endl
         << "Passenger ID : " << pid << endl
         << "Flight ID : " << fid << endl
         << "Paid Amount : " << amount << endl
         << "Status : " << status << endl ;
       
} 

int CalculateDaysUntilFlight(const string& flightDate) {
    int fYear = stoi(flightDate.substr(0, 4));
    int fMonth = stoi(flightDate.substr(5, 2));
    int fDay = stoi(flightDate.substr(8, 2));

    time_t now = time(0);
    tm* now_tm = localtime(&now);
    int cYear = now_tm->tm_year + 1900;
    int cMonth = now_tm->tm_mon + 1;
    int cDay = now_tm->tm_mday;

    tm flight_tm = {};
    flight_tm.tm_year = fYear - 1900;
    flight_tm.tm_mon = fMonth - 1;
    flight_tm.tm_mday = fDay;

    time_t flight_time = mktime(&flight_tm);
    time_t current_time = mktime(now_tm);

    double seconds = difftime(flight_time, current_time);
    int days = seconds / (60 * 60 * 24);

    return days;
}

void createfile(const string &filename) { 

ifstream file(filename) ;

if (!file) { 

    ofstream file(filename) ;

}
} 

int SafeInputInt() {
    int x;
    while (true) {
        cin >> x;
        if (!cin.fail()) break;

        cout << " Invalid input. Please enter a valid number: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }
    cin.ignore();
    return x;
}

int SafeInputInRange(int min, int max) {
    int x;
    while (true) {
        x = SafeInputInt();
        if (x >= min && x <= max) break;

        cout << "Please enter a number between " << min << " and " << max << ": ";
    }
    return x;
}


class passenger{

private:

    int id;
    string name;
    string nationalcode;
    string passportnumber;
    string nationality;
    double balance;

public:

    passenger(int id, string name, string nationalcode,
              string passportnumber, string nationality, double balance)
        : id(id), name(name), nationalcode(nationalcode),
          passportnumber(passportnumber), nationality(nationality), balance(balance) {} 

          int getId()   { return id; }
    string getName()   { return name; }
    string getNationalCode()   { return nationalcode; }
    string getPassportNumber()   { return passportnumber; }
    string getNationality()   { return nationality; }
    double getBalance()   { return balance; }

    void setBalance(double newb)  
    {
         balance = newb;
         }
string ToCSV() {
        return to_string(id) + "," + name + "," + nationalcode + "," + passportnumber + "," + nationality + "," + to_string(balance)+ ",active" ;
    }

};

void AddPassenger(){ 

string name ; 
string nationalcode ;
string passportnumber ; 
string nationality ;
double balance ; 
 
cout <<" Please Enter Your Informaitiions : " ; 
cout << endl ; 
cout << " Full Name : " ; 
getline(cin, name) ; 
cout << " National Code  : " ;
getline(cin, nationalcode) ;
cout << " Passport Number : " ; 
getline(cin, passportnumber) ;
cout << " Nationality : " ; 
getline(cin , nationality) ;
cout << " Balance : " ; 
 cin>>balance ; 
cin.ignore(); 

int id = 1;
    ifstream file("passengers.txt");
    string line;
    while (getline(file, line)) {
        if (!line.empty()) 
         id++;
    }
    file.close();
 
passenger p(id, name, nationalcode, passportnumber, nationality, balance);

   
    ofstream out("passengers.txt", ios::app);
    out << p.ToCSV() << endl;
    out.close();

cout << " Passenger Added Successfully " << endl ; 

} 

void showallpassengers() { 
 
    ifstream file("passengers.txt")  ;

    if (!file.is_open()){ 

         cout <<" The File Coud Not Be Opened " << endl ;
return ;
    } 
string line ; 

cout << " List Of All Passengers :" ;
cout << endl << "_______________________________ " << endl<<endl ;
   
cout << " | ID , Name , National Code , Passport Number , Nationallity , Balance , state | " <<endl<<endl ;

while (getline(file, line)) {   
        if (!line.empty())  {    
            if (line.rfind(",deleted") == string::npos)
            cout << line << endl; 

        }
    }

    file.close(); 
}

void SearchPassengerById(int ID) { 

    ifstream file("passengers.txt");
    if (!file.is_open()) {
        cout << " The File Coud Not Be Opened \n";
        return;
    }

    string line;
    bool found = false;

    while (getline(file, line)) {
        if (!line.empty()) {
            int foundid = line.find(',');
            int Id = stoi(line.substr(0, foundid));

            if (Id == ID && line.rfind(",deleted") == string::npos)
 {
                cout << "Passenger Founded !" <<endl ; 
                PrintPassengerLine(line);
                found = true;
                break;
            }
        }
    }

    if (!found) {
        cout << "There Is No Passenger With The Given Inoformation !!\n";
    }

    file.close();
} 

void SearchPassengerByNationalCode(const string& Ncode) {
    ifstream file("passengers.txt");
    if (!file.is_open()) {
        cout << " The File Coud Not Be Opened \n";
        return;
    }

    string line;
    bool found = false;

    while (getline(file, line)) {
        if (!line.empty()) {
            int first = line.find(',');         
            int second = line.find(',', first + 1);  
            int third = line.find(',', second + 1); 

            string nationalcode = line.substr(second + 1, third - second - 1);

            if (nationalcode == Ncode&& line.rfind(",deleted") == string::npos) {
                cout << "Passenger Founded !" <<endl; 
                PrintPassengerLine(line);
                found = true;
                break;
            }
        }
    }

    if (!found) {
        cout << "There Is No Passenger With The Given Inoformation !!\n";
    }

    file.close();
}

void SearchPassengerByPassport(const string& Pass) {
    ifstream file("passengers.txt");
    if (!file.is_open()) {
        cout << " The File Coud Not Be Opened \n";
        return;
    }

    string line;
    bool found = false;

    while (getline(file, line)) {
        if (!line.empty()) {
            size_t first = line.find(',');
            size_t second = line.find(',', first + 1);
            size_t third = line.find(',', second + 1);
            size_t fourth = line.find(',', third + 1);

            string passport = line.substr(third + 1, fourth - third - 1);

            if (passport == Pass&& line.rfind(",deleted") == string::npos) {
                cout << "Passenger Founded !" <<endl;
                PrintPassengerLine(line);
                found = true;
                break;
            }
        }
    }

    if (!found) {
        cout << "There Is No Passenger With The Given Inoformation !!\n";;
    }

    file.close();
}

void SearchPassengerByName(const string& nam) {
    ifstream file("passengers.txt");
    if (!file.is_open()) {
        cout << " The File Coud Not Be Opened \n";
        return;
    }

    string line;
    bool found = false;

    while (getline(file, line)) {
        if (!line.empty()) {
            size_t first = line.find(',');    
               size_t second = line.find(',', first + 1);
            string name = line.substr(first + 1, second - first - 1);

            if (name.find(nam) != string::npos&& line.rfind(",deleted") == string::npos) { 
                cout << endl ;
                cout << "Passenger Founded !" <<endl;
                PrintPassengerLine(line);
                found = true;
            }
        }
    }

    if (!found) {
        cout << "There Is No Passenger With The Given Inoformation !!\n";;
    }

    file.close(); 
} 

void EditPassengerInfo(int id) {
    ifstream file("passengers.txt");
    ofstream temp("temp.txt");  

    if (!file.is_open() || !temp.is_open()) {
        cout << "The File Could Not Be Opened \n";
        return;
    }

    string line;
    bool found = false;

    while (getline(file, line)) {
        if (line.empty()) continue;

        int cama = line.find(',');         
        string ids = line.substr(0, cama); 
        int IDn = stoi(ids);            

        if (IDn == id) {
            int p1 = cama;
            int p2 = line.find(',', p1 + 1);
            int p3 = line.find(',', p2 + 1);
            int p4 = line.find(',', p3 + 1);
            int p5 = line.find(',', p4 + 1);

            string name = line.substr(p1 + 1, p2 - p1 - 1);
            string nationalCode = line.substr(p2 + 1, p3 - p2 - 1);
            string passportNumber = line.substr(p3 + 1, p4 - p3 - 1);
            string nationality = line.substr(p4 + 1, p5 - p4 - 1);
            string balance = line.substr(p5 + 1);

            cout << "\nWhich Field Do You Want To Edit?\n";
            cout << "1. Name\n";
            cout << "2. National Code\n";
            cout << "3. Passport Number\n";
            cout << "4. Nationality \n";
            cout << "5. Balance\n";
            cout << "6. Edit All\n";
            cout << "Your Choice: ";
            int choice;
            cin >> choice;
            cin.ignore();

            if (choice == 1 || choice == 6) {
                cout << "Please Enter The New Name: ";
                getline(cin, name);
            }
            if (choice == 2 || choice == 6) {
                cout << "Please Enter The New National Code: ";
                getline(cin, nationalCode);
            }
            if (choice == 3 || choice == 6) {
                cout << "Please Enter The New Passport Number: ";
                getline(cin, passportNumber);
            }
            if (choice == 4 || choice == 6) {
                cout << "Please Enter The New Birth Date: ";
                getline(cin, nationality);
            }
            if (choice == 5 || choice == 6) {
                cout << "Please Enter The New Balance: ";
                getline(cin, balance);
            }

            string newLine = to_string(IDn) + "," + name + "," + nationalCode + "," + passportNumber + "," + nationality + "," + balance;
            temp << newLine << endl;
            found = true;
        } else {
            temp << line << endl;
        }
    }

    file.close();
    temp.close();

    if (found) {
        remove("passengers.txt");
        rename("temp.txt", "passengers.txt");
        cout << "Informations Updated Successfully\n";
    } else {
        cout << "There Is No Passenger With The Given ID !!\n";
        remove("temp.txt");
    }
} 
void SoftDeletePassengerById() {
    cout << "Enter Passenger ID to delete: ";
    int id = SafeInputInt();

    ifstream fin("passengers.txt");
    ofstream fout("temp.txt");

    string line;
    bool found = false;

    while (getline(fin, line)) {
        if (line.empty()) continue;

        int pid = stoi(line.substr(0, line.find(',')));

        if (pid == id) {
            found = true;
            int lastComma = line.rfind(',');
            string updated = line.substr(0, lastComma) + ",deleted";
            fout << updated << endl;
        } else {
            fout << line << endl;
        }
    }

    fin.close();
    fout.close();
    remove("passengers.txt");
    rename("temp.txt", "passengers.txt");

    if (found)
        cout << " Passenger deleted.\n";
    else
        cout << " Passenger not found.\n";
}

void PassengerMenu() {
    int choice;
    do {
        cout << "\n---- Passenger Management ----\n";
        cout << "1. Add New Passenger\n";
        cout << "2. Show All Passengers\n";
        cout << "3. Search Passenger\n";
        cout << "4. Edit Passenger Information\n"; 
        cout << "5. Delete Passenger\n";
        cout << "0. Back To Main Menu\n";
        cout << "------------------------\n";
        cout << "Enter Your Choice: ";
        cin >> choice;  
        if (cin.fail()) {
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "Invalid input! Please enter a number.\n";
    continue;
}



        cin.ignore();

        if (choice == 1) {
            AddPassenger();
        } else if (choice == 2) {
            showallpassengers();
        } else if (choice == 3) {
            int schoice;
            cout << "\n--- Search Passenger ---\n";
            cout << "1. By ID\n";
            cout << "2. By Name\n";
            cout << "3. By National Code\n";
            cout << "4. By Passport Number\n";
            cout << "Enter Your Choice: ";
            cin >> schoice;  
            
            if (cin.fail()) {
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "Invalid input! Please enter a number.\n";
    continue;
}

            cin.ignore();

            if (schoice == 1) {
                int id;
                cout << "Enter ID: ";
                cin >> id;
                SearchPassengerById(id);
            }
             else if (schoice == 2) {
                string name;
                cout << "Enter Name: ";
                getline(cin, name);
                SearchPassengerByName(name);
            } 
            else if (schoice == 3) {
                string code;
                cout << "Enter National Code: ";
                getline(cin, code);
                SearchPassengerByNationalCode(code);
            } 
            else if (schoice == 4) {
                string pass;
                cout << "Enter Passport Number: ";
                getline(cin, pass);
                SearchPassengerByPassport(pass);
            }
        } 
        else if (choice == 4) {
            int id;
            cout << "Enter ID: ";
            cin >> id; 
            cin.ignore();
            EditPassengerInfo(id);
        } 
        else if (choice == 5) {
            SoftDeletePassengerById();
        }

    } while (choice != 0);
} 



class Flight {
private:
    int id;
    string flightnumber;
    string origin;
    string destination;
    string date;
    string time;
    int capacity;
    double price;

public:
    Flight(int id, string flightnumber, string origin, string destination,
           string date, string time, int capacity, double price)
        : id(id), flightnumber(flightnumber), origin(origin),
          destination(destination), date(date), time(time),
          capacity(capacity), price(price) {}

    string ToCSV() {
        return to_string(id) + "," + flightnumber + "," + origin + "," + destination + "," +
               date + "," + time + "," + to_string(capacity) + "," + to_string(price)+ ",active";
    }

    int GetId()  { 
         return id; 
        }
    string GetFlightNumber() { 
         return flightnumber;
         }
    string GetOrigin() {
         return origin; 
        }
    string GetDestination() {
         return destination; 
        }
    string GetDate() {
         return date; 
        }
    string GetTime() {
         return time; 
        }
    int GetCapacity() { 
        return capacity; 
    }
    double GetPrice() {
         return price; 
        }
};
void AddNewFlight() { 

    cout << "Please Enter The Flight Information : " << endl;
    cout << "-----------------------------------" << endl;
    string flightNumber ;
    string origin  ;
    string destination;
    int year;
    int month ;
    int day ;
    int hour ;
    int minute ;
    int capacity;
    double price;

    cout << "Enter Flight Number: ";
    getline(cin, flightNumber);

    cout << "Enter Origin: ";
    getline(cin, origin);

    cout << "Enter Destination: ";
    getline(cin, destination);

    cout << "Enter Year: ";
    year = SafeInputInt();
    cout << "Enter Month: ";
    month = SafeInputInt();
    cout << "Enter Day: ";
    day = SafeInputInt();
    cout << "Enter Hour: ";
    hour = SafeInputInt();
    cout << "Enter Minute: ";
    minute = SafeInputInt();

    cout << "Enter Capacity: ";
    capacity = SafeInputInt();
    cout << "Enter Price: "; 
    cin >> price;
   cin.ignore();

    string date = to_string(year) + "-" + to_string(month) + "-" + to_string(day);
    string time = to_string(hour) + ":" + to_string(minute);

    int id = 1;
    string line;
    ifstream file("flights.txt");
    while (getline(file, line)) {
        if (!line.empty()) id++;
    }
    file.close();

    Flight flight(id, flightNumber, origin, destination, date, time, capacity, price);

    ofstream out("flights.txt", ios::app);
    out << flight.ToCSV() << endl;
    out.close();

    cout << "Flight Added Successfully.\n";
}
 
void ShowAllFlights() { 

    ifstream file("flights.txt");
    if (!file.is_open()) {
        cout << "The File Could Not Be Opened \n";
        return;
    }

    string line;
    cout << "\n--- List of Flights ---\n";  
    cout <<"-------------------------------" << endl<<endl ;
    cout << "| ID , Flight Number , Origin , Destination , Date , Time , Capacity , Price , State | " << endl<<endl ;
    while (getline(file, line)) {
        if (!line.empty()) { 
            if (line.rfind(",deleted") == string::npos)
            cout << line << endl;
        }
    }
    file.close();
}
void SearchFlightById(int sid) {
    ifstream file("flights.txt"); 
    if (!file.is_open()) {
        cout << " The File Coud Not Be Opened \n";
        return;
    }
    string line;
    bool found = false;

    while (getline(file, line)) {
        if (!line.empty()) {
            int pos = line.find(',');
            int id = stoi(line.substr(0, pos));
            if (id == sid && line.rfind(",deleted") == string::npos) {
                cout << "Flight Found: " << endl; 
                PrintFlightLine(line);
                found = true;
                break;
            }
        }
    }

    if (!found) {
        cout << "Flight Not Found\n";
    }
}
void SearchFlightByNumber(const string& snum) {
    ifstream file("flights.txt"); 
    if (!file.is_open()) {
        cout << " The File Coud Not Be Opened \n";
        return;
    }
    string line;
    bool found = false;

    while (getline(file, line)) {
        if (!line.empty()) {
            int p1 = line.find(',');
            int p2 = line.find(',', p1 + 1);
            string flightNumber = line.substr(p1 + 1, p2 - p1 - 1);

            if (flightNumber == snum && line.rfind(",deleted") == string::npos) {
                cout << "Flight Found: " << endl;
                PrintFlightLine(line);
                found = true;
                break;
            }
        }
    }

    if (!found) {
        cout << "Flight Not Found\n";
    }
} 


void SearchFlightByOrigion(const string & sorigin) { 

    ifstream file ("flights.txt") ;  
    if (!file.is_open()) { 
        cout << " The File Coud Not Be Opened \n";
        return;
    } 

    
    string line ;
    bool found = false ; 
    while (getline(file, line )) { 
        if (!line.empty()) {  
            int p1 = line.find(',');
        int p2 = line.find(',', p1 + 1);
        int p3 = line.find(',', p2 + 1);
        string origin = line.substr(p2 + 1, p3 - p2 - 1);
       if (origin == sorigin && line.rfind(",deleted") == string::npos) {
            cout << "Flight Found: " <<  endl;
            PrintFlightLine(line);

            found = true;
        }

        }
    } 
    if (!found) {
        cout << "Flight Not Found\n";
    }
}
void SearchFlightByDestination(const string & sdes) { 

    ifstream file ("flights.txt") ;  
    if (!file.is_open()) { 
        cout << " The File Coud Not Be Opened \n";
        return;
    } 

    
    string line ;
    bool found = false ;  

    while (getline(file, line )) { 
        if (!line.empty()) {  
            int p1 = line.find(',');
        int p2 = line.find(',', p1 + 1);
        int p3 = line.find(',', p2 + 1);
        int p4 = line.find(',', p3 + 1);
        string destination = line.substr(p3 + 1, p4 - p3 - 1); 

       if (destination == sdes && line.rfind(",deleted") == string::npos ) {
            cout << "Flight Found: " <<  endl;
            PrintFlightLine(line);
            found = true;
        }

        }
    } 
    if (!found) {
        cout << "Flight Not Found\n";
    }
} 
void SearchFlightByDate() {
    int year, month, day;
    cout << "Enter Year: ";
    year = SafeInputInt();
    cout << "Enter Month: ";
    month = SafeInputInt();
    cout << "Enter Day: ";
    day = SafeInputInt();

    string searchDate = to_string(year) + "-" + to_string(month) + "-" + to_string(day);

    ifstream file("flights.txt");
    if (!file.is_open()) {
        cout << "Could Not Open flights.txt\n";
        return;
    }

    string line;
    bool found = false;

    while (getline(file, line)) {
        if (line.empty()) continue;

        size_t p1 = line.find(',');
        size_t p2 = line.find(',', p1 + 1);
        size_t p3 = line.find(',', p2 + 1);
        size_t p4 = line.find(',', p3 + 1);
        size_t p5 = line.find(',', p4 + 1);
        string date = line.substr(p4 + 1, p5 - p4 - 1);

        if (date == searchDate && line.rfind(",deleted") == string::npos) {
            cout << "Flight Found: " <<  endl;
            PrintFlightLine(line);
            found = true;
        }
    }

    file.close();

    if (!found) {
        cout << "Flight Not Found\n";
    }
}
 void SoftDeleteFlightById() {
    cout << "Enter Flight ID to delete: ";
    int id = SafeInputInt();

    ifstream fin("flights.txt");
    ofstream fout("temp.txt");

    string line;
    bool found = false;

    while (getline(fin, line)) {
        if (line.empty()) continue;

        int fid = stoi(line.substr(0, line.find(',')));

        if (fid == id) {
            found = true;
            int lastComma = line.rfind(',');
            string updated = line.substr(0, lastComma) + ",deleted";
            fout << updated << endl;
        } else {
            fout << line << endl;
        }
    }

    fin.close();
    fout.close();
    remove("flights.txt");
    rename("temp.txt", "flights.txt");

    if (found)
        cout << "Flight deleted (soft delete).\n";
    else
        cout << " Flight not found.\n";
}

void FlightMenu() {
    int choice;
    do {
        cout << "\n---- Flight Management ----\n";
        cout << "1. Add New Flight\n";
        cout << "2. Show All Flights\n";
        cout << "3. Search Flight\n"; 
        cout << "4. Delete Flight\n";
        cout << "0. Back To Main Menu\n";
        cout << "------------------------\n";
        cout << "Enter Your Choice: ";
        cin >> choice;  
        
        if (cin.fail()) {
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "Invalid input! Please enter a number.\n";
    continue;
}

        cin.ignore();

        if (choice == 1) {
            AddNewFlight();
        }  
        else if (choice == 2) {
            ShowAllFlights();
        }
         else if (choice == 3) {
            int fchoice;
            cout << "\n--- Search Flight ---\n";
            cout << "1. By ID\n";
            cout << "2. By Flight Number\n";
            cout << "3. By Origin\n";
            cout << "4. By Destination\n";
            cout << "5. By Date\n";
            cout << "Enter Your Choice: ";
            cin >> fchoice;  
            
            if (cin.fail()) {
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "Invalid input! Please enter a number.\n";
    continue;
}

            cin.ignore();

            if (fchoice == 1) {
                int id;
                cout << "Enter ID: ";
                cin >> id;
                SearchFlightById(id);
            } else if (fchoice == 2) {
                string flightNumber;
                cout << "Enter Flight Number: ";
                getline(cin, flightNumber);
                SearchFlightByNumber(flightNumber);
            } else if (fchoice == 3) {
                string origin;
                cout << "Enter Origin: ";
                getline(cin, origin);
                SearchFlightByOrigion(origin);
            } else if (fchoice == 4) {
                string destination;
                cout << "Enter Destination: ";
                getline(cin, destination);
                SearchFlightByDestination(destination);
            } else if (fchoice == 5) {
                SearchFlightByDate();
            }
        }
        else if (choice == 4) {
            SoftDeleteFlightById();
        }
    } while (choice != 0);
}  

class Reservation {
private: 

    int id;
    int passenger_id;
    int flight_id;
    double amount_paid;
    string status;

public:
    Reservation(int id, int passenger_id, int flight_id, double amount_paid, string status)
        : id(id), passenger_id(passenger_id), flight_id(flight_id),
          amount_paid(amount_paid), status(status) {}

    string ToCSV() {
        return to_string(id) + "," + to_string(passenger_id) + "," +
               to_string(flight_id) + "," + to_string(amount_paid) + "," + status;
    }

    int GetId() { 
         return id; 
         }
    int GetPassengerId() {
         return passenger_id;
         }
    int GetFlightId() {
         return flight_id;
         }
    double GetTotalPrice() {
         return amount_paid;
         }
    string GetStatus() {
         return status;
         }
};

void AddReservation() {
    int passenger_id; 
    int  flight_id; 
    cout << "Please Enter The Reservation Information : " << endl;
    cout << "-----------------------------------" << endl;
    cout << "Enter Passenger ID: ";
    
    passenger_id = SafeInputInt();
    cout << "Enter Flight ID: ";
    flight_id = SafeInputInt();
    cout << endl ;

    bool passengerFound = false, flightFound = false; 

    string fline ; 
    string pline ;
    int capacity = 0;
    double price = 0.0;
    double balance = 0.0;

    ifstream pfile("passengers.txt"); 
    if (!pfile.is_open()) {
        cout << "Could Not Open passengers.txt\n";
        return;
    } 
string pname, pcode, passport, birth;
    
    while (getline(pfile, pline)) {
        if (pline.empty()) continue;
        int pid = stoi(pline.substr(0, pline.find(',')));
        if (pid == passenger_id) {
            passengerFound = true; 
            int p1 = pline.find(',');
            int p2 = pline.find(',', p1 + 1);
            int p3 = pline.find(',', p2 + 1);
            int p4 = pline.find(',', p3 + 1);
            int p5 = pline.find(',', p4 + 1);
            int p6 = pline.find(',', p5 + 1);

            pname = pline.substr(p1 + 1, p2 - p1 - 1);
            pcode = pline.substr(p2 + 1, p3 - p2 - 1);
            passport = pline.substr(p3 + 1, p4 - p3 - 1);
            birth = pline.substr(p4 + 1, p5 - p4 - 1);
            balance = stod(pline.substr(p5 + 1, p6 - p5 - 1));
            break;
        }
    }
    pfile.close();

    
    ifstream ffile("flights.txt"); 
    if (!ffile.is_open()) {
        cout << "Could Not Open flights.txt\n";
        return;
    } 
    string flightNumber, origin, destination, date, time;
    int fyear, fmonth, fday;

    while (getline(ffile, fline)) { 

        if (fline.empty()) continue;
        int fid = stoi(fline.substr(0,fline.find(',')));
        if (fid == flight_id) {
            flightFound = true;

            
            int p1 = fline.find(',');
            int p2 = fline.find(',', p1 + 1);
            int p3 = fline.find(',', p2 + 1);
            int p4 = fline.find(',', p3 + 1);
            int p5 = fline.find(',', p4 + 1);
            int p6 = fline.find(',', p5 + 1);
            int p7 = fline.find(',', p6 + 1);
            int p8 = fline.find(',', p7 + 1);

            flightNumber = fline.substr(p1 + 1, p2 - p1 - 1);
            origin = fline.substr(p2 + 1, p3 - p2 - 1);
            destination = fline.substr(p3 + 1, p4 - p3 - 1);
            date = fline.substr(p4 + 1, p5 - p4 - 1);
            time = fline.substr(p5 + 1, p6 - p5 - 1);
            capacity = stoi(fline.substr(p6 + 1, p7 - p6 - 1));
            price = stod(fline.substr(p7 + 1, p8 - p7 - 1));

            sscanf(date.c_str(), "%d-%d-%d", &fyear, &fmonth, &fday);
            break;
        }
    }
    ffile.close();

    if (!passengerFound || !flightFound) {
        cout << "Invalid Passenger ID or Flight ID\n";
        return;
    }

    if (capacity <= 0) {
        cout << "No Seats Available\n";
        return;
    }
if (balance < price) {
        cout << "Your account balance is insufficient for the reservation.\n";
        return;
    } 

    time_t now = ::time(0);
    tm* now_tm = localtime(&now);
    int cyear = now_tm->tm_year + 1900;
    int cmonth = now_tm->tm_mon + 1;
    int cday = now_tm->tm_mday;

    if (fyear < cyear || (fyear == cyear && fmonth < cmonth) ||
        (fyear == cyear && fmonth == cmonth && fday < cday)) {
        cout << "Cannot reserve past flights.\n";
        return;
    }  

    cout << "\nPassenger:\n";
    cout << "Name: " << pname << "\nNational Code: " << pcode << "\nPassport: " << passport
     << "\nNationality: " << birth << "\nBalance: " << balance << endl;
    cout << "\nFlight:\n";
    cout << "Number: " << flightNumber << "\nFrom: " << origin << " To " << destination
         << "\nDate: " << date << " Time: " << time << "\nPrice: " << price << endl;
cout << "\nConfirm Reservation? (y/n): ";
    char confirm; 
    while (true) {
    cin >> confirm;
    confirm = tolower(confirm);
    if (confirm == 'y' || confirm == 'n') break;
    cout << " Please enter y or n: ";
}
if (confirm == 'n') {
    cout << "Reservation Cancelled\n";
    return;
}

     
    if (confirm != 'y' && confirm != 'Y') {
        cout << "Reservation Cancelled\n";
        return; }
    
 
     ifstream in("passengers.txt");
    ofstream outp("temp.txt");
    while (getline(in, pline)) {
        if (pline.empty()) continue;
        int pid = stoi(pline.substr(0, pline.find(',')));
        if (pid == passenger_id) {
            int lastComma = pline.rfind(',');
            pline = pline.substr(0, lastComma) + "," + to_string(balance - price);
        }
        outp << pline << endl;
    } 
    in.close();
    outp.close();
    remove("passengers.txt");
    rename("temp.txt", "passengers.txt");

    int id = 1;
    string rline;
    ifstream rfile("reservations.txt");
    while (getline(rfile, rline)) {
        if (!rline.empty()) id++;
    }
    rfile.close();

    
    Reservation r(id, passenger_id, flight_id, price, "active");
    ofstream out("reservations.txt", ios::app);
    out << r.ToCSV() << endl;
    out.close();

    
    ifstream fread("flights.txt");
    ofstream ftemp("temp2.txt");
    while (getline(fread, fline)) {
        if (fline.empty()) continue;
        int fid = stoi(fline.substr(0, fline.find(',')));
        if (fid == flight_id) {
            int lastComma = fline.rfind(',');
            string newLine = fline.substr(0, lastComma);
            int newCap = capacity - 1;
            newLine = newLine.substr(0, newLine.rfind(',')) + "," + to_string(newCap) + "," + fline.substr(lastComma + 1);
            ftemp << newLine << endl;
        } else {
            ftemp << fline << endl;
        }
    }
    fread.close();
    ftemp.close();
    remove("flights.txt");
    rename("temp2.txt", "flights.txt");

    cout << "Reservation Added Successfully\n";
}  


void ShowAllReservations() {
    ifstream file("reservations.txt");
    if (!file.is_open()) {
        cout << "Could Not Open reservations.txt\n";
        return;
    }

    string line;
    cout << "\n--- List of Reservations ---\n"; 
    cout << "-----------------------------------" << endl<<endl;
    cout << " | ID , Passenger ID , Flight ID , Amount Paid , Status | " << endl<<endl ;
    while (getline(file, line)) {
        if (line.empty()) continue;
        if (line.find(",canceled") == string::npos) {
            cout << line << endl;
        }
    }
    file.close();
} 

 void SearchReservationById(int sid) {
    ifstream file("reservations.txt");
    if (!file.is_open()) {
        cout << "The File Coud Not Be Opened\n";
        return;
    }

    string line;
    bool found = false;

    while (getline(file, line)) {
        if (line.empty()) continue;

        int pos = line.find(',');
        int rid = stoi(line.substr(0, pos));

        if (rid == sid) {
            cout << "Reservation Found: " << endl;
            PrintReservationLine(line);
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Reservation Not Found\n";
    }

    file.close();
}
 
 void CancelReservationById() {
    int sid;
    cout << "Enter Reservation ID to Cancel: ";
    sid = SafeInputInt();
    cin.ignore();

    ifstream rfile("reservations.txt");
    if (!rfile.is_open()) {
        cout << "Could not open reservations.txt\n";
        return;
    }

    string line;
    bool found = false;
    string reservationLine;
    while (getline(rfile, line)) {
        if (line.empty()) continue;
        int id = stoi(line.substr(0, line.find(',')));
        if (id == sid) {
            found = true;
            reservationLine = line; 
            break;
        }
    }
    rfile.close();

    if (!found) {
        cout << " ReservationNotFound: No reservation with ID " << sid << "\n";
        return;
    }

    int p1 = reservationLine.find(',');
    int p2 = reservationLine.find(',', p1 + 1);
    int p3 = reservationLine.find(',', p2 + 1);
    int p4 = reservationLine.find(',', p3 + 1);

    int passenger_id = stoi(reservationLine.substr(p1 + 1, p2 - p1 - 1));
    int flight_id = stoi(reservationLine.substr(p2 + 1, p3 - p2 - 1));
    double paid = stod(reservationLine.substr(p3 + 1, p4 - p3 - 1));
    string status = reservationLine.substr(p4 + 1);

    cout << "\n Reservation Found:\n";
    cout << "Reservation ID: " << sid << endl;
    cout << "Passenger ID: " << passenger_id << endl;
    cout << "Flight ID: " << flight_id << endl;
    cout << "Paid Amount: " << paid << endl;
    cout << "Status: " << status << endl;
string passengerLine;
    ifstream pfile("passengers.txt");
    if (pfile.is_open()) {
        while (getline(pfile, line)) {
            if (line.empty()) continue;
            int pid = stoi(line.substr(0, line.find(',')));
            if (pid == passenger_id) {
                cout << "\n-- Passenger Info --\n"; 
                passengerLine = line;
                PrintPassengerLine(line);
                break;
            }
        }
        pfile.close();
    }
string flightLine;
    ifstream ffile("flights.txt");
    if (ffile.is_open()) {
        while (getline(ffile, line)) {
            if (line.empty()) continue;
            int fid = stoi(line.substr(0, line.find(',')));
            if (fid == flight_id) {
                cout << "\n-- Flight Info --\n";
                flightLine = line;
                PrintFlightLine(line);  
                break;
            }
        }
        ffile.close();
    }

    char confirm;
    cout << "\n Are you sure you want to cancel this reservation? (y/n): ";
    cin >> confirm; 
    cin.ignore(); 
    if (tolower(confirm) != 'y') {
        cout << " Process Terminated !.\n";
        return;
    } 
   int commaCount = 0;
    int start = 0, end = 0;
    for (int i = 0; i < flightLine.length(); ++i) {
        if (flightLine[i] == ',') {
            commaCount++;
            if (commaCount == 5) start = i + 1;
            if (commaCount == 6) {
                end = i;
                break;
            }
        }
    }
    string flightDate = flightLine.substr(start, end - start);

    int daysRemaining = CalculateDaysUntilFlight(flightDate);

    int refundPercent = 0;
    if (daysRemaining > 48) {
        refundPercent = 90;
    } else if (daysRemaining >= 24) {
        refundPercent = 50;
    } else if (daysRemaining >= 0) {
        refundPercent = 0;
    } else {
        cout << " This flight has already occurred.\n";
        return;
    }

    if (refundPercent == 0) {
        cout << " RefundNotAllowed: Less than 24 hours remaining. Refund not possible.\n";
        return;
    }

    double refundAmount = (refundPercent / 100.0) * paid;  

 cout << "\n Refund Completed Successfully ! \n";
    cout << "Days Remaining Until Flight: " << daysRemaining << " days\n";
    cout << "Refund Percentage: " << refundPercent << "%\n";
   cout  << refundAmount << "  has been refunded to your wallet.\n";

ifstream resIn("reservations.txt");
ofstream resOut("temp_res.txt");

while (getline(resIn, line)) {
    if (line.empty()) continue;

    int rid = stoi(line.substr(0, line.find(',')));

    if (rid == sid) {
        int lastComma = line.rfind(',');
        string updated = line.substr(0, lastComma) + ",cancelled";
        resOut << updated << endl;
    } else {
        resOut << line << endl;
    }
}
resIn.close();
resOut.close();
remove("reservations.txt");
rename("temp_res.txt", "reservations.txt"); 

ifstream passIn("passengers.txt");
ofstream passOut("temp_pass.txt");

while (getline(passIn, line)) {
    if (line.empty()) continue;

    int pid = stoi(line.substr(0, line.find(',')));

    if (pid == passenger_id) {
        
        int p1 = line.find(',');
        int p2 = line.find(',', p1 + 1);
        int p3 = line.find(',', p2 + 1);
        int p4 = line.find(',', p3 + 1);
        int p5 = line.find(',', p4 + 1);
        int p6 = line.find(',', p5 + 1);

        string bef = line.substr(0, p5 + 1);
        double oldBalance = stod(line.substr(p5 + 1, p6 - p5 - 1));
        double newBalance = oldBalance + refundAmount;

        string after = line.substr(p6);
        passOut << bef << to_string(newBalance) << "," << after << endl;
    } else {
        passOut << line << endl;
    }
}
passIn.close();
passOut.close();
remove("passengers.txt");
rename("temp_pass.txt", "passengers.txt");

ifstream flightIn("flights.txt");
ofstream flightOut("temp_flight.txt");

while (getline(flightIn, line)) {
    if (line.empty()) continue;

    int fid = stoi(line.substr(0, line.find(',')));

    if (fid == flight_id) {
        int lc = line.rfind(',');
        string beforeLast = line.substr(0, lc);
        int secondLastComma = beforeLast.rfind(',');
        string beforeCapacity = beforeLast.substr(0, secondLastComma);
        string price = line.substr(lc + 1);

        int oldCap = stoi(beforeLast.substr(secondLastComma + 1));
        int newCap = oldCap + 1;

        string updated = beforeCapacity + "," + to_string(newCap) + "," + price;
        flightOut << updated << endl;
    } else {
        flightOut << line << endl;
    }
}
flightIn.close();
flightOut.close();
remove("flights.txt");
rename("temp_flight.txt", "flights.txt");

}
void ReservationMenu() {   
int ch ;

    do {
cout << "\n Reservation Managment"<<endl ; 
cout << "---------------------------\n" ; 
cout << " 1 : Add New Reservation " <<endl ; 
cout << " 2 : Search Reservation By ID " << endl ;
cout << " 3 : Show All Reservation " << endl ;   
cout << " 4 : Cancel Reservation By ID " << endl ;
cout << " 0 : Back To Main Menu " << endl ;
cout << "---------------------------\n" ;
cout << "Your Choice : " ; 
cin >> ch ;  
if (cin.fail()) {
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "Invalid input! Please enter a number.\n";
    continue;
}
cin.ignore() ; 
if (ch==1)  
AddReservation() ; 
else if (ch==2) { 
  int id ; 
    cout << "Enter The ID " << endl ; 
    cin >> id ; 
    cin.ignore() ; 
   SearchReservationById(id) ;  
}
else if (ch==3) 
ShowAllReservations() ; 
else if (ch==4) { 
   CancelReservationById() ;  
}
else if (ch==0) {
    cout << "Back To Main Menu" << endl ;
}
 else {
    cout << "Invalid Choice! Please try again.\n";
}
 } while (ch!=0) ; 
}
void AllReservationsReport() { 

    ifstream file("reservations.txt");
    if (!file.is_open()) {
        cout << "Could not open reservations.txt\n";
        return;
    }

    string line, temp = "";
    cout << "\nAll Reservations:\n";

    while (getline(file, line)) {
        if (line.empty()) continue;
        PrintReservationLine(line);   
        cout <<"____________________________"<<endl ;
        temp += line + "\n";
    }
    file.close();

    if (temp.empty()) {
        cout << "No reservations found.\n";
        return;
    }

    cout << "\nDo you want to save this report to CSV? (y/n): ";
    char c;
    cin >> c;
    cin.ignore();
    if (tolower(c) == 'y') {
        ofstream out("report_all_reservations.csv");
        out << temp;
        out.close();
        cout << "Report saved in report_all_reservations.csv\n";
    } else {
        cout << "Report not saved.\n";
    }
}


void UpcomingReservationsReport() {
    ifstream rfile("reservations.txt");
    ifstream ffile("flights.txt");

    if (!rfile.is_open() || !ffile.is_open()) {
        cout << "Could not open reservation or flight file.\n";
        return;
    }

    time_t now = time(0);
    tm* now_tm = localtime(&now);
    int cyear = now_tm->tm_year + 1900;
    int cmonth = now_tm->tm_mon + 1;
    int cday = now_tm->tm_mday;

    string rline, fline, output = "";
    cout << "\nUpcoming Reservations:\n";

    while (getline(rfile, rline)) {
        if (rline.empty()) continue;

        stringstream ss(rline);
        string rid, pid, fidStr, price, status;
        getline(ss, rid, ',');
        getline(ss, pid, ',');
        getline(ss, fidStr, ',');
        getline(ss, price, ',');
        getline(ss, status, ',');

        if (status != "active") continue;

        int flight_id = stoi(fidStr);

        ffile.clear(); ffile.seekg(0);
        while (getline(ffile, fline)) {
            if (fline.empty()) continue;
            if (stoi(fline.substr(0, fline.find(','))) == flight_id) {
                int p1 = fline.find(',', fline.find(',') + 1);
                p1 = fline.find(',', p1 + 1);
                p1 = fline.find(',', p1 + 1);
                int p2 = fline.find(',', p1 + 1);
                string date = fline.substr(p1 + 1, p2 - p1 - 1);
                int fy, fm, fd;
                sscanf(date.c_str(), "%d-%d-%d", &fy, &fm, &fd);

                if (fy > cyear || (fy == cyear && fm > cmonth) || (fy == cyear && fm == cmonth && fd > cday)) {
                    PrintReservationLine(rline); 
                    cout <<"____________________________"<<endl ;
                    output += rline + "\n";
                }
                break;
            }
        }
    }

    rfile.close();
    ffile.close();

    if (output.empty()) {
        cout << "No upcoming reservations found.\n";
        return;
    }

    cout << "\nSave to CSV? (y/n): ";
    char c;
    cin >> c;
    cin.ignore();
    if (tolower(c) == 'y') {
        ofstream out("report_upcoming_reservations.csv");
        out << output;
        out.close();
        cout << "Saved.\n";
    } else {
        cout << "Not saved.\n";
    }
}


void CompletedReservationsReport() {
    ifstream rfile("reservations.txt");
    ifstream ffile("flights.txt");

    if (!rfile.is_open() || !ffile.is_open()) {
        cout << "Could not open reservation or flight file.\n";
        return;
    }

    time_t now = time(0);
    tm* now_tm = localtime(&now);
    int cyear = now_tm->tm_year + 1900;
    int cmonth = now_tm->tm_mon + 1;
    int cday = now_tm->tm_mday;

    string rline, fline, output = "";
    cout << "\nCompleted Reservations:\n";

    while (getline(rfile, rline)) {
        if (rline.empty()) continue;

        stringstream ss(rline);
        string rid, pid, fidStr, price, status;
        getline(ss, rid, ',');
        getline(ss, pid, ',');
        getline(ss, fidStr, ',');
        getline(ss, price, ',');
        getline(ss, status, ',');

        if (status != "active") continue;

        int flight_id = stoi(fidStr);

        ffile.clear(); ffile.seekg(0);
        while (getline(ffile, fline)) {
            if (fline.empty()) continue;
            if (stoi(fline.substr(0, fline.find(','))) == flight_id) {
                int p1 = fline.find(',', fline.find(',') + 1);
                p1 = fline.find(',', p1 + 1);
                p1 = fline.find(',', p1 + 1);
                int p2 = fline.find(',', p1 + 1);
                string date = fline.substr(p1 + 1, p2 - p1 - 1);
                int fy, fm, fd;
                sscanf(date.c_str(), "%d-%d-%d", &fy, &fm, &fd);

                if (fy < cyear || (fy == cyear && fm < cmonth) || (fy == cyear && fm == cmonth && fd <= cday)) {
                    PrintReservationLine(rline); 
                    cout <<"____________________________"<<endl ;
                    output += rline + "\n";
                }
                break;
            }
        }
    }

    rfile.close();
    ffile.close();

    if (output.empty()) {
        cout << "No completed reservations found.\n";
        return;
    }

    cout << "\nSave to CSV? (y/n): ";
    char c;
    cin >> c;
    cin.ignore();
    if (tolower(c) == 'y') {
        ofstream out("report_completed_reservations.csv");
        out << output;
        out.close();
        cout << "Saved.\n";
    } else {
        cout << "Not saved.\n";
    }
}

void CancelledReservationsReport() { 

    ifstream file("reservations.txt");
    if (!file.is_open()) {
        cout << "Could not open reservations.txt\n";
        return;
    }

    string line, output = "";
    cout << "\nCancelled Reservations:\n";

    while (getline(file, line)) {
        if (line.empty()) continue;
        if (line.rfind("cancelled") != string::npos) {
            PrintReservationLine(line);  
            cout <<"____________________________"<<endl ;
            output += line + "\n";
        }
    }

    file.close();

    if (output.empty()) {
        cout << "No cancelled reservations found.\n";
        return;
    }

    cout << "\nSave to CSV? (y/n): ";
    char c;
    cin >> c;
    cin.ignore();
    if (tolower(c) == 'y') {
        ofstream out("report_cancelled_reservations.csv");
        out << output;
        out.close();
        cout << "Saved.\n";
    } else {
        cout << "Not saved.\n";
    }
}

 
void ReportPassengersOfFlight() { 

    cout << "Enter Flight ID: ";
    int flightId = SafeInputInt();

    ifstream rfile("reservations.txt");
    if (!rfile.is_open()) {
        cout << "Could not open reservations.txt\n";
        return;
    }

    string rline, output = "";
    cout << "\nPassengers for Flight ID " << flightId << ":\n"<<endl;

    while (getline(rfile, rline)) {
        if (rline.empty()) continue;

        stringstream ss(rline);
        string rid, pidStr, fidStr, price, status;
        getline(ss, rid, ',');
        getline(ss, pidStr, ',');
        getline(ss, fidStr, ',');
        getline(ss, price, ',');
        getline(ss, status, ',');

        int pid = stoi(pidStr);
        int fid = stoi(fidStr);

        if (fid == flightId && status == "active") {
            PrintReservationLine(rline);   
            cout <<"____________________________"<<endl<<endl ;
            output += rline + "\n";
        }
    }

    rfile.close();

    if (output.empty()) {
        cout << "No passengers found for this flight.\n";
        return;
    }

    cout << "\nSave to CSV? (y/n): ";
    char c;
    cin >> c;
    cin.ignore();
    if (tolower(c) == 'y') {
        ofstream out("report_flight_passengers.csv");
        out << output;
        out.close();
        cout << "Saved.\n";
    } else {
        cout << "Not saved.\n";
    }
}


 
void ReportFlightsOfDate() {
    cout << "Enter Date (YYYY-MM-DD): ";
    string iDate;
    cin.ignore();
    getline(cin, iDate);

    ifstream file("flights.txt");
    if (!file.is_open()) {
        cout << "Could not open flights.txt\n";
        return;
    }

    string line, output = "";
    cout << "\nFlights on " << iDate << ":\n"<<endl;

    while (getline(file, line)) {
        if (line.empty()) continue;

        int p1 = line.find(',', line.find(',') + 1); 
        p1 = line.find(',', p1 + 1);  
        p1 = line.find(',', p1 + 1);  
        int p2 = line.find(',', p1 + 1);
        string date = line.substr(p1 + 1, p2 - p1 - 1);

        if (date == iDate && line.rfind(",deleted") == string::npos) {
            PrintFlightLine(line);   
            cout <<"____________________________"<<endl<<endl ;
            output += line + "\n";
        }
    }

    file.close();

    if (output.empty()) {
        cout << "No flights found on the given date.\n";
        return;
    }

    cout << "\nSave to CSV? (y/n): ";
    char c;
    cin >> c;
    cin.ignore();
    if (tolower(c) == 'y') {
        ofstream out("report_flights_by_date.csv");
        out << output;
        out.close();
        cout << "Saved.\n";
    } else {
        cout << "Not saved.\n";
    }
}


void ReportUpcomingFlights() {
    ifstream file("flights.txt");
    if (!file.is_open()) {
        cout << "Could not open flights.txt\n";
        return;
    }

    time_t now = time(0);
    tm* now_tm = localtime(&now);
    int cy = now_tm->tm_year + 1900;
    int cm = now_tm->tm_mon + 1;
    int cd = now_tm->tm_mday;

    string line, output = "";
    cout << "\nUpcoming Flights:\n"<<endl;

    while (getline(file, line)) {
        if (line.empty() || line.rfind(",deleted") != string::npos) continue;

        int p1 = line.find(',', line.find(',') + 1);
        p1 = line.find(',', p1 + 1);
        p1 = line.find(',', p1 + 1);
        int p2 = line.find(',', p1 + 1);
        string date = line.substr(p1 + 1, p2 - p1 - 1);

        int fy, fm, fd;
        sscanf(date.c_str(), "%d-%d-%d", &fy, &fm, &fd);

        if (fy > cy || (fy == cy && fm > cm) || (fy == cy && fm == cm && fd > cd)) {
            PrintFlightLine(line); 
            cout <<"____________________________"<<endl<<endl ;
            output += line + "\n";
        }
    }

    file.close();

    if (output.empty()) { 
        cout << "No upcoming flights found.\n";
        return;
    }

    cout << "\nSave to CSV? (y/n): ";
    char c;
    cin >> c;
    cin.ignore();

    if (tolower(c) == 'y') {
        ofstream out("report_upcoming_flights.csv");
        out << output;
        out.close();
        cout << "Saved.\n";
    } else {
        cout << "Not saved.\n";
    }
}
 
void ReportCompletedFlights() { 

    ifstream file("flights.txt");
    if (!file.is_open()) {
        cout << "Could not open flights.txt\n";
        return;
    }

    time_t now = time(0);
    tm* now_tm = localtime(&now);
    int cy = now_tm->tm_year + 1900;
    int cm = now_tm->tm_mon + 1;
    int cd = now_tm->tm_mday;

    string line, output = "";
    cout << "\nCompleted Flights:\n"<<endl;

    while (getline(file, line)) {
        if (line.empty() || line.rfind(",deleted") != string::npos) continue;

        int p1 = line.find(',', line.find(',') + 1);
        p1 = line.find(',', p1 + 1);
        p1 = line.find(',', p1 + 1);
        int p2 = line.find(',', p1 + 1);
        string date = line.substr(p1 + 1, p2 - p1 - 1);

        int fy, fm, fd;
        sscanf(date.c_str(), "%d-%d-%d", &fy, &fm, &fd);

        if (fy < cy || (fy == cy && fm < cm) || (fy == cy && fm == cm && fd <= cd)) {
           (line); 
            cout <<"____________________________"<<endl ;
            output += line + "\n";
        }
    }

    file.close();

    if (output.empty()) {
        cout << "No completed flights found.\n";
        return;
    }

    cout << "\nSave to CSV? (y/n): ";
    char c;
    cin >> c;
    cin.ignore();

    if (tolower(c) == 'y') {
        ofstream out("report_completed_flights.csv");
        out << output;
        out.close();
        cout << "Saved.\n";
    } else {
        cout << "Not saved.\n";
    }
}

 
void ReportPassengerCompletedFlights() {
    cout << "Enter Passenger ID: ";
    int pid = SafeInputInt();

    ifstream rfile("reservations.txt");
    ifstream ffile("flights.txt");
    if (!rfile.is_open() || !ffile.is_open()) {
        cout << "Could not open files\n";
        return;
    }

    time_t now = time(0);
    tm* tm_now = localtime(&now);
    int cy = tm_now->tm_year + 1900;
    int cm = tm_now->tm_mon + 1;
    int cd = tm_now->tm_mday;

    string rline, fline, output = "";
    cout << "\nCompleted Flights for Passenger ID " << pid << ":\n";

    while (getline(rfile, rline)) {
        if (rline.empty()) continue;

        stringstream ss(rline);
        string rid, pidStr, fidStr, price, status;
        getline(ss, rid, ',');
        getline(ss, pidStr, ',');
        getline(ss, fidStr, ',');
        getline(ss, price, ',');
        getline(ss, status, ',');

        if (stoi(pidStr) != pid || status != "active") continue;

        ffile.clear(); ffile.seekg(0);
        while (getline(ffile, fline)) {
            if (fline.empty() || fline.rfind(",deleted") != string::npos) continue;

            if (stoi(fline.substr(0, fline.find(','))) == stoi(fidStr)) {
                int p1 = fline.find(',', fline.find(',') + 1);
                p1 = fline.find(',', p1 + 1);
                p1 = fline.find(',', p1 + 1);
                int p2 = fline.find(',', p1 + 1);
                string date = fline.substr(p1 + 1, p2 - p1 - 1);

                int fy, fm, fd;
                sscanf(date.c_str(), "%d-%d-%d", &fy, &fm, &fd);

                if (fy < cy || (fy == cy && fm < cm) || (fy == cy && fm == cm && fd <= cd)) {
                    PrintReservationLine(rline); 
                    cout <<"____________________________"<<endl ;
                    output += rline + "\n";
                }
                break;
            }
        }
    }

    rfile.close();
    ffile.close();

    if (output.empty()) {
        cout << "No completed flights found for this passenger.\n";
        return;
    }

    cout << "\nSave to CSV? (y/n): ";
    char c;
    cin >> c;
    cin.ignore();
    if (tolower(c) == 'y') {
        ofstream out("report_passenger_completed.csv");
        out << output;
        out.close();
        cout << "Saved.\n";
    }
}

void ReportPassengerUpcomingFlights() {
    cout << "Enter Passenger ID: ";
    int pid = SafeInputInt();

    ifstream rfile("reservations.txt");
    ifstream ffile("flights.txt");
    if (!rfile.is_open() || !ffile.is_open()) {
        cout << "Could not open files\n";
        return;
    }

    time_t now = time(0);
    tm* tm_now = localtime(&now);
    int cy = tm_now->tm_year + 1900;
    int cm = tm_now->tm_mon + 1;
    int cd = tm_now->tm_mday;

    string rline, fline, output = "";
    cout << "\nUpcoming Flights for Passenger ID " << pid << ":\n";

    while (getline(rfile, rline)) {
        if (rline.empty()) continue;

        stringstream ss(rline);
        string rid, pidStr, fidStr, price, status;
        getline(ss, rid, ',');
        getline(ss, pidStr, ',');
        getline(ss, fidStr, ',');
        getline(ss, price, ',');
        getline(ss, status, ',');

        if (stoi(pidStr) != pid || status != "active") continue;

        ffile.clear(); ffile.seekg(0);
        while (getline(ffile, fline)) {
            if (fline.empty() || fline.rfind(",deleted") != string::npos) continue;

            if (stoi(fline.substr(0, fline.find(','))) == stoi(fidStr)) {
                int p1 = fline.find(',', fline.find(',') + 1);
                p1 = fline.find(',', p1 + 1);
                p1 = fline.find(',', p1 + 1);
                int p2 = fline.find(',', p1 + 1);
                string date = fline.substr(p1 + 1, p2 - p1 - 1);

                int fy, fm, fd;
                sscanf(date.c_str(), "%d-%d-%d", &fy, &fm, &fd);

                if (fy > cy || (fy == cy && fm > cm) || (fy == cy && fm == cm && fd > cd)) {
                    PrintReservationLine(rline); 
                    cout <<"____________________________"<<endl ;
                    output += rline + "\n";
                }
                break;
            }
        }
    }

    rfile.close();
    ffile.close();

    if (output.empty()) {
        cout << "No upcoming flights found for this passenger.\n";
        return;
    }

    cout << "\nSave to CSV? (y/n): ";
    char c;
    cin >> c;
    cin.ignore();
    if (tolower(c) == 'y') {
        ofstream out("report_passenger_upcoming.csv");
        out << output;
        out.close();
        cout << "Saved.\n";
    }
}

void ReportPassengerCancelledReservations() {
    cout << "Enter Passenger ID: ";
    int pid = SafeInputInt();

    ifstream file("reservations.txt");
    if (!file.is_open()) {
        cout << "Could not open reservations.txt\n";
        return;
    }

    string line, output = "";
    cout << "\nCancelled Reservations for Passenger ID " << pid << ":\n";

    while (getline(file, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string rid, pidStr, fidStr, price, status;
        getline(ss, rid, ',');
        getline(ss, pidStr, ',');
        getline(ss, fidStr, ',');
        getline(ss, price, ',');
        getline(ss, status, ',');

        if (stoi(pidStr) == pid && status == "cancelled") {
            PrintReservationLine(line); 
            cout <<"____________________________"<<endl ;
            output += line + "\n";
        }
    }

    file.close();

    if (output.empty()) {
        cout << "No cancelled reservations found for this passenger.\n";
        return;
    }

    cout << "\nSave to CSV? (y/n): ";
    char c;
    cin >> c;
    cin.ignore();
    if (tolower(c) == 'y') {
        ofstream out("report_passenger_cancelled.csv");
        out << output;
        out.close();
        cout << "Saved.\n";
    }
}
void ReservationReportMenu() {
    while (true) {
        cout << "\n--- Reservation Reports ---\n";
        cout << "1. All Reservations\n";
        cout << "2. Upcoming Reservations\n";
        cout << "3. Completed Reservations\n";
        cout << "4. Cancelled Reservations\n";
        cout << "0. Back\n";
        cout << "Choose an option: ";

        int choice = SafeInputInRange(0, 4);

        if (choice == 1)
            AllReservationsReport();
        else if (choice == 2)
            UpcomingReservationsReport();
        else if (choice == 3)
            CompletedReservationsReport();
        else if (choice == 4)
            CancelledReservationsReport();
        else if (choice == 0)
            break;
    }
}
 
void FlightReportsMenu() {
    while (true) {
        cout << "\n--- Flight Reports ---\n";
        cout << "1. List of passengers for a flight\n";
        cout << "2. Flights on a specific date\n";
        cout << "3. Upcoming flights\n";
        cout << "4. Completed flights\n";
        cout << "0. Back\n";
        cout << "Choose an option: ";

        int choice = SafeInputInRange(0, 4);

        if (choice == 1)
            ReportPassengersOfFlight();
        else if (choice == 2)
            ReportFlightsOfDate();
        else if (choice == 3)
            ReportUpcomingFlights();
        else if (choice == 4)
            ReportCompletedFlights();
        else if (choice == 0)
            break;
    }
}
 
void PassengerReportsMenu() {
    while (true) {
        cout << "\n--- Passenger Reports ---\n";
        cout << "1. Completed Flights\n";
        cout << "2. Upcoming Flights\n";
        cout << "3. Cancelled Reservations\n";
        cout << "0. Back\n";
        cout << "Choose an option: ";

        int choice = SafeInputInRange(0, 3);

        if (choice == 1)
            ReportPassengerCompletedFlights();
        else if (choice == 2)
            ReportPassengerUpcomingFlights();
        else if (choice == 3)
            ReportPassengerCancelledReservations();
        else if (choice == 0)
            break;
    }
}
 
void ReportsMenu() {
    while (true) {
        cout << "\n------ Reports Menu ------\n";
        cout << "1. Reservation Reports\n";
        cout << "2. Flight Reports\n";
        cout << "3. Passenger Reports\n";
        cout << "0. Back to Main Menu\n";
        cout << "Choose an option: ";

        int choice = SafeInputInRange(0, 3);

        if (choice == 1)
            ReservationReportMenu();
        else if (choice == 2)
            FlightReportsMenu();
        else if (choice == 3)
            PassengerReportsMenu();
        else if (choice == 0)
            break;
    }
}
void PrintReservation(int rid, int pid, int fid, double price, string status) {
    cout << "Reservation ID: " << rid << "\n"
         << "Passenger ID  : " << pid << "\n"
         << "Flight ID     : " << fid << "\n"
         << "Price         : " << price << "\n"
         << "Status        : " << status << "\n"
         << "-----------------------------\n";
}

void PrintFlight(int id, string number, string origin, string dest,
                 string date, string time, int cap, double price, string status) {
    cout << "Flight ID     : " << id << "\n"
         << "Number        : " << number << "\n"
         << "From          : " << origin << "\n"
         << "To            : " << dest << "\n"
         << "Date          : " << date << "\n"
         << "Time          : " << time << "\n"
         << "Capacity      : " << cap << "\n"
         << "Price         : " << price << "\n"
         << "Status        : " << status << "\n"
         << "-----------------------------\n";
}

void PrintPassenger(int id, string name, string code, string pass,
                    string birth, double balance) {
    cout << "Passenger ID  : " << id << "\n"
         << "Name          : " << name << "\n"
         << "National Code : " << code << "\n"
         << "Passport      : " << pass << "\n"
         << "Birth Date    : " << birth << "\n"
         << "Balance       : " << balance << "\n"
         << "-----------------------------\n";
}


int main() { 
     createfile ("passengers.txt") ; 
     createfile ("flights.txt") ;
     createfile ("reservations.txt") ;    

    int choice; 
do { 
    cout << endl ; 
        cout << "-----------------------------\n";
        cout << "  Airline Reservation System \n";
        cout << "-----------------------------\n";
        cout << endl ;

cout << " ~*~*~ Main Menu ~*~*~ : " << endl<<endl ;  

        cout << "1. Passenger Management\n";
        cout << "2. Flight Management \n";
        cout << "3. Reservation Management \n";
        cout << "4. Reports \n";
        cout << "0. Exit\n";
        cout << "-----------------------\n";

        cout << "Enter Your Choice: ";
        cin >> choice;  

        if (cin.fail()) {
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "Invalid input! Please enter a number.\n";
    continue;
}

        cin.ignore();

        if (choice == 1) {
            PassengerMenu();
        } 
        else if (choice == 2) { 
             FlightMenu() ;
        } 
        else if (choice == 3) { 
             ReservationMenu() ;
        }  
        else if (choice == 4 ) { 
            ReportsMenu() ;
        }
        
}
     while (choice != 0);

    cout << " The Program Has Ended ... \n";

    return 0;
}
