cmake_minimum_required(VERSION 3.24)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")

project(cricket_player)

set(CMAKE_CXX_STANDARD 17)

add_executable(cricket_player main.cpp



        Bowling/Bowling_hashTable.h
        Bowling/Bowling_hashTable.cpp
        Bowling/avl_Bowling.cpp
        Bowling/avl_Bowling.h
        Bowling/bst_Bowling.cpp
        Bowling/bst_Bowling.h
        Bowling/bst_node_Bowling.cpp
        Bowling/bst_node_Bowling.h
        Bowling/intermediate_Bowling.cpp
        Bowling/intermediate_Bowling.h
        Bowling/Bowling.h

        BowlingODI/BowlingODI.h





        player/hashTable.cpp
        player/hashTable.h
        player/helper.cpp
        player/helper.h
        player/intermediate.cpp
        player/intermediate.h
        parser/parser.h
        parser/parser.cpp
        player/player.cpp
        player/player.h
        player/avl.h
        player/avl.cpp
        player/bst_node.h
        player/bst_node.cpp
        player/bst.h
        player/bst.cpp
        country/countryHashTable.h
        country/country.h
        country/country.cpp
        country/bst_country_node.h
        country/bst_country_node.cpp
        country/bst_country.h
        country/bst_country.cpp
        country/avl_country.h
        country/avl_country.cpp
        country/coutry_intermediate.cpp
        country/coutry_intermediate.h
        BattingT20/bst_BattingT20.cpp
        BattingT20/avl_BattingT20.cpp
        BattingT20/bst_node_BattingT20.cpp
        BattingT20/intermediate_BattingT20.cpp
        Batting/avlBatting.cpp
        Batting/bst_Batting.cpp
        Batting/bst_node_Batting.cpp
        Batting/intermediate_Batting.cpp
        parser/parser.cpp
        BattingODI/avl_BattingODI.cpp
        BattingODI/BattingODI_hashTable.h
        BattingODI/bst_BattingODI.cpp
        BattingODI/intermediate_BattingODI.cpp
        BattingTest/avl_BattingTest.cpp
        BattingTest/BattingTest_hashTable.h
        BattingTest/BattingTest_hashTable.cpp
        BattingTest/bst_BattingTest.cpp
        BattingTest/bst_node_BattingTest.cpp
        Fielding/Fielding.h
        Fielding/bst_node_Fielding.h
        Fielding/Fielding_hashTable.h
        Fielding/avl_Fielding.h
        Fielding/avl_Fielding.cpp
        BattingTest/intermediate_BattingTest.cpp Bowling/avl_Bowling.cpp BowlingODI/avl_BowlingODI.cpp BowlingODI/BowlingODI_hashTable.cpp BowlingODI/bst_BowlingODI.cpp BowlingODI/bst_node_BowlingODI.cpp BowlingODI/intermediate_BowlingODI.cpp BowlingT20/avl_BowlingT20.cpp BowlingT20/BowlingT20_hashTable.cpp BowlingT20/bst_BowlingT20.cpp BowlingT20/bst_node_BowlingT20.cpp BowlingT20/intermediate_BowlingT20.cpp BowlingTest/avl_BowlingTest.cpp BowlingTest/BowlingTest_hashTable.cpp BowlingTest/bst_node_BowlingTest.cpp BowlingTest/bst_BowlingTest.cpp BowlingTest/intermediate_BowlingTest.cpp Fielding/avl_Fielding.cpp Fielding/bst_Fielding.cpp Fielding/Fielding_hashTable.cpp FieldingProfile/avl_FieldingProfile.h FieldingProfile/bst_FieldingProfile.cpp FieldingProfile/Fielding_hashTableProfile.h FieldingProfile/avl_FieldingProfile.cpp country/countryHashTable.cpp linkedList/linked_list.h linkedList/node.h linkedList/node.cpp linkedList/linked_list.cpp
        country/player_country.h)
