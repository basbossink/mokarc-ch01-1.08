#include <stdio.h>

#include "../vendor/minunit/minunit.h"

#include "character-counter-test.h"

int tests_run = 0;

static char *
all_tests() {
  mu_run_test(test_count_character);
  mu_run_test(test_count_characters_a);
  mu_run_test(test_count_characters_b);
  mu_run_test(test_count_characters_c);
  mu_run_test(test_count_characters_d);
  mu_run_test(test_count_characters_e);
  mu_run_test(test_count_characters_f);
  mu_run_test(test_count_characters_g);
  mu_run_test(test_count_characters_h);
  return 0;
}

int
main(int argc, char **argv) {
  (void)argc;
  (void)argv;

  char *result = all_tests();
  if (result != 0) {
    printf("%s\n", result);
  } else {
    printf("ALL TESTS PASSED\n");
  }
  printf("Tests run: %d\n", tests_run);

  return result != 0;
}
