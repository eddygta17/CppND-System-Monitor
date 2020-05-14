#include <string>

#include "format.h"

using std::string;

// TODO: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
string Format::ElapsedTime(long seconds) {
    char timestring[10];
    int nanoH = seconds / 3600;
    int remtime = seconds % 3600;
    int nanoM = remtime / 60;
    int nanoS = remtime % 60;
    sprintf(timestring, "%.2d:%.2d:%.2d", nanoH, nanoM, nanoS);
    return timestring;
  }