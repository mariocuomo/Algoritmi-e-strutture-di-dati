# Quick Sort

Il Quick Sort è un algoritmo di ordinamento che sfrutta una strategia <b>divide et impera</b>.
Nasce dall'idea che due sotto sequenze ordinate di lunghezza <i>n</i> e <i>m</i>, siano utili per ottenere una sequenza ordinata di lunghezza <i>n+m</i> se tutti gli elementi della prima sequenza sono minori di <b>k</b> mentre quelli della seconda sono maggiori.

![Quick Sort](https://github.com/mariocuomo/Algoritmi-e-strutture-di-dati/blob/master/ordinamenti/quick%20sort/quick%20sort.png)

Il tempo di esecuzione è il seguente:
<pre>
1. caso migliore: nlog(n)
2. caso medio: nlog(n)
3. caso peggiore: n*n
</pre>

L'idea principale è la seguente:
<pre>
1. Scelgo un pivot nell'array e posiziono tutti i valori minori alla sua sinistra e quelli maggiori alla sua destra.
2. Dopo aver effettuato la partizione, il pivot si trova nella corretta posizione.
3. Ricorro ricorsivamente sui due sotto array.
</pre>

Diverse sono le caratteristiche di questo algoritmo:
<pre>
1. <b>È in loco</b>, perchè non utilizza strutture esterne, gli elementi sono solamente scambiati.
2. <b>Non è stabile</b>, ovvero scambia l'ordine di valori uguali. (sicuramente più apprezzabile quando i dati dell'array sono dati satelliti)
</pre>
