// Daniel Chavez CSCE350 
#include <iostream>
using namespace std;

// A Locker Object
class Locker
{
    public:
        Locker()
        {
            lockerNumber = 0;
            lockerStatus = false;
        }

        /*
        * used to display the locker number and status
        */
        void DisplayLocker()
        {
            cout << "_________________________" << endl;
            cout << "Locker Number: " << lockerNumber << endl;
            if (getLockerStatus())
            {
                cout << "Locker Status: Open" << endl;
            } else {
                cout << "Locker Status: Closed" << endl;
            }
        }

        void setLockerNumber (int number) { lockerNumber = number; }
        void setLockerStatus (bool status) { lockerStatus = status; }
        bool getLockerStatus () { return lockerStatus; }
        int getLockerNumber () { return lockerNumber; }

    private:
        int lockerNumber;
        bool lockerStatus;
        
};

int main()
{
    int numberOfLockers;
    int numberOfPasses;
    int numberOfOpenLockers;
    Locker lockers[numberOfLockers];

    cout << "How many lockers are there?" << endl;
    cin >> numberOfLockers;
    cout << "How many passes are there?" << endl;
    cin >> numberOfPasses;
    
    for(int i = 0; i < numberOfLockers; i++)
    {
        lockers[i].setLockerNumber(i + 1);
    }

    for(int i = 0; i < numberOfPasses; i++)
    {
        for(int j = 0; j < numberOfLockers; j++)
        {
            if (lockers[j].getLockerNumber() % (i + 1) == 0)
            {
                lockers[j].setLockerStatus(!lockers[j].getLockerStatus());
            }
        }
    }

    for(int i = 0; i < numberOfLockers; i++)
    {
        lockers[i].DisplayLocker();
        if (lockers[i].getLockerStatus())
            {
                numberOfOpenLockers++;
            }
    }

            cout << "\n" << "Number of locker doors opened: " << numberOfOpenLockers << endl;

    return 0;
}