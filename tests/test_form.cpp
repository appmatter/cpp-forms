#include <catch2/catch_test_macros.hpp>

#include "cpp_forms/form.hpp"

#include <iostream>

struct User
{
  std::string name;
  std::string email;

  bool operator==(const User &other) const
  {
    return name == other.name && email == other.email;
  }
};

TEST_CASE("Form tracks changes", "[form]")
{
  User user{"Alice", "alice@example.com"};
  Form<User> form(user);

  REQUIRE_FALSE(form.isDirty());

  form.data().name = "Bob";
  REQUIRE(form.isDirty());

  form.commit();
  REQUIRE(user.name == "Bob");
}

TEST_CASE("Form reset discards changes", "[form]")
{
  User user{"Alice", "alice@example.com"};
  Form<User> form(user);

  form.data().email = "bob@example.com";
  form.reset();

  REQUIRE(form.data().email == "alice@example.com");
}

TEST_CASE("Validation rules are applied", "[form]")
{
  User user{"", "notanemail"};
  Form<User> form(user);

  form.addValidation("name", [](const User &u)
                     { return u.name.empty() ? std::optional<std::string>{"Name is required"}
                                             : std::nullopt; });

  form.addValidation("email", [](const User &u)
                     { return u.email.find('@') == std::string::npos
                                  ? std::optional<std::string>{"Invalid email"}
                                  : std::nullopt; });

  form.validate();

  CAPTURE(form.allErrors());

  REQUIRE(form.hasError("name"));
  REQUIRE(form.hasError("email"));
  REQUIRE(form.error("name") == "Name is required");
  REQUIRE(form.error("email") == "Invalid email");
}
