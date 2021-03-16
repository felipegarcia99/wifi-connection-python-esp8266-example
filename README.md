To see in portuguese, click [here](README_pt-BR.md)

# Example of connection between esp8266 and python via TCPsocket

This code is basically an example of how to connect a [esp8266] (https://en.wikipedia.org/wiki/ESP8266) (or another one in the family, with wi-fi) to a computer or other device (such as a Raspberry Pi ) running Python. The connection is made via wi-fi, using a TCP / IP stack as support.

## Problematic

There has always been a need to connect wifi devices like esp8266 with ease to others, mainly due to the IoT issue. In this way, python does very well, both because of the ease of programming and the wealth of libraries.

There are, basically, two ways to connect esp8266 to other devices via wifi: by HTTP requests and by TCP sockets. The first is much more addressed on the internet, especially between two esp8266.

The connection via HTTP requests has the advantage of allowing multiple clients for the same server, but it is not always what you want.

On the other hand, the connection via TCPsocket deals with the direct connection between two devices only (like a tunnel), so that only strings are sent from one to another, directly.

## Objective

The purpose of this code is to provide an example of how to connect an esp8266 microcontroller to a pc via python in a very simple way, using only the python ```socket``` library, which is built-in. In the same way that I needed and found this solution, so I am also helping 😎. Just observe the codes and adapt to your situation.

## Notices

It is important to check that the chosen port is open to connections on the firewall. In Windows, this is verified in the system settings (or the antivirus, if any).

In Linux, you can open the port using the following [command] (https://www.cyberciti.biz/faq/linux-unix-open-ports/) (the port already written in the program was used as an example):

```(bash)
sudo iptables -A INPUT -m state --state NEW -m tcp -p tcp --dport 8080 -j ACCEPT
sudo service iptables save
```

## Future plans

The possibility of programming an API in the future is being analyzed, so that it is only necessary to instantiate a `` `WiFiSocket``` object on both sides, so that, for example

```(python)
soc = WiFiSocket()
soc.send('Hi')
answer = soc.receive()
```

be enough to ensure the connection between the two nodes.

## Credits
I admit, this code is not mine. It was a solution taken from some page on the internet a few years ago, so I don't remember the author. However, the code has been optimized to contain only the essentials.

## License
[MIT](https://choosealicense.com/licenses/mit/)
