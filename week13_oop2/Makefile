CXX      = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g
SRCDIR   = src
TARGETS  = demo01 demo02 demo03 demo04

.PHONY: all clean run01 run02 run03 run04
all: $(TARGETS)
	@echo "  Semua demo berhasil dikompilasi."

demo01: $(SRCDIR)/01_basic_inheritance.cpp
	$(CXX) $(CXXFLAGS) -I$(SRCDIR) -o $@ $^
	@echo "  Built: demo01  (basic inheritance)"

demo02: $(SRCDIR)/02_constructor_chain.cpp
	$(CXX) $(CXXFLAGS) -I$(SRCDIR) -o $@ $^
	@echo "  Built: demo02  (constructor chain)"

demo03: $(SRCDIR)/03_access_specifiers.cpp
	$(CXX) $(CXXFLAGS) -I$(SRCDIR) -o $@ $^
	@echo "  Built: demo03  (access specifiers)"

demo04: $(SRCDIR)/04_ee_potentiometer.cpp
	$(CXX) $(CXXFLAGS) -I$(SRCDIR) -o $@ $^
	@echo "  Built: demo04  (EE potentiometer)"

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
