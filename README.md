

u can join our qq group [424031785](https://jq.qq.com/?_wv=1027&k=5wx5xzv)

if u r interested in our project or think our project is useful for u, please star it, thanks!


### how to compile in ubuntu 16.04 TLS

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

./configure

make -j4

## 欢迎加入我们的[技术社区](https://talk.kunteng.org)一起讨论有关wificoin的技术问题
