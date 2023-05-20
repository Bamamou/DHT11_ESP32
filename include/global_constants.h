/******************************************************************************
 * global_Constants.h
 * Constants that will be used in the whole project
 *****************************************************************************/
#ifndef __GLOBAL_CONSTANTS_H__
#define __GLOBAL_CONSTANTS_H__
#include <Arduino.h>


int delayTime =1000;   // Set the delay time between each values 
int counter;          // data counter
const int totalColumns = 16;
const int totalRows    = 2;
const char* ssid = "xiangyu801";   // your network SSID (name) 
const char* password = "xiangyu801";   // your network password
unsigned long myChannelNumber = 2;
const char * myWriteAPIKey = "RHKAJ2VFK0A812ZN";
// Timer variables
unsigned long lastTime = 0;
unsigned long timerDelay = 15000;
#define DHT_Pin          4

#endif