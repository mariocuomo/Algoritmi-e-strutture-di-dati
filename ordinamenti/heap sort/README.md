# Heap Sort

Il Heap sort è un algoritmo di ordinamento che sfrutta una strategia <b>iterativa</b> e una struttura dati [Heap](https://github.com/mariocuomo/Algoritmi-e-strutture-di-dati/tree/master/heap).

![Heap Sort](https://github.com/mariocuomo/Algoritmi-e-strutture-di-dati/blob/master/ordinamenti/heap%20sort/heap%20sort.png)

In qualsiasi caso il tempo di esecuzione è lo stesso.
<pre>
1. caso migliore: nlog(n)
2. caso medio: nlog(n)
3. caso peggiore: nlog(n)
</pre>

L'idea principale è la seguente:
<pre>
1. alla prima iterazione è trasformato l'array(A) in un max-heap. A[0] contiene quindi il valore più grande.
2. Si scambia il valore di A[0] con l'ultimo elemento dell'array. 
3. Si ricorre ora creando un max-heap di n-1 elementi e scambiando la nuova radice con il penultimo elemento.
4. Si itera fino a che il max heap ha dimensione 0
</pre>

Diverse sono le caratteristiche di questo algoritmo:
<pre>
1. è <b>in loco</b>, ovvero non utilizza strutture dati esterne
2. Non è <b>stabile</b>, in quanto scambia l'ordine di valori uguali. (sicuramente più apprezzabile quando i dati dell'array sono dati satelliti)
</pre>
