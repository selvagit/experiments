favourite_choices = [
    "chai chocolate",
    "green vanilla",  
    "masala strawberry",    
    "chai strawberry",
    "chai strawberry",
    "green chocolate",
    "masala strawberry",
]

unique_chai = { choice for choice in favourite_choices if "chai" in choice }
print(unique_chai)  # Output: {'chai chocolate', 'chai strawberry'}


receipes = {
    "chai chocolate": ["chai", "chocolate", "milk", "sugar"],
    "green vanilla": ["green tea", "vanilla", "milk", "sugar", "chai"],
    "masala strawberry": ["masala", "strawberry", "milk", "sugar"],
}

uniqu_spices = { spice for ingredients in receipes.values() for spice in ingredients }
print(uniqu_spices)
# Output: {'chai', 'chocolate', 'milk', 'sugar', 'green tea', 'vanilla', 'masala', 'strawberry'}

