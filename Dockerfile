FROM debian:latest
ARG LOG_LEVEL=TRACE

RUN apt update
RUN apt install -y make g++ libcurl4-openssl-dev nlohmann-json3-dev

COPY . .

RUN make LOG_LEVEL="${LOG_LEVEL}"

ENTRYPOINT ["make", "run-binary"]
