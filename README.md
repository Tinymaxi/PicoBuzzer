# Pico Buzzer (RP2040)
Short beep on press, Ode to Joy on long press. Requires Raspberry Pi Pico SDK.

## Build
mkdir -p build && cd build
cmake -DPICO_SDK_PATH=$PICO_SDK_PATH ..
make

## Flash
Drag the generated .uf2 to the RPI-RP2 drive (BOOTSEL mode).

## Pins
- Buzzer: GPIO 2
- Button: GPIO 15 (active-low, pull-up)

