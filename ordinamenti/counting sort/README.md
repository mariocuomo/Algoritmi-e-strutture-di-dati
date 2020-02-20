# Counting Sort

Il counting sort è un algoritmo di ordinamento che opera in un tempo lineare, proporzionale alla grandella dell'input.

Può essere applicato quando i valori di input sono interi positivi ed è consigliato applicarlo quando il valore massimo dell'array è al più pari alla grandezza dell'input.

![Counting Sort](https://github.com/mariocuomo/Algoritmi-e-strutture-di-dati/blob/master/ordinamenti/counting%20sort/counting%20sort.png)

In qualsiasi caso il tempo di esecuzione è lo stesso.
<pre>
1. caso migliore: n+m
2. caso medio: n+m
3. caso peggiore: n+m
dove <i>n</i> indica la grandezza dell'input e <i>m</i> è il valore massimo della sequenza
</pre>

L'idea principale è la seguente:
<pre>
1. Si calcola il massimo dell'array e si crea un vettore di quella dimensione
2. Il valore associato a ogni indice rappresenta quante volte tale indice compare all'interno dell'array di partenza
3. Si crea il vettore finale con tali informazioni
</pre>

Diverse sono le caratteristiche di questo algoritmo:
<pre>
1. <b>NON è in loco</b> in quanto utilizza un array di supporto
2. è <b>stabile</b>, ovvero non scambia l'ordine di valori uguali
</pre>


