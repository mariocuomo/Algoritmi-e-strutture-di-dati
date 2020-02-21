# Bucket Sort

Il bucket sort è un algoritmo di ordinamento che opera in un tempo lineare, proporzionale alla grandezza dell'input.

Può essere applicato quando i valori di input sono interi positivi ed è consigliato applicarlo quando il valore massimo dell'array è al più pari alla grandezza dell'input.

![Bucket Sort](https://github.com/mariocuomo/Algoritmi-e-strutture-di-dati/blob/master/ordinamenti/bucket%20sort/bucket%20sort.png)

In qualsiasi caso il tempo di esecuzione è lo stesso.
<pre>
1. caso migliore: n+m
2. caso medio: n+m
3. caso peggiore: n+m
dove <i>n</i> indica la grandezza dell'input e <i>m</i> è il valore massimo della sequenza
</pre>

Esistono diverse versioni di questo algoritmo. Una versione crea un bucket diverso per ogni intervallo di valori diverso, un'altra invece crea un bucket diverso per ogni valore diverso (utile quando l'input è un vettore di interi). Di seguito è implementata la seconda versione.

L'idea principale è la seguente:
<pre>
1. Si calcola il massimo dell'array e si crea un vettore di liste di quella dimensione. Ogni lista rappresenta un bucket.
2. Si scorre l'array di partenza e si aggiungono i valori nei rispettivi bucket.
3. Si aggiorna il vettore di partenza concatenato tali liste.
</pre>

Diverse sono le caratteristiche di questo algoritmo:
<pre>
1. <b>NON è in loco</b> in quanto utilizza un array di supporto
2. Può essere <b>stabile o non stabile</b>. La stabilità se i valori inseriti nelle liste sono aggiunti in coda a tali.
</pre>


