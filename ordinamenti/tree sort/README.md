# Tree Sort

Il tree sort è un algoritmo di ordinamento che sfrutta la costruzione di un <b>[albero binario di ricerca](https://github.com/mariocuomo/Algoritmi-e-strutture-di-dati/tree/master/alberi/alberi%20binari%20di%20ricerca)</b>.

A ogni passo è aggiunto l'elemento nella rispettiva posizione all'interno dell'albero.

![Tree Sort](https://github.com/mariocuomo/Algoritmi-e-strutture-di-dati/blob/master/ordinamenti/tree%20sort/tree%20sort.png)

In qualsiasi caso il tempo di esecuzione è lo stesso.
<pre>
1. caso migliore: nlogn
2. caso medio: nlogn
3. caso peggiore: n^2
</pre>

L'idea principale è la seguente:
<pre>
1. A ogni passo inserisco l'elemento all'interno dell'albero binario di ricerca.
2. Una visita simmetrica dell'albero restituisce tutti gli elementi in ordine crescente
</pre>

Diverse sono le caratteristiche di questo algoritmo:
<pre>
1. <b>Non è in loco</b> in quanto utilizza strutture dati esterne
2. È <b>stabile</b>, ovvero non scambia l'ordine di valori uguali. (sicuramente più apprezzabile quando i dati dell'array sono dati satelliti)
3. È <b>online</b>, ovvero può essere applicato anche quando non è disponibile l'intero input.
</pre>


