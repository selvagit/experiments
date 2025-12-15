tea_prices_inr = {
    "green_tea": 250,   
    "black_tea": 200,
    "herbal_tea": 300,
}

tea_prices_usd = { tea:price/80 for tea, price in tea_prices_inr.items() }
print(tea_prices_usd)