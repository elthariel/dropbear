# --- Building dropbear binaries

FROM alpine:latest AS builder

RUN apk add --update alpine-sdk autoconf zlib-dev

WORKDIR /usr/src/dropbear

ADD . ./
COPY docker/localoptions.h /usr/src/dropbear

RUN autoconf && autoheader && \
    ./configure --disable-syslog --enable-static
RUN make -j PROGRAMS="dropbear" install


# --- Building our minimal images

FROM scratch

WORKDIR /etc
COPY --from=builder /usr/local/sbin/dropbear /dropbear

ENTRYPOINT ["/sbin/dropbear"]

ENV WINDOWSIZE=24576

CMD ["-F", "-E", "-s", "-k", "-W", ${WINDOWSIZE}]
