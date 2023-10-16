#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int space_char(char c) {
  return (c == '\t' || c == ' ' || !c);
}

int non_space_char(char c) {
  return !space_char(c);
}

char *token_start(char *str) {
  if (!str) {
    return NULL;
  }
  char *curr_char = str;
  while (*curr_char == ' ') {
    curr_char ++;
      if (!str) {
	return NULL;
      }
  }
  while (curr_char) {
    if (space_char(*curr_char)){
      return curr_char + 1;
    }
    curr_char ++;
  }
  return NULL;
}

char *token_terminator(char *token) {
  char *curr_char = token;

  while (*curr_char) {
    curr_char ++;
  }

  return curr_char;
}

int count_tokens(char *str) {
  char *curr_str = str;
  int count = 0;
  while (*curr_str) {
    count++;
    curr_str = token_start(curr_str);
  }
  return count;
}

char *copy_str(char *inStr, short len) {
  char *newStr = malloc((len + 1) * sizeof(char));
  char *currChar = newStr;

  do {
    *currChar = *inStr;
    currChar++;
    inStr++;
    len --;
  } while (*inStr && len > 1);

  *currChar = '\0';
  return newStr;
}  

char **tokenize(char *str) {
  char **tokens = malloc(count_tokens(str) * sizeof(char*));
  char **token = tokens;
  char *currWord = str;
  int word_len;
  
  for (int i = 0; i < count_tokens(str); i ++) {
    word_len = (int) (token_start(currWord) - currWord);
    *token = copy_str(currWord, word_len);
    token++;
    currWord = token_start(currWord);
  }

  *token = '\0';

  return tokens;
}

void print_token_array(char **tokens) {
  char **token = tokens;
  while (*token) {
    printf("%s\n", *token);
   token ++;
  }
}
