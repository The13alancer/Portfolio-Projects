# Secure Login System – C++ Project

A secure login and registration system implemented in C++ that demonstrates real-world authentication logic including **salting, peppering, and hashing** with OpenSSL. Also includes a custom hash function for exploration of hash logic.

---

## Features
- User registration with strong password enforcement (length + complexity)
- Passwords hashed using SHA-256 with salt and pepper
- Custom secondary hash function for exploration
- Credential comparison for secure login validation
- Local, runtime-based credential registry (can be extended to file or DB storage)

---

## Concepts Demonstrated
- Cryptography (SHA-256, salt, pepper)
- Security-conscious programming
- Object-Oriented Design
- Input validation & control flow

---

## Tech Stack
- C++ (Standard Library)
- OpenSSL for hashing
- Terminal/CLI interface

---

## Compile & Run

```bash
g++ SecureLogin.cpp -lssl -lcrypto -o securelogin
./securelogin

