#include <string.h>

int space_char(char c) {
  return (c == '\t' || c == ' ' || !c) ? 0 : 1;
}

int non_space_char(char c) {
  return !space_char(char c);
}

char *token_start(char *str) {
  if (!str) {
    return NULL;
  }
  char *curr_char = char;
  while (*curr_char == ' ') {
    curr_char ++;
      if (!str) {
	return NULL;
      }
  }
    while (curr_char) {
      if (space_char(curr_char)){
	return curr_char + 1;
      }
      curr_char ++;
    }
  return NULL;
}

char *token_terminator(char *token) {
  char *curr_char = char;

  while (curr_char) {
    curr_char ++;
  }

  return curr_char;
}

int count_tokens(char *str) {
  char *curr_str = str;
  int count = 0;
  while (curr_str) {
    count++;
    curr_str = token_start(curr_str);
  }
  return count;
}

char *copy_str(char *inStr, short len) {
  char *newStr = malloc(len);
  char currChar = newStr;

  for (short i = 0; i < len; i++) {
    if (!inStr) {
      currChar++;
      break;
    }
    
    *currChar = *inStr;
    currChar++;
    inStr++;
  }

  *currChar = NULL;
  return newStr;
}  

char **tokenize(char *str) {
  char **tokens = malloc(*str.length() * 8);
  char *token = *tokens;
  char *currWord = str;
  int word_len;
  
  for (int i = 0; i < *str.length(); i++) {
    word_len = (int) (currWord - token_terminator(currWord) + 2) / 8; 
    *token = copy_str(currWord, word_len);
    token++;
    currWord = token_start(curr_word);
  }

  *token = copy_str(NULL, 1);
  
  return tokens;
}

void print_token_array(char **tokens) {
  char *token = *tokens;
  while (token) {
   puts(*token);
   token ++;
  }
}
