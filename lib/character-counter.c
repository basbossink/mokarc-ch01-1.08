int
count_charater(int current_value, char input, char to_be_counted) {
  return input == to_be_counted ? current_value + 1 : current_value;
}
