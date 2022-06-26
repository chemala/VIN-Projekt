# Robot Arm Color Sorting
My project's goal is to utilize a servo-driven robot arm to sort objects into separate areas by their color.
I will accomplish this by using an Ultrasonic sensor to detect a placed object, read its color with a Color Sensor and then move it to a place corresponding to its color using the robot arm.

## Components

* Arduino UNO 
* Arduino Nano 
* TCS230 Color Sensor 
* HCSR04 Ultrasonic Sensor 
* 5V 15A Power Supply Unit
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
>> The TCS230 Color Sensor senses color light with the help of an 8 x 8 array of photodiodes for which there are 4x16 filters of different colors (Red, Green, Blue and Clear). Then using a Current-to-Frequency Converter the readings from the photodiodes are converted into a square wave with a frequency directly proportional to the light intensity. This sensor will be used to read the color of the objects placed in front of the arm.
>> Connections:
>>  * Pins S2, S3 -> Control pins used to select which photodiodes will be read (R, G, B, C)
>>  * Pins S0, S1 -> Control pins used for scaling the output frequency of the sensor
>>  * OUT -> outputs a TTL level square wave
>>  * OE -> Output Enable pin (connect to GND by default)
> ### HCSR04 Ultrasonic Sensor
> ![image](https://user-images.githubusercontent.com/76220147/175833519-65f13d60-c2d6-47a9-a1fe-3a0854e0cfb2.png)
>> The HCSR04 consists of two ultrasonic transducers where one acts as a transmitter that converts the electrical signal into 40 KHz ultrasonic sound pulses while the other acts as a receiver and listens for the transmitted pulses. When the receiver receives these pulses, it produces an output pulse whose width is proportional to the distance of the object in front. This sensor provides excellent range detection between 2 cm to 400 cm with an accuracy of 3 mm.
>>  Connections :
>>  * TRIG -> This pin is used to trigger ultrasonic sound pulses. By setting this pin to HIGH for 10µs, the sensor initiates an ultrasonic burst.
>>  * ECHO -> This pin goes high when the ultrasonic burst is transmitted and remains high until the sensor receives an echo, after which it goes low. By measuring the time the Echo pin stays high, the distance can be calculated.
>>  The distance is calculated with the formula **Distance = (Speed of Sound X Time )/2** where the Speed of Sound is 0.034 cm/μs.
> ### 5V 15A Power Supply Unit
> ![image](https://user-images.githubusercontent.com/76220147/175837100-2d372e4b-ba9b-409d-894d-67d29d934bf8.png)
>> The 5V 15A PSU was used to power the robot arm's servo motors. Each of the 6 servos had a peak current draw of 2A so a PSU of this capacity was the best option.
>### 5-axis 6 Servo Robot Arm
> ![image](https://user-images.githubusercontent.com/76220147/175837250-801ac05c-344a-4661-9b1d-853400c12fc5.png)
>> This kit came disassembled and had to be assembled and calibrated from scratch. The kit came with aluminum brackets, screws, bolts, a gripper and 6 servos of which 4 were TowerPro MG996R servos (Torque: 10 kg/cm) and 2 were DigitalServo DS 3218MG servos (Torque: 25 kg/cm). All of the servos have a 0-180 degree range of motion. 






