# Project KeyKette_USB : Build a Keylogger with Teensy 4.1

## Disclaimer : 

This project use is only intended for professional or educationnal purposes.

### Goal :

Using a **Teensy 4.1** board, intercept keyboard input data entered by a user with some awesome features.

## Requirements
| Teensy 4.1 | Keyboard | Arduino IDE |
| :--------: | :------: | :---------: |
|<img src="https://letmeknow.fr/7659-large_default/pjrc-teensy-41.jpg" width=150> | <img src="https://cdn-icons-png.flaticon.com/512/2554/2554320.png" width=150> | <img src="https://cdn.iconscout.com/icon/free/png-256/free-arduino-1-226076.png" width=150> |

We designed our payloads to work for Windows.

## How to use it

1. Clone the repository
```bash
git clone https://github.com/Eragwen/KeyKette_USB.git
```

2. Open the project file **KeyKette.ino** with Arduino IDE

3. In the Arduino IDE, by the left tab **Board Manager**, install the **Teensy** library.

4. By the left tab **Library Manager**, install the **USBHost** library.

5. Connect the Teensy 4.1 board to your computer.

6. On the top left of the Arduino IDE, select the board **Teensy 4.1** and the port where the board is connected.

7. Upload the code to the board by clicking on the arrow on the top left.

8. Open the **Serial Monitor** by clicking on the magnifying glass on the top right.

9. Type on your keyboard and see the magic happen ! You can even type in a text editor to see some results.

## Features

### LED Indicator

To indicate if the KeyKette™ works correctly, we use the LED on the teensy to indicate what is working.

Upon inserting the KeyKette™, 3 sequences of LED flashing will occur, there is a delay of 1 second between every sequence.

First sequence : 1 flash the SD card has a problem, 2 flash the program starts without errors.

Second sequence : 1 flash the keystroke cannot be registered, 2 flash the keystrokes are being registered.

Third sequence : 1 flash the Reverse Shell has a problem, 2 flash the Reverse Shell has been established.

### Keylogging

The main feature of the KeyKette™ is being a Keylogger, it will register the keystrokes from the keyboard and store them in a file called keystrokes.txt in the SD card.

### Reverse shell

The second main feature is the execution of a Reverse Shell on the victim PC. 

It uses TCP and you need to modify the correct parameters in the code to get it to connect to the attacker device.

### The Funny

We enjoy funnyness so if the keyboard users types "QUOI" we input the word "FEUR" or if he types 69 he will earn a "nice" windows popup.

## Authors

- [@Eragwen](https://github.com/Eragwen)
- [@Gizm0o](https://github.com/Gizm0o)