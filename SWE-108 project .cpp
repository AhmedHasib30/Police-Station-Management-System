#include<bits/stdc++.h>
using namespace std;

class pol {
public:
    int id;
    string name;
    string position;
    double salary;
};

class crimi {
public:
    string name;
    int serial;
    string crime;
    string address;
};

vector<pol> police;
vector<crimi> criminal;

// Display police list
void viewpolicelist() {
    cout << "\n=========== Police Officers List ===========\n";
    cout << left << setw(5) << "ID"
         << setw(20) << "Name"
         << setw(15) << "Position"
         << setw(10) << "Salary" << endl;
    cout << "---------------------------------------------\n";

    for (const auto& p : police) {
        cout << left << setw(5) << p.id
             << setw(20) << p.name
             << setw(15) << p.position
             << fixed << setprecision(2)
             << setw(10) << p.salary << endl;
    }

    cout << "=============================================\n\n";
}

// Display criminal list
void viewcriminals() {
    cout << "\n============= Criminals List =============\n";
    cout << left << setw(8) << "Serial"
         << setw(25) << "Name"
         << setw(20) << "Crime"
         << setw(10) << "Cell" << endl;
    cout << "-----------------------------------------------\n";

    for (const auto& c : criminal) {
        cout << left << setw(8) << c.serial
             << setw(25) << c.name
             << setw(20) << c.crime
             << setw(10) << c.address << endl;
    }

    cout << "=============================================\n\n";
}


//selection sort
void sortbyidpolice() {
    for (int i = 0; i < police.size() - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < police.size(); ++j) {
            if (police[j].id < police[minIndex].id) {
                minIndex = j;
            }
        }
        swap(police[i], police[minIndex]);
    }

    cout << "\nPolice list sorted by ID (Selection Sort):\n";
    viewpolicelist();
}


//insertion sort
void sortbysalarypolice() {
    for (int i = 1; i < police.size(); ++i) {
        pol key = police[i];
        int j = i - 1;
        while (j >= 0 && police[j].salary > key.salary) {
            police[j + 1] = police[j];
            --j;
        }
        police[j + 1] = key;
    }

    cout << "\nPolice list sorted by Salary (Insertion Sort):\n";
    viewpolicelist();
}


//bubble sort
void sorybynamecriminals() {
    for (int i = 0; i < criminal.size() - 1; ++i) {
        for (int j = 0; j < criminal.size() - i - 1; ++j) {
            if (criminal[j].name > criminal[j + 1].name) {
                swap(criminal[j], criminal[j + 1]);
            }
        }
    }

    cout << "\nCriminal list sorted by Name (Bubble Sort):\n";
    viewcriminals();
}

//adding new element
void addpoliceorcriminals(){
    int choice;
    cout << "\n--- Add Entry Menu ---\n";
    cout << "1. Add Police Officer\n";
    cout << "2. Add Criminal\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        pol newPolice;
        cout << "Enter ID: ";
        cin >> newPolice.id;
        cout << "Enter Name (no spaces): ";
        cin >> newPolice.name;
        cout << "Enter Position (no spaces): ";
        cin >> newPolice.position;
        cout << "Enter Salary: ";
        cin >> newPolice.salary;

        police.push_back(newPolice);
        cout << "Police officer added successfully.\n";
    }
    else if (choice == 2) {
        crimi newCriminal;
        cout << "Enter Serial Number: ";
        cin >> newCriminal.serial;
        cout << "Enter Name (no spaces): ";
        cin >> newCriminal.name;
        cout << "Enter Crime (no spaces): ";
        cin >> newCriminal.crime;
        cout << "Enter Cell Address (no spaces): ";
        cin >> newCriminal.address;

        criminal.push_back(newCriminal);
        cout << "Criminal added successfully.\n";
    }
    else {
        cout << "Invalid choice.\n";
    }
}

