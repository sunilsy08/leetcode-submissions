#include <vector>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    // Function to find all possible side lengths (gaps between every pair of fences).
    std::unordered_set<int> findPossibleSides(std::vector<int>& fencePositions, int limit) {
        // Add the boundaries (1 and the grid limit)
        fencePositions.push_back(1);
        fencePositions.push_back(limit);

        // Sort the positions to calculate pairwise differences
        std::sort(fencePositions.begin(), fencePositions.end());

        // Set to store unique side lengths
        std::unordered_set<int> sideLengths;

        // Calculate differences between every pair of fences
        for (size_t i = 0; i < fencePositions.size(); ++i) {
            for (size_t j = i + 1; j < fencePositions.size(); ++j) {
                int gap = fencePositions[j] - fencePositions[i];
                sideLengths.insert(gap);  // Add only positive differences
            }
        }

        return sideLengths;
    }

    // Main function to maximize the square area
    int maximizeSquareArea(int m, int n, std::vector<int>& hFences, std::vector<int>& vFences) {
        // Get potential side lengths from horizontal and vertical fences
        std::unordered_set<int> horizontalSides = findPossibleSides(hFences, m);
        std::unordered_set<int> verticalSides = findPossibleSides(vFences, n);

        int maxSide = -1; // Initialize the maximum side length as -1 (if no square is possible)

        // Find the largest common side length in both sets
        for (const int& side : horizontalSides) {
            if (side > 0 && verticalSides.count(side)) {
                maxSide = std::max(maxSide, side);
            }
        }

        const int mod = 1e9 + 7; // Modulus to prevent overflow

        // If we found a valid side, return the square of that side modulo 1e9 + 7
        return maxSide > 0 ? (static_cast<long long>(maxSide) * maxSide) % mod : -1;
    }
};
