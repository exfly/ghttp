# GHttp server [![Build Status](https://travis-ci.org/ExFly/ghttp.svg?branch=master)](https://travis-ci.org/ExFly/ghttp)

## Description

Reimplement httpserver like nginx based on csapp lib.
## Usage

```sh
make
./ghttp 8080
```
```
Get http://localhost:8080/: read tcp [::1]:58899->[::1]:8080: read: connection reset by peer
Get http://localhost:8080/: dial tcp [::1]:8080: i/o timeout

ab -c 10 -n 1000 localhost:8080/
Server Software:        Ghttp
Server Hostname:        localhost
Server Port:            8080

Document Path:          /
Document Length:        556 bytes

Concurrency Level:      1
Time taken for tests:   91.589 seconds
Complete requests:      10000
Failed requests:        0
Total transferred:      6660000 bytes
HTML transferred:       5560000 bytes
Requests per second:    109.18 [#/sec] (mean)
Time per request:       9.159 [ms] (mean)
Time per request:       9.159 [ms] (mean, across all concurrent requests)
Transfer rate:          71.01 [Kbytes/sec] received

Connection Times (ms)
              min  mean[+/-sd] median   max
Connect:        0    0   0.1      0       6
Processing:     7    9   1.0      9      25
Waiting:        7    9   1.0      9      25
Total:          8    9   1.1      9      26

Percentage of the requests served within a certain time (ms)
  50%      9
  66%      9
  75%      9
  80%      9
  90%     10
  95%     11
  98%     12
  99%     13
 100%     26 (longest request)
```

## Notice

change the default html dir at `src/core/core.c parse_uri`
change the default log leve at `src/logger/log.c LOGLEV`
