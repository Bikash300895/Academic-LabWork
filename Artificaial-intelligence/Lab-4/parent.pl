male(a).
male(b).

female(c).
female(d).

parent(a,b).
parent(c,d).

parent(b,c).

father(X,Y):-
	parent(X,Y),male(X).

mother(X,Y):-
	parent(X,Y),female(X).

grantparent(X,Y):-
	parent(X,Z),parent(Z,Y).