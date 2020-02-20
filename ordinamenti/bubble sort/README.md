# Bubble Sort

Il Bubble sort è un algoritmo di ordinamento. Come tutti gli algoritmi di ordinamento può essere utilizzato per ordinare elementi su cui è definita una relazione d'ordine.

![Bubble Sort](https://github.com/mariocuomo/Algoritmi-e-strutture-di-dati/blob/master/ordinamenti/bubble%20sort/bubbleSort.png)

In tempo di esecuzione varia in base al caso che stiamo considerando.
<pre>
1. caso migliore: n
2. caso medio: n^2
3. caso peggiore: n^2
</pre>

L'idea principale è la seguente:
<pre>
A ogni iterazione gli elementi adiacenti sono scambiati secondo la relazione d'ordine considerata.
L'algoritmo termina nel momento in cui non viene effettuato nessuno scambio.
</pre>

Diverse sono le caratteristiche di questo algoritmo:
<pre>
1. è <b>in loco</b>, ovvero non utilizza strutture dati esterne
2. è <b>stabile</b>, ovvero non scambia l'ordine di valori uguali. (sicuramente più apprezzabile quando i dati dell'array sono dati satelliti)
</pre>
