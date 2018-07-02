### GPS Simulator
### This project based on [Software-Defined GPS Signal Simulator Project](https://github.com/osqzss/gps-sdr-sim)
### How To Compile
```
gcc gpssim.c -lm -lpthread -O3 -o gps-sdr-sim
```
Compile on Raspberry Pi 3
```
gcc gpssim.c -lm -lpthread -O3 -std=c11 -o gps-sdr-sim
```
### How To Use
###### Usage: gps-sdr-sim [options]
```
Options:
  -e <gps_nav>     RINEX navigation file for GPS ephemerides (required)
  -u <user_motion> User motion file (dynamic mode)
  -g <nmea_gga>    NMEA GGA stream (dynamic mode)
  -l <location>    Lat,Lon,Hgt (static mode) e.g. 30.286502,120.032669,100
  -t <date,time>   Scenario start time YYYY/MM/DD,hh:mm:ss
  -T <date,time>   Overwrite TOC and TOE to scenario start time
  -d <duration>    Duration [sec] (max: 300)
  -o <output>      I/Q sampling data file (default: gpssim.bin)
  -s <frequency>   Sampling frequency [Hz] (default: 2600000)
  -b <iq_bits>     I/Q data format [1/8/16] (default: 16)
  -i               Interactive mode: North='w', South='s', East='d', West='a'
  -v               Show details about simulated channels
  -m <0,1>         Running Mode: Offline: 0, Online: 1
  -k <address>     Server address, Port 8080
```
###### Offline mode:
```
./gps-sdr-sim -e brdcXXXX.18n -l <lat,long,height> -b 8 -t $(date -u +%Y/%m/%d,%H:%M:%S) -i -o <outfile>
e.g: ./gps-sdr-sim -e brdc0710.18n -l 1.300519,103.7793489,15 -b 8 -t $(date -u +%Y/%m/%d,%H:%M:%S) -i -o /tmp/streaming.bin

```
###### Note: outfile can be fifo
```
mkfifo mystream
./gps-sdr-sim -e brdcXXXX.18n -l <lat,long,height> -b 8 -t $(date -u +%Y/%m/%d,%H:%M:%S) -i -o mystream
```
###### Online Mode (Synchronization):
```
./gps-sdr-sim -e brdcXXXX.18n -k <server_addr> -l <lat,long,height> -b 8 -t $(date -u +%Y/%m/%d,%H:%M:%S) -i -o <output_file>
./gps-sdr-sim -e brdc0710.18n -l 1.300519,103.7793489,15 -b 8 -t $(date -u +%Y/%m/%d,%H:%M:%S) -i -o /tmp/mystream
```
######  Note1: 
* Server must open port "8080" to listen. An example of server at [here](https://github.com/mtoan2111/gpssim_server.git)
* Time input must be in UTC format YYYY/MM/DD,hh:mm:ss. The time input is not more than 4 hours compared to the latest time of ephemeris set.
###### Note2:
* Regarding the Raspberry Pi 3, due to the limit of clock, you can conduct the experiment on that one by 2 ways:
- Reduce the sample rate to ```1e6``` by using ```-s``` option
- Reduce the number of channels by re-define the ```MAX_CHAN``` variable 
