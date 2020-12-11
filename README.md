# **[IoT-PipelineChecker](https://github.com/Centigrade/IoT-PipelineChecker)**

## **ABOUT THIS PROJECT**
### **Arduino Live WiFi Web Pipelinecheckerboard**
In this project I am going to explain how a digital _Pipelinecheckerboard_ was created  with _LEDs_(green, blue, red). The device uses a _ESP8266 WiFi chip_ to connect to the Internet to get actual statuses and ids of different pipelines in a specific Githlab project, plus statuses such as on/off for the LEDs. The device is powered by a _USB Data Sync Cable_ for Arduino UNO. Under the hood it uses an _Arduino Uno R3_ compatible board, which are readily available, economical, and communicate well with the ESP8266 chips.

### **What You Will Need**
 * 1 x Arduino UNO R3 ([€16.50 from Amazon](https://www.amazon.com/-/de/dp/B008GRTSV6/ref=sr_1_3?__mk_de_DE=%C3%85M%C3%85%C5%BD%C3%95%C3%91&dchild=1&keywords=arduino+uno+r3&qid=1607697403&sr=8-3))
 * 1 x ESP8266 WIFI chip ([€9.64 from Amazon](https://www.amazon.com/-/de/dp/B08B3VZS4N/ref=pd_sbs_147_5/147-8534147-2022314?_encoding=UTF8&pd_rd_i=B08B3VZS4N&pd_rd_r=f840cedd-d15c-4866-abaf-4fba7a4f5b01&pd_rd_w=CyfWQ&pd_rd_wg=UEXwD&pf_rd_p=ed1e2146-ecfe-435e-b3b5-d79fa072fd58&pf_rd_r=NT1SKSVPQXR9VRXZ5RR3&psc=1&refRID=NT1SKSVPQXR9VRXZ5RR3))
* 1 x Collection of 0 Ohm-1M Ohm resistors ([€8.27 from Amazon](https://www.amazon.co.uk/SIQUK-Resistors-Assortment-Resistor-Experiments/dp/B07P2KCKPT/ref=pd_sbs_107_4/259-8561364-3575130?_encoding=UTF8&pd_rd_i=B07P2KCKPT&pd_rd_r=e4e46020-455f-4ff7-aa4e-f2ae1e7ec53d&pd_rd_w=Tdbu8&pd_rd_wg=jvHXn&pf_rd_p=2304238d-df78-4b25-a9a0-b27dc7bd722e&pf_rd_r=P37Y9ZFYS1C1K7Y208MH&psc=1&refRID=P37Y9ZFYS1C1K7Y208MH))
* 1 x pack of jumping wires ([€15.25 from Amazon](https://www.amazon.co.uk/WayinTop-Breadboard-Preformed-Solderless-Prototyping/dp/B07PRGFW5Z/ref=sr_1_5?dchild=1&keywords=jumping+wires+arduino&qid=1607698443&s=computers&sr=1-5))
* 40 pcs 20cm Male to Female Jumper Wire ([€4.91 from Amazon](https://www.amazon.co.uk/Ganvol-Solderless-Flexible-Breadboard-Raspberry-Male-Female/dp/B01LVVIOUO/ref=sr_1_4?dchild=1&keywords=jumping+wires+arduino&qid=1607698443&s=computers&sr=1-4))
* 1 x Arduino Solderless Breadboard ([€6.53 from Amazon](https://www.amazon.co.uk/Breadboard-Solderless-Prototype-PCB-Board/dp/B06XWFG9DT/ref=sr_1_8?crid=1G756QO9TXPKL&dchild=1&keywords=arduino+breadboard&qid=1607698866&s=computers&sprefix=arduino+breadbord%2Ccomputers%2C175&sr=1-8))
* 1 x LEDs pack ([€12.37 from Amazon](https://www.amazon.com/-/de/dp/B073QMYKDM/ref=sr_1_4?__mk_de_DE=%C3%85M%C3%85%C5%BD%C3%95%C3%91&dchild=1&keywords=LEDs+arduino&qid=1607695120&sr=8-4))


### **Apps And Online Services**
* [Arduino IDE](https://www.arduino.cc/en/software)

### **Using the ESP8266 WIFI Chip**
Our _pipelinecheckerboard_ needs to connect to the Internet to get data to display on our LED components. The Arduino Uno compatible boards do not contain on-board WiFi, and so we have to use a further component to connect our project to the Internet.

![ESP8266 WiFi chip](https://www.electronicwings.com/public/images/user_images/images/Sensor%20%26%20Modules/ESP8266/esp8266.jpg)

The ESP8266 chip is marvellous, at around $6 in the US, or 2 for 10 euros here in Europe it is extremely good value. It's actually a complete SOC (system-on-a-chip) so in many ways is effectively 'another Arduino' style component, you can upload code to the device and use it on it's own. In this project however we wish to use it alongside our Arduino compatible board, with information being passed from the ESP8266 chip to our central board.

This task is more complicated than it might otherwise be due to the fact that the ESP8266 runs at 3.3v not 5v like our Arduino Mega board. This means that signals sent from the ESP8266 can't simply be connected to digital pins on our Arduino, and we can't power the ESP8266 from the 5v pin on our Arduino.