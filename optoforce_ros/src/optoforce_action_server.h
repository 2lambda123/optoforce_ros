#include "optoforce_node.h"
#include <actionlib/server/simple_action_server.h>
#include <optoforce_ros/OptoForceAction.h>

//typedef actionlib::SimpleActionServer<optoforce_ros::OptoForceAction> ActionServer;

class optoforce_action_server : public optoforce_node {

  public:

    // Constructor
    // Initialize ROS Subscribers
    optoforce_action_server(std::string name);

    // Destructor
    ~optoforce_action_server();

    // Inherited virtual method from optoforce_node
    // Start transmision trough topics, only enable the flag
    void transmitStart ();

    // Inherited virtual method from optoforce_node
    // Stop transmision trough topics, only enable the flag
    void transmitStop ();

    void executeCB(const actionlib::SimpleActionServer<optoforce_ros::OptoForceAction>::GoalConstPtr& goal);

  private:
    //ActionServer as_;
    ros::NodeHandle nh_;
    actionlib::SimpleActionServer<optoforce_ros::OptoForceAction> as_;
    std::string action_name_;

    optoforce_ros::OptoForceGoal goal_; // goal message, received from client
    optoforce_ros::OptoForceResult result_; // put results here, to be sent back to the client when done w/ goal
    optoforce_ros::OptoForceFeedback feedback_; // for feedback


};
