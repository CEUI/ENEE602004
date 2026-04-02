# ============================================================
# Makefile — Week 9: Singly Linked List
# ENEE602004 Algoritma Pemrograman dan Praktikum
# ============================================================
CXX      = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g
SRCDIR   = src

# File implementasi bersama (dibutuhkan semua demo)
SLL      = $(SRCDIR)/sll_ops.cpp

# Daftar semua program demo
TARGETS  = demo01 demo02 demo03 demo04

.PHONY: all clean run01 run02 run03 run04

all: $(TARGETS)
	@echo "  Semua demo berhasil dikompilasi."

demo01: $(SLL) $(SRCDIR)/01_append_prepend.cpp
	$(CXX) $(CXXFLAGS) -I$(SRCDIR) -o $@ $^
	@echo "  Built: demo01  (append & prepend)"

demo02: $(SLL) $(SRCDIR)/02_search.cpp
	$(CXX) $(CXXFLAGS) -I$(SRCDIR) -o $@ $^
	@echo "  Built: demo02  (search)"

demo03: $(SLL) $(SRCDIR)/03_insert_delete.cpp
	$(CXX) $(CXXFLAGS) -I$(SRCDIR) -o $@ $^
	@echo "  Built: demo03  (insertAfter & deleteNode)"

demo04: $(SLL) $(SRCDIR)/04_ee_sensor.cpp
	$(CXX) $(CXXFLAGS) -I$(SRCDIR) -o $@ $^
	@echo "  Built: demo04  (EE sensor log)"

run01: demo01
	./demo01

run02: demo02
	./demo02

run03: demo03
	./demo03

run04: demo04
	./demo04

clean:
	rm -f $(TARGETS)
