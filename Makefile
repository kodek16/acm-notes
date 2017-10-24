TESTS=example_test.cc

CXX=g++
CXXFLAGS=--std=c++14 -I.

all:
	# Run two times to update table of contents.
	pdflatex notebook
	pdflatex notebook

test: $(TESTS:.cc=.o) test.cc
	$(CXX) -o test test.cc $(TESTS:.cc=.o) $(CXXFLAGS)
	./test

%.o: %.c
	$(CXX) -c -o $@ $< $(CXXFLAGS)

clean:
	rm -f *.log *.aux *.toc *.pdf
	rm -f *.o
	rm -f test
