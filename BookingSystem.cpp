#include <iostream>
#include <ctime>
using namespace std;

class Booking
{
protected:
    int id;
    int days;

public:
    void take_info()
    {
        cout << "____________________\n";
        cout << "WELCOME, PLEASE FILL THE FORM FOR BOOKING THE ROOM\n";
        cout << "ENTER THE LAST 4-DIGITS OF YOUR AADHAAR CARD: ";
        while (!(cin >> id))
        {
            cout << "Invalid input. Please enter a valid integer: ";
            cin.clear();
            cin.ignore(10000, '\n'); // ignore up to 10000 characters or until newline
        }
        cout << "ENTER THE NUMBER OF DAYS YOU WANT YOUR STAY: ";
        while (!(cin >> days))
        {
            cout << "Invalid input. Please enter a valid integer: ";
            cin.clear();
            cin.ignore(10000, '\n'); // ignore up to 10000 characters or until newline
        }

        if (days <= 0)
        {
            cout << "Number of days must be positive. Please re-enter: ";
            cin >> days;
        }
    }

    void show_booking_info()
    {
        cout << "____________________\n";
        cout << "BOOKING INFORMATION\n";
        cout << "CUSTOMER ID: " << id << endl;

        // Get the timestamp for the current date and time
        time_t timestamp;
        time(&timestamp);

        // Display the date and time represented by the timestamp
        cout << "TODAY'S DATE AND TIME: " << ctime(&timestamp);
        cout << "DURATION OF STAY: " << days << " DAY(S)\n";
    }
};

class Guest : public Booking
{
private:
    string name;
    string surname;
    int age;

public:
    void take_info()
    {
        Booking::take_info(); // Call the base class method

        cout << "____________________\n";
        cout << "NOW FILL YOUR PERSONAL DETAILS\n";
        cout << "ENTER YOUR FIRST NAME: ";
        cin >> name;
        cout << "ENTER YOUR LAST NAME: ";
        cin >> surname;
        cout << "ENTER YOUR AGE: ";
        while (!(cin >> age))
        {
            cout << "Invalid input. Please enter a valid integer: ";
            cin.clear();
            cin.ignore(10000, '\n'); // ignore up to 10000 characters or until newline
        }
    }

    void show_guest_info()
    {
        cout << "____________________\n";
        cout << "GUEST INFORMATION\n";
        cout << "NAME: " << name << " " << surname << endl;
        cout << "AGE: " << age << " YEARS\n";
        show_booking_info(); // Call the base class show function
    }
};

class Room : public Guest
{
protected:
    int room_type;

public:
    void take_info()
    {
        Guest::take_info(); // Call the base class method

        cout << "____________________\n";
        cout << "NOW FILL YOUR ROOM TYPE\n";
        cout << "ROOM TYPE:\n1) AC ROOM (PRICE: 600 Rs/DAY)\n2) NON-AC ROOM (PRICE: 400 Rs/DAY)\n";
        cout << "SELECT 1 FOR AC ROOM AND 2 FOR NON-AC ROOM: ";
        cin >> room_type;

        if (room_type != 1 && room_type != 2)
        {
            cout << "Invalid selection. Please choose 1 or 2: ";
            cin >> room_type;
        }
    }

    void show_room_info()
    {
        cout << "____________________\n";
        cout << "ROOM INFORMATION\n";
        if (room_type == 1)
        {
            cout << "YOU SELECTED AC ROOM\n";
        }
        else if (room_type == 2)
        {
            cout << "YOU SELECTED NON-AC ROOM\n";
        }
        show_guest_info(); // Call the base class show function
    }
};

class Payment : public Room
{
private:
    int payment_mode;

public:
    void take_info()
    {
        Room::take_info(); // Call the base class method

        cout << "____________________\n";
        cout << "NOW FILL YOUR PAYMENT DETAILS\n";
        cout << "CHOOSE MODE OF PAYMENT:\n1) CASH\n2) ONLINE PAYMENT\n";
        cin >> payment_mode;

        if (payment_mode != 1 && payment_mode != 2)
        {
            cout << "Invalid selection. Please choose 1 or 2: ";
            cin >> payment_mode;
        }
    }

    void show_payment_info()
    {
        cout << "____________________\n";
        cout << "PAYMENT INFORMATION\n";

        if (payment_mode == 1)
        {
            cout << "PAYMENT MODE: CASH\n";
        }
        else if (payment_mode == 2)
        {
            cout << "PAYMENT MODE: ONLINE\n";
        }

        int total_bill = 0;

        if (room_type == 1)
        {
            total_bill = 600 * days;
        }
        else if (room_type == 2)
        {
            total_bill = 400 * days;
        }

        cout << "YOUR TOTAL BILL IS: " << total_bill << " Rs\n";
        show_room_info(); // Call the base class show function
        cout << "YOUR TOTAL BILL IS: " << total_bill << endl;
    }
};

int main()
{
    Payment p1;
    p1.take_info();
    p1.show_payment_info();
    return 0;
}
