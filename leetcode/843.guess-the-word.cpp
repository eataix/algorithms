#include <list>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
/*
 * [873] Guess the Word
 *
 * https://leetcode.com/problems/guess-the-word/description/
 *
 * algorithms
 * Hard (33.68%)
 * Total Accepted:    2.2K
 * Total Submissions: 6.6K
 * Testcase Example:  '"acckzz"\n["acckzz","ccbazz","eiowzz","abcczz"]\n10'
 *
 * This problem is an interactive problem new to the LeetCode platform.
 *
 * We are given a word list of unique words, each word is 6 letters long, and
 * one word in this list is chosen as secret.
 *
 * You may call master.guess(word) to guess a word.  The guessed word should
 * have type string and must be from the original list with 6 lowercase
 * letters.
 *
 * This function returns an integer type, representing the number of exact
 * matches (value and position) of your guess to the secret word.  Also, if
 * your guess is not in the given wordlist, it will return -1 instead.
 *
 * For each test case, you have 10 guesses to guess the word. At the end of any
 * number of calls, if you have made 10 or less calls to master.guess and at
 * least one of these guesses was the secret, you pass the testcase.
 *
 * Besides the example test case below, there will be 5 additional test cases,
 * each with 100 words in the word list.  The letters of each word in those
 * testcases were chosen independently at random from 'a' to 'z', such that
 * every word in the given word lists is unique.
 *
 *
 * Example 1:
 * Input: secret = "acckzz", wordlist = ["acckzz","ccbazz","eiowzz","abcczz"]
 *
 * Explanation:
 *
 * master.guess("aaaaaa") returns -1, because "aaaaaa" is not in wordlist.
 * master.guess("acckzz") returns 6, because "acckzz" is secret and has all 6
 * matches.
 * master.guess("ccbazz") returns 3, because "ccbazz" has 3 matches.
 * master.guess("eiowzz") returns 2, because "eiowzz" has 2 matches.
 * master.guess("abcczz") returns 4, because "abcczz" has 4 matches.
 *
 * We made 5 calls to master.guess and one of them was the secret, so we pass
 * the test case.
 *
 *
 * Note:  Any solutions that attempt to circumvent the judge will result in
 * disqualification.
 *
 */
/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */

#ifdef DEBUG
class Master {
public:
  int guess(string word);
};
#endif
class Solution {
  int match(const string &a, const string &b) {
    int matches = 0;
    for (int i = 0; i < a.size(); ++i) {
      if (a[i] == b[i]) {
        matches += 1;
      }
    }
    return matches;
  }

  string bestCandidate(const list<string> &remaining,
                       const vector<vector<int>> &probs) {
    auto bestIt = remaining.cbegin();
    int maxScore = 0;
    for (auto it = remaining.cbegin(); it != remaining.cend(); ++it) {
      auto word = *it;
      int score = 1;
      for (int i = 0; i < 6; ++i) {
        score *= probs[i][word[i] - 'a'];

        if (score > maxScore) {
          maxScore = score;
          bestIt = it;
        }
      }
    }
    return *bestIt;
  }

public:
  void findSecretWord(vector<string> &wordlist, Master &master) {
    vector<vector<int>> probs(6, vector<int>(26, 0));
    list<string> remWords{wordlist.begin(), wordlist.end()};

    for (auto const &word : remWords) {
      for (auto i = 0; i < 6; ++i) {
        probs[i][word[i] - 'a'] += 1;
      }
    }

    for (int matched = 0; matched < 6;) {
      auto candidate = bestCandidate(remWords, probs);

      matched = master.guess(candidate);

      for (auto it = remWords.begin(); it != remWords.end();) {
        if (match(*it, candidate) != matched) {
          for (int i = 0; i < 6; ++i) {
            probs[i][(*it)[i] - 'a'] -= 1;
          }
          it = remWords.erase(it);
        } else {
          ++it;
        }
      }
    }
  }

  void findSecretWord2(vector<string> &wordlist, Master &master) {
    for (int i = 0, matched = 0; i < 10 && matched < 6; ++i) {
      unordered_map<string, int> count;
      for (auto const &w1 : wordlist) {
        for (auto const &w2 : wordlist) {
          if (match(w1, w2) == 0) {
            count[w1] += 1;
          }
        }
      }

      pair<string, int> minimax = {wordlist[0], numeric_limits<int>::max()};
      for (auto const &word : wordlist) {
        if (count[word] <= minimax.second) {
          minimax = {word, count[word]};
        }
      }
      matched = master.guess(minimax.first);

      vector<string> wordlist2;
      for (auto const &word : wordlist) {
        if (match(minimax.first, word) == matched) {
          wordlist2.push_back(word);
        }
      }
      wordlist = wordlist2;
    }
  }
};
