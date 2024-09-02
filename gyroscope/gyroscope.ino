#include <Wire.h>

void setup() {
  Wire.begin();
  Serial.begin(9600);

  // Initialize MPU6050
  Wire.beginTransmission(0x68);
  Wire.write(0x6B);  // Power management 1
  Wire.write(0);     // Wake up the MPU6050
  Wire.endTransmission(true);
}

void loop() {
  Wire.beginTransmission(0x68);
  Wire.write(0x3B);  // Starting register for accelerometer readings
  Wire.endTransmission(false);
  Wire.requestFrom(0x68, 14, true);

  int16_t ax = (Wire.read() << 8 | Wire.read());  // Accelerometer X-axis
  int16_t ay = (Wire.read() << 8 | Wire.read());  // Accelerometer Y-axis
  int16_t az = (Wire.read() << 8 | Wire.read());  // Accelerometer Z-axis
  int16_t gx = (Wire.read() << 8 | Wire.read());  // Gyroscope X-axis
  int16_t gy = (Wire.read() << 8 | Wire.read());  // Gyroscope Y-axis
  int16_t gz = (Wire.read() << 8 | Wire.read());  // Gyroscope Z-axis

  // Print the data to the Serial Monitor
  Serial.print("ax: "); Serial.print(ax);
  Serial.print(" ay: "); Serial.print(ay);
  Serial.print(" az: "); Serial.print(az);
  Serial.print(" temp: "); Serial.print(temp);
  Serial.print(" gx: "); Serial.print(gx);
  Serial.print(" gy: "); Serial.print(gy);
  Serial.print(" gz: "); Serial.println(gz);

  delay(500);  // Delay for readability
}
