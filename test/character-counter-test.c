#include <stdio.h>
#include <string.h>

#include "../vendor/minunit/minunit.h"
#include "../lib/character-counter.h"

struct count_case {
  int starting_value;
  int expected;
  char input;
};

static const char to_be_counted = '.';


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
test_count_character(void) {

  const char *message_format = "(%s:%s:%d) expected count of '%c' when starting with %d for input '%c' to equal %d but got %d";
  const size_t number_of_test_cases = sizeof(test_cases) / sizeof(struct count_case);
  for (unsigned long i = 0ul;
       i < number_of_test_cases;
       i++) {
    struct count_case test = test_cases[i];
    int actual = count_character(test.starting_value, test.input, to_be_counted);
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


static const char* a = "";
static const char* b = "x";
static const char* c = "x.x";
static const char* d = ".x";
static const char* e = ".x..x";
static const char* f = "x.x.x";
static const char* g = "x..x...";
static const char* h = "...x...";


#define get_character_stub(input) int get_character_stub_##input(void) {\
  static size_t call_count = 0;\
  size_t input_length = strlen(input);\
  int return_value = call_count < input_length ? input[call_count] : EOF;\
  call_count++;\
  return return_value;\
}


get_character_stub(a)
get_character_stub(b)
get_character_stub(c)
get_character_stub(d)
get_character_stub(e)
get_character_stub(f)
get_character_stub(g)
get_character_stub(h)

#undef get_character_stub

#define test_count_characters(t,e) char* test_count_characters_##t(void) { \
  const char *message_format = "(%s:%s) expected count of '%c' in '%s' to equal %d but got %d";\
  struct count_result to_be_result[] = { { .character = to_be_counted, .count = 0 } };\
  count_characters(get_character_stub_##t, to_be_result, 1);\
  (void)snprintf(\
    message,\
    sizeof message,\
    message_format,\
    __FILE__,\
    __func__,\
    to_be_counted,\
    t,\
    e,\
    to_be_result[0].count);\
    mu_assert(message, to_be_result[0].count == e);\
  return 0;\
}

test_count_characters(a,0)
test_count_characters(b,0)
test_count_characters(c,1)
test_count_characters(d,1)
test_count_characters(e,3)
test_count_characters(f,2)
test_count_characters(g,5)
test_count_characters(h,6)

#undef test_count_characters
