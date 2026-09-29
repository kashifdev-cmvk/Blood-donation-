#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

/*
========================================================
                 HEMOLINK
     BLOOD DONATION & EMERGENCY SUPPORT SYSTEM

              DATA STRUCTURE PROJECT

DATA STRUCTURES USED:

1. Linked List - Donor Management
2. Queue - Normal Blood Requests
3. Priority Queue - Emergency Requests
4. Stack - Donation History
5. Array - Blood Stock
6. Linear Search - Donor Search
7. Bubble Sort - Donor Sorting

DATABASE NOT USED
ALL DATA IS STORED IN MEMORY
========================================================
*/


// =====================================================
// CONSTANT
// =====================================================

#define MAX 50


// =====================================================
// DONOR STRUCTURE - LINKED LIST
// =====================================================

struct Donor
{
    int id;
    char name[30];
    int age;
    char bloodGroup[5];
    char city[30];
    char phone[15];
    int available;

    Donor *next;
};

Donor *head = NULL;


// =====================================================
// NORMAL BLOOD REQUEST - QUEUE
// =====================================================

struct BloodRequest
{
    int requestId;
    char patientName[30];
    char hospital[40];
    char bloodGroup[5];
    int units;
    char contact[15];
};

BloodRequest requestQueue[MAX];

int front = -1;
int rear = -1;

int requestCounter = 1;


// =====================================================
// EMERGENCY REQUEST - PRIORITY QUEUE
// =====================================================

struct EmergencyRequest
{
    int id;
    char patientName[30];
    char bloodGroup[5];
    char hospital[40];
    int units;
    int priority;
};

EmergencyRequest emergencyQueue[MAX];

int emergencyCount = 0;

int emergencyCounter = 1;


// =====================================================
// DONATION HISTORY - STACK
// =====================================================

struct Donation
{
    int donationId;
    char donorName[30];
    char bloodGroup[5];
    int units;
};

Donation donationStack[MAX];

int top = -1;

int donationCounter = 1;


// =====================================================
// BLOOD STOCK - ARRAY
// =====================================================

char bloodGroups[8][5] =
{
    "A+",
    "A-",
    "B+",
    "B-",
    "AB+",
    "AB-",
    "O+",
    "O-"
};


int bloodStock[8] =
{
    10,
    5,
    12,
    4,
    6,
    3,
    15,
    5
};


// =====================================================
// FUNCTION DECLARATIONS
// =====================================================

// Donor Functions

void donorMenu();

void registerDonor();

void displayDonors();

void searchDonor();

void updateAvailability();

void deleteDonor();

void sortDonors();

int getDonorCount();


// Request Functions

void requestMenu();

void addBloodRequest();

void processBloodRequest();

void displayBloodRequests();


// Emergency Functions

void emergencyMenu();

void addEmergencyRequest();

void processEmergency();

void displayEmergencyRequests();


// Donation Functions

void donationMenu();

void recordDonation();

void undoLastDonation();

void displayDonationHistory();


// Blood Stock Functions

void stockMenu();

void displayBloodStock();

void addBloodStock();

void reduceBloodStock();

int getBloodIndex(char group[]);


// Statistics

void displayStatistics();


// Main Menu

void mainMenu();


// =====================================================
// DONOR MANAGEMENT
// LINKED LIST
// =====================================================


// -----------------------------------------------------
// REGISTER NEW DONOR
// INSERT AT END OF LINKED LIST
// -----------------------------------------------------

void registerDonor()
{
    Donor *newDonor;
    Donor *temp;

    newDonor = new Donor;

    clrscr();

    cout << "\n";
    cout << "==========================================";
    cout << "\n DONOR REGISTRATION FORM";
    cout << "\n==========================================";

    cout << "\n\nEnter Donor ID: ";
    cin >> newDonor->id;

    cout << "Enter Donor Name: ";
    cin >> newDonor->name;

    cout << "Enter Age: ";
    cin >> newDonor->age;

    if(newDonor->age < 18 || newDonor->age > 65)
    {
        cout << "\nInvalid Age!";
        cout << "\nDonor must be between 18 and 65.";

        delete newDonor;

        getch();

        return;
    }

    cout << "Enter Blood Group: ";
    cin >> newDonor->bloodGroup;

    cout << "Enter City: ";
    cin >> newDonor->city;

    cout << "Enter Phone Number: ";
    cin >> newDonor->phone;

    cout << "\nAvailable for Donation?";
    cout << "\n1. Yes";
    cout << "\n0. No";

    cout << "\nEnter Choice: ";
    cin >> newDonor->available;


    newDonor->next = NULL;


    // First Node

    if(head == NULL)
    {
        head = newDonor;
    }


    // Insert At End

    else
    {
        temp = head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newDonor;
    }


    cout << "\n\n==========================================";
    cout << "\nDonor Registered Successfully!";
    cout << "\n==========================================";

    getch();
}


