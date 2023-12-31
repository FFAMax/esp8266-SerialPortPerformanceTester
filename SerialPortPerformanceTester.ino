/*
 * Назначение Программы (Русский):
 * Эта программа предназначена для тестирования производительности серийного порта микроконтроллера ESP8266 путем измерения времени,
 * необходимого для отправки различных объемов данных. Программа последовательно увеличивает количество отправляемых байтов
 * и записывает время, затраченное на их отправку, позволяя наблюдать за изменениями в производительности и задержках
 * при разных размерах данных. Это исследование полезно для выявления особенностей и ограничений серийного интерфейса
 * конкретных платформ, что важно для оптимизации коммуникационных процессов и для понимания влияния размера данных на скорость передачи.
 *
 * Program Purpose (English):
 * This program is designed to test the performance of the ESP8266 microcontroller's serial port by measuring the time 
 * it takes to send varying amounts of data. It incrementally increases the number of bytes sent and records the time taken 
 * to send them, allowing for observation of performance changes and delays at different data sizes. This investigation is useful 
 * for identifying characteristics and limitations of the serial interface on specific platforms, which is important for 
 * optimizing communication processes and understanding the impact of data size on transmission speed.
 */

// ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXBytes sent: 128, Time elapsed: 0 ms
// ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFBytes sent: 136, Time elapsed: 0 ms
// ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNBytes sent: 144, Time elapsed: 1 ms
// ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVBytes sent: 152, Time elapsed: 3 ms
// ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDBytes sent: 160, Time elapsed: 3 ms
// ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLBytes sent: 168, Time elapsed: 3 ms
// ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTBytes sent: 176, Time elapsed: 4 ms
// ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABBytes sent: 184, Time elapsed: 5 ms
// ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJBytes sent: 192, Time elapsed: 5 ms
// ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRBytes sent: 200, Time elapsed: 6 ms

/*
 * Наблюдения и Полезность Программы (Русский):
 * Из результатов тестирования видно, что с увеличением объема отправляемых данных время, необходимое для их передачи,
 * увеличивается нелинейно, особенно после определенного порога. Это указывает на потенциальное переполнение буфера и
 * ограничения скорости передачи данных через серийный порт. Такой тест позволяет разработчикам оптимизировать объем
 * передаваемых данных для эффективной работы приложений, особенно в условиях, где важна скорость передачи данных и
 * минимизация задержек.
 *
 * Observations and Utility of the Program (English):
 * The test results show that as the amount of data sent increases, the time required for its transmission increases 
 * non-linearly, especially beyond a certain threshold. This suggests potential buffer overflow and limitations in the 
 * data transmission speed through the serial port. Such a test allows developers to optimize the amount of data 
 * transmitted for efficient application performance, particularly in scenarios where data transmission speed and delay 
 * minimization are crucial.
 */

#include <Arduino.h>

void setup() {
  Serial.begin(115200); // Initialize serial port
}

void loop() {
  static int dataSize = 8; // Initial size of data to send
  byte testData[dataSize]; // Array for data to be sent

  // Fill array with test data
  for (int i = 0; i < dataSize; i++) {
    testData[i] = 'A' + (i % 26); // Sample test data
  }

  unsigned long startTime = millis(); // Time measurement before sending
  Serial.write(testData, dataSize); // Send data
  //Serial.flush(); // Wait for all data to be transmitted (commented out as it may block)
  unsigned long elapsedTime = millis() - startTime; // Calculate time spent

  // Print results to the console
  Serial.print("Bytes sent: ");
  Serial.print(dataSize);
  Serial.print(", Time elapsed: ");
  Serial.print(elapsedTime);
  Serial.println(" ms");

  dataSize += 8; // Increase the data size for the next iteration
  if (dataSize > 200) { // Limit the maximum data size
    dataSize = 8;
  }
  delay(1000); // Delay to ensure all data is sent
}
