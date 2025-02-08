📌 Problem Statement

The longest compounded word (a word formed by concatenating other words in the same list).

The second longest compounded word.

The time taken to process the file.

The input file contains an alphabetically sorted word list (one word per line, all lowercase, no spaces).

📂 Input Files

This program reads from files such as:

Input_01.txt (Small dataset)

Input_02.txt (Large dataset with 100,000+ words)

🔹 Example Input (Input_01.txt)

cat
cats
catsdogcats
catxdogcatsrat
dog
dogcatsdog
hippopotamuses
rat
ratcatdogcat

✅ Expected Output

Longest Compound Word: ratcatdogcat
Second Longest Compound Word: catsdogcats
Time taken to process file: 500 milliseconds

🚀 How to Run the Program

1️⃣ Compile the Code

g++ word_composition.cpp -o word_composition

2️⃣ Run the Program

./word_composition

3️⃣ Enter the Input Filename

You will be prompted to enter the filename:

Enter the input filename: Input_01.txt

🛠 Implementation Details

Data Structure Used: unordered_set for quick lookup.

Sorting: Words are sorted by length (longest first) for efficient processing.

Search Optimization: Uses DFS + Memoization to avoid redundant calculations.

Time Complexity: Optimized to handle large datasets efficiently.
