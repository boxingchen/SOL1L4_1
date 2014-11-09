/* File: lab4_1.c */
/* Alexander Ustyuzhanin, IE SO1 group 1, WS14, 07.11.2014 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define ARSIZE 26

typedef struct letter_counter
{
	char letter[ARSIZE];						// 'a' ... 'z'
	int counter_per_letter[ARSIZE];				// counter per letter
	int total_num_of_letters;					// total number of letters counted
}
LETTER_COUNTER;

void bubble_sort(LETTER_COUNTER *, int);
void inc(LETTER_COUNTER *, char[]);		// this one is incorrect too (same problem, plus it counts EOS)
int get_count(LETTER_COUNTER *, char);	
int get_total(char[]);					// this one is incorrect (counts non-alphabet characters)

int main()
{
	LETTER_COUNTER counter = {{'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'}, {0}, 0};
	char text_str[]="abbcccddddeeeeeffffffggggggghhhhhhhhiiiiiiiii";
	int index = 0;
	char *starString;
	unsigned int stringLength, i;		// for the starString

	inc(&counter, text_str);
	get_count(&counter, 'b');
	
	printf("\n------------------------------------------------------\n");
	printf("Text under investigation is :\n");
	puts(text_str);
	printf("------------------------------------------------------\n");
	printf("The text contains %d characters.\n", get_total(text_str));
	printf("\t  1234567890123456789012345678901234567890\n");
	bubble_sort(&counter, ARSIZE);
	while(index < ARSIZE)
	{
		if(counter.counter_per_letter[index] == 0)
			break;
		i = 0;
		stringLength = counter.counter_per_letter[index] + 1;				// +1 so the \0 fits
		starString = (char *) malloc(sizeof(char) * stringLength);
		while(i < (stringLength - 1))
		{
			starString[i] = '*';
			i++;
		}
		starString[(stringLength - 1)] = '\0';
		printf("letter %c :%s\n", counter.letter[index], starString);
		free(starString);
		index++;
	}
	system("pause");
	return 0;
}

void inc(LETTER_COUNTER *counter, char string[])
{
	enum alphabet{a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z};
	while(string[counter->total_num_of_letters] != '\0')
	{
		switch(string[counter->total_num_of_letters])
		{
			case 'a':
			case 'A':
				counter->counter_per_letter[a]++;
				break;
			case 'b':
			case 'B':
				counter->counter_per_letter[b]++;
				break;
			case 'c':
			case 'C':
				counter->counter_per_letter[c]++;
				break;
			case 'd':
			case 'D':
				counter->counter_per_letter[d]++;
				break;
			case 'e':
			case 'E':
				counter->counter_per_letter[e]++;
				break;
			case 'f':
			case 'F':
				counter->counter_per_letter[f]++;
				break;
			case 'g':
			case 'G':
				counter->counter_per_letter[g]++;
				break;
			case 'h':
			case 'H':
				counter->counter_per_letter[h]++;
				break;
			case 'i':
			case 'I':
				counter->counter_per_letter[i]++;
				break;
			case 'j':
			case 'J':
				counter->counter_per_letter[j]++;
				break;
			case 'k':
			case 'K':
				counter->counter_per_letter[k]++;
				break;
			case 'l':
			case 'L':
				counter->counter_per_letter[l]++;
				break;
			case 'm':
			case 'M':
				counter->counter_per_letter[m]++;
				break;
			case 'n':
			case 'N':
				counter->counter_per_letter[n]++;
				break;
			case 'o':
			case 'O':
				counter->counter_per_letter[o]++;
				break;
			case 'p':
			case 'P':
				counter->counter_per_letter[p]++;
				break;
			case 'q':
			case 'Q':
				counter->counter_per_letter[q]++;
				break;
			case 'r':
			case 'R':
				counter->counter_per_letter[r]++;
				break;
			case 's':
			case 'S':
				counter->counter_per_letter[s]++;
				break;
			case 't':
			case 'T':
				counter->counter_per_letter[t]++;
				break;
			case 'u':
			case 'U':
				counter->counter_per_letter[u]++;
				break;
			case 'v':
			case 'V':
				counter->counter_per_letter[v]++;
				break;
			case 'w':
			case 'W':
				counter->counter_per_letter[w]++;
				break;
			case 'x':
			case 'X':
				counter->counter_per_letter[x]++;
				break;
			case 'y':
			case 'Y':
				counter->counter_per_letter[y]++;
				break;
			case 'z':
			case 'Z':
				counter->counter_per_letter[z]++;
				break;
			default:
				break;
		}
		counter->total_num_of_letters++;
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
	unsigned int index = 0;
	while(string[index] != '\0')
		index++;
	return index;
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

				charTemp = counter->letter[i];
				counter->letter[i] = counter->letter[i+1];
				counter->letter[i+1] = charTemp;

				ready = 0;															// false;
			}
		}
	} 
	while(!ready);
} 