// -----------------------------------------------------
// DISPLAY ALL DONORS
// TRAVERSAL OF LINKED LIST
// -----------------------------------------------------

void displayDonors()
{
    Donor *temp;

    clrscr();

    cout << "\n";
    cout << "==================================================";
    cout << "\n REGISTERED DONORS";
    cout << "\n==================================================";

    if(head == NULL)
    {
        cout << "\n\nNo Donors Registered!";

        getch();

        return;
    }


    temp = head;


    while(temp != NULL)
    {
        cout << "\n\n--------------------------------------------";

        cout << "\nDonor ID : " << temp->id;

        cout << "\nName : " << temp->name;

        cout << "\nAge : " << temp->age;

        cout << "\nBlood Group : " << temp->bloodGroup;

        cout << "\nCity : " << temp->city;

        cout << "\nPhone : " << temp->phone;


        if(temp->available == 1)
        {
            cout << "\nStatus : AVAILABLE";
        }

        else
        {
            cout << "\nStatus : NOT AVAILABLE";
        }


        temp = temp->next;
    }


    cout << "\n\n--------------------------------------------";

    getch();
}


// -----------------------------------------------------
// SEARCH DONOR
// LINEAR SEARCH
// -----------------------------------------------------

void searchDonor()
{
    Donor *temp;

    char group[5];

    int found = 0;


    clrscr();

    cout << "\n";
    cout << "==========================================";
    cout << "\n SEARCH BLOOD DONOR";
    cout << "\n==========================================";


    cout << "\n\nEnter Required Blood Group: ";

    cin >> group;


    temp = head;


    while(temp != NULL)
    {
        if(strcmp(temp->bloodGroup, group) == 0
        && temp->available == 1)
        {
            cout << "\n\n--------------------------------";

            cout << "\nName : " << temp->name;

            cout << "\nAge : " << temp->age;

            cout << "\nBlood Group : " << temp->bloodGroup;

            cout << "\nCity : " << temp->city;

            cout << "\nPhone : " << temp->phone;


            found = 1;
        }


        temp = temp->next;
    }


    if(found == 0)
    {
        cout << "\n\nNo Available Donor Found!";
    }


    getch();
}


// -----------------------------------------------------
// UPDATE DONOR AVAILABILITY
// -----------------------------------------------------

void updateAvailability()
{
    Donor *temp;

    int id;

    int found = 0;


    clrscr();


    cout << "\n";
    cout << "==========================================";
    cout << "\n UPDATE DONOR AVAILABILITY";
    cout << "\n==========================================";


    cout << "\n\nEnter Donor ID: ";

    cin >> id;


    temp = head;


    while(temp != NULL)
    {
        if(temp->id == id)
        {
            found = 1;


            cout << "\n\nDonor: " << temp->name;


            cout << "\n\n1. Available";

            cout << "\n0. Not Available";


            cout << "\nEnter New Status: ";

            cin >> temp->available;


            cout << "\n\nAvailability Updated Successfully!";


            break;
        }


        temp = temp->next;
    }


    if(found == 0)
    {
        cout << "\nDonor Not Found!";
    }


    getch();
}


// -----------------------------------------------------
// DELETE DONOR
// LINKED LIST DELETION
// -----------------------------------------------------

void deleteDonor()
{
    Donor *temp;

    Donor *previous;

    int id;


    clrscr();


    cout << "\n";
    cout << "==========================================";
    cout << "\n DELETE DONOR";
    cout << "\n==========================================";


    cout << "\n\nEnter Donor ID: ";

    cin >> id;


    temp = head;

    previous = NULL;


    while(temp != NULL && temp->id != id)
    {
        previous = temp;

        temp = temp->next;
    }


    if(temp == NULL)
    {
        cout << "\n\nDonor Not Found!";
    }


    else
    {
        // Delete First Node

        if(temp == head)
        {
            head = head->next;
        }


        // Delete Middle or Last Node

        else
        {
            previous->next = temp->next;
        }


        delete temp;


        cout << "\n\nDonor Deleted Successfully!";
    }


    getch();
}


