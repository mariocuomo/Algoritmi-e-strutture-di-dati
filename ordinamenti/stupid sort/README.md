# Stupid Sort

Lo Stupid sort è un algoritmo di ordinamento che sfrutta una strategia <b>probabilistica</b>.

![Stupid Sort](https://github.com/mariocuomo/Algoritmi-e-strutture-di-dati/blob/master/ordinamenti/stupid%20sort/stupid%20sort.png)

In qualsiasi caso il tempo di esecuzione varia
<pre>
1. caso migliore: n
2. caso medio: n x n!
3. caso peggiore: n x n!
</pre>

L'idea principale è la seguente:
<pre>
1. Controllo se l'array è ordinato
2. Se non è ordinato lo mescolo. 
3. Torno al punto 1
</pre>

La caratteristica di questo algoritmo:
<pre>
1. è <b>in loco</b>, ovvero non utilizza strutture dati esterne
</pre>
