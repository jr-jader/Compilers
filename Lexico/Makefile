FLEX=flex
CXX=g++
CXXFLAGS=
LIBS=-lfl

PROGRAMA = lexico
LEXICO = lexico.l

$(PROGRAMA): $(LEXICO)
	$(FLEX) $(LEXICO)
	$(CXX) lex.yy.c $(LIBS) $(CXXFLAGS) -o $(PROGRAMA)

clean:
	rm -f lex.yy.c
	rm -f lexico.exe lexico
