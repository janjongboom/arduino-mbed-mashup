# Running Arduino sketches on Mbed OS

The new [Arduino Nano 33 BLE](https://blog.arduino.cc/2019/07/31/why-we-chose-to-build-the-arduino-nano-33-ble-core-on-mbed-os/) board is a development board that runs both Arduino and Mbed OS. This is done by implementing Arduino core on top of Mbed OS, giving users the opportunity to write both Arduino sketches and Mbed OS applications at the same time. This project also allows us to add the Arduino core as a library to any Mbed OS application, thus adding support for Arduino sketches and libraries to any Mbed OS project.

This repository contains an example of running the [Arduino ChainableLED sketch](https://github.com/pjpmarques/ChainableLED) on Mbed OS boards. It can be used as a basis to run any Arduino sketch on any Mbed OS board.

## Building with Mbed CLI

1. Connect a Grove Chainable LED to pin D4/D5 on your development board.
1. Import this application:

    ```
    $ mbed import https://github.com/janjongboom/mbed-arduino-mashup
    ```

1. Build and flash the application:

    ```
    $ mbed compile -m auto -t GCC_ARM -f
    ```

1. Done!

## The sketch and bootstrapping

The sketch is located in [source/sketch.cpp](source/sketch.cpp).

Arduino uses a `setup` and a `loop` function, which are unknown to Mbed OS. Thus, you'll need to call these functions manually. You'll see this at the bottom of the `sketch.cpp` file:

```cpp
// Mbed OS bootstrap code
int main() {
    setup();

    while (1) loop();
}
```

Here you'll have the full power of Mbed OS on your hands, so you can start new threads, use the file system, or use one of the network drivers. See [source/sketch.cpp.multithreaded](source/sketch.cpp.multithreaded) for an example.
