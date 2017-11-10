# EdingCNC Handwheel
This is a Tool to connect EdingCNC (with cncapi) to a Microcontroller over Firmata Serial Protocol.

## Prerequisites
- Qt 5.6 (http://www.qt.io)
-- during installation select Qt->Qt 5.6->MinGW 4.9.2 32 bit
- EdingCNC (http://www.edingcnc.com)
- QtFirmata (https://github.com/jazzycamel/QtFirmata)

## How to build
- Build QtFirmata
- Update Paths in edingcnc_handwheel.pro
-- QTFIRMATA_DIR - to QtFirmata source files
-- QTFIRMATA_LIB - to QtFirmata dll (built the step before)
-- CNCAPI_DIR - to Folder with cncapi.dll
- In Project settings
-- change working dir to EdingCNC Installation (like C:\CNC4.03)
-- (for Testing) add the COM Port of your microcontroller to the command line arguments (like COM9)
- Run/Build and have fun
