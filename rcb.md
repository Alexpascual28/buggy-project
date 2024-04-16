<p align="center">
  <img src="https://www.svgrepo.com/show/311722/autonomous-car.svg" width="100" alt="project-logo">
</p>
<p align="center">
    <h1 align="center">RCB (Remote Control Buggy)</h1>
</p>
<p align="center">
    <em><code>Arduino remote control buggy project files, using Arduino UNO and ESP8266 NodeMCU. The final files can be found in the '00 Final' directory. MotorArduino must be loaded into the UNO board. MotorESP must be loaded into the NodeMCU ESP board.</code></em>
</p>

<br><!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary><br>

- [ Overview](#-overview)
- [ File Descriptions](#-features)
- [ Repository Structure](#-repository-structure)
- [ Modules](#-modules)
- [ Getting Started](#-getting-started)
  - [ Requirements](#requirements)
  - [ Installation](#-installation)
- [ Code](#code)
- [ Contributing](#-contributing)
</details>
<hr>

##  Overview

<code> This project details the construction and programming of a remote control buggy using Arduino UNO with ESP32 and ESP8266 modules. The control algorithm employs PWM modulation and a PD (Proportional-Derivative) control strategy to manage motor operations, while ensuring responsive and reliable control over a dedicated WiFi network using TCP for communications and data serialization. </code>

---

##  File Descriptions

1. 00 Final

* MotorArduino: Contains the final firmware for the Arduino UNO, which handles motor control, sensor readings, and other device-specific operations.
* MotorESP: Houses the final firmware for the ESP8266 NodeMCU, managing network communications, specifically handling TCP/IP protocols and WiFi connectivity.

2. Alex

* **ESP8266(WifiNodeMCU)**: Scripts for setting up and testing WiFi features on ESP8266.
* **H-Bridge**: Dedicated to controlling motor drivers via H-Bridge circuits.
* **H-Bridge_and_ESP8266**: Integrations of motor control and WiFi connectivity.
* **Joystick+UNO+ESP**: Integration scripts for controlling the buggy via a joystick through Arduino UNO and ESP communication links.
* **Megalovania**: Themed project with sound-related scripts.
* **MotorArduino**: Development versions of Arduino motor control scripts.
* **MotorESP**: Development versions of ESP8266 networking scripts.
* **testVoltage**: Scripts for testing voltage and power supply related functionalities.

3. Angel

* **Codigo_buggy_5**: Contains scripts and project files specifically worked on by Angel, a component of the buggy control system including an algorithm implementation for the buggy's control logic, tailored to refine performance metrics and add functionalities.

4. David

* **ESPudp**: Contains scripts related to UDP communication via ESP modules.
* **Joystick**: Scripts for handling joystick-based input controls.
* **MotorControl**: Dedicated to the development of motor control algorithms.
* **UART**: Focuses on serial communication between devices.
* **UDP**: Includes development and testing of UDP protocol communications.

5. SubProg

* **Codigo_buggy_5**: Additional supportive scripts for the buggy control system, similar to Angel’s directory.
* **ESPudp**: Related to UDP communications using ESP modules.
* **ESP_from_Arduino_UDP**: Handling of UDP messages sent from Arduino to ESP.
* **Joystick**: Related to the development and testing of joystick functionalities.
* **Joysticktest1-UNO**: Specific tests involving a joystick and Arduino UNO setup.
* **MotorControl**: Scripts and tools for motor control functionalities.
* **UART**: Serial communication related scripts and utilities.
* **UDP**: Scripts for managing UDP communications.

---

##  Repository Structure

```sh
└── rcb_buggy/
    ├── 00 Final
    │   ├── MotorArduino
    │   └── MotorESP
    ├── Alex
    │   ├── ESP8266(WifiNodeMCU)
    │   ├── H-Bridge
    │   ├── H-Bridge_and_ESP8266
    │   ├── Joystick+UNO+ESP
    │   ├── Megalovania
    │   ├── MotorArduino
    │   ├── MotorESP
    │   └── testVoltage
    ├── Angel
    │   └── Codigo_buggy_5
    ├── David
    │   ├── ESPudp
    │   ├── Joystick
    │   ├── MotorControl
    │   ├── UART
    │   └── UDP
    ├── README.md
    └── SubProg
        ├── Codigo_buggy_5
        ├── ESP_from_Arduino_UDP
        ├── ESPudp
        ├── Joystick
        ├── Joysticktest1-UNO
        ├── MotorControl
        ├── UART
        └── UDP
```

---

##  Modules

<details closed><summary>All Modules</summary>

<details closed><summary>00 Final.MotorESP</summary>

| File                                                                                                      | Summary                         |
| ---                                                                                                       | ---                             |
| [MotorESP.ino](https://github.com/Alexpascual28/rcb_buggy.git/blob/master/00 Final/MotorESP/MotorESP.ino) | <code>► INSERT-TEXT-HERE</code> |

</details>

<details closed><summary>00 Final.MotorArduino</summary>

| File                                                                                                                  | Summary                         |
| ---                                                                                                                   | ---                             |
| [MotorArduino.ino](https://github.com/Alexpascual28/rcb_buggy.git/blob/master/00 Final/MotorArduino/MotorArduino.ino) | <code>► INSERT-TEXT-HERE</code> |

</details>

<details closed><summary>SubProg.ESP_from_Arduino_UDP</summary>

| File                                                                                                                                         | Summary                         |
| ---                                                                                                                                          | ---                             |
| [ESP_from_Arduino_UDP.ino](https://github.com/Alexpascual28/rcb_buggy.git/blob/master/SubProg/ESP_from_Arduino_UDP/ESP_from_Arduino_UDP.ino) | <code>► INSERT-TEXT-HERE</code> |

</details>

<details closed><summary>SubProg.Joysticktest1-UNO</summary>

| File                                                                                                                                | Summary                         |
| ---                                                                                                                                 | ---                             |
| [Joysticktest1-UNO.ino](https://github.com/Alexpascual28/rcb_buggy.git/blob/master/SubProg/Joysticktest1-UNO/Joysticktest1-UNO.ino) | <code>► INSERT-TEXT-HERE</code> |

</details>

<details closed><summary>SubProg.UDP</summary>

| File                                                                                      | Summary                         |
| ---                                                                                       | ---                             |
| [UDP.ino](https://github.com/Alexpascual28/rcb_buggy.git/blob/master/SubProg/UDP/UDP.ino) | <code>► INSERT-TEXT-HERE</code> |

</details>

<details closed><summary>SubProg.UART.ESP_to_Arduino</summary>

| File                                                                                                                            | Summary                         |
| ---                                                                                                                             | ---                             |
| [ESP_to_Arduino.ino](https://github.com/Alexpascual28/rcb_buggy.git/blob/master/SubProg/UART/ESP_to_Arduino/ESP_to_Arduino.ino) | <code>► INSERT-TEXT-HERE</code> |
| [ESP_to_Arduino.txt](https://github.com/Alexpascual28/rcb_buggy.git/blob/master/SubProg/UART/ESP_to_Arduino/ESP_to_Arduino.txt) | <code>► INSERT-TEXT-HERE</code> |

</details>

<details closed><summary>SubProg.UART.Arduino_to_ESP_communication</summary>

| File                                                                                                                                                                      | Summary                         |
| ---                                                                                                                                                                       | ---                             |
| [Arduino_to_ESP_communication.ino](https://github.com/Alexpascual28/rcb_buggy.git/blob/master/SubProg/UART/Arduino_to_ESP_communication/Arduino_to_ESP_communication.ino) | <code>► INSERT-TEXT-HERE</code> |

</details>

<details closed><summary>SubProg.UART.Arduino_from_ESP</summary>

| File                                                                                                                                  | Summary                         |
| ---                                                                                                                                   | ---                             |
| [Arduino_from_ESP.ino](https://github.com/Alexpascual28/rcb_buggy.git/blob/master/SubProg/UART/Arduino_from_ESP/Arduino_from_ESP.ino) | <code>► INSERT-TEXT-HERE</code> |

</details>

<details closed><summary>SubProg.UART.ESP_from_Arduino_communication</summary>

| File                                                                                                                                                                            | Summary                         |
| ---                                                                                                                                                                             | ---                             |
| [ESP_from_Arduino_communication.ino](https://github.com/Alexpascual28/rcb_buggy.git/blob/master/SubProg/UART/ESP_from_Arduino_communication/ESP_from_Arduino_communication.ino) | <code>► INSERT-TEXT-HERE</code> |

</details>

<details closed><summary>SubProg.Codigo_buggy_5</summary>

| File                                                                                                                       | Summary                         |
| ---                                                                                                                        | ---                             |
| [Codigo_buggy_5.ino](https://github.com/Alexpascual28/rcb_buggy.git/blob/master/SubProg/Codigo_buggy_5/Codigo_buggy_5.ino) | <code>► INSERT-TEXT-HERE</code> |

</details>

<details closed><summary>SubProg.ESPudp</summary>

| File                                                                                               | Summary                         |
| ---                                                                                                | ---                             |
| [ESPudp.ino](https://github.com/Alexpascual28/rcb_buggy.git/blob/master/SubProg/ESPudp/ESPudp.ino) | <code>► INSERT-TEXT-HERE</code> |

</details>

<details closed><summary>SubProg.Joystick</summary>

| File                                                                                                     | Summary                         |
| ---                                                                                                      | ---                             |
| [Joystick.ino](https://github.com/Alexpascual28/rcb_buggy.git/blob/master/SubProg/Joystick/Joystick.ino) | <code>► INSERT-TEXT-HERE</code> |

</details>

<details closed><summary>SubProg.MotorControl</summary>

| File                                                                                                                 | Summary                         |
| ---                                                                                                                  | ---                             |
| [MotorControl.ino](https://github.com/Alexpascual28/rcb_buggy.git/blob/master/SubProg/MotorControl/MotorControl.ino) | <code>► INSERT-TEXT-HERE</code> |

</details>

<details closed><summary>David.UDP</summary>

| File                                                                                    | Summary                         |
| ---                                                                                     | ---                             |
| [UDP.ino](https://github.com/Alexpascual28/rcb_buggy.git/blob/master/David/UDP/UDP.ino) | <code>► INSERT-TEXT-HERE</code> |

</details>

<details closed><summary>David.UART.ESP_to_Arduino</summary>

| File                                                                                                                          | Summary                         |
| ---                                                                                                                           | ---                             |
| [ESP_to_Arduino.ino](https://github.com/Alexpascual28/rcb_buggy.git/blob/master/David/UART/ESP_to_Arduino/ESP_to_Arduino.ino) | <code>► INSERT-TEXT-HERE</code> |
| [ESP_to_Arduino.txt](https://github.com/Alexpascual28/rcb_buggy.git/blob/master/David/UART/ESP_to_Arduino/ESP_to_Arduino.txt) | <code>► INSERT-TEXT-HERE</code> |

</details>

<details closed><summary>David.UART.Arduino_to_ESP_communication</summary>

| File                                                                                                                                                                    | Summary                         |
| ---                                                                                                                                                                     | ---                             |
| [Arduino_to_ESP_communication.ino](https://github.com/Alexpascual28/rcb_buggy.git/blob/master/David/UART/Arduino_to_ESP_communication/Arduino_to_ESP_communication.ino) | <code>► INSERT-TEXT-HERE</code> |

</details>

<details closed><summary>David.UART.Arduino_from_ESP</summary>

| File                                                                                                                                | Summary                         |
| ---                                                                                                                                 | ---                             |
| [Arduino_from_ESP.ino](https://github.com/Alexpascual28/rcb_buggy.git/blob/master/David/UART/Arduino_from_ESP/Arduino_from_ESP.ino) | <code>► INSERT-TEXT-HERE</code> |

</details>

<details closed><summary>David.UART.ESP_from_Arduino_communication</summary>

| File                                                                                                                                                                          | Summary                         |
| ---                                                                                                                                                                           | ---                             |
| [ESP_from_Arduino_communication.ino](https://github.com/Alexpascual28/rcb_buggy.git/blob/master/David/UART/ESP_from_Arduino_communication/ESP_from_Arduino_communication.ino) | <code>► INSERT-TEXT-HERE</code> |

</details>

<details closed><summary>David.ESPudp</summary>

| File                                                                                             | Summary                         |
| ---                                                                                              | ---                             |
| [ESPudp.ino](https://github.com/Alexpascual28/rcb_buggy.git/blob/master/David/ESPudp/ESPudp.ino) | <code>► INSERT-TEXT-HERE</code> |

</details>

<details closed><summary>David.Joystick</summary>

| File                                                                                                   | Summary                         |
| ---                                                                                                    | ---                             |
| [Joystick.ino](https://github.com/Alexpascual28/rcb_buggy.git/blob/master/David/Joystick/Joystick.ino) | <code>► INSERT-TEXT-HERE</code> |

</details>

<details closed><summary>David.MotorControl</summary>

| File                                                                                                               | Summary                         |
| ---                                                                                                                | ---                             |
| [MotorControl.ino](https://github.com/Alexpascual28/rcb_buggy.git/blob/master/David/MotorControl/MotorControl.ino) | <code>► INSERT-TEXT-HERE</code> |

</details>

<details closed><summary>Angel.Codigo_buggy_5</summary>

| File                                                                                                                     | Summary                         |
| ---                                                                                                                      | ---                             |
| [Codigo_buggy_5.ino](https://github.com/Alexpascual28/rcb_buggy.git/blob/master/Angel/Codigo_buggy_5/Codigo_buggy_5.ino) | <code>► INSERT-TEXT-HERE</code> |

</details>

<details closed><summary>Alex.H-Bridge.hbridge_motors_test</summary>

| File                                                                                                                                            | Summary                         |
| ---                                                                                                                                             | ---                             |
| [hbridge_motors_test.ino](https://github.com/Alexpascual28/rcb_buggy.git/blob/master/Alex/H-Bridge/hbridge_motors_test/hbridge_motors_test.ino) | <code>► INSERT-TEXT-HERE</code> |

</details>

<details closed><summary>Alex.ESP8266(WifiNodeMCU).Station Mode.scan_networks_test1</summary>

| File                                                                                                                                                                     | Summary                         |
| ---                                                                                                                                                                      | ---                             |
| [scan_networks_test1.ino](https://github.com/Alexpascual28/rcb_buggy.git/blob/master/Alex/ESP8266(WifiNodeMCU)/Station Mode/scan_networks_test1/scan_networks_test1.ino) | <code>► INSERT-TEXT-HERE</code> |

</details>

<details closed><summary>Alex.ESP8266(WifiNodeMCU).Station Mode.station_mode_setup_test1</summary>

| File                                                                                                                                                                                    | Summary                         |
| ---                                                                                                                                                                                     | ---                             |
| [station_mode_setup_test1.ino](https://github.com/Alexpascual28/rcb_buggy.git/blob/master/Alex/ESP8266(WifiNodeMCU)/Station Mode/station_mode_setup_test1/station_mode_setup_test1.ino) | <code>► INSERT-TEXT-HERE</code> |

</details>

<details closed><summary>Alex.ESP8266(WifiNodeMCU).Station Mode.station_mode_test1_LED</summary>

| File                                                                                                                                                                              | Summary                         |
| ---                                                                                                                                                                               | ---                             |
| [station_mode_test1_LED.ino](https://github.com/Alexpascual28/rcb_buggy.git/blob/master/Alex/ESP8266(WifiNodeMCU)/Station Mode/station_mode_test1_LED/station_mode_test1_LED.ino) | <code>► INSERT-TEXT-HERE</code> |

</details>

<details closed><summary>Alex.ESP8266(WifiNodeMCU).MAC_Address</summary>

| File                                                                                                                                | Summary                         |
| ---                                                                                                                                 | ---                             |
| [MAC_Address.ino](https://github.com/Alexpascual28/rcb_buggy.git/blob/master/Alex/ESP8266(WifiNodeMCU)/MAC_Address/MAC_Address.ino) | <code>► INSERT-TEXT-HERE</code> |

</details>

<details closed><summary>Alex.ESP8266(WifiNodeMCU).ESP8266-AP-JSON</summary>

| File                                                                                                                                            | Summary                         |
| ---                                                                                                                                             | ---                             |
| [ESP8266-AP-JSON.ino](https://github.com/Alexpascual28/rcb_buggy.git/blob/master/Alex/ESP8266(WifiNodeMCU)/ESP8266-AP-JSON/ESP8266-AP-JSON.ino) | <code>► INSERT-TEXT-HERE</code> |

</details>

<details closed><summary>Alex.ESP8266(WifiNodeMCU).UDP_comm</summary>

| File                                                                                                                       | Summary                         |
| ---                                                                                                                        | ---                             |
| [UDP_comm.ino](https://github.com/Alexpascual28/rcb_buggy.git/blob/master/Alex/ESP8266(WifiNodeMCU)/UDP_comm/UDP_comm.ino) | <code>► INSERT-TEXT-HERE</code> |

</details>

<details closed><summary>Alex.ESP8266(WifiNodeMCU).Access point mode.retrieve_data_pureHTML_test3</summary>

| File                                                                                                                                                                                                     | Summary                         |
| ---                                                                                                                                                                                                      | ---                             |
| [retrieve_data_pureHTML_test3.ino](https://github.com/Alexpascual28/rcb_buggy.git/blob/master/Alex/ESP8266(WifiNodeMCU)/Access point mode/retrieve_data_pureHTML_test3/retrieve_data_pureHTML_test3.ino) | <code>► INSERT-TEXT-HERE</code> |

</details>

<details closed><summary>Alex.ESP8266(WifiNodeMCU).Access point mode.access_point_test1</summary>

| File                                                                                                                                                                       | Summary                         |
| ---                                                                                                                                                                        | ---                             |
| [access_point_test1.ino](https://github.com/Alexpascual28/rcb_buggy.git/blob/master/Alex/ESP8266(WifiNodeMCU)/Access point mode/access_point_test1/access_point_test1.ino) | <code>► INSERT-TEXT-HERE</code> |

</details>

<details closed><summary>Alex.ESP8266(WifiNodeMCU).Access point mode.retrieve_data_html_Static</summary>

| File                                                                                                                                                                                            | Summary                         |
| ---                                                                                                                                                                                             | ---                             |
| [retrieve_data_html_Static.ino](https://github.com/Alexpascual28/rcb_buggy.git/blob/master/Alex/ESP8266(WifiNodeMCU)/Access point mode/retrieve_data_html_Static/retrieve_data_html_Static.ino) | <code>► INSERT-TEXT-HERE</code> |

</details>

<details closed><summary>Alex.ESP8266(WifiNodeMCU).Access point mode.access_point_load_HTML</summary>

| File                                                                                                                                                                                   | Summary                         |
| ---                                                                                                                                                                                    | ---                             |
| [access_point_load_HTML.ino](https://github.com/Alexpascual28/rcb_buggy.git/blob/master/Alex/ESP8266(WifiNodeMCU)/Access point mode/access_point_load_HTML/access_point_load_HTML.ino) | <code>► INSERT-TEXT-HERE</code> |

</details>

<details closed><summary>Alex.ESP8266(WifiNodeMCU).Access point mode.retrieve_data_html</summary>

| File                                                                                                                                                                       | Summary                         |
| ---                                                                                                                                                                        | ---                             |
| [retrieve_data_html.ino](https://github.com/Alexpascual28/rcb_buggy.git/blob/master/Alex/ESP8266(WifiNodeMCU)/Access point mode/retrieve_data_html/retrieve_data_html.ino) | <code>► INSERT-TEXT-HERE</code> |

</details>

<details closed><summary>Alex.testVoltage</summary>

| File                                                                                                           | Summary                         |
| ---                                                                                                            | ---                             |
| [testVoltage.ino](https://github.com/Alexpascual28/rcb_buggy.git/blob/master/Alex/testVoltage/testVoltage.ino) | <code>► INSERT-TEXT-HERE</code> |

</details>

<details closed><summary>Alex.MotorESP</summary>

| File                                                                                                  | Summary                         |
| ---                                                                                                   | ---                             |
| [MotorESP.ino](https://github.com/Alexpascual28/rcb_buggy.git/blob/master/Alex/MotorESP/MotorESP.ino) | <code>► INSERT-TEXT-HERE</code> |

</details>

<details closed><summary>Alex.MotorArduino</summary>

| File                                                                                                              | Summary                         |
| ---                                                                                                               | ---                             |
| [MotorArduino.ino](https://github.com/Alexpascual28/rcb_buggy.git/blob/master/Alex/MotorArduino/MotorArduino.ino) | <code>► INSERT-TEXT-HERE</code> |

</details>

<details closed><summary>Alex.Joystick+UNO+ESP.ESP_from_Arduino_UDP</summary>

| File                                                                                                                                                       | Summary                         |
| ---                                                                                                                                                        | ---                             |
| [ESP_from_Arduino_UDP.ino](https://github.com/Alexpascual28/rcb_buggy.git/blob/master/Alex/Joystick+UNO+ESP/ESP_from_Arduino_UDP/ESP_from_Arduino_UDP.ino) | <code>► INSERT-TEXT-HERE</code> |

</details>

<details closed><summary>Alex.Joystick+UNO+ESP.Joysticktest1-UNO</summary>

| File                                                                                                                                              | Summary                         |
| ---                                                                                                                                               | ---                             |
| [Joysticktest1-UNO.ino](https://github.com/Alexpascual28/rcb_buggy.git/blob/master/Alex/Joystick+UNO+ESP/Joysticktest1-UNO/Joysticktest1-UNO.ino) | <code>► INSERT-TEXT-HERE</code> |

</details>

<details closed><summary>Alex.Joystick+UNO+ESP.Arduino_to_ESP</summary>

| File                                                                                                                                     | Summary                         |
| ---                                                                                                                                      | ---                             |
| [Arduino_to_ESP.ino](https://github.com/Alexpascual28/rcb_buggy.git/blob/master/Alex/Joystick+UNO+ESP/Arduino_to_ESP/Arduino_to_ESP.ino) | <code>► INSERT-TEXT-HERE</code> |

</details>

<details closed><summary>Alex.Joystick+UNO+ESP.ESP_to_Arduino_TCP</summary>

| File                                                                                                                                                 | Summary                         |
| ---                                                                                                                                                  | ---                             |
| [ESP_to_Arduino_TCP.ino](https://github.com/Alexpascual28/rcb_buggy.git/blob/master/Alex/Joystick+UNO+ESP/ESP_to_Arduino_TCP/ESP_to_Arduino_TCP.ino) | <code>► INSERT-TEXT-HERE</code> |

</details>

<details closed><summary>Alex.Joystick+UNO+ESP.ESP_from_Arduino_TCP</summary>

| File                                                                                                                                                       | Summary                         |
| ---                                                                                                                                                        | ---                             |
| [ESP_from_Arduino_TCP.ino](https://github.com/Alexpascual28/rcb_buggy.git/blob/master/Alex/Joystick+UNO+ESP/ESP_from_Arduino_TCP/ESP_from_Arduino_TCP.ino) | <code>► INSERT-TEXT-HERE</code> |

</details>

<details closed><summary>Alex.H-Bridge_and_ESP8266.AP_HTMLjoystick_and_H-Bridge</summary>

| File                                                                                                                                                                                   | Summary                         |
| ---                                                                                                                                                                                    | ---                             |
| [AP_HTMLjoystick_and_H-Bridge.ino](https://github.com/Alexpascual28/rcb_buggy.git/blob/master/Alex/H-Bridge_and_ESP8266/AP_HTMLjoystick_and_H-Bridge/AP_HTMLjoystick_and_H-Bridge.ino) | <code>► INSERT-TEXT-HERE</code> |

</details>

<details closed><summary>Alex.Megalovania</summary>

| File                                                                                                           | Summary                         |
| ---                                                                                                            | ---                             |
| [Megalovania.ino](https://github.com/Alexpascual28/rcb_buggy.git/blob/master/Alex/Megalovania/Megalovania.ino) | <code>► INSERT-TEXT-HERE</code> |

</details>

</details>

---

##  Getting Started

### Requirements

**Hardware Requirements**

* Arduino UNO
* ESP32 Antenna
* ESP8266 NodeMCU
* Motor Driver (H-Bridge)
* Ultrasonic Sensor
* Connecting jumper wires and resistors

**Software and Libraries**

* Arduino IDE
* ESP8266WiFi library
* WiFiUDP library

Ensure these libraries are installed through the Arduino Library Manager.

###  Installation

<h4>From <code>source</code></h4>

> 1. Clone the rcb_buggy repository:
>
> ```console
> $ git clone https://github.com/Alexpascual28/rcb_buggy.git
> ```
>
> 2. Change to the project directory:
> ```console
> $ cd rcb_buggy
> ```

**Setup Instructions**

1. *Arduino Setup*:

* Upload `MotorArduino.ino` to the Arduino UNO.
* Connect motor drivers, ultrasonic sensors, and necessary LEDs as per pin configuration in the script.

2. *ESP8266 Setup*:

* Upload `MotorESP.ino` to the ESP8266 NodeMCU.
* Ensure that the device is configured to connect to the designated WiFi network.

3. *Network Configuration*:

* Set up a dedicated WiFi network with SSID and password as specified in `MotorESP.ino`.
* Verify IP addresses and ports are correctly set for TCP communication.

---

##  Code

### Mockups

**MotorArduino.ino**

> ```cpp
> void loop() {
>   receiveCommands();
>   setMotorVelocity();
>   collisionDetection();
>   debugOutputs();
> }
> 
> void receiveCommands() {
>   if (Serial.read() == 0x80) {
>     Lcomms = Serial.read();
>     Rcomms = Serial.read();
>     SW = Serial.read();
>   } else {
>     Serial.flush();
>   }
> }
> ```

**MotorESP.ino**

> ```cpp
> void loop() {
>   listenForUDP();
>   sendCommandToArduino();
> }
> 
> void listenForUDP() {
>   int packetSize = udp.parsePacket();
>   if (packetSize) {
>     udp.read(data, 3); // read the incoming bytes
>   }
> }
> ```

###  Description of Processes

**Motor Control and Communication**

The main control loop receives velocity commands via UART. Motor velocity is adjusted based on these inputs using PWM signals to the motor driver. Collision detection is handled via an ultrasonic sensor, where proximity thresholds trigger visual alerts via LEDs.

**Networking and Data Handling**

The ESP8266 handles the WiFi connectivity, setting up an access point and listening for UDP packets. Commands are serialized and sent to the Arduino for processing. This ensures reliable communication between the remote control and the buggy.

---

##  Contributing

Contributions are welcome! Here are several ways you can contribute:

- **[Report Issues](https://github.com/Alexpascual28/rcb_buggy.git/issues)**: Submit bugs found or log feature requests for the `rcb_buggy` project.
- **[Submit Pull Requests](https://github.com/Alexpascual28/rcb_buggy.git/blob/main/CONTRIBUTING.md)**: Review open PRs, and submit your own PRs.
- **[Join the Discussions](https://github.com/Alexpascual28/rcb_buggy.git/discussions)**: Share your insights, provide feedback, or ask questions.

<details closed>
<summary>Contributing Guidelines</summary>

1. **Fork the Repository**: Start by forking the project repository to your github account.
2. **Clone Locally**: Clone the forked repository to your local machine using a git client.
   ```sh
   git clone https://github.com/Alexpascual28/rcb_buggy.git
   ```
3. **Create a New Branch**: Always work on a new branch, giving it a descriptive name.
   ```sh
   git checkout -b new-feature-x
   ```
4. **Make Your Changes**: Develop and test your changes locally.
5. **Commit Your Changes**: Commit with a clear message describing your updates.
   ```sh
   git commit -m 'Implemented new feature x.'
   ```
6. **Push to github**: Push the changes to your forked repository.
   ```sh
   git push origin new-feature-x
   ```
7. **Submit a Pull Request**: Create a PR against the original project repository. Clearly describe the changes and their motivations.
8. **Review**: Once your PR is reviewed and approved, it will be merged into the main branch. Congratulations on your contribution!
</details>

<details closed>
<summary>Contributor Graph</summary>
<br>
<p align="center">
   <a href="https://github.com{/Alexpascual28/rcb_buggy.git/}graphs/contributors">
      <img src="https://contrib.rocks/image?repo=Alexpascual28/rcb_buggy.git">
   </a>
</p>
</details>

---
