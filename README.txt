Tetris in Consola.

Cum se joaca:
Sunt patru miscari posibile, mutare stanga si dreapta, 1 si 3 respectiv,
rotire: 4, coborare: 2.

TODO:
Implementare pentru restul de 4 din cele 7 piese.
Implementare cu evenimente.
Bugfixing.

Am folosit o librarie din windows, nu ruleaza implicit pe linux.

Fiecare piesa are o "ancora", un punct in jurul careia se misca si se roteste
piesa. La miscari se verifica daca exista potentiale coliziuni.
Coborarea se face instant, se muta in jos piesa pana cand apare o coliziune.