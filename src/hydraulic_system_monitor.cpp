#include "robot_info/hydraulic_system_monitor.h"
#include <ros/ros.h>

const std::string HydraulicSystemMonitor::HEADERS[3] = {
    "hydraulic_oil_temperature", "hydraulic_oil_tank_fill_level",
    "hydraulic_oil_pressure"};

HydraulicSystemMonitor::HydraulicSystemMonitor(std::string oil_temp,
                                               std::string tank_level,
                                               std::string oil_pres)
    : hydraulic_oil_temperature(oil_temp),
      hydraulic_oil_tank_fill_level(tank_level),
      hydraulic_oil_pressure(oil_pres) {}

const std::string *HydraulicSystemMonitor::getAllHeaders() {
  return HydraulicSystemMonitor::HEADERS;
}
