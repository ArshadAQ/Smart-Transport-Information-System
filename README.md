# Smart-Transport-Information-System
Real time public transport information update.

This project updates passengers with real time status updates of public transport to help them with better decision, planning and time management.
A bus has been taken as an example.

## Core Functionalities

* Get current location of a particular bus
* Get no. of people in the bus
* Distance from a particular stop

With this proposed system, people can decide whether to board the immediate next bus or profitably wait for a subsequent bus, perhaps a lesser crowded one.  

Passengers can visit the website to get realtime status updates of the bus

## Getting Started

### Prerequisites/ Components Required

* Arduino IDE or any compatible IDE for running Arduino Mega code
* Arduino Mega
* IR sensors
* GPS module
* GSM Modem
* SIM
* Power Source

### Setting up

- Install 2 IR sensors at each door of the public transport
- Install GPS module and configure
- Install GSM Modem with a SIM
- Connect the above to the Arduino board and power it

![alt text](https://github.com/ArshadAQ/Smart-Transport-Information-System/blob/master/screenshots/screenshot1.png)

## Deployment

Upload the code using an arudino compatible IDE and you are ready to go!

## Working Prototype

![alt text](https://github.com/ArshadAQ/Smart-Transport-Information-System/blob/master/screenshots/setup.JPG)

### SMS update

![alt text](https://github.com/ArshadAQ/Smart-Transport-Information-System/blob/master/screenshots/bus_status.jpg)

### Displaying on the web

![alt text](https://github.com/ArshadAQ/Smart-Transport-Information-System/blob/master/screenshots/proposed_frontend.JPG)

Note: Connection by the GSM module to the localhost could not be made due to the IP of the localhost not being public. Hence sending SMS was chosen as a substitute.

## Built With

* [Arduino IDE](https://www.arduino.cc/en/Main/Software) - The IDE used
* [Tiny GPS++](https://github.com/mikalhart/TinyGPSPlus) - GPS Library
* PHP, Javascript, Google maps API - The tech stack for the website
