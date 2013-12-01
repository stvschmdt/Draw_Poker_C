cpoker
======

cpoker
===============================================================================

Poker Game - in C

5-card draw poker application in C using 3 simulated players and one "live" player (the user).
5-card draw: en.wikipedia.org/woki/Five-card_draw. 

===============================================================================
GAME LOGIC
===============================================================================

The game logic is as follows:
 - create a deck of cards
 - shuffle the deck
 - deal five cards to each of the four players
 - loop over each of the three automated players and have them make
   a decision on which cards (if any) to exchange.
		* using an AI decision making process.  Monte Carlo simulation of all possible hands,
		resulting in a ranking of each hand and thus a decision on
		the probable best move. 
- request input from live player (MC simulator will advise live
  player as well). MC advisor should advise on the absolute quality
  of the best move. 
- compare the hands and determine a winner
- Wrap the above single hand simulator in a game loop which
  allows for a round of betting at each hand, eliminates players when
  they run out of money, allow a player to fold, etc.
