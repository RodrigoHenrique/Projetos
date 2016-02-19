maxL(M,[X|Xs]):-Xs\==[],maxL(M,Xs),X<M,!.
maxL(X,[X|Xs]):-Xs\==[],maxL(M,Xs),X>=M,!.
maxL(X,[X]).