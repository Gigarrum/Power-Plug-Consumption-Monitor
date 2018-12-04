# Power-Plug-Consumption-Monitor
This project consists in a prototype of an power plug adapter to connect it to the internet and monitor the energy comsuption on it.

For this project it was used:
-An ESP8266 to send the data for a dashboard platform called Blynk, that can be used on mobile devices.  
-A current sensor SCT013 for measuring the actual current values on the power plug for estimate the comsumption on it.  
-Some others components as diodes, capacitors, resistors and an electrical transformer for being able to power the ESP8266 board with the energy coming from the power plug.  

<h1>Some References</h1>

Example code for using SCT013 -> https://www.filipeflop.com/blog/medidor-de-corrente-sct013-com-arduino/ (Unfortunatly the explanations are in Portuguese, but still have an example code :D)  

More technical information about SCT013 -> https://nicegear.nz/obj/pdf/SCT-013-datasheet.pdf  

Tutorial for using Blynk library for sending data to their platform -> https://www.blynk.cc/getting-started/   
                                                                    ->http://help.blynk.cc/getting-started-library-auth-token-code-examples/blynk-basics/how-to-display-any-sensor-data-in-blynk-app
                                                                    

