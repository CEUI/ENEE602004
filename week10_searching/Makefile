CXX      = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g
SRCDIR   = src
OPS      = $(SRCDIR)/search_ops.cpp
TARGETS  = demo01 demo02 demo03 demo04

.PHONY: all clean run01 run02 run03 run04
all: $(TARGETS)
	@echo "  Semua demo berhasil dikompilasi."

demo01: $(OPS) $(SRCDIR)/01_linear_search.cpp
	$(CXX) $(CXXFLAGS) -I$(SRCDIR) -o $@ $^
	@echo "  Built: demo01  (linear search)"

demo02: $(OPS) $(SRCDIR)/02_binary_search.cpp
	$(CXX) $(CXXFLAGS) -I$(SRCDIR) -o $@ $^
	@echo "  Built: demo02  (binary search)"

demo03: $(OPS) $(SRCDIR)/03_stl_search.cpp
	$(CXX) $(CXXFLAGS) -I$(SRCDIR) -o $@ $^
	@echo "  Built: demo03  (STL search)"

demo04: $(OPS) $(SRCDIR)/04_ee_adc_calibration.cpp
	$(CXX) $(CXXFLAGS) -I$(SRCDIR) -o $@ $^
	@echo "  Built: demo04  (EE ADC calibration)"

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
