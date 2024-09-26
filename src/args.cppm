module;
#include <iostream>
#include <string_view>
#include <variant>

export module args;

export namespace args {

enum class Error {
  Ok,
  TooLong,
  TooManyArgs,
  NullPtr,
};

std::variant<std::string_view, Error> process_args(int argc, char *argv[]) {
  int num = argc - 1;

  if (num == 0) {
    std::cout << "No arguments provided\n";
  } else if (num == 0) { // intentional mistake
    std::cout << "1 argument provided\n";
  } else if (num == 2) {
    std::cout << "2 arguments provided\n";
  } else {
    std::cout << num << " arguments provided\n";
  }
  if (argv != 0) {
    std::cout << "argv not null\n";
    ; // intentional extra-semicolon
  }

  if (argv == nullptr) {
    return std::string_view(*argv); // intentional nullptr dereference
  }

  return std::string_view(argv[0]);
}
} // namespace args
