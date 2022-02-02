# intelliStat-Node

Project intelliStat consists of ESP8266 nodes that beam real time data from the sensors and renders it on the Web App GUI, with Timestamp and FFT visualization in real-time. 

The project was designed as a demo for NohPei lab, under Professor Pei Zhang, Department of EECS, University of Michigan. The nodes are deployed and connected to geo vibration sensors deployed in cattle-farm based in Nebraska. The sensor nodes send movement data to the web app where the safety scenarios of baby cows are monitored and used for research in vibrational sensing projects. 

## Parameters Measured

1. vibrational Harmonics
2. pH
3. Cage temperature
4. Ambient Noise
5. IR data feed

## Application Architecture
The application consists of the following components:
    1. Firmware - hosted on the NodeMcu
    2. Web Server Client - hosted  on Raspberry Pi4
    3. Web App - AWS deployment
