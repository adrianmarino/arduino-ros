#include "RosUtils.h"
#include "Logger.h"


bool assertOk(rcl_ret_t result, String msg) {
    if(result == RCL_RET_OK) {
      return true;
    } else {
      logger.error(msg);
      return false; 
    }
}

void connect_to_agent_via_wifi(
    String hostname,
    String wifi_ssid,
    String wifi_pass,
    String agent_ip,
    uint16_t agent_port,
    bool energySavingMode,
  wifi_power_t wifi_power)
{
  WiFi.setHostname(toCharArray(hostname));

  if (!energySavingMode)
  {
    // Establece el ESP32 en modo estación
    WiFi.mode(WIFI_STA);
    // Desactiva el modo de ahorro de energía Wi-Fi
    WiFi.setSleep(energySavingMode);
  }

  IPAddress ip;
  ip.fromString(agent_ip);

  logger.info("Set Micro Ros wifi transports...");
  set_microros_wifi_transports(
      toCharArray(wifi_ssid),
      toCharArray(wifi_pass),
      ip,
      agent_port);

  logger.info("Wait for wifi connection...");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(100); 
    Serial.print(".");
  }

  if (WiFi.setTxPower(wifi_power))
    logger.info("Setup TX Power...");
  else
   logger. error("TX Power: Setup error...");

  logger.info("Wifi connection stablished...");
}