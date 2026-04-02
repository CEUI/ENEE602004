CXX      = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g
SRCDIR   = src
OPS      = $(SRCDIR)/sort_ops.cpp
TARGETS  = demo01 demo02 demo03 demo04

.PHONY: all clean run01 run02 run03 run04
all: $(TARGETS)
	@echo "  Semua demo berhasil dikompilasi."

demo01: $(OPS) $(SRCDIR)/01_bubble_sort.cpp
	$(CXX) $(CXXFLAGS) -I$(SRCDIR) -o $@ $^
	@echo "  Built: demo01  (bubble sort)"

demo02: $(OPS) $(SRCDIR)/02_insertion_sort.cpp
	$(CXX) $(CXXFLAGS) -I$(SRCDIR) -o $@ $^
	@echo "  Built: demo02  (insertion sort)"

demo03: $(OPS) $(SRCDIR)/03_selection_sort.cpp
	$(CXX) $(CXXFLAGS) -I$(SRCDIR) -o $@ $^
	@echo "  Built: demo03  (selection sort)"

demo04: $(OPS) $(SRCDIR)/04_ee_median_filter.cpp
	$(CXX) $(CXXFLAGS) -I$(SRCDIR) -o $@ $^
	@echo "  Built: demo04  (EE median filter)"

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
