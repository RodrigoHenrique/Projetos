compr(L,T):-L=[X|Xs],compr(Xs,T1),T=1+T1.
compr(L,T):-L=[],T=0.

compr1([X|Xs],T):-compr1(Xs,T1),T=1+T1.
compr1([],0).

compr2([_|Xs],1+C):-compr2(Xs,C).
compr2([],0).

compr3(L,A):-comprAcc(L,0,A).
comprAcc([X|Xs],Acc,A):-comprAcc(Xs,Acc+1,A).
comprAcc([],Acc,B):-B=Acc.