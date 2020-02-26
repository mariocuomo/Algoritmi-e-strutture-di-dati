# Radix Sort

Il radix sort è un algoritmo di ordinamento che opera in un tempo lineare, proporzionale alla grandezza dell'input.

Può essere applicato quando i valori di input hanno una stessa struttura, e su ogni elemento è definita una relazione d'ordine.

![Radix Sort](https://github.com/mariocuomo/Algoritmi-e-strutture-di-dati/blob/master/ordinamenti/radix%20sort/radix%20sort.png)

In qualsiasi caso il tempo di esecuzione è lo stesso.
<pre>
1. caso migliore: n*m
2. caso medio: n*m
3. caso peggiore: n*m
dove <i>n</i> indica la grandezza dell'input e <i>m</i> è il numero medio di elementi di ogni elemento dell'input.
</pre>

Esistono diverse versioni di questo algoritmo.
Il caso proposto crea 10 parole random di lunghezza costante 10.


L'idea principale è la seguente:
<pre>
1. Parto dalla colonna con meno importanza, in questo caso l'ultima (che rappresenta l'ultima lettera delle parole).
2. Ordino le parole con un algoritmo stabile.
3. All'iterazione successiva passo alla colonna precedente.
</pre>

Nel caso proposto l'algoritmo stabile utilizzato è il [Selection Sort](https://github.com/mariocuomo/Algoritmi-e-strutture-di-dati/tree/master/ordinamenti/selection%20sort).

Diverse sono le caratteristiche di questo algoritmo:
<pre>
1. <b>NON è in loco</b> in quanto utilizza un array di supporto per effettuare lo scambio delle righe.
2. <b>È stabile</b>, ovvero non scambia elementi con lo stesso valore.
</pre>


