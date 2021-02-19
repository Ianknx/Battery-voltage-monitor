// ADS 1x115 4 channel Battery voltage

#include <Arduino.h>

//#define SERIAL_DEBUG_DISABLED

#define USE_LIB_WEBSOCKET true

#include "sensesp_app.h"
#include "sensors/ads1x15.h"
#include "signalk/signalk_output.h"
#include "transforms/linear.h"
#include "transforms/voltage_multiplier.h"

ReactESP app([]() {
#ifndef SERIAL_DEBUG_DISABLED
  SetupSerialDebug(115200);
#endif

  sensesp_app = new SensESPApp();

  // Create an instance of a ADS1115 Analog-to-Digital Converter (ADC).
  
  adsGain_t gain = GAIN_TWOTHIRDS;
  ADS1115* ads1115 = new ADS1115(0x48, gain);

  // Create an instance of ADS1115Voltage to read a specific channel of the ADC,
  
  // revert it back to the voltage that was read by the ADC.

  ADS1x15Channel_t channel_12V  = channel_0;
  ADS1x15Channel_t channel_12V1 = channel_1;
  ADS1x15Channel_t channel_12V2 = channel_2;
  ADS1x15Channel_t channel_12V3 = channel_3;


  // Set time for taking readings from batteries, can be incresed or decreased as neccesary
  uint read_delay_12V = 5000;



     //**********************************************************
     //READ THE VOLTAGE AS SUPPLIED THROUGH A 12V VOLTAGE DIVIDER
     // *****  DO NOT ATTACH DIRECT TO 12V SUPPLY******
     //**********************************************************


// Battery 1
   auto* alt_12v_voltage = new ADS1115Voltage(ads1115, channel_12V, read_delay_12V,
                                             "/12V_Alt/ADC read delay");

//Battery 2
  auto* alt_12v1_voltage = new ADS1115Voltage(ads1115, channel_12V1, read_delay_12V,
                                             "/12V_Alt/ADC read delay");
//Battery 3
  auto* alt_12v2_voltage = new ADS1115Voltage(ads1115, channel_12V2, read_delay_12V,
                                             "/12V_Alt/ADC read delay");

//Battery 4
  auto* alt_12v3_voltage = new ADS1115Voltage(ads1115, channel_12V3, read_delay_12V,
                                             "/12V_Alt/ADC read delay");


 
  
  
  // To find valid Signal K Paths that fits your need you look at this link:
  // https://signalk.org/specification/1.4.0/doc/vesselsBranch.html#vesselsregexpelectrical


  //Battery1

       alt_12v_voltage->connect_to(new VoltageMultiplier(
                                  10000, 4730,                
                                  "/12V_Alt/VoltMultiplier")) 
      ->connect_to(new SKOutputNumber("electrical.battery 1.voltage",
                                      "/12V_Alt/skPath"));


       alt_12v1_voltage->connect_to(new VoltageMultiplier(
                                  10000, 4730,                
                                  "/12V_Alt/VoltMultiplier")) 
      ->connect_to(new SKOutputNumber("electrical.battery 2.voltage",
                                      "/12V1_Alt/skPath"));
                               

      alt_12v2_voltage->connect_to(new VoltageMultiplier(
                                  10000, 4730,                
                                  "/12V_Alt/VoltMultiplier")) 
      ->connect_to(new SKOutputNumber("electrical.battery 3.voltage",
                                      "/12V1_Alt/skPath"));


      alt_12v3_voltage->connect_to(new VoltageMultiplier(
                                  10000, 4730,
                                             
                                  "/12V_Alt/VoltMultiplier")) 
      ->connect_to(new SKOutputNumber("electrical.battery 4.voltage",
                                      "/12V1_Alt/skPath"));
                               


                               
  


  sensesp_app->enable();
});