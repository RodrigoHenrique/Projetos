reverse2(L,Y):-reverseAcc(L,[],Y).

reverseAcc([X|Xs],Acc,Y):-reverseAcc(Xs,[X|Acc],Y).
reverseAcc([],Y,Y).