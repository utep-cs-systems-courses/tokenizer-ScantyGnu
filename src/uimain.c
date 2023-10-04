#include "tokenizer.h"

int main() {
  puts("Welcome to the Tokenizer!");

  while(1) {

    fputs("Select an option (Input String = s, Print History = h, Quit = q)\n> ", stdout);
    fflush(stdout);

    int input;
    int charNum = 0;
    char inputStr[20];
    char **tokens;
    
    while ((c = getchar()) == '\n'); /* ignore newlines */
    if (c == EOF)		     /* terminate on end-of-file */
      goto done;

    // Given the user answer, select which method to call
    switch (c) {
    case 's':
      puts("You chose to input a string, enter it below:\n> ");
      scanf('%s', w);
      tokens = tokenize(w);
      print_token_array(tokens);
      break;
    case 'h':
      puts("You selected history:");
      goto done;
      break;
    case 'w':
      puts("You selected word:");
      puts("Enter a word:");
      scanf("%s", w);
      print_word_myfont(w);
      break;
    case 'q':
      puts("Bye!");
      goto done; 		/* terminate */
    case '\n':
      break;
    default:
      printf("Unrecognized option '%c', please try again!\n", c);
    }
  }

 done: // To exit from program
  return 0;
}
