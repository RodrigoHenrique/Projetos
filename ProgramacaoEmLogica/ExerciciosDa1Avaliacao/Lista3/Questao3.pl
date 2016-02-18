append1([A|As],B,[A|AsB]):-append1(As,B,AsB).
append1([],B,B).