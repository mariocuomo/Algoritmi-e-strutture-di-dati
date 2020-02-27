# Code di priorità

Una coda di priorità è una particolare struttura dati in cui gli elementi sono ordinai in base alla loro <b>priorità</b>.

![Coda di priorità](https://github.com/mariocuomo/Algoritmi-e-strutture-di-dati/blob/master/heap/maxHeap.jpg)

Le operazioni che si vogliono far svolgere all'utente sono le seguenti:
<pre>
-Estrarre l'elemento a più alta priorità
-Inserire un elemento con una certa priorità
</pre>

Se si implementa una coda di priorità come una lista, si hanno le seguenti caratteristiche:
<pre>
-Se la lista è ordinata, l'estrazione costa 1 mentre l'inserimento costa ordine di <i>n</i> (con <i>n</i> numero di elementi) nel caso peggiore.

-Se la lista non è ordinata invece l'estrazione costa <i>n</i> mentre l'inserimento costa 1.
</pre>

Utilizzando un max heap per implementare una coda di priorità si possono ottenere entrambe le operazioni in un tempo ordine di nlog(n).

