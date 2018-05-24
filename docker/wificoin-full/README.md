# wificoin-full
a full wificoin full environment docker image, include build environment and run environment.

### usage
1. copy `wificoin/Dockerfile` to `./`
2. run `docker docker build ./ -t wificoin-full:latest`
3. run `docker run -d -p 9665:9665 -p 9666:9666 -v ~/.wificoin:/root/.wificoin --name wificoin  wificoin-full:latest`
