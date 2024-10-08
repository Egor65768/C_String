FROM ubuntu:22.04
RUN apt-get update && \
    apt-get install -y gcc check make && \
    rm -rf /var/lib/apt/lists/*
WORKDIR /home/
COPY . .
CMD ["sh", "-c", "make test"]