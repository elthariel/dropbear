# --- Building dropbear binaries

FROM alpine:latest AS builder

RUN apk add --update alpine-sdk autoconf zlib zlib-dev

WORKDIR /usr/src/dropbear

ADD . ./
COPY docker/localoptions.h /usr/src/dropbear

RUN autoconf && autoheader && \
    ./configure --disable-syslog --enable-static
RUN make -j PROGRAMS="dropbear" install


# --- Building our minimal images

FROM scratch

WORKDIR /etc/dropbear
COPY --from=builder /usr/local/sbin/dropbear /dropbear

EXPOSE 22
ENTRYPOINT ["/dropbear"]

CMD ["-FREsk"]
