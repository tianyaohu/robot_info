#pragma once
#include "robot_info/hydraulic_system_monitor.h"
#include "robot_info/robot_info_class.h"
#include "ros/node_handle.h"
#include <ros/ros.h>
#include <string>
#include <vector>
using namespace std;

class AGVRobotInfo : private RobotInfo {
public:
  AGVRobotInfo(ros::NodeHandle *node_handle, std::string *arrValue,
               std::string oil_temp, std::string tank_level,
               std::string oil_pres,
               const std::string *arrName = DEFAULT_NAMES);

  void init_max_payload(std::string *max_load);
  void update_msg_with_hydr_sys_monitor();

  void publish_data() override;

protected:
  std::string *maximum_payload;
  HydraulicSystemMonitor hsm;
};