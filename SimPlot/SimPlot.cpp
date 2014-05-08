#include "SimPlot.h"
#include "Functions.h"

int buffer[20];
float deltaAngle = 3.14/51; //Arbitrary angle increment size
float angle = 0;
int amplitude = 100;

void setup() {
	  Serial.begin(57600);
}

void loop() {
	  int data1;
	  int data2;
	  int data3;
	  int data4;
	  int data5;
	  int data6;

	  //Generating data that will be plotted
	  data1 = amplitude * sin(angle);
	  data2 = amplitude * cos(angle);

	  data3 = (amplitude/2) * sin(angle);
	  data4 = (amplitude/2) * cos(angle);

	  data5 = (amplitude * 2) * sin(angle);
	  data6 = (amplitude * 2) * cos(angle);

	  angle = angle + deltaAngle;

	  plot(data1,data2,data3,data4, data5, data6);
	  p("%10d%10d%10d%10d%10d%10d\n", data1,data2,data3,data4, data5, data6);

	  delay(100); //Need some delay else the program gets swamped with data
}

void plot(int data1, int data2, int data3, int data4, int data5, int data6) {
  int pktSize;

  buffer[0] = 0xCDAB;             //SimPlot packet header. Indicates start of data packet
  buffer[1] = 6*sizeof(int);      //Size of data in bytes. Does not include the header and size fields
  buffer[2] = data1;
  buffer[3] = data2;
  buffer[4] = data3;
  buffer[5] = data4;
  buffer[6] = data5;
  buffer[7] = data6;

  pktSize = 2 + 2 + (6*sizeof(int)); //Header bytes + size field bytes + data

  Serial.write((uint8_t * )buffer, pktSize);
}

