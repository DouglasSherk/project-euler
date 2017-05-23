#include <iostream>
#include <string>
#include <fstream>
#include <unordered_set>
#include <climits>
#include <algorithm>

#include "headers/euler.hpp"

const int SECRET_KEY_LENGTH = 3;

std::string getCipher(std::string fileName) {
  std::ifstream cipherFile(fileName);

  std::string line;
  std::string cipher;
  while (getline(cipherFile, line, ',')) {
    cipher += (unsigned char) euler::toInt(line);
  }

  return cipher;
}

bool nextSecretKey(unsigned char secretKey[SECRET_KEY_LENGTH]) {
  char carry = 1;

  for (int i = SECRET_KEY_LENGTH - 1; i >= 0; i--) {
    if (secretKey[i] == 'z') {
      secretKey[i] = 'a';
      carry = 1;
    } else {
      secretKey[i] += carry;
      carry = 0;
      break;
    }
  }

  return !carry;
}

std::string decryptCipher(std::string cipher, unsigned char secretKey[SECRET_KEY_LENGTH]) {
  std::string text;
  int secretKeyPos = 0;

  for (auto c : cipher) {
    text += c ^ secretKey[secretKeyPos++];
    secretKeyPos %= SECRET_KEY_LENGTH;
  }

  return text;
}

int countEnglishWordsInText(std::string text, const std::unordered_set<std::string>& englishWords) {
  int numEnglishWords = 0;

  for (auto englishWord : englishWords) {
    int pos = -1;

    while ((pos = text.find(englishWord, pos + 1)) != std::string::npos) {
      numEnglishWords++;
    }
  }

  return numEnglishWords;
}

long long countTotalStringAscii(std::string text) {
  long long sum = 0;

  for (auto c : text) {
    sum += c;
  }

  return sum;
}

int main(int argc, char** argv) {
  // Most common English words with at least 2 characters.
  std::unordered_set<std::string> englishWords({
    "the", "be", "to", "of", "and", "in", "that", "have", "for", "not", "with"
  });

  unsigned char secretKey[SECRET_KEY_LENGTH];
  for (int i = 0; i < SECRET_KEY_LENGTH; i++) {
    secretKey[i] = 'a';
  }

  int largestNumEnglishWords = 0;
  std::string largestNumEnglishWordsText;

  std::string cipher = getCipher("59_cipher.txt");

  while (nextSecretKey(secretKey)) {
    std::string text = decryptCipher(cipher, secretKey);

    int numEnglishWords = countEnglishWordsInText(text, englishWords);

    if (numEnglishWords > largestNumEnglishWords) {
      largestNumEnglishWords = numEnglishWords;
      largestNumEnglishWordsText = text;
    }
  }

  std::cout << "Text with largest number (" << largestNumEnglishWords << ") of English words: "
            << largestNumEnglishWordsText << std::endl;
  std::cout << "Total value of all ASCII characters in text: "
            << countTotalStringAscii(largestNumEnglishWordsText) << std::endl;

  return 0;
}
