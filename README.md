

[![license][1]][2]
[![PRs Welcome][3]][4]
[![Issue Welcome][5]][6]
[![Release Version][7]][8]
[![OpenWRT][11]][12]


[1]: https://img.shields.io/badge/license-GPLV3-brightgreen.svg?style=plastic
[2]: https://github.com/liudf0716/apfree_wifidog/blob/master/COPYING
[3]: https://img.shields.io/badge/PRs-welcome-brightgreen.svg?style=plastic
[4]: https://github.com/wificoin-project/wificoin/pulls
[5]: https://img.shields.io/badge/Issues-welcome-brightgreen.svg?style=plastic
[6]: https://github.com/wificoin-project/wificoin/issues/new
[7]: https://img.shields.io/badge/release-2.10.1437-red.svg?style=plastic
[8]: https://github.com/wificoin-project/wificoin/releases
[11]: https://img.shields.io/badge/Platform-%20OpenWRT%7C%20LEDE%20-brightgreen.svg?style=plastic
[12]: https://github.com/KunTengRom/kunteng-lede-17.01.4

## about wificoin

wificoin was forked from bitcoin, it aimed to  wireless router industry, such as pay wfc to surf internet in public business scene and etc.

## how to compile in ubuntu 16.04 TLS

1

sudo apt-get install software-properties-common

sudo add-apt-repository ppa:bitcoin/bitcoin

sudo apt-get update

2

sudo apt-get install build-essential libtool autotools-dev autoconf pkg-config libssl-dev libevent-dev

sudo apt-get install libboost-all-dev

sudo apt-get install libdb4.8-dev libdb4.8++-dev

sudo apt-get install libminiupnpc-dev

sudo apt-get install libprotobuf-dev protobuf-compiler

sudo apt-get install libqrencode-dev

3

git clone https://github.com/wificoin-project/wificoin

./autogen.sh

./configure --disable-tests

make -j4

## 欢迎加入我们的[技术社区](https://talk.kunteng.org)一起讨论有关wificoin的技术问题

## contact us
qq group: 424031785

star our project and support us

## donate
### wfc: [weiKbu9DYg26gH2zucSHJHgH5KsuuZd3wW](https://wfc.xyblock.net/#/wifiPortal/donate)



