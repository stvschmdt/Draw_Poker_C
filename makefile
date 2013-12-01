poker: poker.c deck.c card.c player.c interface.c analysis.c monte.c
	gcc -Wall -o poker poker.c deck.c card.c player.c interface.c analysis.c monte.c

make clean:
	rm -f poker
