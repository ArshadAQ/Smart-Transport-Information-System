# Smart-Transport-Information-System
Real time public transport information update
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

![alt text](https://raw.githubusercontent.com/ArshadAQ/Smart-Transport-Information-System/master/screenshots/screenshot1.png?token=AYud0ObwH9TL5Q2UHc2Rk7wlOfFD9XZuks5bRIZcwA%3D%3D)

## Deployment

Upload the code using an arudino compatible IDE and you are ready to go!

## Working Prototype

![alt text](https://raw.githubusercontent.com/ArshadAQ/Smart-Transport-Information-System/master/screenshots/setup.JPG?token=AYud0GtqzFB2DKAbv6N5KOQkyHRgaNwGks5bRIgGwA%3D%3D)

### SMS update

![alt text](https://raw.githubusercontent.com/ArshadAQ/Smart-Transport-Information-System/master/screenshots/bus_status.jpg?token=AYud0IqeqImwXZX0cIw912e6JyvCegrHks5bRI5UwA%3D%3D)

### Displaying on the web

![alt text](https://raw.githubusercontent.com/ArshadAQ/Smart-Transport-Information-System/master/screenshots/proposed_frontend.JPG?token=AYud0OWZbdxxL9-U-stwkyWeZumS3_YVks5bRI8BwA%3D%3D)

Note: Connection by the GSM module to the localhost could not be made due to the IP of the localhost not being public. Hence sending SMS was chosen as a substitute.

## Built With

* [Arduino IDE](https://www.arduino.cc/en/Main/Software) - The IDE used
* [Tiny GPS++](https://github.com/mikalhart/TinyGPSPlus) - GPS Library
* PHP, Javascript, Google maps API - The tech stack for the website
