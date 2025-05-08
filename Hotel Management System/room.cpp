#include <iostream>
//In en output functions.
#include <string>
using namespace std;

int main() {
    // Hotel room data
    int roomNumbers[5] = {101, 102, 201, 202, 301};
    string roomTypes[5] = {"Single", "Single", "Double", "Double", "Suite"};
    float roomPrices[5] = {50.0, 50.0, 80.0, 80.0, 120.0};
    bool isAvailable[5] = {true, true, true, true, true}; // true = available
   //Stores room numbers as integers. Contains 5 rooms: 101, 102, 201, 202, 301.
   //Stores the type of each room as strings.
   //Stores the price per night for each room as floating-point numbers.
   //Indicates whether each room is available (true) or booked (false).


    // Reservation data
    string guestNames[5];
    int reservedRooms[5];
    int reservedNights[5];
    int reservationCount = 0;
    //Declares arrays and variable to store data of the customer. 
    //Each reservation is stored in the same index number across all arrays.
    
    int choice;
    
    cout << "Welcome to Simple Hotel Booking System!\n";
    
    do {
        // Display menu
        cout << "\nMAIN MENU\n";
        cout << "1. View all rooms\n";
        cout << "2. Book a room\n";
        cout << "3. View bookings\n";
        cout << "4. Cancel booking\n";
        cout << "5. Exit\n";
        cout << "Enter your choice (1-5): ";
        cin >> choice;
        //cin is used to input the users choice.

        //View all rooms.
        if (choice == 1) { 
            cout << "\nROOM LIST:\n";
            cout << "Room#\tType\tPrice\tAvailable?\n";
            cout << "--------------------------------\n";
            for (int i = 0; i < 5; i++) {
                cout << roomNumbers[i] << "\t" << roomTypes[i] << "\t$" << roomPrices[i];
                cout << (isAvailable[i] ? "\tYes" : "\tNo") << endl;
            }
        }
        //Displays a table of all rooms using the arrays from the earlier code, such as the Room Number,Type, Price, Availability.

        //Book a room
        else if (choice == 2) { // Book a room
            cout << "\nAvailable Rooms:\n";
            for (int i = 0; i < 5; i++) {
                if (isAvailable[i]) {
                    cout << roomNumbers[i] << " - " << roomTypes[i] << " ($" << roomPrices[i] << "/night)\n";
                }
            }// Dsiplays available rooms.
            
            int roomChoice;
            cout << "Enter room number to book: ";
            cin >> roomChoice;
            // Asks the user to input a room number.
            
            int roomIndex = -1;
            for (int i = 0; i < 5; i++) {
                if (roomNumbers[i] == roomChoice && isAvailable[i]) {
                    roomIndex = i;
                    break;
                }
            //Searches for the room in roomNumbers and checks, if the room exists and if it's available
            }
            //If found, stores its index in roomIndex; otherwise, keeps roomIndex = -1.
            if (roomIndex == -1) {
                cout << "Invalid room number or room not available!\n";
            //Shows error if the room doesn't exist, or is already booked.
            } else {
                string name;
                int nights;
                
                cout << "Enter your name: ";
                cin.ignore(); // Clear input buffer
                getline(cin, name);
            //Uses cin.ignore() to prevent skipping getline.
            //cin.ignore() ensures getline works correctly after cin >> roomChoice.
                
                cout << "How many nights? ";
                cin >> nights;
                
                // Save reservation
                isAvailable[roomIndex] = false;
                guestNames[reservationCount] = name;
                reservedRooms[reservationCount] = roomNumbers[roomIndex];
                reservedNights[reservationCount] = nights;
                reservationCount++;
                //Updates: isAvailable: Sets the room to false (booked).
                //Stores booking details: guestNames, reservedRooms, reservedNights.
                //reservationCount: Increments for the next booking.

                //Display conformation.
                float total = roomPrices[roomIndex] * nights;
                //Calculates the total cost
                cout << "\nBooking successful!\n";
                cout << "Room: " << roomNumbers[roomIndex] << endl;
                cout << "Type: " << roomTypes[roomIndex] << endl;
                cout << "Nights: " << nights << endl;
                cout << "Total cost: $" << total << endl;
                //Prints a receipt. (Bon)
            }
        }
        else if (choice == 3) { // View bookings
            if (reservationCount == 0) {
                cout << "\nNo bookings yet!\n";
            // If no bookings exist (reservationCount == 0), displays a message and skips the rest.
            } else {
                cout << "\nCURRENT BOOKINGS:\n";
                cout << "Name\t\tRoom#\tNights\n";
                cout << "------------------------\n";
                for (int i = 0; i < reservationCount; i++) {
                    cout << guestNames[i] << "\t" << reservedRooms[i] << "\t" << reservedNights[i] << endl;
                    //Prints a formatted table header with columns:
                    ////Iterates from i = 0 to reservationCount - 1.
                }
            }
        }


        else if (choice == 4) { // Cancel booking
            if (reservationCount == 0) {// Checks for existing bookings.
                cout << "\nNo bookings to cancel!\n";
                //Displays this if there is no booking found.
            } else {
                cout << "\nCurrent Bookings:\n";
                for (int i = 0; i < reservationCount; i++) {
                    cout << (i + 1) << ". " << guestNames[i] << " - Room " << reservedRooms[i] << endl;
                }//Lists all bookings with numbered indices (starting from 1).
            
                
                int cancelChoice;
                cout << "Enter booking number to cancel (1-" << reservationCount << "): ";
                cin >> cancelChoice;
                //Asks the user to select a booking to cancel by number.
                
                if (cancelChoice < 1 || cancelChoice > reservationCount) {
                    cout << "Invalid choice!\n";//Rejects invalid input (out of range).
                } else {
                    // Mark room as available
                    int roomToCancel = reservedRooms[cancelChoice - 1];
                    for (int i = 0; i < 5; i++) {
                        if (roomNumbers[i] == roomToCancel) {
                            isAvailable[i] = true;
                            break; //Finds the room number in the booking. Updates isAvailable to true for that room.
                        }
                    }
                    
                    // Remove booking by shifting array
                    for (int i = cancelChoice - 1; i < reservationCount - 1; i++) {
                        guestNames[i] = guestNames[i + 1];
                        reservedRooms[i] = reservedRooms[i + 1];
                        reservedNights[i] = reservedNights[i + 1];
                    }//
                    
                    reservationCount--;
                    cout << "Booking cancelled successfully!\n";
                    //Confirms cancellation.
                }
            }
        }
        else if (choice == 5) { // Exit
            cout << "Thank you for using our system!\n";
            //When the user selects 5, the program displays a farewell message.
        }
        else {
            cout << "Invalid choice! Please enter 1-5.\n";
            //Catches any invalid input that isn't between 1-5.
            //hows an error message but allows the loop to continue, prompting the user again.
        }
        
    } while (choice != 5); // Loop until user chooses exit
    
    return 0;
}