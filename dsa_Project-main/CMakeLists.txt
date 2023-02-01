cmake_minimum_required(VERSION 3.24)
project(DSA_Project)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(hashTables)

add_executable(DSA_Project
        hashTables/avl.cpp
        hashTables/avl.h
        hashTables/bst.cpp
        hashTables/bst.h
        hashTables/bst_node.cpp
        hashTables/bst_node.h
        hashTables/hashTable.cpp
        hashTables/hashTable.h
        hashTables/intermediate.cpp
        hashTables/intermediate.h
        hashTables/main.cpp
        hashTables/player.cpp
        hashTables/player.h
        Batting.cpp
        BattingODI.cpp
        BattingT20.cpp
        BattingTest.cpp
        Bowling.cpp
        BowlingODI.cpp
        BowlingT20.cpp
        BowlingTest.cpp
        bst_node_player.h
        Fielding.cpp
        FieldingODI.cpp
        FieldingT20.cpp
        FieldingTest.cpp
        Player.h
        player_hasttable.h
        player_intermediate.h
        playerHashTable.cpp
        playerHashTable.h bstPlayer.h bstPlayer.cpp avlPlayer.h avlPlayer.cpp Batting/Batting_hashTable.h Batting/avlBatting.cpp Batting/avlBatting.h Batting/bst_node_Batting.h Batting/Batting_hashTable.h BattingODI/intermediate_BattingODI.h)
