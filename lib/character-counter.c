#include <stdio.h>

#include "character-counter.h"


int
count_character(
  int current_value,
  char input,
  char to_be_counted) {
  return input == to_be_counted ? current_value + 1 : current_value;
}


void
count_characters(
  get_character source,
  struct count_result results[],
  size_t number_of_results) {
  int current_character;
  while((current_character = source()) != EOF) {
    for(size_t i = 0; i < number_of_results; i++) {
      results[i].count = count_character(
        results[i].count,
        current_character,
        results[i].character);
    }
  }
}
