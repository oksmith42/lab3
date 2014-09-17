#if !defined PASSWORD_H
#define PASSWORD_H
#include "ListArray.h"
using CSC2110::ListArray;
#include "Text.h"
using CSC2110::String;

class Password
{
   private:
    	ListArray<String>* viable_words;  //the list of words that can still be the password
    	ListArray<String>* all_words;  //the original list of words
    	int len;  //the length of the first word entered is stored to check that all subsequent words have the same length

    	//a private helper method to report the number of character matches between two Strings

    	/*
    	*Pre:
    	* curr_word and word_guess must both be of type String*
    	* cutt_word and word_guess must be the same length
    	*Post:
    	* If preconditions are met, the function will return the number of characters that matched in both words.
    	*/
    	int getNumMatches(String* curr_word, String* word_guess);

	public:
		Password(); //constructor
		~Password(); //destructor (there is work to do here, delete the individual words)
		/*
		*Pre:
		* word must be a String* type variable.
		*Post:
		*Assuming preconditions are met, the function will add the given String* to both password lists.
		*/
		void addWord(String* word); //add a word to the list of possible passwords
		/*
		*Pre:
		* try_password must be an integer that is the index which contains the password that you attempted.
		* num_matches must be an integer which is told to you by the game once you have guessed a password (it's how many characters matched)
		*Post:
		* Assuming preconditions are met, it will update the viable_words list to only include possible matches
		*/
		void guess(int try_password, int num_matches); //index of guessed word in the list of all words (1-based), number of matches reported by fallout 3, update viable passwords list
		/*
		*Pre:
		* none
		*Post:
		* the function will return the number of words in the viable_words list.	
		*/
		int getNumberOfPasswordsLeft(); //returns the number of possible passwords remaining
		/*
		*Pre:
		* none.
		*Post:
		* The function will print out all of the words in the viable_words list.	
		*/
		void displayViableWords(); //display the current list of possible passwords
		/*
		*Pre:
		* none
		*Post:
		*The function will tell you what word to guess that will eliminate the most passwords.
		*/
		int bestGuess(); //the best word in the original list to guess next (done for you)
		/*
		*Pre:
		* index must be an integer, index is the index number from the original words list.
		*Post:
		* the function will return whatever word was in the provided index of the all_words list.
		*/
		String* getOriginalWord(int index); //get a word from the original list of all passwords, 1-based


};

#endif
