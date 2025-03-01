# CellularHttpLib

CellularHttpLib is an Arduino library designed for easy integration of GPRS connectivity and HTTP requests in your projects. This library simplifies the process of connecting to a GPRS network and making GET and POST requests to a specified server.

## Installation

To install the CellularHttpLib library, follow these steps:

1. Download the library as a ZIP file from the repository.
2. Open the Arduino IDE.
3. Go to **Sketch** > **Include Library** > **Add .ZIP Library...**
4. Select the downloaded ZIP file and click **Open**.

The library will be added to your Arduino libraries.

## Usage

To use the CellularHttpLib library in your Arduino sketch, include the main header file:

```cpp
#include <CellularHttpLib.h>
```

### Example

Here is a simple example of how to use the library to connect to a GPRS network and make an HTTP GET request:

```cpp
#include <CellularHttpLib.h>

void setup() {
  Serial.begin(115200);
  GPRS_wake_up();
  if (server_connect()) {
    Serial.println("Server connected!");
    String response = HttpGET(resource);
    Serial.println(response);
  } else {
    Serial.println("Server not connected!");
  }
}

void loop() {
  // Your loop code here
}
```

## API Reference

### Functions

- `void GPRS_wake_up()`: Initializes the GPRS module and prepares it for connectivity.
- `bool server_connect()`: Establishes a connection to the server.
- `String HttpGET(const String& resource)`: Performs an HTTP GET request to the specified resource.
- `String HttpPost(const String& resource)`: Performs an HTTP POST request to the specified resource.

## License

This library is released under the MIT License. See the LICENSE file for more details.