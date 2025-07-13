
#include "RosTwistSubscriber.h"

RosTwistSubscriber::RosTwistSubscriber(
    rcl_node_t *node, 
    rclc_executor_t *executor, 
    String name,
    void (*onReceiveMessage)(const void *) 
)
{
    // Create subscriber
    CHECK(
        "Error to create subscriber: " + name,
        rclc_subscription_init_default(
            &subscriber,
            node,
            ROSIDL_GET_MSG_TYPE_SUPPORT(geometry_msgs, msg, Twist),
            toCharArray(name)
        )
    );

    CHECK(
        "Error suscribing to topic: " + name + " with geometry_msgs::msg::Twist type",
        rclc_executor_add_subscription(
            executor, 
            &subscriber, 
            &msg,
            onReceiveMessage,
            ON_NEW_DATA
        )
    );

    msg = geometry_msgs__msg__Twist();
}

geometry_msgs__msg__Twist *RosTwistSubscriber::getTwist()
{
    return &msg;
}
