#pragma once
#include <micro_ros_platformio.h>
#include <rcl/rcl.h>
#include <rclc/rclc.h>
#include <rcl/error_handling.h>
#include <StringUtils.h>
#include <rcl/time.h>
#include <rcl/allocator.h>
#include <rosidl_runtime_c/string_functions.h>

const wifi_power_t WIFI_POWER_20_5dBm = (wifi_power_t)82; // 20.5 dBm * 4 = 82

bool assertOk(rcl_ret_t result, String msg);

/**
 * @brief Connect to the micro-ROS agent via Wi-Fi.
 *
 * This function connects to the micro-ROS agent using the provided Wi-Fi SSID,
 * password, IP address, and port number.
 *
 * @param wifi_ssid Wi-Fi SSID for connection.
 * @param wifi_pass Wi-Fi password for connection.
 * @param agent_ip IP address of the micro-ROS agent.
 * @param agent_port Port number of the micro-ROS agent (default is 8888).
 *
 */
void connect_to_agent_via_wifi(
    String hostname,
    String wifi_ssid,
    String wifi_pass,
    String agent_ip,
    uint16_t agent_port,
    bool energySavingMode,
    wifi_power_t wifi_power);

