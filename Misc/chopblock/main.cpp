/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on May 6, 2015, 1:02 PM
 * Notes for next update: work on betting format, 3rd high card, all-Ins
 *      Purpose: Head's Up Texas Hold'em
 */
//System Libraries
//I/O standard
//computer time
//for random seed
//formatting
//for strings
//file in/out

//User Libraries
//Global Constants
//Function Prototypes
//instructions on how to play
//initializes and shuffles the deck
//starts a new round of poker
//deal 1 card
//gives hand value
 //finds a short string rank of hand
//finds what the card is for output
//sort for high card
//find best version of your hand
//set hand with best combination
//find winning hand between two players
//find round winner
//displays money totals
// calls ante
//individual ante
// main betting function
//player bet function
//computer bet function
//check to end betting round
//award pot to winner
//split the pot for ties
//all in or fold for skip
//Execution Begins Here!

    //Declare Variables
    //output to file
    //open file
    //set random seed
    //input for info query, and repeat query
    //total wins for each player
    //beginning money total
    //dealer button
    //overall winner and player name input
    //size of the deck
    //declare array with zeros
    //current round win
    //percentage of wins for the player/ totals rounds
    //fill array with card values (1-52)
    //Prompt for rules
    //prompt for name of player
    //do
        //Start new round
        //if 1 player 1 win round
        //if 2 player 2 win round
        //Shuffle 
        //increment the total rounds
    //while player wants to repeat
    //Congratulate Overall Winner
    //output results to a file
    //Exit Stage Right!
//*********************************************//
//*             Rules Function                *//
//*********************************************// 
    //declare variables
    //menu / choice
    //bool for skip 
    //begin explanation of how to play
    //do
        //start showing hand rankings
        //prompt for specific hand ranking display
        //menu for hand display
            //case for hi card
            //case for pair
            //case for two pair
            //case for three of a kind
            //case for straight
            //case for flush
            //case for full house
            //case for four of a kind
            //case for straight flush
            //case for royal flush
            //default for skip
            //set skip to true
        //if skip is false
        //prompt for repeat
    //while player wants to repeat
//*********************************************//
//*             Initialize Deck               *//
//*********************************************//
    //increment while still in array
        //for position i, set i to i ex: 41 =41
//*********************************************//
//*                New round                  *//
//*********************************************//
    //Declare variables
    //player hole cards
    //computer hole cards
    //community cards
    //number for combination of hand
    //player final hand cards 1-5
    //computer final hand cards 1-5
    //hand values
    //high card for tie hands
    //player number who has top hand
    //quick string for hand ranking
    //variables for betting
    //pot total 
    //skip if there is all in
    //player or computer fold
    //get ante
    //display totals
    //Deal hole cards
    //display hole cards
    //call betting round 1
    //Deal 3 Community Cards (Flop)
        //betting round 2
    //Deal 1 Community Card (Turn)
        //betting round 3
    //Deal 1 Community Card (River)
    //find best combination of cards per player
    //set final hand to best combination
    //high card and sort
    //find hand value of player
    //find hand value of computer
    //set string for short hand ranking
    //display final community cards
    //state player hand value
    //Display player hand
        //final bet round
    //Unveil all hands
    //find winning hand
        //find winNum
    //find winner name
    //state winner
    //award pot to winner
    //display player totals
    //increment button
    //return winner number
//*********************************************//
//*               Deal 1                      *//
//*********************************************//
    //declare variables
    //repeat
    //new card
    //do
        //pick random number
        //if card is 0, then its already picked, so repeat
        //else dont repeat
    //while need new card
    //set the card you picked to zero in array
    //c1 = card
//*********************************************//
//*             Card Values                   *//
//*********************************************//
    //declare string f for card name
    //Spades
    //Hearts
    //Clubs
    //Diamonds
    //return card name
//*********************************************//
//*             Hand Ranking                  *//
//*********************************************//
    //declare variables
    //high card hand value= 1
    //temp
    // straight = n, flush = n
    //flush = 6
    //spades
    //hearts
    //clubs
    //diamonds
    //get rid of suits
    //sort for straight
        //sort first value
        //sort second value
        //sort third value
        //sort fourth value
    //high card for flush
    //high card for high card hand
    //pair = 2
    //two pair = 3
    //three of a kind = 4
    //straight = 5
    //full house = 7
    //four of a kind = 8
    //straight flush = 9
    // if flush and straight then value =9
    //return hand value
//*********************************************//
//*             Short Hand Rank               *//
//*********************************************//
    //declare string for hand type
    //if 1 then high card
    //if 2 then pair
    //if 3 then two pair
    // if 4 then 3 of a kind
    //if 5 then straight
    //if 6 then flush
    // 7 then full house
    //if 8 then four of a kind
    // if 9 then straight flush
    //return string for hand type
//*********************************************//
//*               High Card/Sort              *//
//*********************************************//
    //temp variables for swap
    //get rid of suits
    //take away 13 for values above 13
    //sort first value
        //swap if needed
    //sort second value
        //swap if needed
    //sort third value
        //swap if needed
    //sort fourth value
        //swap if needed
//*********************************************//
//*            Best Combination               *//
//*********************************************//
    //variables
    //high,temporary,placeholder,best combination number,current High Card
    //5 community cards
    //3 com cards and 2 hole
    //4 com card and first hole card
    //4 com card and second hole card
    //return best combination found
//*********************************************//
//*               Set Final Hand              *//
//*********************************************//
    // if the comb =  number
    // set specific hand
//*********************************************//
//*               Winning Hand                *//
//*********************************************//
    //find top hand value
    //declare variables for ties
    //find all that have the same value of the top hand
    //compare ties for top hand
    //if two have tie
        //win =1
        //win =2
    //if no tie
    //win 1
    //win 2
    //return win
//*********************************************//
//*            Winning Player                 *//
//*********************************************//
    //declare string variable for winner
    //if 1 then winner = user
    //if 2 then winner = tom
    // else tie game
    //return winner
//*********************************************//
//*                Worth                      *//
//*********************************************//
    //state string
//*********************************************//
//*                AnteUp                      *//
//*********************************************//
    //variables
    //call indAnte
    //player 1 ante
    //player 2 ante
    //find if skip is needed
//*********************************************//
//*            Individual Ante                *//
//*********************************************//
    //if a=0 fold is true
    //if a>0 take away ante and add to pot
    //if a=0 && fold=false then its an all in
//*********************************************//
//*            Betting Function               *//
//*********************************************//
    //declare variables
    //tally to make sure both players bet at least once
    //player/computer total bet and current bet
    //do
           //call player bet
       //call computer bet
           //call player bet
       //check for raises
    //while stoop = false
    //find skip
    //display totals
//*********************************************//
//*            Player Bet                     *//
//*********************************************//
    //variables
    //display current bet
    //prompt for bet
//*********************************************//
//*             Computer Bet                  *//
//*********************************************//
    //variables
    //find computer bet
    //do computer bet
//*********************************************//
//*           Check for Bet end               *//
//*********************************************//
    //if both players have bet the same return true
    //if one player has folded return true
    //if a player is all in return true
    //otherwise return false
//*********************************************//
//*         Award pot to winner               *//
//*********************************************//
    //winner gains the pot
//*********************************************//
//*           Split the pot                   *//
//*********************************************//
    //divide pot by two
    //award both players half the pot
//*********************************************//
//*           All in or Fold                  *//
//*********************************************//
    //if either player is all in or fold return true
    //else return false