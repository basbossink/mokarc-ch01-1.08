#include <stdio.h>

#include "../vendor/minunit/minunit.h"
#include "../lib/character-counter.h"

struct count_case {
  int starting_value;
  int expected;
  char input;
};

static  const char to_be_counted = 'b';


#define FORMATTED_MESSAGE_SIZE_MAX 256
  static char message[FORMATTED_MESSAGE_SIZE_MAX];
#undef FORMATTED_MESSAGE_SIZE_MAX


#define TEST_CASE(s,i,e) { .starting_value = (s), .input = (i), .expected = (e) },
struct count_case test_cases[] = {
  TEST_CASE(0, to_be_counted, 1)
  TEST_CASE(1, to_be_counted + 1, 1)
  TEST_CASE(37, to_be_counted, 38)
  TEST_CASE(42, to_be_counted -1, 42)
};
#undef TEST_CASE


char *
test_character_counter(void) {


  const char *message_format = "(%s:%s:%d) expected count of '%c' when starting with %d for input '%c' to equal %d but got %d";
  const size_t number_of_test_cases = sizeof(test_cases) / sizeof(struct count_case);
  for (unsigned long i = 0ul;
       i < number_of_test_cases;
       i++) {
    struct count_case test = test_cases[i];
    int actual = count_charater(test.starting_value, test.input, to_be_counted);
    (void)snprintf(
      message,
      sizeof message,
      message_format,
      __FILE__,
      __func__,
      i,
      to_be_counted,
      test.starting_value,
      test.input,
      test.expected,
      actual);
    mu_assert(message, actual == test.expected);
  }
  return 0;
}
