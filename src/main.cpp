#include <Arduino.h>
#include "lib.pap2.h"


void setup() {
  MotorPaP_init(1,2,3,4);
}

void loop() {
  MotorPaP(1,2,3,4,'N',30);

}