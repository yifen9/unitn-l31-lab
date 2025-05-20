#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

void split(string fields[], string line, char delimiter);

// debug global, so that we do not need to pass it to functions as an extra
// argument
bool debug = false;

int main(int argc, char *argv[]) {
  char delimiter = ',';
  int field = 1;

  // parse command options
  for (int i = 0; i < argc; i++) {
    // look for a substring and get the argument
    if (strstr(argv[i], "-d")) {
      int string_size = strlen(argv[i]);
      delimiter = argv[i][string_size - 1];
    }

    if (strstr(argv[i], "-f")) {
      int string_size = strlen(argv[i]);

      // Smart:
      // field = atoi(argv[i] + 2);

      // More readable:
      string str = argv[i];
      field = stoi(str.substr(2));
    }

    // strcmp returns 0 if strings equal (no differences)
    if (!strcmp(argv[i], "--debug")) {
      debug = true;
    }
  }

  if (debug) {
    cout << "Arguments: " << endl;
    cout << delimiter << endl;
    cout << field << endl;
  }
  
  string line;
  string fields[100];

  // getline returns NULL (?) when no further lines to process
  // we use stdin so that we can use redirection
  while (getline(cin, line)) {
    split(fields, line, delimiter);

    if (debug) {
      cout << "LINE IS: " << line << endl;
      cout << "FIELDS ARE: " << endl;
      int index = 0;
      while (fields[index] != "") {
        cout << fields[index++] << endl;
      }
      cout << "END FIELDS" << endl;
    }

    cout << fields[field - 1] << endl;
  }
}

// where we store fields (allocated externally)
// the line we parse
// the delimiter we are looking for
void split(string fields[], string line, char delimiter) {
  // reset
  for (int i = 0; i < 100; i++) {
    fields[i] = "";
  }

  // fill

  // we iterate over the string using two cursors:
  //
  // - current_pos, where we start from
  // - found_pos, where we found the next field delimiter
  // 
  // in a single step:
  //
  // (colon processed at the previous step)
  // v
  // :systemd-journal:
  //  ^              ^
  //  current_pos    found
  //  <------ len --->
  //
  // then we move current_pos after found and continue

  // where we have looked so far
  int current_pos = 0;
  // where we find the next :
  int found_pos = 0;
  // the field we are currently storing
  int index = 0;

  // super-though: read, assign, compare, and use the return value for while
  while ((found_pos = line.find(delimiter, current_pos)) != string::npos) {

    if (debug) {
      cout << line << endl;
      cout << "CURRENT POS: " << current_pos << endl;
      cout << "FOUND POS: " << found_pos << endl;
    }

    string record = line.substr(current_pos, found_pos - current_pos);

    if (debug) {
      cout << "SUBSTR: " << record << endl << endl;
    }

    fields[index++] = record;
    current_pos = found_pos + 1;
  }

  // what if we don't do this?
  if (current_pos < line.length()) {
    fields[index] = line.substr(current_pos, string::npos);
  }
}
