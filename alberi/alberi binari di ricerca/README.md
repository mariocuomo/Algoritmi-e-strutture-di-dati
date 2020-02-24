# Alberi binari di ricerca

Un albero binario di ricerca è una struttura di dati omogenea che si sviluppa da un nodo radice ai nodi figli.


![Albero binario di ricerca](https://github.com/mariocuomo/Algoritmi-e-strutture-di-dati/blob/master/alberi/alberi%20binari%20di%20ricerca/Albero-di-ricerca-binario.png)

Una albero binario di ricerca è un [albero binario](https://github.com/mariocuomo/Algoritmi-e-strutture-di-dati/tree/master/alberi/alberi%20binari) in cui ogni nodo ha al più due figli e in particolare rispetta la seguente caratteristica:
<pre>
Per ogni nodo radice <i>n</i>, si ha che:

1. i nodi del sotto-albero destro sono maggiori del valore del nodo radice
2. i nodi del sotto-albero sinistro sono minori del valore del nodo radice
</pre>

Esso è rappresentato con una struttare a quattro campi:
<pre>
1. un campo che rappresenta il valore intero positivo
2. un campo che rappresenta un riferimento al figlio sinistro
3. un campo che rappresenta un riferimento al figlio destro
4. un campo che rappresenta un riferimento al genitore
</pre>

