/**
 * @file   optoforce_node.cpp
 * @author Asier Fernandez <asier.fernandez@tecnalia.com>
 * @date   2016
 *
 * Copyright 2016 Tecnalia Research & Innovation.
 * Distributed under the GNU GPL v3. For full terms see https://www.gnu.org/licenses/gpl.txt
 *
 * @brief OptoForce ROS node with an interface through topics.
 *        The program inherits optoforce_node, which:
 *          reads parameters from ROS parameter server
 *          initialize  optoforce driver
 *          get periodically wrench data
 *
 *        ROS Subscribers. Type std_msgs::Bool
 *          start_publishing:
 *            true:   start publishing wrench data
 *            false:  stop publishing wrench data
 *          start_new_acquisition:
 *            true:   start recording data to be stored in a csv file
 *            false:  stop recording data to be stored in a csv file
 *
 */

#include "optoforce_node.h"
#include "std_msgs/Bool.h"

class optoforce_topic : public optoforce_node {

  public:

    //! Constructor
    //! Initialize ROS Publishers and Subscribers
    optoforce_topic();

    //! Destructor
    ~optoforce_topic();

    //! Inherited virtual method from optoforce_node
    //! Start transmision trough topics, only enable the flag
    //! Add ROS Publisher and Subscribers
    void add_ros_interface();

    //! Inherited virtual method from optoforce_node
    //! Start transmision trough topics, only enable the flag
    int run ();


    //! Inherited virtual method from optoforce_node
    //! Start transmision trough topics, only enable the flag
    void transmitStart ();

    //! Inherited virtual method from optoforce_node
    //! Stop transmision trough topics, only enable the flag
    void transmitStop ();

  private:
    //! Wrench Publisher
    ros::Publisher wrench_pub_[2];

    //! ROS Subscribers
    //! subs_[0]: start_publishing
    //! subs_[1]: start_new_acquisition
    //! subs_[2]: auto_store
    ros::Subscriber subs_[3];

    //! Calback enable/disable publishing topic
    void startPublishingCB(const std_msgs::Bool::ConstPtr& msg);

    //! Calback enable/disable new acquisition
    void startRecordingCB(const std_msgs::Bool::ConstPtr& msg);

    //! Calback enable/disable auto-storing data after an acquisition starts
    void autoStoreCB(const std_msgs::Bool::ConstPtr& msg);

    bool start_recording_;


};