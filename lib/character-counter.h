#include <stdint.h>

struct count_result {
  char character;
  uint64_t count;
};

typedef int (*get_character)(void);

int
count_character(int current_value, char input, char to_be_counted);

void
count_characters(get_character source, struct count_result* results, size_t number_of_results);
