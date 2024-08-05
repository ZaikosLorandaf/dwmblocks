PREFIX  := /usr/local
CC      := cc
:x
LDFLAGS := -lX11

HOST := $(shell uname -n)

ifeq ($(HOST), disaster)
#define
	CONFIG_FLAG = -DHOST_DISASTER
endif

all: options dwmblocks

options:
	@echo dwmblocks build options:
	@echo "CFLAGS  = ${CFLAGS}"
	@echo "LDFLAGS = ${LDFLAGS}"
	@echo "CC      = ${CC}"
	@echo "CONFIG_FLAG = ${CONFIG_FLAG}"

dwmblocks: dwmblocks.c blocks.def.h blocks.h
	${CC} -o dwmblocks dwmblocks.c ${CFLAGS} ${LDFLAGS} ${CONFIG_FLAG}

blocks.h:
	cp blocks.def.h $@

clean:
	rm -f *.o *.gch dwmblocks

install: dwmblocks
	mkdir -p ${DESTDIR}${PREFIX}/bin
	cp -f dwmblocks ${DESTDIR}${PREFIX}/bin
	chmod 755 ${DESTDIR}${PREFIX}/bin/dwmblocks

uninstall:
	rm -f ${DESTDIR}${PREFIX}/bin/dwmblocks

.PHONY: all options clean install uninstall
