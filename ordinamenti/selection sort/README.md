# Selection Sort

Il selection sort è un algoritmo di ordinamento che sfrutta una strategia <b>greedy</b>.
A ogni passo infatti sceglie come scelta ottima quella più appetibile in quel momento.

![Selection Sort](https://github.com/mariocuomo/Algoritmi-e-strutture-di-dati/blob/master/ordinamenti/selection%20sort/selectionSort.jpg)

In qualsiasi caso il tempo di esecuzione è lo stesso.
<pre>
1. caso migliore: n^2
2. caso medio: n^2
3. caso peggiore: n^2
</pre>

L'idea principale è la seguente:
<pre>
1. alla prima iterazione è calcolato il valore più piccolo ed è inserito in prima posizione
2. alla seconda iterazione è calcolato il valore più piccolo tra quelli restanti, ed è inserito in seconda posizione
3. alla terza iterazione [...]
</pre>

Diverse sono le caratteristiche di questo algoritmo:
<pre>
1. è <b>in loco</b>, ovvero non utilizza strutture dati esterne
2. è <b>stabile</b>, ovvero non scambia l'ordine di valori uguali. (sicuramente più apprezzabile quando i dati dell'array sono dati satelliti)
</pre>