// -----------------------------------------------------
// SORT DONORS BY ID
// BUBBLE SORT
// -----------------------------------------------------

void sortDonors()
{
    Donor *i;

    Donor *j;


    int tempId;

    int tempAge;

    int tempAvailable;


    char tempName[30];

    char tempBlood[5];

    char tempCity[30];

    char tempPhone[15];


    if(head == NULL)
    {
        cout << "\nNo Donors Available!";

        getch();

        return;
    }


    for(i = head; i != NULL; i = i->next)
    {
        for(j = i->next; j != NULL; j = j->next)
        {
            if(i->id > j->id)
            {

                // ID

                tempId = i->id;

                i->id = j->id;

                j->id = tempId;


                // Name

                strcpy(tempName, i->name);

                strcpy(i->name, j->name);

                strcpy(j->name, tempName);


                // Age

                tempAge = i->age;

                i->age = j->age;

                j->age = tempAge;


                // Blood Group

                strcpy(tempBlood, i->bloodGroup);

                strcpy(i->bloodGroup, j->bloodGroup);

                strcpy(j->bloodGroup, tempBlood);


                // City

                strcpy(tempCity, i->city);

                strcpy(i->city, j->city);

                strcpy(j->city, tempCity);


                // Phone

                strcpy(tempPhone, i->phone);

                strcpy(i->phone, j->phone);

                strcpy(j->phone, tempPhone);


                // Availability

                tempAvailable = i->available;

                i->available = j->available;

                j->available = tempAvailable;
            }
        }
    }


    cout << "\n\nDonors Sorted Successfully By ID!";


    getch();
}


// -----------------------------------------------------
// GET TOTAL DONORS
// -----------------------------------------------------

int getDonorCount()
{
    Donor *temp;

    int count = 0;


    temp = head;


    while(temp != NULL)
    {
        count++;

        temp = temp->next;
    }


    return count;
}


// =====================================================
// DONOR MENU
// =====================================================

void donorMenu()
{
    int choice;


    do
    {
        clrscr();


        cout << "\n";
        cout << "==========================================";
        cout << "\n DONOR MANAGEMENT";
        cout << "\n==========================================";


        cout << "\n\n1. Register New Donor";

        cout << "\n2. View All Donors";

        cout << "\n3. Search Donor By Blood Group";

        cout << "\n4. Update Donor Availability";

        cout << "\n5. Delete Donor";

        cout << "\n6. Sort Donors By ID";

        cout << "\n0. Back To Main Menu";


        cout << "\n\nEnter Your Choice: ";


        cin >> choice;


        switch(choice)
        {
            case 1:
                registerDonor();
                break;


            case 2:
                displayDonors();
                break;


            case 3:
                searchDonor();
                break;


            case 4:
                updateAvailability();
                break;


            case 5:
                deleteDonor();
                break;


            case 6:
                sortDonors();
                break;


            case 0:
                break;


            default:

                cout << "\nInvalid Choice!";

                getch();
        }

    }
    while(choice != 0);
}


// =====================================================
// NORMAL BLOOD REQUEST
// QUEUE
// =====================================================


// -----------------------------------------------------
// ENQUEUE REQUEST
// -----------------------------------------------------

void addBloodRequest()
{
    clrscr();


    if(rear == MAX - 1)
    {
        cout << "\nRequest Queue Is Full!";

        getch();

        return;
    }


    if(front == -1)
    {
        front = 0;
    }


    rear++;


    requestQueue[rear].requestId = requestCounter;


    cout << "\n";
    cout << "==========================================";
    cout << "\n NEW BLOOD REQUEST";
    cout << "\n==========================================";


    cout << "\n\nPatient Name: ";

    cin >> requestQueue[rear].patientName;


    cout << "Hospital Name: ";

    cin >> requestQueue[rear].hospital;


    cout << "Required Blood Group: ";

    cin >> requestQueue[rear].bloodGroup;


    cout << "Required Units: ";

    cin >> requestQueue[rear].units;


    cout << "Contact Number: ";

    cin >> requestQueue[rear].contact;


    requestCounter++;


    cout << "\n\nBlood Request Added Successfully!";

    cout << "\nRequest ID: " << requestQueue[rear].requestId;


    getch();
}


// -----------------------------------------------------
// DEQUEUE REQUEST
// -----------------------------------------------------

