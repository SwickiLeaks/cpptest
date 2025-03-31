/**
 * Classic dependency graph problem for formula evaluation
 *
 * 1. Parse the input formulas
 * 2. Build a dep graph of variables
 * 3. Topologically sort the graph to find a safe evaluation order
 *      - This can be done with DFS
 * 4. Evaluate the expressions in order, replacing variables with their values
 *
 * Key Datastructures
 * - unordered_map to map variable names to their expressions and values
 * - unordered_set for dependency tracking
 *
 * Will need
 * - A simple tokenizer
 * -
 */

#include <iostream>
#include <regex>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class FormulaEval {
public:
  unordered_map<string, string> expressions;
  unordered_map<string, int> values;
  unordered_map<string, unordered_set<string>> dependencies;
  unordered_set<string> visited;

  vector<string> operations = {"+", "-", "/", "*"};

  /**
   *  @brief Determine if string value is a number
   */
  bool isNumber(const string &s) {
    return all_of(s.begin(), s.end(), ::isdigit);
  }

  /**
   *  @brief Simple tokenizer to return vector of strings
   */
  vector<string> tokenizer(const string &expr) {
    stringstream ss(expr);
    string token;
    vector<string> tokens;

    while (ss >> token) {
      tokens.push_back(token);
    }

    return tokens;
  }

  /**
   *  @brief Create a map of var to expressions
   */
  void setExpressions(vector<string> &formulas) {
    for (const auto &formula : formulas) {
      auto eq = formula.find("=");
      auto var = formula.substr(0, eq - 1);
      auto expr = formula.substr(eq + 2);

      expressions[var] = expr;
    }

    for (const auto &expr : expressions) {
      cout << "Var: " << expr.first << ", Expr: " << expr.second << endl;
    }
  }

  /**
   *  @brief Find dependencies between variables in the math expression
   */
  void mapDependencies(const string &var, const string &expr) {
    for (const auto &token : tokenizer(expr)) {
      if (!isNumber(token) && find(operations.begin(), operations.end(),
                                   token) == operations.end()) {
        dependencies[var].insert(token);
        cout << "Dependency for " << var << " -> " << token << endl;
      }
    }
  }

  /**
   *  @brief Function to evaluate the expression
   */
  int evaluateExpression(const string &expr) {
    stringstream ss(expr);
    string token;

    int result = 0;
    int sign = 1;

    while (ss >> token) {
      if (find(operations.begin(), operations.end(), token) !=
          operations.end()) {

        if (token == "+")
          sign = 1;
        else
          sign = -1;
      } else {
        int val = isNumber(token) ? stoi(token) : values.at(token);
        result += sign * val;
      }
    }
    return result;
  }

  /**
   *  @brief Perform DFS operation to safely order the evaluation order
   */
  void dfs(const string &var, vector<string> &order,
           unordered_set<string> &temp) {
    if (temp.contains(var))
      throw runtime_error("Cycle Detected!");
    if (!visited.contains(var)) {
      temp.insert(var);
      for (const auto &dep : dependencies[var]) {
        dfs(dep, order, temp);
      }
      temp.erase(var);
      visited.insert(var);
      order.push_back(var);
    }
  }

  /**
   *  @brief Evaluate the list of formulas with tools we have
   *  created as part of this class
   */
  vector<int> evaluateFormulas(vector<string> &formulas) {
    setExpressions(formulas);

    for (const auto &expr : expressions) {
      mapDependencies(expr.first, expr.second);
    }

    // TODO: The hard part.  Find evaluation order
    vector<string> evaluationOrder;
    unordered_set<string> temp;
    for (const auto &[var, expr] : expressions) {
      // If variable has value as expression, store in the values map
      if (isNumber(expr)) {
        values[var] = stoi(expr);
      }

      // Perform DFS here
      if (!visited.contains(var)) {
        dfs(var, evaluationOrder, temp);
      }
    }

    // Actually evaluate evaluate the expressions per the eval order
    for (const auto &eval : evaluationOrder) {
      //   values[eval] = evaluateExpression(expressions[eval]);
      if (!values[eval]) {
        cout << "Evaluting expression: " << eval << " = " << expressions[eval]
             << endl;
        values[eval] = evaluateExpression(expressions[eval]);
      }
    }

    for (const auto &[var, val] : values) {
      cout << var << " = " << val << endl;
    }

    return {};
  }
};