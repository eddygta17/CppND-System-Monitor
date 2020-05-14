#include "processor.h"

// TODO: Return the aggregate CPU utilization
float Processor::Utilization() {
  std::string cpu, user, nice, system, idle, iowait, irq, softirq, steal, guest,
      guest_nice;
  std::string line;
  std::ifstream stream(LinuxParser::kProcDirectory +
                       LinuxParser::kStatFilename);
  if (stream.is_open()) {
    std::getline(stream, line);
    std::istringstream linestream(line);
    linestream >> cpu >> user >> nice >> system >> idle >> iowait >> irq >>
        softirq >> steal >> guest >> guest_nice;
  }


  int idletime = std::stoi(idle) + std::stoi(iowait);
  int nonidletime = std::stoi(user) + std::stoi(nice) + std::stoi(system) + std::stoi(irq) + std::stoi(softirq) + std::stoi(steal);
  float totaltime = idletime + nonidletime;
  float util_ = (totaltime - idletime)/totaltime;
  return util_;
}