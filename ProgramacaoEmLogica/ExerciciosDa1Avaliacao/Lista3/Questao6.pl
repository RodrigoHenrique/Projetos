maxL2([X|Xs],M):-maxLAcc(Xs,X,M).

maxLAcc([X|Xs],Acc,M):-Acc>X,!,maxLAcc(Xs,Acc,M).
maxLAcc([X|Xs],_,M):-maxLAcc(Xs,X,M).
maxLAcc([],M,M).