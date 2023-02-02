# BattleShips

von Julia Brunotte, 01.02.2023

Zu Beginn des Spiels wird durch die Eingabe eines Integers die Größe des Spielfeldes festgelegt(zwischen 3 und 20).
In der welcome Funktion, legt der Spieler seinen Namen fest und wird begrüßt, dann folgt der Aufruf der Legende.
ALs nächstes wird durch eine Eingabe festgelegt, mit wievielen Schiffen gespielt wird.
Dann platzieren der Spieler und der Computer ihre Schiffe auf unterschiedlichen Spielfeldern.
Der Computer macht dies mit Zufallszahlen, dabei wird sicher gestellt, dass er kein Feld mit zwei
Schiffen belegt. Dann wird das Spielfeld des Spielers das 1. Mal angezeigt.
Danach wird gezählt, wieviele Schiffe vom Spieler und vom Computer jeweils aktiv sind. 
In der folgenden while Schleife, werden so lange Angriffe ausgeführt, wie noch aktive Schiffe im Spiel sind.
Dafür wird zunächst ein Angriff des Spielers auf den Computer mittels Eingabe durchgeführt, dann 
ein Angriff des Computers auf den Spieler mittels Zufallszahlen. Die entsprechenden Felder werden geprüft und ggf. markiert.
Es werden wieder die aktiven Schiffe gezählt und der Durchlauf beginnt ggf. von vorne. Vorher
wird nocheinmal das Spielfeld des Spielers dargestellt und die aktuelle Anzahl der aktiven Schiffe
ausgegeben. Wenn entweder der Spieler oder der Computer jeweils 0 aktive Schiffe hat, wird das Spiel beendet
und es erfolgt eine Ausgabe, ob der Spieler gewonnen oder verloren hat. 
