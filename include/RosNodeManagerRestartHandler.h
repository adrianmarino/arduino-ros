#pragma once
#include "RosNodeManager.h"
#include <DeltaTimeComputer.h>

class RosNodeManagerRestartHandler
{
private:
    RosNodeManager *nodeManager;
    const int timeout_ms;
    DeltaTimeComputer *checkConnection;

    void restart();

public:
    RosNodeManagerRestartHandler(
        RosNodeManager *nodeManager,
        const int checkConnectionIntervalMs = 10000,
        const int timeout_ms = 5000);

    void update();
};