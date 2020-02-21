# Insertion Sort

Insertion sort è un algoritmo di ordinamento che sfrutta una strategia <b>incrementale</b>.
Al passo <i>i</i> tutti gli elementi prima della posizione <i>i</i> sono ordinati.

![Insertion Sort](https://github.com/mariocuomo/Algoritmi-e-strutture-di-dati/blob/master/ordinamenti/insertion%20sort/insertion%20sort.jpg)

Il tempo di calcolo varia in base al caso che stiamo considerando
<pre>
1. caso migliore: n
2. caso medio: n^2
3. caso peggiore: n^2
</pre>

L'idea principale è la seguente:
<pre>
1. l'array è sempre diviso in due sotto-array, il primo ordinato fino alla posizione <i>i</i>, e il secondo non ordinato.
2. a ogni iterazione è estratto un elemento dalla porzione non ordinata e inserito nella porzione ordinata traslandone gli elementi.
</pre>

Diverse sono le caratteristiche di questo algoritmo:
<pre>
1. è <b>in loco</b>, ovvero non utilizza strutture dati esterne
2. è <b>stabile</b>, ovvero non scambia l'ordine di valori uguali. (sicuramente più apprezzabile quando i dati dell'array sono dati satelliti)
2. è <b>online</b>, ovvero può essere applicato anche quando non è disponibile l'intero input.
</pre>

Tale algoritmo è sicuramente quello che applichiamo inconsciamente quando ordiniamo delle carte da gioco nella nostra mano. A ogni passo ne prendiamo una nuova dal mazzo e la posizione nella posizione giusta nella mano traslando quelle già presenti per fare spazio a quella nuova appena pescata.