void processBloodRequest()
{
    clrscr();


    if(front == -1 || front > rear)
    {
        cout << "\nNo Pending Blood Requests!";

        getch();

        return;
    }


    cout << "\n";
    cout << "==========================================";
    cout << "\n PROCESSING REQUEST";
    cout << "\n==========================================";


    cout << "\n\nRequest ID: "
         << requestQueue[front].requestId;


    cout << "\nPatient: "
         << requestQueue[front].patientName;


    cout << "\nBlood Group: "
         << requestQueue[front].bloodGroup;


    cout << "\nUnits: "
         << requestQueue[front].units;


    cout << "\n\nRequest Processed Successfully!";


    front++;


    getch();
}


// -----------------------------------------------------
// DISPLAY QUEUE
// -----------------------------------------------------

void displayBloodRequests()
{
    int i;


    clrscr();


    cout << "\n";
    cout << "==========================================";
    cout << "\n PENDING BLOOD REQUESTS";
    cout << "\n==========================================";


    if(front == -1 || front > rear)
    {
        cout << "\n\nNo Pending Requests!";

        getch();

        return;
    }


    for(i = front; i <= rear; i++)
    {
        cout << "\n\n--------------------------------";

        cout << "\nRequest ID: "
             << requestQueue[i].requestId;


        cout << "\nPatient: "
             << requestQueue[i].patientName;


        cout << "\nHospital: "
             << requestQueue[i].hospital;


        cout << "\nBlood Group: "
             << requestQueue[i].bloodGroup;


        cout << "\nUnits: "
             << requestQueue[i].units;


        cout << "\nContact: "
             << requestQueue[i].contact;
    }


    getch();
}


// =====================================================
// REQUEST MENU
// =====================================================

void requestMenu()
{
    int choice;


    do
    {
        clrscr();


        cout << "\n";
        cout << "==========================================";
        cout << "\n BLOOD REQUEST MANAGEMENT";
        cout << "\n==========================================";


        cout << "\n\n1. Add Blood Request";

        cout << "\n2. Process Next Request";

        cout << "\n3. View Pending Requests";

        cout << "\n0. Back To Main Menu";


        cout << "\n\nEnter Choice: ";


        cin >> choice;


        switch(choice)
        {
            case 1:
                addBloodRequest();
                break;


            case 2:
                processBloodRequest();
                break;


            case 3:
                displayBloodRequests();
                break;


            case 0:
                break;


            default:

                cout << "\nInvalid Choice!";

                getch();
        }

    }
    while(choice != 0);
}


// =====================================================
// EMERGENCY REQUEST
// PRIORITY QUEUE
// =====================================================


// -----------------------------------------------------
// ADD EMERGENCY REQUEST
// -----------------------------------------------------

void addEmergencyRequest()
{
    int position;


    clrscr();


    if(emergencyCount == MAX)
    {
        cout << "\nEmergency Queue Is Full!";

        getch();

        return;
    }


    EmergencyRequest newRequest;


    newRequest.id = emergencyCounter;


    cout << "\n";
    cout << "==========================================";
    cout << "\n EMERGENCY BLOOD REQUEST";
    cout << "\n==========================================";


    cout << "\n\nPatient Name: ";

    cin >> newRequest.patientName;


    cout << "Hospital Name: ";

    cin >> newRequest.hospital;


    cout << "Blood Group Required: ";

    cin >> newRequest.bloodGroup;


    cout << "Required Units: ";

    cin >> newRequest.units;


    cout << "\nPriority Level";

    cout << "\n1. CRITICAL";

    cout << "\n2. HIGH";

    cout << "\n3. NORMAL";


    cout << "\nEnter Priority: ";

    cin >> newRequest.priority;


    emergencyCounter++;


    // Insert according to priority

    position = emergencyCount;


    while(position > 0 &&
          emergencyQueue[position - 1].priority > newRequest.priority)
    {
        emergencyQueue[position] =
        emergencyQueue[position - 1];

        position--;
    }


    emergencyQueue[position] = newRequest;


    emergencyCount++;


    cout << "\n\nEmergency Request Added Successfully!";


    getch();
}


// -----------------------------------------------------
// PROCESS HIGHEST PRIORITY
// -----------------------------------------------------

void processEmergency()
{
    int i;


    clrscr();


    if(emergencyCount == 0)
    {
        cout << "\nNo Emergency Requests!";

        getch();

        return;
    }


    cout << "\n";
    cout << "==========================================";
    cout << "\n PROCESSING EMERGENCY CASE";
    cout << "\n==========================================";
