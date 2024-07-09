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

