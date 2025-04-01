/**
 * Message Parser
 *
 * Problem Parameters
 * ---------------------------------------
 * Given a "file" with statements describing a data message format
 * Parse the messages into a data class for which we can query on
 *
 * Messages can be made up of floats, ints, strings.
 * Assume strings = 256 bytes, int = 4 bytes, floats = 4 bytes
 *
 * Example Input
 *      // Message Input
 *      Message Vehicle
 *      float x_position
 *      float y_position
 *      float velocity
 *      float acceleration
 *      int num_wheels
 *      string name
 *
 *      Message Vector2d
 *      float x_position
 *      float y_position
 *      // End Input
 *
 * Data Structures Needed
 *      hashmap for strings and fields
 *      hashmap for string and type sizes
 */

#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class MessageParser {
private:
  unordered_map<string, vector<string>> messageFields;
  unordered_map<string, int> typeSizes = {
      {"int", 4},
      {"float", 4},
      {"string", 256},
  };

  // Custom trim function
  static string trim(const string &s) {
    size_t start = s.find_first_not_of(" \t");
    if (start == string::npos)
      return "";
    size_t end = s.find_last_not_of(" \t");
    return s.substr(start, end - start + 1);
  }

public:
  void parse(const vector<string> &lines) {
    string currentMessage;
    for (const string &line : lines) {
      string trimmed = trim(line);

      // If the message line is Start/End input
      if (trimmed.empty() || trimmed.starts_with("//"))
        continue;

      // Handle 'Message' here
      if (trimmed.starts_with("Message")) {
        currentMessage = trimmed.substr(8); // Get the message after 'Message'
        messageFields[currentMessage] = {};
      }

      // Handle values here
      else {
        istringstream iss(trimmed);
        string type, name;

        iss >> type >> name;

        cout << "Type: " << type << endl;
        cout << "Name: " << name << endl;

        messageFields[currentMessage].push_back(type);
      }
    }

    cout << endl;
    for (const auto &[k, vm] : messageFields) {
      cout << "Message " << k << endl;
      for (const auto &m : vm) {
        cout << m << endl;
      }
    }
  }
};