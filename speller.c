// Implements a dictionary's functionality

#include<stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

int dictionary_size = 0;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26 * 26 * 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int index = hash(word);
    node *trav = table[index];
    while (trav != NULL)
    {
        if (strcasecmp(trav->word, word) == 0)
        {
            return true;
        }
        trav = trav->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int i = 0;
    int index = 0;
    while (word[i] != '\0')
    {
        i++;
    }
    if (i == 1)
    {
        index = toupper(word[0]) - 'A';
    }
    else if (i == 2)
    {
        index = (toupper(word[0]) - 'A') * 26 + toupper(word[1]) - 'A';
    }
    else
    {
        index = (toupper(word[0]) - 'A') * 676 + (toupper(word[1]) - 'A') * 26 + toupper(word[2]) - 'A';
    }

    return index;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    char temp[LENGTH + 1];
    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        return false;
    }

    while (fscanf(dict, "%s", temp) != EOF)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }
        strcpy(n->word, temp);
        n->next = table[hash(temp)];
        table[hash(temp)] = n;
        dictionary_size++;
    }
    fclose(dict);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return dictionary_size;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    node *temp;
    node *cursor;
    for (int i = 0; i < N; i++)
    {
        temp = table[i];
        cursor = table[i];
        while (temp != NULL)
        {
            cursor = cursor->next;
            free(temp);
            temp = cursor;
        }
        if (cursor == NULL && i == N - 1)
        {
            return true;
        }
    }

    return false;
}
