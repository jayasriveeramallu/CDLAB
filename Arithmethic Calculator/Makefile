calc: lexical.o parser.o
        cc -o calc lexical.o parser.o -ll -ly
lexical.o: lex.yy.c
        cc -c lex.yy.c -o lexical.o
lex.yy.c: cal.l y.tab.h
        lex cal.l
parser.o: y.tab.c
        cc -c y.tab.c -o parser.o
y.tab.c y.tab.h:cal.y
        yacc -d cal.y
