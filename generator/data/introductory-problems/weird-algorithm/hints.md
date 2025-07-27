# Hints

## Hint 1: Understanding the Pattern
Look at what happens to the number in each step:
- If it's even (divisible by 2), divide by 2
- If it's odd, multiply by 3 and add 1

## Hint 2: Implementation Strategy  
You don't need to store all the numbers. Just process them one by one and print as you go.

## Hint 3: Loop Condition
Keep repeating the process until the number becomes 1. The sequence always terminates at 1.

## Hint 4: Example Walkthrough
For n = 5:
- 5 is odd → 5 × 3 + 1 = 16
- 16 is even → 16 ÷ 2 = 8  
- 8 is even → 8 ÷ 2 = 4
- 4 is even → 4 ÷ 2 = 2
- 2 is even → 2 ÷ 2 = 1
- Stop at 1

## Hint 5: Edge Cases
- What happens when n = 1? (Just print 1)
- Make sure to print the initial value of n as well