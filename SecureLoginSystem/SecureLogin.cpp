//
// Created by aniru on 7/28/2025.
//
#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <fstream>
#include <openssl/sha.h>

class User {
public:
    std::string username;
    std::string salt;
    std::string hashedPassword;

    User(const std::string& uname, const std::string& salt, const std::string& hashedPwd)
        : username(uname), salt(salt), hashedPassword(hashedPwd) {}
};

class LoginSystem {
private:
    std::vector<User> users;
    const std::string PEPPER = "7#p9!k2$z";
    const std::string USER_DB = "users.dat";

    std::string generateSalt(size_t length = 16) {
        static const std::string charset =
            "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, charset.size() - 1);

        std::string salt;
        for (size_t i = 0; i < length; ++i) {
            salt += charset[dis(gen)];
        }
        return salt;
    }

    std::string hashPassword(const std::string& password, const std::string& salt) {
        std::string saltedPeppered = salt + password + PEPPER;
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256(reinterpret_cast<const unsigned char*>(saltedPeppered.c_str()),
               saltedPeppered.size(), hash);

        std::string hashed;
        for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
            char buf[3];
            sprintf(buf, "%02x", hash[i]);
            hashed += buf;
        }
        return hashed;
    }

    bool isStrongPassword(const std::string& password) {
        if (password.length() < 12) return false;

        bool hasUpper = false, hasLower = false, hasDigit = false, hasSpecial = false;
        for (char c : password) {
            if (isupper(c)) hasUpper = true;
            else if (islower(c)) hasLower = true;
            else if (isdigit(c)) hasDigit = true;
            else if (ispunct(c)) hasSpecial = true;
        }
        return (hasUpper + hasLower + hasDigit + hasSpecial) >= 3;
    }

public:
    bool registerUser(const std::string& username, const std::string& password) {
        if (!isStrongPassword(password)) {
            std::cerr << "Password too weak. Use 12+ chars with uppercase, lowercase, numbers, and symbols.\n";
            return false;
        }

        std::string salt = generateSalt();
        std::string hashedPassword = hashPassword(password, salt);
        users.emplace_back(username, salt, hashedPassword);
        return true;
    }

    bool login(const std::string& username, const std::string& password) {
        for (const auto& user : users) {
            if (user.username == username) {
                std::string attemptHash = hashPassword(password, user.salt);
                return (attemptHash == user.hashedPassword);
            }
        }
        return false;
    }
};

class CustomHasher {
public:
    static std::string hash(const std::string& input) {
        uint32_t hash = 5381;

        for (char c : input) {
            hash = ((hash << 5) + hash) + static_cast<uint32_t>(c);
        }

        hash ^= hash >> 16;
        hash *= 0x85ebca6b;
        hash ^= hash >> 13;
        hash *= 0xc2b2ae35;
        hash ^= hash >> 16;

        return std::to_string(hash);
    }
};

int main() {
    LoginSystem secureSystem;
    secureSystem.registerUser("secure_user", "SecurePass123!");
    bool secureLogin = secureSystem.login("secure_user", "SecurePass123!");
    std::cout << "Secure system login: " << (secureLogin ? "SUCCESS" : "FAIL") << "\n";
    std::cout << "Custom hash of 'test': " << CustomHasher::hash("test") << "\n";
}