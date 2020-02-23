# Merge Sort

Il Merge Sort è un algoritmo di ordinamento che sfrutta una strategia <b>divide et impera</b>.
Nasce dall'idea che due sotto sequenze ordinate di lunghezza <i>n</i> e <i>m</i>, siano utili per ottenere una sequenza ordinata di lunghezza <i>n+m</i>.

![Merge Sort](https://github.com/mariocuomo/Algoritmi-e-strutture-di-dati/blob/master/ordinamenti/merge%20sort/merge%20sort.png)

In qualsiasi caso il tempo di esecuzione è lo stesso.
<pre>
1. caso migliore: nlog(n)
2. caso medio: nlog(n)
3. caso peggiore: nlog(n)
</pre>

L'idea principale è la seguente:
<pre>
1. Continuo a dividere l'array in due parti uguali (differenza lunghezze +-1) fino ad arrivare a un caso base, ovvero l'array di un elemento che risulta essere ordinato per definizione.
2. Dopo aver effettuato la divisione, ordino le due sotto parti.
3. Al termine, unisco tutte le sotto parti.
</pre>

Diverse sono le caratteristiche di questo algoritmo:
<pre>
1. <b>Non è in loco</b>, perchè utilizza un array di supporto
2. è <b>stabile</b>, ovvero non scambia l'ordine di valori uguali. (sicuramente più apprezzabile quando i dati dell'array sono dati satelliti)
</pre>
