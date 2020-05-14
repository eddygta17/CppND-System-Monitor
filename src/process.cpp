#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>

#include "process.h"
#include "linux_parser.h"

using std::string;
using std::to_string;
using std::vector;

Process::Process(int pid)
    : pid_(pid),
      command_(LinuxParser::Command(pid)),
      user_(LinuxParser::User(pid)){};


// TODO: Return this process's ID
int Process::Pid() const { return pid_; }

// TODO: Return this process's CPU utilization
float Process::CpuUtilization() const {

  float totaltime = LinuxParser::ActiveJiffies(Pid());  
  float uptime = LinuxParser::UpTime();                 
  float secondsactive =
      uptime - (Process::UpTime() / sysconf(_SC_CLK_TCK));  
  float cpu_usage =
      (totaltime / sysconf(_SC_CLK_TCK)) / secondsactive;  
  return cpu_usage;
}

// TODO: Return the command that generated this process
string Process::Command() { return command_; }

// TODO: Return this process's memory utilization
string Process::Ram() { return LinuxParser::Ram(Pid()); }

// TODO: Return the user (name) that generated this process
string Process::User() { return user_; }

// TODO: Return the age of this process (in seconds)
long int Process::UpTime() const { return LinuxParser::UpTime(Pid()); }

// TODO: Overload the "less than" comparison operator for Process objects
// REMOVE: [[maybe_unused]] once you define the function
bool Process::operator<(Process const& a) const {
  return CpuUtilization() < a.CpuUtilization();
}