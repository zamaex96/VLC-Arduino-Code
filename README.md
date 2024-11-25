Software based Transmitter and receiver codes for sending pressure and temperature data via VLC/UWOC communication.
Platform: Arduino
Microcontroller: NRF

# Summary of Transmitter Code

## Overview
The provided code reads temperature data from an HTS221 sensor and sends it serially. It initializes the sensors and continuously sends temperature readings to a receiver identified by an ID. 

## Libraries Used
- **Arduino_LPS22HB:** Used for reading pressure data (currently commented out).
- **Arduino_HTS221:** Used for reading temperature and humidity data.

## Constants and Variables
- **Constants:**
  - `DELAY`: Delay in microseconds for signal transmission.
  - `LED`: Pin number for the LED used as an indicator.
  - `ID`: Identifier for the receiver.
  - `BITLENGTH`: Number of bits (8 bits per byte).
  - `FIRSTBIT`: Most significant bit value.
  - `TRUE`: Boolean value representing true (1).

- **Variables:**
  - `Pressure`: Float variable for storing pressure data.
  - `Temperature`: Float variable for storing temperature data.
  - `Humidity`: Float variable for storing humidity data.
  - `count`: Integer for counting loop iterations.

## Functions
- **`setup()`:**
  - Initializes the LED pin and the HTS221 sensor.
  - If sensor initialization fails, the program enters an infinite loop.

- **`loop()`:**
  - Continuously reads temperature from the HTS221 sensor.
  - Sends the receiver ID and temperature data via `writeByte()` function.
  - Commented out code suggests possible future integration of pressure and humidity readings.
  - Contains commented-out serial print statements for debugging.

- **`writeByte(char decimal)`:**
  - Converts a decimal value to binary and sends it bit-by-bit.
  - Uses digital writes to simulate binary transmission via a specified LED pin.
  - Delays between writes to ensure signal integrity.

## Notes
- The code demonstrates basic sensor initialization, data reading, and serial communication techniques typical in Arduino projects.
- It is structured for continuous operation, sending temperature data in binary format to a receiver.
- Serial print statements for debugging are commented out, suggesting previous testing or future debugging needs.

# Summary of Receiver Arduino C Code

## Overview
This Arduino code reads data from a sensor connected to `sensorPin` and communicates it serially. It includes functionality to calculate average temperature, evaluate packet success rate (PSR), and packet error rate (PER) based on received data packets.

## Constants and Variables
- **Constants:**
  - `SETTING`: Not explicitly used in provided code.
  - `DELAY`: Delay in microseconds for various operations.
  - `BITLENGTH`: Number of bits per byte (8 bits).
  - `DIFFERENCE`: Threshold difference for determining middle value between logic states.
  - `S1`: Digital pin (not used in provided code).
  - `ID`: Identifier expected from received data.
  - `sensorPin`: Analog pin used to read sensor data.
  - `ledPin`: Digital pin (not used as an LED in provided code).
  - `TRUE`: Boolean value representing true (1).

- **Variables:**
  - `sensorValue`: Holds current analog reading from `sensorPin`.
  - `middleValue`: Calculated middle value between logic states.
  - `inputByte[4]`: Array to store received data bytes.
  - `CheckID`: Holds received identifier to compare with `ID`.
  - `temperature`: Float variable for temperature calculation.
  - `count`: Counter for received data packets.
  - `temp[256]`: Array to store received temperature data for analysis.
  - `ber`: Bit error rate (not utilized in provided code).
  - `correct`: Counter for correctly received packets.
  - `chk`: Holds result of temperature range check.
  - `low`, `avg`, `sum`, `high`: Variables for average temperature calculation and range checking.

## Functions
- **`setup()`:**
  - Initializes serial communication and sets pin modes.

- **`loop()`:**
  - Checks received data for correct `ID`.
  - Reads temperature, pressure, and humidity data bytes.
  - Calculates average temperature over 256 packets.
  - Checks each temperature packet against a predefined range.
  - Calculates and prints PSR and PER.

- **`checkMiddle()`:**
  - Determines middle value between logic states (`0` and `1`) based on sensor readings.

- **`readByte()`:**
  - Reads and returns a byte of data from `sensorPin`, interpreting bits based on sensor readings compared to `middleValue`.

- **`inRange(float low, float high, float x)`:**
  - Checks if `x` falls within the range defined by `low` and `high`.

## Notes
- The code implements serial communication and data handling for temperature, pressure, and humidity readings.
- It includes functionality for packet error analysis (PSR and PER) based on received temperature data packets.
- Certain constants (`SETTING`, `ledPin`, `S1`) are defined but not utilized in the provided code.
- The use of delay times (`DELAY`) ensures proper timing for sensor readings and data transmission.
- Serial print statements provide debug and output information for monitoring sensor readings and error rates.

<div align="center">
  <a href="https://maazsalman.org/">
    <img width="70" src="click-svgrepo-com.svg" alt="gh" />
  </a>
  <p> Explore More! 🚀</p>
</div>
