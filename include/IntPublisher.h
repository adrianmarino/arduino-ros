#pragma once
#include "RosMessage.h"
#include "MicroRosPublisher.h"

/**
 * IntPublisher class for publishing integer values using micro-ROS.
 *
 * This class provides methods to create a publisher and publish integer values
 * using the micro-ROS framework.
 */
class IntPublisher {
public:
    /**
     * Constructor for IntPublisher.
     * @param publisher Pointer to the MicroRosPublisher object
     */
    IntPublisher(MicroRosPublisher* publisher);

    /**
     * Publish the integer value.
     * @param value Integer value to be published.
     */
    void publish(int value);

private:
    MicroRosPublisher *publisher;
    std_msgs__msg__Int32 *msg;
};