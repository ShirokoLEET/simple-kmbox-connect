# Simple Kmbox Connect

A simplified, single-header C++ library for interacting with the Kmbox (Net version) hardware.

## Features

- **Single Header**: All logic is encapsulated in `kmbox.hpp`.
- **Easy to Use**: Simple object-oriented interface (`KmboxNet` class).
- **Thread Safe**: Uses `std::mutex` for thread handling.
- **Lightweight**: Minimal dependencies (Winsock2).

## Requirements

- Windows OS
- C++11 or later
- Visual Studio (recommended)

## information

- **Project Directory**: `simple-kmbox-connect`
- **Main File**: `simple-kmbox-connect.cpp`
- **Header File**: `kmbox.hpp`

## Usage

1. **Include the header**:
   ```cpp
   #include "kmbox.hpp"
   ```

2. **Initialize and use**:
   ```cpp
   KmboxNet kmbox;
   
   // Connect to the device (IP, Port, Mac)
   // IP and Port are strings, Mac is a string (e.g., "12344321")
   int ret = kmbox.Init("192.168.2.188", "1234", "12344321");
   
   if (ret == SUCCESS) {
       // Move mouse
       kmbox.MouseMove(100, 100);
       
       // Click mouse
       kmbox.MouseLeft(1); // Press
       kmbox.MouseLeft(0); // Release
   }
   ```

## Build Instructions

1. Open `simple-kmbox-connect.sln` in Visual Studio.
2. Build the solution (Ctrl+Shift+B).
3. Run the application.

### Manual Compilation
If compiling manually, ensure you link against specific libraries:
- `ws2_32.lib`
- `iphlpapi.lib`

(Note: These are automatically linked via `#pragma comment` in `kmbox.hpp` for MSVC).

## Protocol Reference

The library implements standard Kmbox commands:
- `CMD_CONNECT`: Connect to device
- `CMD_MOUSE_MOVE`: Relative mouse movement
- `CMD_MOUSE_LEFT`/`RIGHT`/`MIDDLE`: Mouse button control
- `CMD_MONITOR`: Monitor device state
- And more...

See `kmbox.hpp` for the full list of supported commands and error codes.
