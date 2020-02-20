# Queue

Una queue o semplicemente coda, è un tipo astratto di dati che rappresenta una struttura di dati il cui accesso segue un approccio <b>FIFO (First In First Out)</b>.

![QUEUE](https://github.com/mariocuomo/Algoritmi-e-strutture-di-dati/blob/master/queue/queue.png)

Un modo molto semplice per visualizzare il concetto di coda è quello di pensare a una vera e propria coda per esempio alle casse del supermercato.
Le operazioni concesse quindi sono quelle di inserire un nuovo elemento alla fine della coda e quella di estrarre l'elemento attualmente in testa.

La coda considerata è di interi positivi ed è rappresentata con una struttura a quattro campi:
<pre>
1. un campo che rappresenta l'array di interi positivi 
2. un campo (testa) che rappresenta un riferimento al primo elemento inserito
3. un campo (coda) che rappresenta un riferimento alla prima posizione libera dell'array
4. la dimensione dell'array
</pre>

Una coda è vuota quando il campo coda e testa coincidono. 
Per non creare incomprensioni tra coda vuota e coda piena si assume che una coda con un array di <i>n</i> elementi può contenerne al più <i>n-1</i>


Attualmente non vi è nessuna gestione telescopica della memoria della coda.
