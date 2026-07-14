# reactionTimeGame

A breadboard Arduino game that tests the reaction speed of two players based on who presses their button first. Test the game <a href="https://wokwi.com/projects/469476521715600385" target="_blank" rel="noopener noreferrer">here.</a>


https://github.com/user-attachments/assets/005c3da3-78fe-4f93-938d-b6cef09952ee

## Circuit
<img width="877" height="411" alt="reaction time game bread board diagram" src="https://github.com/user-attachments/assets/d2b350df-2d99-4d28-9ea0-7a451252d0b9" />

*Breadboard wiring in Wowki.*


---


<p float="left">
  <img alt="" src="https://github.com/user-attachments/assets/a7188ec8-f650-4e83-800b-29839dec3a6f" width="49%" />
  <img alt="" src="https://github.com/user-attachments/assets/1d963f5b-3c22-474a-aebf-01914379796a" width="49%" />
</p>

*Actual build. Arduino Nano. Buttons on D2/D3, LEDs on D8/D9/D12. Yellow tape was for the button that kept falling off.*


---


## How it works
When an LED  from the side lights up, the player who clicks their button first wins the game. Each player has a respective LED to display who won the reaction time game. A hardware interrupt on pins D2 and D3 was used to determine the reaction speed, with high accuracy, of the winning player. Polling was used to determine if a hardware interrupt occured, and if it did, the results would be displayed.

## Notes
Polling-based detection for the reaction speed would likely be less accurate (a marginal difference) compared to interrupt-based. Polling was the initial way of capturing the reaction speed time, but I decided to switch to interrupts anyway. This was for the sake of a more precise number for player reaction speed numbers. Core logic was made by Gemini AI but had to be debugged by hand and rewritten several times by me.
