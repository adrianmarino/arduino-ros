#include <RosNodeManager.h>

RosNodeManager::RosNodeManager(
    String nodeName,
    String wifi_ssid,
    String wifi_pass,
    String agent_ip,
    uint16_t agent_port,
    bool wifiEnergySavingMode,
    wifi_power_t wifi_power,
    bool syncTime)
{
    this->nodeName = nodeName;
    this->wifi_ssid = wifi_ssid;
    this->wifi_pass = wifi_pass;
    this->agent_ip = agent_ip;
    this->agent_port = agent_port;
    this->wifiEnergySavingMode = wifiEnergySavingMode;
    this->wifi_power = wifi_power;
    this->syncTime = syncTime;
}

void RosNodeManager::initWifi()
{
    logger.info("Wait for wifi connection...");
    connect_to_agent_via_wifi(
        nodeName,
        wifi_ssid,
        wifi_pass,
        agent_ip,
        agent_port,
        wifiEnergySavingMode,
        wifi_power);
}

RosNodeManager *RosNodeManager::setup()
{
    this->initWifi();

    if(syncTime) {
        syncClockTimeStamp(AR_UTC_TIME_OFFSET_IN_SECONDS);
    }

    // Create init_options
    assertOk(
        rclc_support_init(
            &support,
            0,
            NULL,
            &allocator),
        "Can't create support for node: " + nodeName);

    // Create node
    char *charNodeName = toCharArray(nodeName);

    assertOk(
        rclc_node_init_default(
            &node,
            charNodeName,
            "",
            &support),
        "Can't create micro-ros node: " + nodeName);

    delete charNodeName;

    assertOk(
        rclc_executor_init(
            &executor,
            &support.context,
            1,
            &allocator),
        "Error to create executor for node: " + nodeName);

    logger.info("Connected to Ros2 Agent");
    return this;
}

rclc_support_t *RosNodeManager::getSupport()
{
    return &support;
};

rcl_node_t *RosNodeManager::getNode()
{
    return &node;
};

rcl_allocator_t *RosNodeManager::getAllocator()
{
    return &allocator;
}

rclc_executor_t *RosNodeManager::getExecutor()
{
    return &executor;
}

bool RosNodeManager::update(const uint64_t timeout_ns)
{
    return assertOk(
        rclc_executor_spin_some(
            &executor,
            timeout_ns),
        "Cant't Node Manager state");
}

bool RosNodeManager::isConnected(const int timeout_ms, const uint8_t attempts)
{
    return rmw_uros_ping_agent(timeout_ms, attempts) == RMW_RET_OK;
}