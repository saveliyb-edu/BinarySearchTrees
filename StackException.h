#pragma once

#include <exception>
#include <iostream>
#include <string>

class StackException : public std::exception {
public:
	StackException() :
		whatStr("StackException") {};
	const char* what() const noexcept override {
		return whatStr.c_str();
	};
	~StackException() noexcept = default;
private:
	std::string whatStr;
};

class WrongStackSize : public std::exception {
public:
	WrongStackSize() :
		whatStr("Stack is empty!") {};

	const char* what() const noexcept override 	{
		return whatStr.c_str();
	}
	~WrongStackSize() noexcept = default;
private:
	std::string whatStr;
};

class StackUnderflow : public std::exception {
public:
	StackUnderflow() : whatStr("StackUnderflow") {};
	const char* what() const noexcept override {
		return whatStr.c_str();
	};
	~StackUnderflow() noexcept = default;

private:
	std::string whatStr;
};

class StackOverflow : public std::exception {
public:
	StackOverflow() : whatStr("StackOverflow") {};
	const char* what() const noexcept override {
		return whatStr.c_str();
	};
	~StackOverflow() noexcept = default;

private:
	std::string whatStr;
};