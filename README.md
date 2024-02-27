# created on Fedora linux with ncurses
You can find some examples with ncurses on my website https://sites.google.com/view/festila-george-catalin/tutoriale
# radio-online-catafest

This is a simple radio online .

Use arrow keys , enter key and F1 key with ESC for quit.

In this moment has one single online radio channel.

You can add more , I have a list with radio channels:

BBC / dial 222 (BBC Radio - US & World News)
/usr/bin/mpg123 -q -s --mono -r 8000 -f 8192 -b 0 http://stream.live.vc.bbcmedia.co.uk/bbc_world_service

KABL / dial 5225 (KABL Oldies Radio, San Francisco, CA)
/usr/bin/ffmpeg -i https://stationplaylist.com:7104/listen.aac -f s16le -ac 1 -ar 8000 -vol 32 pipe:1 :

OLDT / dial 6538 (Old Times Radio, Stories)
/usr/bin/mpg123 -q -s --mono -r 8000 -f 8192 -b 0 -@ http://radio.macinmind.com/listen.m3u

WNAR / dial 9627 (Old Times Radio, Stories)
/usr/bin/mpg123 -q -s --mono -r 8000 -f 8192 -b 0 http://162.244.80.33:8500/;stream.mp3

JAZ1 / dial 5291 (Smooth Jazz Internet Radio)
/usr/bin/mpg123 -q -s --mono -r 8000 -f 8192 -b 0 http://ais-sa2.cdnstream1.com/b22139_128mp3

JAZ2 / dial 5292 (smoothjazz.com)
/usr/bin/ffmpeg -i http://smoothjazz.cdnstream1.com/2585_64.aac -f s16le -ac 1 -ar 8000 -vol 32 pipe:1

KQED / dial 5733 (KQED Radio, San Francisco, CA)
/usr/bin/mpg123 -q -s --mono -r 8000 -f 8192 -b 0 http://streams.kqed.org/kqedradio.m3u

KNPR / dial 5677 (NPR Radio, Nevada)
/usr/bin/mpg123 -q -s --mono -r 8000 -f 8192 -b 0 http://pd.npr.org/anon.npr-mp3/npr/news/newscast.mp3

INFO / dial 4636 (France Info, 24h French News)
/usr/bin/mpg123 -q -s --mono -r 8000 -f 8192 -b 0 http://icecast.radiofrance.fr/franceinfo-midfi.mp3

RTL / dial 785 (RTL Radio, French Broadcaster)
/usr/bin/mpg123 -q -s --mono -r 8000 -f 8192 -b 0 http://streaming.radio.rtl.fr/rtl-1-44-128

CINE / dial 2463 (CineMix Internet Radio, Movie themes)
/usr/bin/mpg123 -q -s --mono -r 8000 -f 8192 -b 0 -@ http://listenwmp.cinemix.fr

BEAT / dial 2328 (Beatles Radio, 24h Beatles music)
/usr/bin/mpg123 -q -s --mono -r 8000 -f 8192 -b 0 http://www.beatlesradio.com:8000/stream/1/

CLAS / dial 2527 (Classic FM, UK based classical music radio)
/usr/bin/mpg123 -q -s --mono -r 8000 -f 8192 -b 0 -@ http://media-ice.musicradio.com/ClassicFMMP3.m3u

KDFC / dial 5332 (KDFC Radio, classical music)
/usr/bin/mpg123 -q -s --mono -r 8000 -f 8192 -b 0 -@ http://provisioning.streamtheworld.com/pls/KDFCFM.pls

WCPE / dial 9273 (WCPE Radio, classical music)
/usr/bin/mpg123 -q -s --mono -r 8000 -f 8192 -b 0 -@ http://www.ibiblio.org/wcpe/wcpe.pls

The above channels will show up in the file /etc/asterisk/musiconhold_additional.conf as MOH entries are created through the web GUI.
They will appear in the following format (BBC and KABL shown as examples, there will be as many as entered through MOH):

[BBC]
mode=custom
application=/usr/bin/mpg123 -q -s --mono -r 8000 -f 8192 -b 0 http://stream.live.vc.bbcmedia.co.uk/bbc_world_service
format=

[KABL]
mode=custom
application=/usr/bin/ffmpeg -i https://stationplaylist.com:7104/listen.aac -f s16le -ac 1 -ar 8000 -vol 32 pipe:1
format=

Close the radio channel by pressing enter key , then you can use F1 key or ESC key to quit.

I used ncurses , see [the wikipedia article](https://en.wikipedia.org/wiki/Ncurses) on Fedora 39 Linux Distro.

```
gcc -o ro-catafest ro-catafest.c -lncurses
```

The software is licensed as GPL-licensed software. The GPL is a copyleft license that requires derivative works to be licensed under the same terms as the original work. This means that if you create a derivative work based on GPL-licensed software, you must also release your work under the GPL. The GPL is commonly used for open source software, such as the Linux operating system.

