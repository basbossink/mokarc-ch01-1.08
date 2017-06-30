#include <stdio.h>
#include <stdlib.h>

#include "../lib/character-counter.h"

int
main(int argc, char **argv) {
  (void)argc;
  (void)argv;
  struct count_result whitespace[] = {
    { .character = ' ', .count = 0 },
    { .character = '\t', .count = 0 },
    { .character = '\n', .count = 0 },
  };
  size_t number_of_results = sizeof(whitespace) / sizeof(struct count_result);
  count_characters(getchar, whitespace, number_of_results);
  printf(
    "Standard in contains the following whitespace counts\n"    \
    "Spaces | Tabs   | Newlines |\n"\
    "%6lu | %6lu | %8lu |\n", whitespace[0].count, whitespace[1].count, whitespace[2].count);
  return EXIT_SUCCESS;
}
