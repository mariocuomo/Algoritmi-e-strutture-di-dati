# Heap

Un Heap è una struttura di dati che rispetta una particolare <b>proprietà</b>.

![Heap](https://github.com/mariocuomo/Algoritmi-e-strutture-di-dati/blob/master/heap/maxHeap.jpg)


La proprietà che consideriamo è la seguente:
<pre>
Ogni nodo possiede un valore maggiore di entrambi i figli. 
</pre>

Così facendo è costruito quello che prende il nome di max heap.
È evidente quindi che il valore massimo sarà la radice.
Esiste anche la proprietà opposta che caratterizza un min heap.

Esso è implementato tramite un array.
In particolare, dato un elemento in posizione i, si ha che:

<pre>
1. il genitore si trova in posizione (i-1)/2
2. il figlio sinistro si trova in posizione 2i+1
3. il figlio destro si trova in posizione 2i+2
</pre>

