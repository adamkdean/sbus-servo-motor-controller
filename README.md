<p align="center">
  <img src="https://user-images.githubusercontent.com/1639527/86492238-56925a80-bd65-11ea-8763-8e9960e668e8.png" width="600"><br><br>
  Servo/motor control via R-XSR SBUS receiver input<br>
</p>

----

### SBUS Inverter

![Inverter](https://user-images.githubusercontent.com/1639527/86492451-18e20180-bd66-11ea-96cb-001294850b62.png)

R1: 10 kΩ, R2: 4.8 kΩ, Transistor: 2N3904 or similar

> The SBUS signal from the FrSky X-receivers are a serial at 100.000 baud, but it is inverted. Therefore you will need an inverter like the one above in order for the Arduino to read it correct.

----

### License

MIT License

Copyright (c) 2020 Adam K Dean

```
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```
