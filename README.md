# GHttp server

## Description

Reimplement httpserver like nginx.

## Usage

```sh
make
./ghttp 8080
```
```
Get http://localhost:8080/: read tcp [::1]:58899->[::1]:8080: read: connection reset by peer
Get http://localhost:8080/: dial tcp [::1]:8080: i/o timeout

statistics:
  total:1000
  k:ok v:813
  k:err v:187
```

## Notice

change the default html dir at `src/core/core.c parse_uri`
change the default log leve at `src/logger/log.c LOGLEV`
