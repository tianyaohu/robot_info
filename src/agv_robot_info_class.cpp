#include "robot_info/agv_robot_info_class.h"
#include "robot_info/robot_info_class.h"
#include <ros/ros.h>

AGVRobotInfo::AGVRobotInfo(ros::NodeHandle *node_handle, std::string *arrValue,
                           std::string oil_temp, std::string tank_level,
                           std::string oil_pres, const std::string *arrName)
    : RobotInfo(node_handle, arrValue, arrName),
      hsm(oil_temp, tank_level, oil_pres) {}

void AGVRobotInfo::init_max_payload(std::string *max_load) {
  if (!max_load->empty()) {
    msg_info.vec1.emplace_back("maximum_payload");
    msg_info.vec2.emplace_back(max_load->c_str());
    max_load++; // change pointer to empty;
  }
}

void AGVRobotInfo::update_msg_with_hydr_sys_monitor() {
  // push header to vec1
  //   for (const std::string &header : hsm.getAllHeaders()) {
  //     msg_info.vec1.push_back(header);
  //   }
  const std::string *headers = HydraulicSystemMonitor::getAllHeaders();
  while (!headers->empty()) {
    msg_info.vec1.push_back(headers->c_str());
    ROS_INFO("updating vec1 with %s", headers->c_str());
    headers++;
  }
  // push values to vec2
  msg_info.vec2.push_back(hsm.getOilTemp().c_str());
  msg_info.vec2.push_back(hsm.getTankLevel().c_str());
  msg_info.vec2.push_back(hsm.getOilPressure().c_str());
}

void AGVRobotInfo::publish_data() {
  pub_info.publish(msg_info);
  ros::spinOnce();
  ROS_INFO("AGV infor node Published Information message");
}
