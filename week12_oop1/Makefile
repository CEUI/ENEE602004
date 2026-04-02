CXX      = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g
SRCDIR   = src
TARGETS  = demo01 demo02 demo03 demo04

.PHONY: all clean run01 run02 run03 run04
all: $(TARGETS)
	@echo "  Semua demo berhasil dikompilasi."

demo01: $(SRCDIR)/01_basic_class.cpp
	$(CXX) $(CXXFLAGS) -I$(SRCDIR) -o $@ $^
	@echo "  Built: demo01  (basic class)"

demo02: $(SRCDIR)/02_encapsulation.cpp
	$(CXX) $(CXXFLAGS) -I$(SRCDIR) -o $@ $^
	@echo "  Built: demo02  (encapsulation)"

demo03: $(SRCDIR)/03_overloading.cpp
	$(CXX) $(CXXFLAGS) -I$(SRCDIR) -o $@ $^
	@echo "  Built: demo03  (overloading)"

demo04: $(SRCDIR)/04_ee_voltage_divider.cpp
	$(CXX) $(CXXFLAGS) -I$(SRCDIR) -o $@ $^
	@echo "  Built: demo04  (EE voltage divider)"

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
