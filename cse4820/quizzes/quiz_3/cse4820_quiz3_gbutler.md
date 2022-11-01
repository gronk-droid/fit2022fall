**CSE 4820 – Fall 2022**

**Quiz #3**

**Due: 10/04/2022 10:45AM**

You are welcome to use any figure/text that you find online. However, you <span style="text-decoration:underline;">MUST</span> provide your reference (i.e., website link, slide number, book chapter, etc.). 

Please answer what is being asked only and provide any justification/assumptions you make.



1. What are the Bluetooth pairing techniques available? What are the differences between them? Explain in short. (40p)

The different bluetooth pairing techniques include a page request from the device that wants to connect, then the other device responds with an ID, and then the connection is established. To secure this protocol, there are two methods. One is a Link Key, which has a pin generated from the address of the device to be connected to, and then the user needs to input that pin to the two devices. The other one is Secure Simple Pairing (SSP) where both have a public key that is then put through an exchange that gives them both a DHkey. Then, there are different ways to authenticate, being just works, numeric comparison, a pairing code, or using another factor of authentication like a physical NFC connection. SSP is much more secure than the regular Link Key technique due to the different modes of authentication.



2. Can you use Bluetooth with TCP? Why (and how) or why not? What about HTTP? If yes, would that be a feasible and smart way to provide communication? Please explain in either case. (60p)

You could use TCP on Bluetooth since TCP is a protocol that is in the transport layer, where Bluetooth is the physical layer of connection. So, in some world you could take TCP and run it over Bluetooth, though I am unsure if there is an Internet Protocol (IP) built to run TCP/IP on Bluetooth. It would run extremely slowly, as the bandwidth of Bluetooth is atrocious. HTTP could also run over that, as HTTP just transfers hypertext documents. You could even start using something like SSH as a protocol, or maybe just FTP. I believe FTP is something that is done over Bluetooth sometimes, like in older Android phones back in the early 2010s to transfer ringtones or small photos.
