#pragma once
#include <exception>
#include <iostream>
#include <string>

class QueueException : public std::exception {
public:
	QueueException() :
		whatStr("QueueException") {};
	const char* what() const noexcept override {
		return whatStr.c_str();
	};
	~QueueException() noexcept = default;

private:
	std::string whatStr;
};

class QueueOverflow : public std::exception {
public:
	QueueOverflow() : whatStr("QueueOverflow") {};
	const char* what() const noexcept override {
		return whatStr.c_str();
	};
	~QueueOverflow() noexcept = default;

private:
	std::string whatStr;
};

class WrongQueueSize : public std::exception {
public:
	WrongQueueSize() : whatStr("Queue is empty!") {};
	const char* what() const noexcept override {
		return whatStr.c_str();
	}
	~WrongQueueSize() noexcept = default;

private:
	std::string whatStr;
};

class QueueUnderflow : public std::exception {
public:
	QueueUnderflow() : whatStr("QueueUnderflow") {};
	const char* what() const noexcept override {
		return whatStr.c_str();
	};
	~QueueUnderflow() noexcept = default;

private:
	std::string whatStr;
};