### GPS Simulator
### This project based on [Software-Defined GPS Signal Simulator Project](https://github.com/osqzss/gps-sdr-sim)
### How To Compile
```
gcc gpssim.c -lm -lpthread -g -O3 -o gps-sdr-sim
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
./gps-sdr-sim -e brdcXXXX.18n -l <lat,long,height> -b 8 -t $(date +%Y/%m/%d,%H:%M:%S) -i -o <outfile>
```
###### Note: outfile can be fifo
```
mkfifo mystream
./gps-sdr-sim -e brdcXXXX.18n -l <lat,long,height> -b 8 -t $(date +%Y/%m/%d,%H:%M:%S) -i -o mystream
```
###### Online Mode (Synchronization):
```
./gps-sdr-sim -e brdcXXXX.18n -k <server_addr> -l <lat,long,height> -b 8 -t $(date +%Y/%m/%d,%H:%M:%S) -i -o <output_file>
```
###### Note: Server must open port "8080" to listen

