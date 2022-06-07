all:
	gcc GTK1.c BoardManagment1.c Castle1.c CheckMovement1.c FindAttacks1.c CheckMate1.c -o Chess22 `pkg-config gtk+-3.0 --cflags --libs`

