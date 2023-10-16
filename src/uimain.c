#include "tokenizer.h"
#include "history.h"
#include <stdio.h>
#include <stdlib.h>

int main() {

    struct s_List *historyList = init_history();
  
    while(1) {

    printf("Select an option (Input String = s, Print History = h, Quit = q)\n");
    
    int input;
    int charNum = 0;
    int c;
    char *inputStr = malloc(30 * sizeof(char));
    char **tokens;
    
    while ((c = getchar()) == '\n'); /* ignore newlines */
    if (c == EOF)		     /* terminate on end-of-file */
      goto done;

    // Given the user answer, select which method to call
    switch (c) {
    case 's':
      printf("You chose to input a string, enter it below:\n> ");
      while (getchar() !='\n')
	continue;
      scanf("%[^\n]s", inputStr);
      printf("you inputed: %s\n", inputStr);
      tokens = tokenize(inputStr);
      while (*tokens){
	add_history(historyList,*tokens);
	tokens++;
      }
      break;
    case 'h':
      puts("You selected history:");
      print_history(historyList);
      break;
    case 'q':
      puts("Bye!");
      free_history(historyList);
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
