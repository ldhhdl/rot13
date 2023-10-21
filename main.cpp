#include <cassert>
#include <cstdlib>
#include <iostream>

void rot13(std::string &input) {
  for (auto c = input.begin(); c != input.end(); ++c) {
    unsigned base_value{0};
    if (65 <= *c && *c <= 90) {
      // uppercase
      base_value = 65;
    } else if (97 <= *c && *c <= 122) {
      // lowercase
      base_value = 97;
    }
    if (base_value != 0) {
      *c = static_cast<char>((((static_cast<int>(*c) + 13) - base_value) % 26) +
                             base_value);
    }
  }
  return;
}

int main() {
  std::string test{"The quick brown fox jumps over 13 lazy dogs."};
  std::string original{test};
  const std::string expected_value{
      "Gur dhvpx oebja sbk whzcf bire 13 ynml qbtf."};

  rot13(test);
  assert(test == expected_value);

  rot13(test);
  assert(test == original);
  return EXIT_SUCCESS;
}
