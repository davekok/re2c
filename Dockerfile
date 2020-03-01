FROM alpine AS builder
ENV BASE_FLAGS="-O2 -g"
ENV CFLAGS="-O2 -g"
ENV CXXFLAGS="-O2 -g"
ENV LDFLAGS="-O2 -g"
COPY . /src/re2c
RUN apk add gcc g++ make automake autoconf m4 bash bison clang libtool file \
	&& cd /src/re2c \
	&& mkdir m4 \
	&& autoreconf -i -W all \
	&& ./configure --prefix=/app --bindir=/app --mandir=/man \
	&& make \
	# && make check \
	&& make install

FROM alpine
RUN apk add --no-cache libgcc libstdc++
COPY --from=builder /app /app
ENTRYPOINT ["/app/re2c"]
