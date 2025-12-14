menu = [
    "spaghetti",
    "Iced pizza",   
    "salad",
    "Iced soup", 
]

iced_menu = [item for item in menu if "Iced" in item]
print(iced_menu)  # Output: ['Iced pizza', 'Iced soup'] 
