PROGNAME    = sweet 
VERSION     = 1.00

PROGS       = afl signal

CFLAGS     ?= -O3 -funroll-loops
CFLAGS     += -Wall -D_FORTIFY_SOURCE=2 -g -Wno-pointer-sign

CXXFLAGS += -O2 -g -Wall -std=c++11 -fmessage-length=0

ifneq "$(filter Linux GNU%,$(shell uname))" ""
  LDFLAGS  += -ldl
endif

MEM_LDFLAGS  = -lrt

COMM_HDR    = alloc-inl.h config.h debug.h types.h


all: $(PROGS)

afl:$(COMM_HDR)
	$(CXX) $(CXXFLAGS) $@.cc -o $@

signal:$(COMM_HDR)
	$(CXX) $(CXXFLAGS) $@.cc -o $@

sweet-start: $(COMM_HDR)
	$(CXX) $(CXXFLAGS) $@.cc -o $@ $(MEM_LDFLAGS)

clean:
	rm -f $(PROGS) *.o
