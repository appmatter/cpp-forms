#pragma once

#include <functional>
#include <optional>
#include <string>
#include <type_traits>
#include <unordered_map>

template <typename T> class Form {
public:
  using ValidationRule = std::function<std::optional<std::string>(const T &)>;

  Form(T &original) : originalRef(original), workingCopy(original) {}

  T &data() { return workingCopy; }

  void commit() { originalRef = workingCopy; }

  void reset() {
    workingCopy = originalRef;
    errors.clear();
  }

  bool isDirty() const { return !(originalRef == workingCopy); }

  void addValidation(const std::string &field, ValidationRule rule) {
    rules[field] = rule;
  }

  void validate() {
    errors.clear();
    for (const auto &[field, rule] : rules) {
      if (auto result = rule(workingCopy)) {
        errors[field] = *result;
      }
    }
  }

  bool hasError(const std::string &field) const {
    return errors.find(field) != errors.end();
  }

  std::string error(const std::string &field) const {
    auto it = errors.find(field);
    return it != errors.end() ? it->second : "";
  }

  const std::unordered_map<std::string, std::string> &allErrors() const {
    return errors;
  }

private:
  T &originalRef;
  T workingCopy;
  std::unordered_map<std::string, ValidationRule> rules;
  std::unordered_map<std::string, std::string> errors;
};
