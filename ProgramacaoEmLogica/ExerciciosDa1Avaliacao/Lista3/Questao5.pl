reverse1([X|Xs],Y):-Xs\==[],reverse1(Xs,Z),append1(Z,[X],Y),!.
reverse1([X],[X]).

append1([A|As],B,[A|AsB]):-append1(As,B,AsB).
append1([],B,B).