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
#include "minhashrecommender.h"

namespace recommendify {

void MinHashRecommender::addPreferenceSet(const ItemSet& preference_set) {
  std::vector<Fingerprint> fingerprints;

  minhash_.computeFingerprints(preference_set, fingerprints);

  for (const auto& fingerprint : fingerprints) {
    printf("%s\n", fingerprint.humanReadable().c_str());
  }
}

void MinHashRecommender::getRecommendations(const ItemSet& query_point,
    size_t max_items, RankedItemList& result) const {
  printf("get recos %i\n", query_point.getItems().size());
}

}