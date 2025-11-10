# Credit Card

Validate credit card numbers using Luhn’s algorithm and determine the card brand (AMEX, MASTERCARD, VISA).

## Requirements

- Prompt the user for a credit card number.
- Validate with Luhn’s algorithm.
- Output:
  - "AMEX" for valid American Express numbers (15 digits; starts with 34 or 37)
  - "MASTERCARD" for valid MasterCard numbers (16 digits; starts with 51–55 or 2221–2720 depending on spec; classic pset expects 51–55)
  - "VISA" for valid Visa numbers (13 or 16 digits; starts with 4)
  - "INVALID" otherwise

Note
- AMEX: 15 digits, prefix 34 or 37
- MASTERCARD: 16 digits, prefix 51–55
- VISA: 13 or 16 digits, prefix 4

## Luhn’s Algorithm (summary)

1. Starting from the last digit and moving left:
   - Sum digits in odd positions (from the right, 1-indexed) directly.
   - For digits in even positions, double each digit; if the result is >= 10, add the two digits (equivalently, add result // 10 + result % 10).
2. Add both sums.
3. If the total modulo 10 is 0, the number is valid.

(If you need additional context)[https://www.youtube.com/watch?v=kMpEj7roKxM]

## Brand Detection

- Extract length and starting digits:
  - first = first digit
  - first_two = first two digits
- Rules:
  - AMEX: length == 15 and first_two in {34, 37}
  - MASTERCARD: length == 16 and first_two in {51, 52, 53, 54, 55}
  - VISA: length in {13, 16} and first == 4

## Example Inputs

- 378282246310005 → AMEX
- 371449635398431 → AMEX
- 5555555555554444 → MASTERCARD
- 5105105105105100 → MASTERCARD
- 4111111111111111 → VISA
- 4012888888881881 → VISA
- 1234567890 → INVALID

## Testing

Try the sample numbers above. Also test edge cases:
- Leading zeros (not typical for cards, but ensure your parsing doesn’t drop them if using strings).
- Invalid lengths (e.g., 12, 14, 17).
- Valid Luhn but wrong prefixes should print "INVALID".

## Notes

- Stick to the pset’s specified brand ranges unless your instructor allows the newer MasterCard 2-series.
- Avoid 64-bit overflow by operating on digits; the provided code uses integer division and modulo safely.
