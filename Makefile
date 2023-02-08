default: all

all: compile

ENTRYPOINT	=	"main"

CC				=	g++ -std=c++20
CCFLAGS			= 	-g -Wall -O0
CURLFLAGS		= 	-lcurl
INCLUDEFLAGS	=   -I$(shell pwd)

# make LOG_LEVEL=INFO
LOG_LEVEL=TRACE

compile:
	@$(CC) $(CCFLAGS) `find lifesim -name '*.cc' | xargs echo` -o ${ENTRYPOINT} -D LOG_LEVEL=${LOG_LEVEL} ${CURLFLAGS} ${INCLUDEFLAGS}

run-binary:
	@./${ENTRYPOINT}

build:
	docker build --build-arg LOG_LEVEL="${LOG_LEVEL}" -t lifesim:latest .

run:
	docker run -it lifesim:latest
