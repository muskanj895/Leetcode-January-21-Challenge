class Solution {
public:
    int superpalindromesInRange(string left, string right) {
        const long double lo_bound = sqrtl(stol(left));
        const long double hi_bound = sqrtl(stol(right));
        std::int_fast32_t superpalindromes = lo_bound <= 3 && 3 <= hi_bound;
        std::queue<std::pair<long, std::int_fast32_t>> queue;
        queue.push({1, 1});
        queue.push({2, 1});

        while (true) {
            const auto curr = queue.front();
            const long num = curr.first;
            const std::int_fast32_t length = curr.second;
            queue.pop();

            if (num > hi_bound) {
                break;
            }

            long W = powl(10, -~length / 2);

            if (num >= lo_bound) {
                superpalindromes += is_palindrome(num * num);
            }

            const long right = num % W;
            const long left = num - (length & 1 ? num % (W / 10) : right);

            if (length & 1) {
                queue.push({10 * left + right, -~length});

            } else {
                for (std::int_fast8_t d = 0; d < 3; ++d) {
                    queue.push({10 * left + d * W + right, -~length});
                }
            }
        }

        return superpalindromes;
    }

private:
    static bool is_palindrome(const long num) {
        if (!num) {
            return true;
        }

        if (!num % 10) {
            return false;
        }

        long left = num;
        long right = 0;

        while (left >= right) {
            if (left == right || left / 10 == right) {
                return true;
            }

            right = 10 * right + (left % 10);
            left /= 10;
        }

        return false;
    }

};

