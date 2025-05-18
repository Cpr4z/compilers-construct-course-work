grammar b;

program
    : definition* EOF
    ;

definition
    : name constant? (ival (',' ival)*)* ';'
    | name '(' (name (',' name)*)? ')' statement
    ;

ival
    : constant
    | name
    ;

statement
    : externsmt
    | autosmt
    | autoarraysmt
    | name ':' statement
    | casestmt
    | blockstmt
    | ifstmt
    | whilestmt
    | switchstmt
    | gotostmt
    | returnstmt
    | expressionstmt
    | nullstmt
    ;

nullstmt
    : ';'
    ;

expressionstmt
    : rvalue ';'
    ;

blockstmt
    : '{' statement* '}'
    ;

returnstmt
    : 'return' ('(' rvalue ')')? ';'
    ;

gotostmt
    : 'goto' rvalue ';'
    ;

switchstmt
    : 'switch' rvalue statement
    ;

whilestmt
    : 'while' '(' rvalue ')' statement
    ;

ifstmt
    : 'if' '(' rvalue ')' statement ('else' statement)?
    ;

casestmt
    : 'case' constant ':' statement
    ;

externsmt
    : 'extrn' name (',' name)* ';'
    ;

autosmt
    : 'auto' name constant? (',' name constant?)* ';'
    ;

autoarraysmt
    : 'auto' name '[' INT ']' ';'
    ;

rvalue
    : expression
    | comparison
    | ternary
    | assignment
    ;

ternary
    : expression '?' rvalue ':' rvalue
    ;

comparison
    : expression binary rvalue
    ;

assignment
    : name assign rvalue
    | name '[' rvalue ']' assign rvalue
    ;

expression
    : '(' rvalue ')'
    | name
    | constant
    | incdec name
    | name incdec
    | unary rvalue
    | '&' name
    | functioninvocation
    | name '[' rvalue ']'
    ;

functioninvocation
    : name '(' functionparameters? ')'
    ;

functionparameters
    : rvalue (',' rvalue)*
    ;

assign
    : '=' binary?
    ;

incdec
    : '++'
    | '--'
    ;

unary
    : '-'
    | '!'
    ;

binary
    : '|'
    | '&'
    | '=='
    | '!='
    | '<'
    | '<='
    | '>'
    | '>='
    | '<<'
    | '>>'
    | '-'
    | '+'
    | '%'
    | '*'
    | '/'
    ;

lvalue
    : name
    | '*' rvalue
    | name '[' INT ']'
    | rvalue '[' rvalue ']'
    ;

constant
    : INT
    | STRING1
    | STRING2
    ;

name
    : NAME
    ;

NAME
    : [a-zA-Z] [a-zA-Z0-9_]*
    ;

INT
    : [0-9]+
    ;

STRING1
    : '"' ~ ["\r\n]* '"'
    ;

STRING2
    : '\'' ~ ['\r\n]* '\''
    ;

BLOCKCOMMENT
    : '/*' .*? '*/' -> skip
    ;

WS
    : [ \t\r\n] -> skip
    ;