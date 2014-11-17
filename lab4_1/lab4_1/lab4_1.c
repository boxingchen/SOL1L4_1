/* File: lab4_1.c */
/* Alexander Ustyuzhanin, IE SO1 group 1, WS14, 07.11.2014 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define ARSIZE 26		// alphabet length
#define ASCII_OFFSET 32 // offset of the capital letters from the lowercase ones

typedef struct letter_counter
{
	char letter[ARSIZE];						// 'a' ... 'z'
	int counter_per_letter[ARSIZE];				// counter per letter
	int total_num_of_letters;					// total number of letters counted
}
LETTER_COUNTER;

void bubble_sort(LETTER_COUNTER *, int);		// prototypes
void inc(LETTER_COUNTER *, char[]);
int get_count(LETTER_COUNTER *, char);	
int get_total(char[]);

int main()
{
	LETTER_COUNTER counter = {{'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'}, {0}, 0}; // initialize our structure
	char text_str[]="abc!_ ABC";											// the sting of text to analyse
	int index = 0;															// used in printing the result
	char *starString;														// used in printing the result
	unsigned int stringLength, i;											// for the starString

	inc(&counter, text_str);												// call the inc function to fill counter with data
	printf("get count for \"b\" returned %d\n", get_count(&counter, 'b'));  // check if this function works correctly
	
	printf("\n------------------------------------------------------\n");
	printf("Text under investigation is :\n");
	puts(text_str);
	printf("------------------------------------------------------\n");
	printf("The text contains %d characters.\n", counter.total_num_of_letters);
	printf("get_total function counted %d characters.\n", get_total(text_str));
	printf("\t  1234567890123456789012345678901234567890\n");
	bubble_sort(&counter, ARSIZE);											// sort the array
	while(index < ARSIZE)													// this cycle prints number of occurances for each letter (stars)
	{																		// I used memory allocation just to remember how it's done
		if(counter.counter_per_letter[index] == 0)							// don't print anything if the letter was never encountered
			break;
		i = 0;
		stringLength = counter.counter_per_letter[index] + 1;				// +1 so the \0 fits
		starString = (char *) malloc(sizeof(char) * stringLength);			// allocate memory to place the string of asterisks
		while(i < (stringLength - 1))										// fill it with asterisks
		{
			starString[i] = '*';
			i++;
		}
		starString[(stringLength - 1)] = '\0';								// append EOS to the asterisk string
		printf("letter %c :%s\n", counter.letter[index], starString);		// print the string
		free(starString);													// free the memory
		index++;
	}

	system("pause");
	return 0;
}

void inc(LETTER_COUNTER *counter, char string[])
{
	int i = 0;								// letter array index
	int j = 0;								// string index
	char capital;							// for convenience

	while(string[i] != '\0')
	{
		while(j < ARSIZE)
		{
			capital = (char) (counter->letter[j] - ASCII_OFFSET); // I'm using the fact that capital letters are offset from lowercase ones by 32 (dec)
			if(counter->letter[j] == string[i] || capital == string[i]) 
			{
				counter->counter_per_letter[j]++;
				counter->total_num_of_letters++;
				j++;
				break;						// terminate the inner loop once we have a match
			}
			j++;
		}
		j = 0;								// reset the inner loop index
		i++;
	}
}
int get_count(LETTER_COUNTER *counter, char letter)
{
	unsigned int index = 0;
	while(index < ARSIZE)
	{
		if(letter != counter->letter[index])
		{
			index++;
		}
		else
			return counter->counter_per_letter[index];
	}
	return 0;
}

int get_total(char string[])
{
	char alphabet[ARSIZE] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	unsigned int index = 0;			// string index
	unsigned int i = 0;				// alphabet array index
	unsigned int total = 0;			// total number of letter in the string
	char capital;					// convenience
	while(string[index] != '\0')
	{
		i = 0;
		while(i < ARSIZE)
		{
			capital = (char) (alphabet[i] - ASCII_OFFSET);
			if(string[index] == alphabet[i] || string[index] == capital)
			{
				total++;
				break;
			}
			i++;
		}
		index++;
	}
	return total;
}

void bubble_sort(LETTER_COUNTER *counter, int dimension)
{ 
	int ready, i, intTemp;
	char charTemp;
	do
	{
		ready = 1;																	// true
		for(i=0; i < dimension-1; i++)
		{
			if(counter->counter_per_letter[i] < counter->counter_per_letter[i+1])	// '>' ascending order, '<' descending order
			{
				intTemp = counter->counter_per_letter[i];
				counter->counter_per_letter[i] = counter->counter_per_letter[i+1];
				counter->counter_per_letter[i+1] = intTemp;

				charTemp = counter->letter[i];										// I swap the letters in the alphabet array so we can get the correct output when printing astesisks
				counter->letter[i] = counter->letter[i+1];
				counter->letter[i+1] = charTemp;

				ready = 0;															// false;
			}
		}
	} 
	while(!ready);
} 