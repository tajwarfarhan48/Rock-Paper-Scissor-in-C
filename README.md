# Rock-Paper-Scissor-in-C
A rock-paper-scissor game created in C, with option for both single player and multiplayer

NOTE: In this version, Player 1 is the human and Player 2 is the computer

NOTE: Only the single player option can be played at the moment. Multiplayer functionality will be added in a later update

# Steps to play the game
Copy and paste the following commands on your Linux/Mac terminal or Git Bash on Windows (I will add the corresponding Windows Command Prompt operations at a later date):

git clone https://github.com/tajwarfarhan48/Rock-Paper-Scissor-in-C.git rock_paper_scissor  
cd rock_paper_scissor  
open rock_paper_scissor  

# If you really, really want multiplayer RIGHT NOW
WARNING: The following directions are experimental and should only be done by those who know what they are doing  

Multiplayer will be properly implemented soon, but the source code for it is already present inside the *rock_paper_scissor.c* file. You can find it inside the 'play_one_round' function. Just go ahead and un-comment the code under the *Player 2's Turn* and *Preventing Player 2's Invalid Input* section. Recompile the program using gcc, clang or any other compiler of your choice, execute the .exe file, and voila!
