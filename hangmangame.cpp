#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include<fstream>
#include <vector>
#include<sstream>

using namespace std;

const int MAX_TRIES=5;

int search_word (char, string, string&);

int main ()
{
    int c,totalscore;
 for(;;){
string name;
char letter,a;
int chances=0;
int num_of_wrong_guesses=0;
ifstream myfile("gameWord.txt");
//myfile.open("F:\STUDY\my project&\c++project\mondol project\gameWord.txt");
string word;
string words[3417];
if(myfile.is_open())
    {


        for(int i = 0; i < 3417; ++i)
        {
            myfile >> words[i];
        }
    }
char *hanged[]={
                     "|=====|\n"
                     "      |\n"
                     "      |\n"
                     "      |\n"
                     "     ===\n",
                     "|=====|\n"
                     "O     |\n"
                     "      |\n"
                     "      |\n"
                     "     ===\n",
                     "|=====|\n"
                     "O     |\n"
                     "|     |\n"
                     "      |\n"
                     "     ===\n",
                     "|=====|\n"
                     "O     |\n"
                     "|     |\n"
                     "|     |\n"
                     "     ===\n",
                     " |=====|\n"
                     " O     |\n"
                     " |     |\n"
                    "/ \\    |\n"
                     "     ===\n"

    };

cout<<"\n\n\t\tEnter your choice:\n\n\t\t1.Play\t 2.HELP\t 3.EXIT\n\n";
cin>>c;
        if(c==1){
srand(time(NULL));
int n=rand()% 3417;
word=words[n];

int score =0,p,i=0;

// Initialize the secret word with the * character.
string unknown(word.length(),'*');
totalscore=word.length()+MAX_TRIES;

// welcome the user
cout << "\t\t.....WELCOME TO HANGMAN....\n\nGuess the word if u can!!";
cout<<"\n\t\tLET'S PLAY THE GAME\n\n";
cout<<"\nFor using clue press 1\n or not using press 2:";
cin>>p;
if(p==1){
    score=score;
    for(i=0;i<1;i++)

    cout<<" This is a simple Dictionary Word\n"<<" Frist letter of word= "<<word[0];}
if(p==2)
    score=5;

while (num_of_wrong_guesses < MAX_TRIES)
{
cout << "\n\n" << unknown<<" ";
cout << "\n\nGuess a letter: ";
cin >> letter;

if(search_word(letter, word, unknown)==0)
{
cout << endl << "Whoops! That letter isn't in there!" << endl;
cout<<"\n\n"<<hanged[num_of_wrong_guesses]<<"\n\n";
if(num_of_wrong_guesses>3)
    cout<<"You have killed a person\n";
num_of_wrong_guesses++;
score=score;
}
else
{
score++;
cout << endl << "You found a letter! Isn't that exciting!" << endl;
}
// Tell user how many guesses has left.
cout << "You have " << MAX_TRIES-num_of_wrong_guesses;
cout << " guesses left." << endl;
// Check if user guessed the word.
if (word==unknown)
{
cout << word << endl;
cout << "Yeah! You got it!"<<"Your score is "<<score<<" out of totalscore "<<totalscore<<endl;
break;
}
}
if(num_of_wrong_guesses == MAX_TRIES)
{
cout << "\nSorry, you lose...you've been hanged."<<"Your score is "<<score<<" out of totalscore "<<totalscore<<endl;
cout << "The word was : " << word << endl;
}
cin.ignore();
cin.get();
}
if(c==2){
        cout<<"\t\t Game Hints\n\n";
        cout << "\n\nEach letter is represented by a strar.";
cout << "\n\nYou have to type only one letter in one try";
cout << "\n\nYou have " << MAX_TRIES << "  extra tries to  guess that word.\n\nBest of Luck\n";
cout<<"\nYou can use one clue.\nIf you use clue no bonus point else u will get 5 extra points\n\n";
   }
if(c==3){
 cout<<" You dont want to play,....You are a foolish.... \n";break;}
}
}
//search function
int search_word (char guess, string secretword, string &guessword)
{
int i;
int matches=0;
int len=secretword.length();
for (i = 0; i< len; i++)
{
// Did we already match this letter in a previous guess?
if (guess == guessword[i])
return 0;
// Is the guess in the secret word?
if (guess == secretword[i])
{
guessword[i] = guess;
matches++;
}
}
return matches;
}


