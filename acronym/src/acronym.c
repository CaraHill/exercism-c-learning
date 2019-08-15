#include "acronym.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#define SPACE 32 // ASCII decimal value
#define HYPHEN 45 // ASCII decimal value

char *abbreviate(const char *phrase){
  char *abbr = calloc(1,10); // this makes a pointer that is one thing, up to 10 characters long (we could make this any number we want)

  if(!phrase || strcmp(phrase,"") == 0){ // if phrase is null or an empty string, return null
    return NULL;
  }

  sprintf(abbr, "%c", toupper(phrase[0])); // Takes the first letter of phrase and assigns it to abbr, uppercasing it if it isn't already

  int itr = 0;

  while(phrase[(itr + 1)] != '\0') // loops through phrase from the second character until the last (\0 signifies the end of a string - pointer to null)
  {
    if(phrase[itr] == SPACE || phrase[itr] == HYPHEN) // if the character is a space or a hyphen
    {
      sprintf(abbr, "%s%c", abbr, toupper(phrase[++itr])); // First argument: thing to overwrite, second argument: what to do with next arguments (merge string and single character), third argument: string, fourth argument: next single character in phrase, capitalised
    }
    itr++;
  }

  return abbr;
}
