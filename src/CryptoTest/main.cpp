// Copyright (c) 2018, The TurtleCoin Developers
//
// Please see the included LICENSE file for more information.

#include <iostream>

#include "CryptoNote.h"
#include "CryptoTypes.h"
#include "Common/StringTools.h"
#include "crypto/crypto.h"

using namespace Crypto;
using namespace CryptoNote;

int main(int argc, char** argv) {
  try {
    if (argc != 2)
    {
      throw std::runtime_error("Must supply data to hash");
    }

    std::string input = argv[1];

    const BinaryArray& rawData = Common::fromHex(input);

    std::cout << "\nInput: " << input << "\n\n";

    Hash hash = Hash();

    cn_fast_hash(rawData.data(), rawData.size(), hash);
    std::cout << "cn_fast_hash: " << Common::toHex(&hash, sizeof(Hash)) << "\n";

    cn_slow_hash_v6(rawData.data(), rawData.size(), hash);
    std::cout << "cn_slow_hash_v0: " << Common::toHex(&hash, sizeof(Hash)) << "\n";

    if (rawData.size() >= 43)
    {
      cn_slow_hash_v7(rawData.data(), rawData.size(), hash);
      std::cout << "cn_slow_hash_v1: " << Common::toHex(&hash, sizeof(Hash)) << "\n";

      cn_lite_slow_hash_v0(rawData.data(), rawData.size(), hash);
      std::cout << "cn_lite_slow_hash_v0: " << Common::toHex(&hash, sizeof(Hash)) << "\n";

      cn_lite_slow_hash_v1(rawData.data(), rawData.size(), hash);
      std::cout << "cn_lite_slow_hash_v1: " << Common::toHex(&hash, sizeof(Hash)) << "\n";
      
      cn_soft_shell(rawData.data(), rawData.size(), hash, 0);
      std::cout << "cn_soft_shell(0): " << Common::toHex(&hash, sizeof(Hash)) << "\n";
      
      cn_soft_shell(rawData.data(), rawData.size(), hash, 512);
      std::cout << "cn_soft_shell(512): " << Common::toHex(&hash, sizeof(Hash)) << "\n";
      
      cn_soft_shell(rawData.data(), rawData.size(), hash, 1024);
      std::cout << "cn_soft_shell(1024): " << Common::toHex(&hash, sizeof(Hash)) << "\n";
      
      cn_soft_shell(rawData.data(), rawData.size(), hash, 1536);
      std::cout << "cn_soft_shell(1536): " << Common::toHex(&hash, sizeof(Hash)) << "\n";
      
      cn_soft_shell(rawData.data(), rawData.size(), hash, 2048);
      std::cout << "cn_soft_shell(2048): " << Common::toHex(&hash, sizeof(Hash)) << "\n";
      
      cn_soft_shell(rawData.data(), rawData.size(), hash, 2560);
      std::cout << "cn_soft_shell(2560): " << Common::toHex(&hash, sizeof(Hash)) << "\n";
      
      cn_soft_shell(rawData.data(), rawData.size(), hash, 3072);
      std::cout << "cn_soft_shell(3072): " << Common::toHex(&hash, sizeof(Hash)) << "\n";
      
      cn_soft_shell(rawData.data(), rawData.size(), hash, 3584);
      std::cout << "cn_soft_shell(3584): " << Common::toHex(&hash, sizeof(Hash)) << "\n";
      
      cn_soft_shell(rawData.data(), rawData.size(), hash, 4096);
      std::cout << "cn_soft_shell(4096): " << Common::toHex(&hash, sizeof(Hash)) << "\n";
      
      cn_soft_shell(rawData.data(), rawData.size(), hash, 6144);
      std::cout << "cn_soft_shell(6144): " << Common::toHex(&hash, sizeof(Hash)) << "\n";
      
      cn_soft_shell(rawData.data(), rawData.size(), hash, 8192);
      std::cout << "cn_soft_shell(8192): " << Common::toHex(&hash, sizeof(Hash)) << "\n";
    }
  }
  catch (std::exception& e)
  {
    std::cout << "Something went terribly wrong...\n" << e.what() << "\n\n";
  }

  return 0;
}