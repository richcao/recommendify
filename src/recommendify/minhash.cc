/**
 * This file is part of the "recommendify" project
 *   Copyright (c) 2014 Paul Asmuth <paul@paulasmuth.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#include <stdlib.h>
#include <assert.h>
#include <random>
#include "minhash.h"

namespace recommendify {

MinHash::MinHash(
    uint64_t p,
    uint64_t q,
    const std::vector<std::tuple<uint64_t, uint64_t, uint64_t>>& params) :
    params_(params) {
  assert(params_.size() == p * q);
};

void MinHash::generateParameters(
    std::vector<std::tuple<uint64_t, uint64_t, uint64_t>>& destination,
    uint64_t n,
    uint64_t m /* = 0x7fffffff */) {
  uint64_t i;

  std::mt19937 prng((std::random_device())());
  std::uniform_int_distribution<> dist(1, m - 1);

  for (i = 0; i < n; ++i) {
    uint64_t a, b;

    a = dist(prng);
    b = dist(prng);

    destination.push_back(std::tuple<uint64_t, uint64_t, uint64_t>(
        a, b, m));
  }
}

}