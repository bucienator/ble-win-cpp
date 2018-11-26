# ble-win-cpp
Bluetooth LE query code in c++ Windows console application

An experiment on how to listen to advertisements, connect to devices, use GATT services. All in a standalone Windows console application, leveraging C++/WinRT and UWP libraries.

I have found the UWP documentations a bit lacking, so most of the code is based on trial and error experimentation, and the basic examples. Most obscure part yet to me is the threading model behind UWP classes: which threads are used by *Async calls? How/why can I call an *Async call from an event handler? What are the implications and the constrains? Anyway, it seems to be working, at least most of the time.

If you know better, please correct me, preferably in the form of a pull request, so that when I loose interest for BLE, this code might still get updated, and not left here as a bad example.
