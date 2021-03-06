#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv) {
  if (argc <= 1) { /* No program name was given. */
  /* Simple doesn't mean not user friendly! */
    fprintf(stderr, "usage: %s filename [args...]\n", argv[0]);
    return 1;
  }

  /* We pass argv[1] as the program to execute, and then the rest of the
   * arguments as argv.
   */
  execvp(argv[1], argv + 1);

  /* Not checking the return value is sort of cheeky, but we know execvp will
   * only return if it fails, so we only ever get here if there was an error!
   */
  fprintf(stderr, "Ooops, something went wrong!\n");
  return 1;
}
