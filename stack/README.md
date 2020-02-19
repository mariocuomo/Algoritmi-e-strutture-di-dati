# Stack

Uno stack, coda o semplicemente pila, è un tipo astratto di dati che rappresenta una struttura di dati il cui accesso segue un approccio <b>LIFO (Last In First Out)</b>.

![STACK](https://github.com/mariocuomo/Algoritmi-e-strutture-di-dati/blob/master/stack/stack.png)

Un modo molto semplice per visualizzare il concetto di pila è quello di pensare a una vera e propria pila di piatti. 
Le operazioni concesse quindi sono quelle di inserire un nuovo elemento in testa alla pila e quella di estrarre l'elemento attualmente in testa.

La pila considerata è di interi positivi ed è rappresentata con una struttura a tre campi:
<pre>
1. un campo che rappresenta l'array di interi positivi
2. un campo che rappresenta un riferimento all'ultimo elemento inserito (o analogamente alla prima posizione libera)
3. un campo che indica la dimensione dell'array
</pre>

La dimensione dell'array è gestita in maniera <b>telescopica</b>. Quando è raggiunto il limite massimo la dimensione è raddoppiata.
Analogamente, quando il numero di elementi dell'array è molto piccolo(circa un terzo) rispetto alla grandezza dell'array, esso è ridimensionato.
