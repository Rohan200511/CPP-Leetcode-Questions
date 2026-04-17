# Problem Statement

You are given m items, where each item has:

- Weight (w)
- Value (v)
- Penalty (p)

Your task is to maximize the total net value in a knapsack of capacity maxW.

    The net value of an item is defined as:
    net value = value - penalty

- If an item has a negative or zero net value, it should not be included.

Unlike the standard knapsack problem, you are allowed to take fractions of items.

# Objective

    Maximize:
    
    Total Net Value = Σ (value - penalty)
    
    subject to:
    
    Total Weight ≤ maxW
       Approach (Greedy Strategy)

## This problem is a variation of the Fractional Knapsack, solved using a greedy approach.

# Steps:

Compute ratio for each item:

- (value - penalty) / weight

- Sort items in descending order of this ratio.

### Iterate through items:

    If the item fully fits → take it.
    
    Else → take the fractional part.
    
    Skip items with net ≤ 0.

Instead of maximizing value/weight, we maximize:

    (value - penalty) / weight

This ensures we prioritize items with high effective profit.
