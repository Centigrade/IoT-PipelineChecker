# **[IoT-PipelineChecker](https://github.com/Centigrade/IoT-PipelineChecker)**

## **ABOUT THIS PROJECT**
### **Arduino Live WiFi Web Pipelinecheckerboard**
In this project I am going to explain how a digital _Pipelinecheckerboard_ was created  with _LEDs_(green, blue, red). The device uses a _ESP32 WiFi chip_ to connect to the Internet to get actual statuses and ids of different pipelines in a specific Githlab project, plus statuses such as on/off for the LEDs. The device is powered by a _USB Data Sync Cable_ for Arduino UNO. Under the hood it uses an _Arduino Uno R3_ compatible board, which are readily available, economical, and communicate well with the ESP32 chips.

### **What You Will Need**
 * 1 x Arduino UNO R3 ([€16.50 from Amazon](https://www.amazon.com/-/de/dp/B008GRTSV6/ref=sr_1_3?__mk_de_DE=%C3%85M%C3%85%C5%BD%C3%95%C3%91&dchild=1&keywords=arduino+uno+r3&qid=1607697403&sr=8-3))
 * 1 x ESP32 WIFI chip ([€9.49 from Amazon](https://www.amazon.de/AZDelivery-ESP32-NodeMCU-gratis-eBook/dp/B07Z83MF5W/ref=sr_1_3?dchild=1&hvadid=80333167146753&hvbmt=be&hvdev=c&hvqmt=e&keywords=esp32-wroom-32&qid=1614259889&sr=8-3))
* 1 x Collection of 0 Ohm-1M Ohm resistors ([€8.27 from Amazon](https://www.amazon.co.uk/SIQUK-Resistors-Assortment-Resistor-Experiments/dp/B07P2KCKPT/ref=pd_sbs_107_4/259-8561364-3575130?_encoding=UTF8&pd_rd_i=B07P2KCKPT&pd_rd_r=e4e46020-455f-4ff7-aa4e-f2ae1e7ec53d&pd_rd_w=Tdbu8&pd_rd_wg=jvHXn&pf_rd_p=2304238d-df78-4b25-a9a0-b27dc7bd722e&pf_rd_r=P37Y9ZFYS1C1K7Y208MH&psc=1&refRID=P37Y9ZFYS1C1K7Y208MH))
* 1 x pack of jumping wires ([€15.25 from Amazon](https://www.amazon.co.uk/WayinTop-Breadboard-Preformed-Solderless-Prototyping/dp/B07PRGFW5Z/ref=sr_1_5?dchild=1&keywords=jumping+wires+arduino&qid=1607698443&s=computers&sr=1-5))
* 40 pcs 20cm Male to Female Jumper Wire ([€4.91 from Amazon](https://www.amazon.co.uk/Ganvol-Solderless-Flexible-Breadboard-Raspberry-Male-Female/dp/B01LVVIOUO/ref=sr_1_4?dchild=1&keywords=jumping+wires+arduino&qid=1607698443&s=computers&sr=1-4))
* 1 x Arduino Solderless Breadboard ([€6.53 from Amazon](https://www.amazon.co.uk/Breadboard-Solderless-Prototype-PCB-Board/dp/B06XWFG9DT/ref=sr_1_8?crid=1G756QO9TXPKL&dchild=1&keywords=arduino+breadboard&qid=1607698866&s=computers&sprefix=arduino+breadbord%2Ccomputers%2C175&sr=1-8))
* 1 x LEDs pack ([€12.37 from Amazon](https://www.amazon.com/-/de/dp/B073QMYKDM/ref=sr_1_4?__mk_de_DE=%C3%85M%C3%85%C5%BD%C3%95%C3%91&dchild=1&keywords=LEDs+arduino&qid=1607695120&sr=8-4))


### **Apps And Online Services**
* [Arduino IDE](https://www.arduino.cc/en/software)

### **Using the ESP32 WIFI Chip**
Our _pipelinecheckerboard_ needs to connect to the Internet to get data to display on our LED components. The Arduino Uno compatible boards do not contain on-board WiFi, and so we have to use a further component to connect our project to the Internet.

![ESP32 WiFi chip](https://images-na.ssl-images-amazon.com/images/I/71bM0Mel%2BcL._SL1500_.jpg)

The ESP32 WiFi and Bluetooth chip is the latest generation of Espressif products. It has a dual-core 32-bit MCU, which integrates WiFi HT40 and Bluetooth/BLE 4.2 technology inside.

Compared to the [arduino ESP8266](https://en.wikipedia.org/wiki/ESP8266) (the previous generation), the ESP32 wifi and bluetooth chip (also known as ESP wroom 32) has a significant performance improvement. It is equipped with a high-performance dual-core Tensilica LX6 MCU. One core handles high speed connection and the other for standalone application development. The dual-core MCU has a 240 MHz frequency and a computing power of 600 DMIPS.

In addition, it supports Wi-Fi HT40, Classic Bluetooth/BLE 4.2, and more GPIO resources.
ESP32 chip (ESP wroom 32) integrates a wealth of hardware peripherals, including capacitive touch sensors, Hall sensors, low noise sensor amplifiers, SD card interfaces, Ethernet interfaces, high-speed SDIO / SPI, UART, I2S and I2C, etc.

Engineered for mobile devices, wearable electronics and Internet of Things (IoT) applications, the ESP32 wroom 32 achieves ultra-low power consumption with a combination of several proprietary software applications. The state-of-the-art power saving features include fine resolution clock gating, power modes, and dynamic power scaling.

DFRobot introduces the ESP-ROOM-32 module, based on the Espressif. ESP32 chip. It has integrated electronic peripherals, external expansion of all GPIO pins, an onboard antenna, stamp hole design and easy mass production. It can be used for product development, integrated design and many more applications.


### **Hardware Circuity**

The project hardware uses six LEDs to get a level of illumination at least sort of visible from across the room. Here each pin of a esp32 WROOM can only output a small amount of current which is enough to power a single LED at anywhere near maximum brightness.

![Hardware circuity](https://i.postimg.cc/2yGVrzsh/PSX-20210225-144539.jpg)
![Hardware circuity](https://i.postimg.cc/6qczZY6k/Capture.png)


It powers multiple LEDs directly from an Arduino’s xV supply pins, which can provide a much higher current than a common 5V output. The program resets and runs easily, switching the LEDs on and off using a capacitor, whose base is wired to the reset pin and the ground pins of the esp32 WROOM. This way, the board runs and resets automatically rather than always resseting mannually.

with help of the USB connector’s power, I am able to supply the board with enough current and upload the program code on to it. It isn’t exactly pretty, but it works just fine. The resistors I used are 200 Ohm between the digital pins and ground bases.


### **Code**

The code written for this project can be found here:
     [Project   loTpipeLineChecker](https://github.com/Centigrade/IoT-PipelineChecker/tree/feature/finish-pipeLineChecker)

* [Arduino core for ESP32 WiFi chip](https://dl.espressif.com/dl/package_esp32_index.json) to run the whole thing on any ESP32-based board. To install this, you need to add the library URL to your Arduino Board Manager: `https://dl.espressif.com/dl/package_esp32_index.json` .

* [ArduinoJson](https://arduinojson.org/) to deserialize GitLab API responses and extract the pipeline id and status. This can be installed and included directly via the Arduino Library Manager.

Fill out the settings at the top, and flash it on a compatible board. Connect via Serial Monitor to check that it works - it’ll connect to WiFi and start polling the pipeline status, outputting some debug info along the way.


### **Green, blue, red and various states**

Alongside the obvious SUCCESS (green), RUNNING (blue) and FAILED (red) statuses there’s also  UNKNOWN (blinking blue, when the status is different from anything the code checks against).


### **Deployment**

* All parametres wich are to be use all through the project such as URLs, LEDs pins setup and many others should be stored in a [configuration file](https://github.com/Centigrade/IoT-PipelineChecker/blob/feature/finish-pipeLineChecker/config.h) and imported in to the [main file](https://github.com/Centigrade/IoT-PipelineChecker/blob/feature/finish-pipeLineChecker/IoT-PipelineChecker.ino) as a libary.

* Also all sensitive informations not to be shared with the general public like for example passwords should be stored in a secret file an imported in to the [main file](https://github.com/Centigrade/IoT-PipelineChecker/blob/feature/finish-pipeLineChecker/IoT-PipelineChecker.ino) as a libary as well. 
Here we can find an example of such a file: [secrets.h.example](https://github.com/Centigrade/IoT-PipelineChecker/blob/feature/finish-pipeLineChecker/secrets.h.example).


### **Authors**

* _Martin Fokam Simo_ - Initial work - loTpipeLineChecker

See also the list of [contributors](https://github.com/Centigrade/IoT-PipelineChecker/blob/feature/finish-pipeLineChecker/Contributors.md) who participated in this project.


### **License**

This project is licensed under the MIT License - see the [LICENSE](https://github.com/Centigrade/IoT-PipelineChecker/blob/feature/finish-pipeLineChecker/LICENSE) file for details.




