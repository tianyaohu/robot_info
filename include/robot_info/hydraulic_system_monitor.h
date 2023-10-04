#pragma once
#include <string>

class HydraulicSystemMonitor {

public:
  HydraulicSystemMonitor(std::string oil_temp, std::string tank_level,
                         std::string oil_pres);


  const static std::string HEADERS[3];
  // setter
  void setOilTemp(std::string t) { hydraulic_oil_temperature = t; }
  // Getter
  std::string getOilTemp() { return hydraulic_oil_temperature; }
  // setter
  void setTankLevel(std::string l) { hydraulic_oil_tank_fill_level = l; }
  // Getter
  std::string getTankLevel() { return hydraulic_oil_tank_fill_level; }
  // setter
  void setOilPressure(std::string p) { hydraulic_oil_pressure = p; }
  // Getter
  std::string getOilPressure() { return hydraulic_oil_pressure; }

  static const std::string* getAllHeaders();

private:

  std::string hydraulic_oil_temperature;
  std::string hydraulic_oil_tank_fill_level;
  std::string hydraulic_oil_pressure;
};