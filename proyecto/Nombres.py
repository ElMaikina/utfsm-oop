import random

def generate_name():
    prefixes = ['Ka', 'Zu', 'Lu', 'Fi', 'Ri', 'Ba', 'Ni', 'Ta', 'Ze', 'Mai', 'Tom', 'Vic', 'Chu', 'Bla']
    suffixes = ['li', 'ra', 'na', 'da', 'mi', 'sa', 'lo', 'ka', 'zi', 'iki', 'bi', 'ka']
    
    name = random.choice(prefixes) + random.choice(suffixes)
    return name