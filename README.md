# reactionTimeGame

A breadboard Arduino game that tests the reaction speed of two players based on who presses their button first. 

## How it works
When an LED goes off, the player who clicks their button first wins the game. Each player has a respective LED to display who won the reaction time game. Interrupt-based detection was used to determine the exact moment the button was pressed to capture the reaction speed, with high accuracy, of the winning player. Polling based detection was used to determine if either button was pressed in order to display the results. 

## Notes
Polling-based detection for the reaction speed would likely have a be less accurate (a marginal difference) compared to interrupt-based. Polling was the intitial way of capturing the reaction speed time, but I decided to switch to interrupts anyway. This was for the sake of a more precise number for player reaction speed numbers. Core logic was made by Gemini AI but had to be debugged by hand and rewritten several times by me.