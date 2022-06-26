# Robot Arm Color Sorting
My project's goal is to utilize a servo-driven robot arm to sort objects into separate areas by their color.
I will accomplish this by using an Ultrasonic sensor to detect a placed object, read its color with a Color Sensor and then move it to a place corresponding to its color using the robot arm.

## Components

* Arduino UNO 
* Arduino Nano 
* TCS230 Color Sensor 
* HCSR04 Ultrasonic Sensor 
* 5V 15A Power Supply 
* 5-Axis 6 Servo Robot Arm 

## Component Descriptions

> ### Arduino UNO
> ![image](https://user-images.githubusercontent.com/76220147/175832686-62c6ccaf-dde7-4a1b-80ef-9b5948d92ae6.png)
>> The Arduino UNO is a microcontroller board based on the ATmega328P. It is used for prototyping and simple electronics projects. It has 14 digital I/O pins of which 6 are also PWM outputs. The servo motors will use this PWM output as an input for moving to a distinct position (degree).
> ### Arduino Nano
> ![image](https://user-images.githubusercontent.com/76220147/175833119-f5a3df82-f6f2-4107-a08f-3d0e0d69989b.png)
>> The Arduino Nano is a microcontroller board that has the same functionality of an Arduino UNO board but in a much smaller form factor. The only difference between them is that the UNO can be used with a bigger number of shields. The Nano board will be used to communicate with the Color and Ultrasonic sensors and send the data to the UNO board via a serial connection.
> ### TCS230 Color Sensor
> ![image](https://user-images.githubusercontent.com/76220147/175833316-014aa6cd-8bdb-4a7d-b036-c1c7f22ae73c.png)





