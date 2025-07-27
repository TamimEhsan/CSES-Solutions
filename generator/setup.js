const fs = require('fs');
const path = require('path');

/**
 * Setup script to create the initial project structure
 */
function setupProject() {
    console.log('🏗️  Setting up CSES Solutions project...\n');
    
    // Create directories
    const directories = [
        'topics',
        'topics/weird-algorithm',
        'topics/missing-number',
        'topics/distinct-numbers',
        'generator/templates',
        'generator/assets'
    ];
    
    // Create template and asset directories
    directories.forEach(dir => {
        if (!fs.existsSync(dir)) {
            fs.mkdirSync(dir, { recursive: true });
            console.log(`✓ Created directory: ${dir}`);
        }
    });
    
    // Create example data.json if it doesn't exist
    if (!fs.existsSync('data.json')) {
        const exampleData = {
            topics: [
                {
                    id: "introductory-problems",
                    name: "Introductory Problems",
                    problems: [
                        {
                            id: "weird-algorithm",
                            name: "Weird Algorithm",
                            tags: ["implementation", "math"],
                            link: "https://cses.fi/problemset/task/1068"
                        },
                        {
                            id: "missing-number",
                            name: "Missing Number",
                            tags: ["math", "implementation"],
                            link: "https://cses.fi/problemset/task/1083"
                        }
                    ]
                },
                {
                    id: "sorting-searching",
                    name: "Sorting and Searching",
                    problems: [
                        {
                            id: "distinct-numbers",
                            name: "Distinct Numbers",
                            tags: ["sorting", "data structures"],
                            link: "https://cses.fi/problemset/task/1621"
                        }
                    ]
                }
            ]
        };
        
        fs.writeFileSync('data.json', JSON.stringify(exampleData, null, 2));
        console.log('✓ Created data.json with example data');
    }
    
    // Create example problem files
    createExampleProblem();
    
    console.log('\n🎉 Project setup complete!');
    console.log('\nNext steps:');
    console.log('1. npm install');
    console.log('2. Add your problem content to the topics/ folder');
    console.log('3. npm run build');
    console.log('4. npm run serve (to preview locally)');
}

function createExampleProblem() {
    const problemPath = 'topics/weird-algorithm';
    
    // Create description.md
    const description = `# Weird Algorithm

Consider an algorithm that takes as input a positive integer n. If n is even, the algorithm divides it by two, and if n is odd, the algorithm multiplies it by three and adds one. The algorithm repeats this, until n is one.

For example, the sequence for n=5 is as follows:
5 → 16 → 8 → 4 → 2 → 1

Your task is to simulate the execution of the algorithm for a given value of n.

## Input

The only input line contains an integer n.

## Output

Print a line that contains all values of n during the algorithm.

## Constraints

- 1 ≤ n ≤ 10^6

## Example

**Input:**
\`\`\`
5
\`\`\`

**Output:**
\`\`\`
5 16 8 4 2 1
\`\`\``;

    // Create solution.md
    const solution = `# Solution

This problem asks us to implement the Collatz conjecture sequence.

## Algorithm

1. Start with the given number n
2. Print n
3. While n is not equal to 1:
   - If n is even: n = n / 2
   - If n is odd: n = 3n + 1
   - Print n

## Complexity

- **Time Complexity**: O(log n) on average
- **Space Complexity**: O(1)

## Key Insights

- Simple simulation problem - just follow the rules
- The sequence always reaches 1 for the given constraints
- Print each number separated by spaces`;

    // Create hints.md
    const hints = `# Hints

## Hint 1
Look at what happens when the number is even vs odd.

## Hint 2
You don't need to store all numbers, just process them one by one.

## Hint 3
The sequence always terminates at 1 (Collatz conjecture).`;

    // Create code.cpp
    const codeCpp = `#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long n;
    cin >> n;
    
    while (true) {
        cout << n;
        
        if (n == 1) {
            break;
        }
        
        cout << " ";
        
        if (n % 2 == 0) {
            n = n / 2;
        } else {
            n = n * 3 + 1;
        }
    }
    
    cout << endl;
    
    return 0;
}`;

    // Write files only if they don't exist
    const files = [
        { name: 'description.md', content: description },
        { name: 'solution.md', content: solution },
        { name: 'hints.md', content: hints },
        { name: 'code.cpp', content: codeCpp }
    ];
    
    files.forEach(file => {
        const filePath = path.join(problemPath, file.name);
        if (!fs.existsSync(filePath)) {
            fs.writeFileSync(filePath, file.content);
            console.log(`✓ Created example: ${filePath}`);
        }
    });
}

// Run setup if this script is executed directly
if (require.main === module) {
    setupProject();
}

module.exports = { setupProject };