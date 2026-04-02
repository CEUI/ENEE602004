# Makefile Week 14: OOP 3 (Polymorphism)
# ENEE602004 Algoritma Pemrograman dan Praktikum
CXX      = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g
SRCDIR   = src
TARGETS  = demo01 demo02 demo03 demo04

.PHONY: all clean

all: $(TARGETS)
	@echo "  Semua demo berhasil dikompilasi."

demo01: $(SRCDIR)/01_virtual_dispatch.cpp
	$(CXX) $(CXXFLAGS) -I$(SRCDIR) -o $@ $^
	@echo "  Built: demo01  (virtual dispatch)"

demo02: $(SRCDIR)/02_abstract_class.cpp
	$(CXX) $(CXXFLAGS) -I$(SRCDIR) -o $@ $^
	@echo "  Built: demo02  (abstract class)"

demo03: $(SRCDIR)/03_unique_ptr.cpp
	$(CXX) $(CXXFLAGS) -I$(SRCDIR) -o $@ $^
	@echo "  Built: demo03  (unique_ptr)"

demo04: $(SRCDIR)/04_ee_bom_analyzer.cpp
	$(CXX) $(CXXFLAGS) -I$(SRCDIR) -o $@ $^
	@echo "  Built: demo04  (EE BOM analyzer)"

clean:
	rm -f $(TARGETS)
