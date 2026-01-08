#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <iomanip>
using namespace std;

int main() {
    ofstream of;
    time_t timestamp;
    time(&timestamp);
    tm* startTime = localtime(&timestamp);
    tm* endTime;
    string logfile = "logs.txt";

    of.open(logfile, ios::app); // attempts to open the file in append
    if (!of) {
        std::ofstream(logfile).close(); // if the file can't be opened then it creates an empty file
        of.open(logfile, ios::app); // the file was opened closed so we reopen it in append
    }
    of << put_time(startTime, "%Y-%m-%d %H:%M:%S") << ": Main is running" << endl; // logs the start of main
    // The simulation is started here
    time(&timestamp);
    endTime = localtime(&timestamp);
    of << put_time(endTime, "%Y-%m-%d %H:%M:%S") << ": Main is closing" << endl << endl; //logs when the program finishes
    of.close();
}