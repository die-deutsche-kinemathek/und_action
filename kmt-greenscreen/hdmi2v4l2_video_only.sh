#!/bin/sh

# … die bilder werden vom hdmi-grabber abgeholt, deinterlaced und an ein v4l2-
# loopback-device weitergereicht, dort werden sie dann wiederum von pure data
# abgeholt
# das gleiche gilt für das audio - ffmpeg kann kein jack ausgeben, darum gehen
# sie per pipe zu jack-stdin

# /usr/local/bin/bmdcapture -m 10  -f pipe:1 -F nut | /usr/bin/ffmpeg \
#   -i - -vf yadif=1:-1:0 -pix_fmt uyvy422 -vtag UYVY -f v4l2 /dev/video0

/usr/local/bin/bmdcapture -m 10  -f pipe:1 -F nut | /usr/bin/ffmpeg -i - \
  -vf yadif=1:-1:0 -pix_fmt uyvy422 -vtag UYVY  -f v4l2 /dev/video0 
