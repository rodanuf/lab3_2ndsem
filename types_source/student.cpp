#include <iostream>
#include "../types_headers/student.hpp"

student::student() : name(""), surname(""), patronymic(""), group_number(""), grade() {}
student::student(const std::string &name, float grade) : name(name), surname(""), patronymic(""), group_number(""), grade(grade) {}
student::student(const std::string &name, const std::string &surname, const std::string &patronymic, const std::string &group_number, float grade) : name(name), surname(surname), patronymic(patronymic), group_number(group_number), grade(grade) {}

bool student::operator==(const student &other) const
{
    return name == other.name && surname == other.surname && patronymic == other.patronymic && group_number == other.group_number && grade == other.grade;
}

bool student::operator!=(const student &other) const
{
    return name != other.name || surname != other.surname || patronymic != other.patronymic || group_number != other.group_number || grade != other.grade;
}