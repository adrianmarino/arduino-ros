#include "IntPublisher.h"

IntPublisher::IntPublisher(
    MicroRosPublisher *publisher)
{
    this->publisher = publisher;
    msg = createIntMessage();
}

void IntPublisher::publish(int value)
{
    msg->data = value;
    publisher->publish(msg);
}