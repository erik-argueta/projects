// Simulates a hotel room's availability and occupancy
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void welcomeName(string& hotelName);	// welcomes user and asks for name of hotel
void setFloors(int& totalFloors, string hotelName);		// asks user to input total number of floors
void setLevelRooms(int totalFloors, int& totalRooms, int& totalOccupied);	// prompts user to enter number of rooms and number occupied floor by floor
double percentOccupancy(int totalRooms, int totalOccupied);		// calculates occupancy percentage
void print(string hotelName, int totalFloors, int totalOccupied, int totalRooms);	// prints the information for the user.

int main() {
	string hotelName;
	int totalFloors{ 0 }; int totalOccupied{ 0 }; int totalRooms{ 0 };

	welcomeName(hotelName);
	setFloors(totalFloors, hotelName);
	setLevelRooms(totalFloors, totalRooms, totalOccupied);
	print(hotelName, totalFloors, totalOccupied, totalRooms);

	return 0;
}

void welcomeName(string& hotelName) {
	cout << "Welcome! Please enter the name of your hotel: ";
	getline(cin, hotelName);
}

void setFloors(int& totalFloors, string hotelName) {
	while (totalFloors < 1) {
		cout << "Please enter the total number of floors in " << hotelName << ": ";
		cin >> totalFloors;
		if (totalFloors < 1) {
			cout << "You have entered an invalid number of floors.\nPlease enter a number that is greater than 1.\n\n";
		}
	}
}

void setLevelRooms(int totalFloors, int& totalRooms, int& totalOccupied) {
	
	for (int currentFloor = 1; currentFloor <= totalFloors; currentFloor++) {
		int levelRoom = 0;
		int levelOccupied = -1;
		if (currentFloor == 13) { continue; }		// most hotels do not have a floor 13 with rooms

		while (levelRoom < 10) {
			cout << "Please enter the number of rooms on floor #" << currentFloor << ": ";
			cin >> levelRoom;
			if (levelRoom < 10) {
				cout << "You have entered an invalid number of rooms.\nPlease enter a number greater than or equal to 10.\n\n";
			}
		}

		while (levelOccupied < 0 || levelOccupied > levelRoom) {
			cout << "Please enter the how many of those rooms are occupied: ";
			cin >> levelOccupied;
			if (levelOccupied < 0 || levelOccupied > levelRoom) {
				cout << "You have entered more occupied rooms than there are on the floor.\nPlease enter a number that is less than or equal to " << levelRoom << ".\n";
			}
		}
		
		totalRooms += levelRoom;
		totalOccupied += levelOccupied;
		
	}
}

double percentOccupancy(int totalRooms, int totalOccupied) {
	return ((static_cast<double>(totalOccupied) / static_cast<double>(totalRooms)) * 100);		// int's cannot be used to calculate percentage, so we static cast
}

void print(string hotelName, int totalFloors, int totalOccupied, int totalRooms) {
	cout << hotelName << ":\n"
		<< "Total Floors: " << totalFloors
		<< "\nTotal Rooms: " << totalRooms
		<< "\nTotal Occupied Rooms: " << totalOccupied
		<< "\nLevel of Occupancy: " << setprecision(3) << percentOccupancy(totalRooms, totalOccupied) << "%\n\n";
}