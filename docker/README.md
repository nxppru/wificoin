# wificoin
a minimal wificoin runable docker image.

### usage
1. copy `wificoind`, `wificoin-cli`,`wificoin-tx` to `./wificoin`
2. copy `wificoin/Dockerfile` to `./`
3. run `docker pull registry.cn-hangzhou.aliyuncs.com/wificoin-project/wificoin-run:latest`
4. run `docker tag registry.cn-hangzhou.aliyuncs.com/wificoin-project/wificoin-run:latest wificoin-run:latest`
5. run `docker docker build ./ -t wificoin:latest`
6. run `docker run -d -p 9665:9665 -p 9666:9666 -v ~/.wificoin:/root/.wificoin --name wificoin  wificoin:latest`

# public image

```
docker run -d -p 9665:9665 -p 9666:9666 \
            -v ~/.wificoin:/root/.wificoin \
            --name wificoin \
            registry.cn-hangzhou.aliyuncs.com/wificoin-project/wificon:latest
```

# wificoin.conf in `.wificon`
```
listen=1
server=1
rpcport=9665
rpcuser=test
rpcpassword=admin
rpcallowip=0.0.0.0/0
```