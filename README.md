# Cricket Fans
This program contains the data of cricket players. It allows the user to perform variety of functions regarding the information related to the cricket players. This program gives quick comparision of stats for cricket players. The program covers stats for all three formats t20, odi and test cricket and in all three profiles that is bowling, batting and fielding in each of the format.  
Functions that user can perform are :  
- Press 1 to search player by name 
- Press 2 to get players by country 
- Press 3 to get players with centuries in t20 
- Press 4 to get players with centuries in test 
- Press 5 to get players with centuries in ODI 
- Press 6 to get players with 5 wicket haul t20
- Press 7 to get players with 10 wicket haul in test
- Press 8 to get players with 5 wicket haul odi
- Press 3 to get players with centuries in t20 
- Press 10 to get players who scored centuries in same span as then entered player
- Press 11 to get players who scored more centuries in test then entered player and are in same span 
- Press -1 to exit  
# Logical Structure
The program is built using multi level hash tables that uses avl trees for collision detection and resolution. The worst case complexity is between O(1) and ln(n) since hash tables can not be perfect.  
The structure is as following:  
- Primary Hash Map of all players names that containes pointers to the 
  - Secondary Hash Maps of Batting , Bowling and Fielding Profiles. Each one of them points to  
    - Tertially Hash Maps of Odi, T20 and Test stats of players in respective format
    
- Primary Hash Map's indexes also points to other indexes of the very Hash Map, if the player has overlapping period of career in test with other player  
# Dataset 
Dataset was downloaded from following link : https://www.kaggle.com/datasets/mahendran1/icc-cricket?resource=download
# Developers
Hafiz Ahmad Raza Khan
Hasib Aslam 