//delet elemnets
void deletpoliceorcriminals(){
    int choice;
    cout << "\n--- Delete Entry Menu ---\n";
    cout << "1. Delete Police Officer by ID\n";
    cout << "2. Delete Criminal by Serial Number\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        int id;
        cout << "Enter Police ID to delete: ";
        cin >> id;

        bool found = false;
        for (auto it = police.begin(); it != police.end(); ++it) {
            if (it->id == id) {
                police.erase(it);
                cout << "Police officer with ID " << id << " deleted.\n";
                found = true;
                break;
            }
        }
        if (!found) cout << "No police officer found with ID " << id << ".\n";
    }
    else if (choice == 2) {
        int serial;
        cout << "Enter Criminal Serial Number to delete: ";
        cin >> serial;

        bool found = false;
        for (auto it = criminal.begin(); it != criminal.end(); ++it) {
            if (it->serial == serial) {
                criminal.erase(it);
                cout << "Criminal with Serial " << serial << " deleted.\n";
                found = true;
                break;
            }
        }
        if (!found) cout << "No criminal found with Serial " << serial << ".\n";
    }
    else {
        cout << "Invalid choice.\n";
    }
}


//linear search
void searchCriminalByName() {
    string target;
    cout << "Enter the name of the criminal to search (case-sensitive): ";
    cin >> target;

    bool found = false;
    for (const auto& c : criminal) {
        if (c.name == target) {
            cout << "\nCriminal Found:\n";
            cout << "Serial: " << c.serial << "\n";
            cout << "Name: " << c.name << "\n";
            cout << "Crime: " << c.crime << "\n";
            cout << "Cell Address: " << c.address << "\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Criminal named '" << target << "' not found.\n";
    }
}

//
void searchPoliceByID() {
    sortbyidpolice();
    int target;
    cout << "Enter Police ID to search: ";
    cin >> target;

    int left = 0, right = police.size() - 1;
    bool found = false;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (police[mid].id == target) {
            cout << "\nPolice Officer Found:\n";
            cout << "ID: " << police[mid].id << "\n";
            cout << "Name: " << police[mid].name << "\n";
            cout << "Position: " << police[mid].position << "\n";
            cout << "Salary: " << police[mid].salary << "\n";
            found = true;
            break;
        }
        else if (police[mid].id < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    if (!found) {
        cout << "Police officer with ID " << target << " not found.\n";
    }
}

//implementation of queue
const int qsize = 20;
int que[qsize];
int fnt=-1,bck=-1;

void qpush(int value){
    if(fnt == (bck+1)%qsize) return;
    if(fnt==-1 && bck ==-1) fnt=0;
    bck++;
    bck%=qsize;
    que[bck]=value;
}

void qpop(){
    if(fnt==bck){
        fnt=-1;
        bck=-1;
    }
    else{
        fnt= (fnt+1)%qsize;
    }
}

bool qempty(){
    if(fnt==-1 && bck==-1) return true;
    else return false;
}
// end of queue implementation



// history (Implementation of Stack);
const int stsz = 1000;
string st[stsz];
int stop = -1;
void stpush(string s){
    if(stop==999) return;
    stop ++;
    st[stop]=s;
}

void stpop(){
    if(stop==-1) return;
    stop--;
}

int stsize(){
    return stop+1;
}

// insert police information
void defaultpolice() {
    police.push_back({1, "Abrar Hasan", "OC", 75000});
    police.push_back({2, "Mustafir Rahman", "OC", 77000});
    police.push_back({3, "Rafiq Ahmed", "SI", 60000});
    police.push_back({4, "Kamal Hossain", "SI", 59000});
    police.push_back({5, "Jahidul Islam", "Officer", 50000});
    police.push_back({6, "Nazmul Hossain", "Officer", 48000});
    police.push_back({7, "Tarek Rahman", "Officer", 51000});
    police.push_back({8, "Iqbal Hossain", "Officer", 47000});
    police.push_back({9, "Kabir Uddin", "Constable", 30000});
    police.push_back({10, "Nayan Mia", "Constable", 29500});
    police.push_back({11, "Rubel Sarkar", "Constable", 29000});
    police.push_back({12, "Liton Sheikh", "Constable", 28500});
    police.push_back({13, "Sohag Mia", "Constable", 28500});
    police.push_back({14, "Aminul Islam", "Constable", 28000});
    police.push_back({15, "Mamun Sheikh", "Constable", 28000});
    police.push_back({16, "Biplob Hossain", "Constable", 27500});
    police.push_back({17, "Alamin Bepari", "Constable", 27500});
    police.push_back({18, "Hasibur Rahman", "Constable", 27000});
    police.push_back({19, "Sajib Khan", "Constable", 27000});
    police.push_back({20, "Jashim Uddin", "Constable", 26500});
}

// insert criminal information
void defaultcriminal() {
    criminal.push_back({"Juwel mia", 1, "Eve-teasing", "Cell-01"});
    criminal.push_back({"Mine uddin", 2, "Rep", "Cell-01"});
    criminal.push_back({"Tayebur Rahman", 3, "Murder", "Cell-02"});
    criminal.push_back({"Seyam Hossain", 4, "Murder", "Cell-02"});
    criminal.push_back({"Taimiha Hawladar", 5, "Extortion", "Cell-03"});
    criminal.push_back({"Atikul Islam", 6, "Extortion", "Cell-03"});
    criminal.push_back({"Junaidul Alam Arko", 7, "Rep", "Cell-04"});
    criminal.push_back({"Yeaz Uddin Hridoy", 8, "Snatching", "Cell-04"});
    criminal.push_back({"Tuhin mia", 9, "Rep", "Cell-05"});
    criminal.push_back({"Dipongkr", 10, "Eve-teasing", "Cell-05"});
    criminal.push_back({"Dipto Poul", 11, "Drags Diller", "Cell-06"});
    criminal.push_back({"Mustafur Rahman", 12, "Arms case", "Cell-07"});
    criminal.push_back({"Jawad bhuiyan", 13, "Rep", "Cell-01"});
    criminal.push_back({"Bishal", 14, "Rep", "Cell-01"});
    criminal.push_back({"Tonmoy", 15, "Drag Diller", "Cell-02"});
    criminal.push_back({"Rifah Jakia", 16, "Car Staling", "Cell-03"});
    criminal.push_back({"Prithy Akter", 17, "Staling", "Cell-04"});
    criminal.push_back({"Rokaiya Binte Obaid", 18, "Fraud", "Cell-05"});
    criminal.push_back({"Amena Akter", 19, "Kidnapping", "Cell-06"});
    criminal.push_back({"Lamia Akter", 20, "Kidnapping", "Cell-06"});
}

int main() {
    defaultpolice();
    defaultcriminal();

    while (true) {
        cout << "\n---SWE POLICE STATION---\n";
        cout << "1. View Police List\n";
        cout << "2. View Criminals List\n";
        cout << "3. Add Police or Criminal\n";
        cout << "4. Delete Police or Criminal\n";
        cout << "5. Sort Police by ID\n";
        cout << "6. Sort Police by Salary\n";
        cout << "7. Sort Criminals by Name\n";
        cout << "8. Search Criminal by Name\n";
        cout << "9. Search Police by ID\n";
        cout << "10. View History\n";
        cout << "11. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                viewpolicelist();
                stpush("Viewed Police List");
                break;

            case 2:
                viewcriminals();
                stpush("Viewed Criminals List");
                break;

            case 3:
                addpoliceorcriminals();
                stpush("Added Police or Criminal");
                break;

            case 4:
                deletpoliceorcriminals();
                stpush("Deleted Police or Criminal");
                break;

            case 5:
                sortbyidpolice();
                stpush("Sorted Police by ID");
                break;

            case 6:
                sortbysalarypolice();
                stpush("Sorted Police by Salary");
                break;

            case 7:
                sorybynamecriminals();
                stpush("Sorted Criminals by Name");
                break;

            case 8:
                searchCriminalByName();
                stpush("Searched Criminal by Name");
                break;

            case 9:
                searchPoliceByID();
                stpush("Searched Police by ID");
                break;

            case 10:
                cout << "\n--- History ---\n";
                if (stsize() == 0) {
                    cout << "No history available.\n";
                } else {
                    for (int i = 0; i < stsize(); i++) {
                        cout << st[i] << endl;
                    }
                }
                break;

            case 11:
                cout << "Exiting program.\n";
                return 0;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}

