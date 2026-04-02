# Makefile Week 15: Socket Programming
# ENEE602004 Algoritma Pemrograman dan Praktikum
CXX      = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g
SRCDIR   = src
TARGETS  = demo01 demo02 demo03 demo04

.PHONY: all clean

all: $(TARGETS)
	@echo "  Semua demo berhasil dikompilasi."

demo01: $(SRCDIR)/01_tcp_server.cpp
	$(CXX) $(CXXFLAGS) -I$(SRCDIR) -o $@ $^
	@echo "  Built: demo01  (TCP server)"

demo02: $(SRCDIR)/02_tcp_client.cpp
	$(CXX) $(CXXFLAGS) -I$(SRCDIR) -o $@ $^
	@echo "  Built: demo02  (TCP client)"

demo03: $(SRCDIR)/03_udp_demo.cpp
	$(CXX) $(CXXFLAGS) -I$(SRCDIR) -o $@ $^
	@echo "  Built: demo03  (UDP demo)"

demo04: $(SRCDIR)/04_ee_sensor_server.cpp
	$(CXX) $(CXXFLAGS) -I$(SRCDIR) -o $@ $^
	@echo "  Built: demo04  (EE sensor server)"

clean:
	rm -f $(TARGETS)
