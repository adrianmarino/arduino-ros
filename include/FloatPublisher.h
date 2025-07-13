#pragma once
#include "RosMessage.h"
#include "MicroRosPublisher.h"

/**
 * FloatPublisher class for publishing float values using micro-ROS.
 *
 * This class provides methods to create a publisher and publish float values
 * using the micro-ROS framework.
 */
class FloatPublisher {
public:
    /**
     * Constructor for FloatPublisher.
     * @param publisher Pointer to the MicroRosPublisher object
     */
    FloatPublisher(MicroRosPublisher* publisher);

    /**
     * Publish the float value.
     * @param value Float value to be published.
     */
    void publish(int value);

private:
    MicroRosPublisher *publisher;
    std_msgs__msg__Float32 *msg;
};