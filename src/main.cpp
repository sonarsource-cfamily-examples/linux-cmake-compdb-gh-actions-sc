#include <iostream>
#include <variant>

import args;

using namespace std;

int main(int argc, char *argv[]) {
  auto get_proc_name = args::process_args(argc, argv);
  if (std::holds_alternative<args::Error>(get_proc_name)) {
    switch (std::get<args::Error>(get_proc_name)) {
    case args::Error::TooLong:
      std::cout << "Proc name too long\n";
      return 1;
    }
    return 0;
  }

  auto &&value = std::get<std::string_view>(get_proc_name);
  std::cout << value << '\n';
  return 0;
}
