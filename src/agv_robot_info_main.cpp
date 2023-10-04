#include "robot_info/agv_robot_info_class.h" //header file required
#include <ros/ros.h>

// declear main function
int main(int argc, char **argv) {
  // start ros node with NODE_NAME (HAS TO MATCH LAUNCH FILE "name" field
  ros::init(argc, argv, "robot_info_node");
  ros::NodeHandle nh;
  string test[4] = {"Mir100", "56 7A359", "169.254.5.180", "3.5.8"};
  string oil_temp("45C");
  string tank_level("100%");
  string oil_pres("250 bar");
  AGVRobotInfo ri = AGVRobotInfo(&nh, test, oil_temp, tank_level, oil_pres);
  // init payload
  std::string payload = "100 kg";
  ri.init_max_payload(&payload);
  //init hydraulic system monitor
  ri.update_msg_with_hydr_sys_monitor();

  //continuously publishing message until ^c
  while (nh.ok()) {
    ri.publish_data();
    usleep(1000000);
  }

  ri.publish_data();
  ros::spin(); // spin the ros node
}