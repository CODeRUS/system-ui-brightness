#!/bin/sh
if [ "$1" != "" ]; then
  echo $1 > /sys/devices/omapdss/display0/backlight/display0/brightness
fi
exit 0
