# HASH TABLE

Un Hash Table è una struttura di dati che permette di realizzare mappe (o insiemi) in quanto associa a una <b>chiave</b> un determinato <b>valore</b>.

![HASH TABLE](https://github.com/mariocuomo/Algoritmi-e-strutture-di-dati/blob/master/tabelle%20hash/hash%20table.png)

In una mappa a ogni chiave si ha associato uno e uno solo valore.
Dato che il numero di chiavi può essere anche molto più grande rispetto all'effettivo numero di chiavi utilizzate nella mappa, si adotta il seguente stratagemma.

Molto semplicemente l'hash table è implementata con un array di liste.

Quando si inserisce un nuovo valore con la relativa chiave la prima operazione che si effettua è il calcolo dell'hash, ovvero si trasforma la chiave in un intero.
L'intero calcolato rappresenta la posizione nel vettore di liste.
A questo punto si inserisce un nuovo nodo alla lista in posizione <i>i</i> dell'array.

Un esempio di funzione di hash per stringhe potrebbe essere quella di sommare i codici ASCII dei caratteri.
Un problema evidente è quello in cui le seguenti stringhe hanno lo stesso codice hash e causano una collisione in posizione i

<pre>
1. PIPPO
2. POPPI
</pre>

Per questo motivo gli elementi della lista hanno un riferimento anche verso la chiave

Per verificare che gli elementi che collidono su una stessa posizione si riferiscono a due chiavi differenti è necessario implementare una funzione equal che verifica l'uguaglianza (nel caso descritto in precedenza si verifica carattere per carattere).

