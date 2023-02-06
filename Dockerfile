FROM debian:latest

RUN apt update
RUN apt install -y make g++ libcurl4-openssl-dev nlohmann-json3-dev

COPY . .

RUN make

ENTRYPOINT ["make", "run-binary"]
