#include <optoforce_ros/OptoForceAction.h>
#include <actionlib/client/simple_action_client.h>

typedef actionlib::SimpleActionClient<optoforce_ros::OptoForceAction> Client;

int main(int argc, char** argv)
{
  ros::init(argc, argv, "optoforce_action_client");

  Client client("action_server", true); // true -> don't need ros::spin()

  client.waitForServer(ros::Duration(5.0));

  optoforce_ros::OptoForceGoal goal;

  // Fill in goal here
  goal.duration = 5000;
  goal.freq = 1000;
  client.sendGoal(goal);
  client.waitForResult(ros::Duration(5.0));

  if (client.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    printf("Yay! The dishes are now clean");

  printf("Current State: %s\n", client.getState().toString().c_str());

  return 0;
}
