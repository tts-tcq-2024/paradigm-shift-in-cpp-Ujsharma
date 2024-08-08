#ifndef BATTERYPARAMETERCHECK_H
#define BATTERYPARAMETERCHECK_H

bool checkTemperature(float temperature);
bool checkSoc(float soc);
bool checkChargeRate(float chargeRate);
bool verifyBatteryStatus(float temperature, float soc, float chargeRate);

#endif // BATTERYPARAMETERCHECK_H
