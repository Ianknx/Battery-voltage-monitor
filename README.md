# Battery voltage 
  Battery voltage monitor for battery bank extendable.
  SignalK server.

  A battery monitor for a 12/24 volt battery bank working on the KISS principle which initialy is for four batteries but can be extended in groups of four.

  Using ESP8266 wifi module with ADS1115 ADC and output to Signal K.

  To be continued.......
  
  
  Example of Voltage Divider

  ![image](https://user-images.githubusercontent.com/31249487/108519770-e0297500-72c1-11eb-8fbb-234a1a7956ee.png)
  
  
  
 A Voltage divider simply consists of two resistors connected in series. As you can see the resistors values used in this module are 30k and 7.5k.
 
 Calculations are thus:-

maximum Input voltage of this NodeMCU (ESP8266) is 5 volts DC,

First we need to calculate the output voltage of the Voltage divider when the input supply is 14 volts, we use 14 Volts as a fully charged battery can be as high as 13.8Volts

==================================

Vin = 14V

R1 = 30000 ohm

r2 = 7500 ohm


Vout = ( r2  x  Vin ) / ( r1 + r2) 
 
Vout = (7500 x 14) / (30000 + 7500) 

       = 105000 / 37500
       =
       
Vout = 3.47 V Volt

So this Voltage divider can be used with the ADS 1115 (2V to 5v)and NodeMCU (3.3 or 5V) without any problem, the ESP8266 is a 3.3v microcontroller, applying more than 3.6v on any pin can damage the chip.

 Always try to keep the input Voltage to the Voltage divider below 18 volts, using the above formula 18 volts will give 3.6 volts.
 =================================================================================================================================
