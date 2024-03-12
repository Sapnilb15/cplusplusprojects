//Sapnil Basnet
//1/25/2024
//PA1
//Collaborators:None
//Assignment Number: 1
//CS 2308- Spring 2024
// Purpose :This program tracks and displays the medal count for various countries

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//Structure to represent a country
struct Country {
    string name;
    int gold;
    int silver;
    int bronze;
};

//Named constant for the array size
const int NUM_COUNTRIES = 8;

//Function to display the table header
void showResults(const Country countries[]) {
    //Header
    cout << left
         << setw(3) << "N"
         << setw(15) << "Country"
         << right
         << setw(10) << "Gold"
         << setw(10) << "Silver"
         << setw(10) << "Bronze"
         << setw(10) << "Total"
         << endl;

    //Display data for each country
    for (int i = 0; i < NUM_COUNTRIES; i++) {
        
    // Calculate total medals for each country
        int total = countries[i].gold + countries[i].silver + countries[i].bronze;

    //Display country details in a formatted row
        cout << left
             << setw(3) << i + 1
             << setw(15) << countries[i].name
             << right
             << setw(10) << countries[i].gold
             << setw(10) << countries[i].silver
             << setw(10) << countries[i].bronze
             << setw(10) << total
             << endl;
    }
}

//Function to update the medal counts
void addMedal(Country countries[], int countryNumber, char medalType) {
    if (medalType == 'G' || medalType == 'g') {
        countries[countryNumber-1].gold++;
    } else if (medalType == 'S' || medalType == 's') {
        countries[countryNumber-1].silver++;
    } else if (medalType == 'B' || medalType == 'b') {
        countries[countryNumber-1].bronze++;
    } 
}

//Function to calculate the total number of medals 
int totalMedals(const Country countries[]) {
    int total = 0;
    // Sum up gold, silver, and bronze medals for all countries
    for (int i = 0; i<NUM_COUNTRIES; ++i) {
        total += countries[i].gold + countries[i].silver + countries[i].bronze;
    }
    return total;
}

//Function to find the index of the country with the most total medals
int mostTotalMedals(const Country countries[]) {
    int maxTotal = -1;
    int maxIndex = 0;
    //countries to find the one with the most total medals
    for (int i = 0; i < NUM_COUNTRIES; ++i) {
        int total = countries[i].gold + countries[i].silver + countries[i].bronze;
        if (total > maxTotal) {
            maxTotal = total;
            maxIndex = i;
        }
    }
    return maxIndex;
}

int main() {
    // Array of countries
    Country countries[NUM_COUNTRIES] = {
        {"Australia", 11, 14, 12},
        {"Canada", 5, 0, 1},
        {"China", 9, 14, 11},
        {"Great Britain", 8, 4, 8},
        {"Japan", 8, 10, 10},
        {"Netherlands", 7, 6, 7},
        {"Russia", 6, 10, 8},
        {"USA", 10, 6, 7}
    };

    int choice;
    // Main program loop
    while (choice != 0) {
        // Display the table of countries
        showResults(countries);

        // Prompt the user for input
        cout << "Enter the country number (0 to quit):"<<endl;
        cin >> choice;

          if (choice == 0) {
            // User chose to quit, exit the loop
            break;
        }

        
        char medalType;
        // Prompt the user for the medal type
        cout << "Enter the medal type (G,S, or B):"<<endl;
        cin >> medalType;
        // Update medal count based on user input
        addMedal(countries, choice, medalType);
        
    }


    // Calculate total medals and find the country with the most total medals
    int total = totalMedals(countries);
    int mostMedalsIndex = mostTotalMedals(countries);

    // Display the final results
    cout << "Total medals awarded: " << total<<endl;
    cout << "Country with the most total medals: " << countries[mostMedalsIndex].name << endl;

    return 0;
}
