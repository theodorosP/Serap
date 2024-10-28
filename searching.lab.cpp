#include <iostream>
#include <fstream>
#include <cstring>  // For strlen, strcmpi or strcasecmp
#include <cctype>   // For isdigit
#include <algorithm> // For std::sort
using namespace std;

// Enable or disable debug messages
#define debug_messages 1

// Define the max number of records and character array lengths
const int LIST_LENGTH = 256;
const int NAME_SIZE = 40;
const int NUMBER_SIZE = 13;
const int LINE_SIZE = 80;

// Define the structure for the array of records
struct PhoneRec {
    char name[NAME_SIZE];
    char number[NUMBER_SIZE];
};

// Function to compare PhoneRec for sorting by number
bool compareByNumber(const PhoneRec &a, const PhoneRec &b) {
    return strcasecmp(a.number, b.number) < 0;
}

// Function to compare PhoneRec for sorting by name
bool compareByName(const PhoneRec &a, const PhoneRec &b) {
    return strcasecmp(a.name, b.name) < 0;
}

int main() {
    PhoneRec List[LIST_LENGTH];     // Array of phone records
    char line[LINE_SIZE];           // Line of text from the disk
    char filename[] = "phonebook.txt";  // Update path here
    int searchCounter = 0;

    // Open the file
    ifstream PhoneFile(filename);
    if (!PhoneFile) {
        cerr << "Unable to open " << filename << endl;
        return 1;
    }

    int listsize = 0;
    line[0] = 0;                            // Clear the line buffer
    PhoneFile.getline(line, LINE_SIZE);     // Read the first line

    // Read each line from the file into List[]
    while (!PhoneFile.eof() && listsize < LIST_LENGTH && line[0]) {
        if (strlen(line) > 1) {
            char* ptr = strtok(line, ".");                 // Find name, separated by '.'
            strcpy(List[listsize].name, ptr);              // Copy name
            ptr = strtok(NULL, ".\r\n");                   // Find phone number
            strcpy(List[listsize].number, ptr);            // Copy phone number
            listsize++;
        }
        line[0] = 0;                            // Clear the buffer
        PhoneFile.getline(line, LINE_SIZE);     // Read next line
    }

#if debug_messages == 1
    cout << "There are " << listsize << " lines in the file." << endl;
#endif

    // Sort the list by phone number for binary search
    sort(List, List + listsize, compareByNumber);

    // Request a search string
    char searchString[80];
    cout << "Enter a name or phone number: ";
    cin.getline(searchString, 80);

    // Check if the search input is a phone number or name
    bool isNumberSearch = isdigit(searchString[0]);
    bool found = false;
    int index;

    // Sequential Search based on input type
    for (index = 0; index < listsize; index++) {
        searchCounter++;
        if (isNumberSearch) {  // Search by phone number
            if (strstr(List[index].number, searchString)) {
                found = true;
                cout << "Customer name: " << List[index].name << endl;
                break;
            }
        } else {  // Search by name (case-insensitive)
            if (strcasecmp(List[index].name, searchString) == 0) {
                found = true;
                cout << "Customer phone number: " << List[index].number << endl;
                break;
            }
        }
    }

    if (!found) {
        cout << "Not found in sequential search." << endl;
    }

    // Binary Search for phone number
    if (isNumberSearch) {
        searchCounter = 0;
        int lowerBound = 0;
        int upperBound = listsize - 1;
        int midPoint = 0;
        found = false;

        cout << "\n\n********** Starting the BINARY SEARCH **********\n";
        while (lowerBound <= upperBound) {
            searchCounter++;
            midPoint = (lowerBound + upperBound) / 2;

#if debug_messages == 1
            cout << searchCounter << " lowerBound = " << lowerBound
                 << " midPoint=" << midPoint
                 << " upperBound=" << upperBound
                 << "  " << List[midPoint].name << endl;
#endif

            // Case-insensitive comparison for binary search
            if (strcasecmp(List[midPoint].number, searchString) < 0)
                lowerBound = midPoint + 1;
            else if (strcasecmp(List[midPoint].number, searchString) > 0)
                upperBound = midPoint - 1;
            else {
                found = true;
                cout << "Customer name: " << List[midPoint].name << endl;
                break;
            }
        }

        if (!found) {
            cout << "Not found in binary search." << endl;
        } else {
            cout << searchCounter << " tests were made in binary search." << endl;
        }
    }

    // Binary Search for name
    if (!isNumberSearch) {
        searchCounter = 0;
        // Sort the list by name for binary search
        sort(List, List + listsize, compareByName);
        int lowerBound = 0;
        int upperBound = listsize - 1;
        int midPoint = 0;
        found = false;

        cout << "\n\n********** Starting the BINARY SEARCH for NAME **********\n";
        while (lowerBound <= upperBound) {
            searchCounter++;
            midPoint = (lowerBound + upperBound) / 2;

#if debug_messages == 1
            cout << searchCounter << " lowerBound = " << lowerBound
                 << " midPoint=" << midPoint
                 << " upperBound=" << upperBound
                 << "  " << List[midPoint].number << endl;
#endif

            // Case-insensitive comparison for binary search
            if (strcasecmp(List[midPoint].name, searchString) < 0)
                lowerBound = midPoint + 1;
            else if (strcasecmp(List[midPoint].name, searchString) > 0)
                upperBound = midPoint - 1;
            else {
                found = true;
                cout << "Customer phone number: " << List[midPoint].number << endl;
                break;
            }
        }

        if (!found) {
            cout << "Not found in binary search." << endl;
        } else {
            cout << searchCounter << " tests were made in binary search." << endl;
        }
    }

    return 0;
}


//Run this: 
//g++ -o phonebook searching.lab.cpp
//./phonebook
